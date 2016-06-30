# Copyright 2015 Google Inc. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""Module used by gcloud to communicate with appengine services."""

from __future__ import with_statement

import urllib2

from googlecloudsdk.api_lib.app import logs_requestor
from googlecloudsdk.api_lib.app import util
from googlecloudsdk.api_lib.app import yaml_parsing
from googlecloudsdk.core import exceptions
from googlecloudsdk.core import log
from googlecloudsdk.core import properties
from googlecloudsdk.core.console import console_io
from googlecloudsdk.core.credentials import devshell as c_devshell
from googlecloudsdk.core.credentials import http
from googlecloudsdk.core.credentials import service_account as c_service_account
from googlecloudsdk.core.credentials import store as c_store
from googlecloudsdk.third_party.appengine.datastore import datastore_index
from googlecloudsdk.third_party.appengine.tools import appengine_rpc_httplib2
from oauth2client.contrib import gce as oauth2client_gce
import yaml


APPCFG_SCOPES = ['https://www.googleapis.com/auth/cloud-platform']

# Parameters for reading from the GCE metadata service.
METADATA_BASE = 'http://metadata.google.internal'
SERVICE_ACCOUNT_BASE = ('computeMetadata/v1/instance/service-accounts/default')

RpcServerClass = appengine_rpc_httplib2.HttpRpcServerOAuth2  # pylint: disable=invalid-name


class Error(exceptions.Error):
  """Base exception for the module."""
  pass


class UnknownConfigType(Error):
  """An exception for when trying to update a config type we don't know."""
  pass


class AppengineClient(object):
  """Client used by gcloud to communicate with appengine services.

  Attributes:
    server: The appengine server to which requests are sent.
    project: The appengine application in use.
    oauth2_access_token: An existing OAuth2 access token to use.
    oauth2_refresh_token: An existing OAuth2 refresh token to use.
    authenticate_service_account: Authenticate using the default service account
      for the Google Compute Engine VM in which gcloud is being called.
    ignore_bad_certs: Whether to ignore certificate errors when talking to the
      server.
  """

  def __init__(self, server=None, ignore_bad_certs=False):
    self.server = server or 'appengine.google.com'
    self.project = properties.VALUES.core.project.Get(required=True)
    self.ignore_bad_certs = ignore_bad_certs
    # Auth related options
    self.oauth2_access_token = None
    self.oauth2_refresh_token = None
    self.oauth_scopes = APPCFG_SCOPES
    self.authenticate_service_account = False
    self.client_id = None
    self.client_secret = None

    account = properties.VALUES.core.account.Get()
    # This statement will raise a c_store.Error if there is a problem
    # fetching credentials.
    credentials = c_store.Load(account=account)
    if isinstance(credentials, c_service_account.ServiceAccountCredentials):
      self.oauth2_access_token = credentials.access_token
      self.client_id = credentials.client_id
      self.client_secret = credentials.client_secret
    elif isinstance(credentials, c_devshell.DevshellCredentials):
      # TODO(user): This passes the access token to use for API calls to
      # appcfg which means that commands that are longer than the lifetime
      # of the access token may fail - e.g. some long deployments.  The proper
      # solution is to integrate appcfg closer with the Cloud SDK libraries,
      # this code will go away then and the standard credentials flow will be
      # used.
      self.oauth2_access_token = credentials.access_token
      self.client_id = None
      self.client_secret = None
    elif isinstance(credentials, oauth2client_gce.AppAssertionCredentials):
      # If we are on GCE, use the service account
      self.authenticate_service_account = True
      self.client_id = None
      self.client_secret = None
    else:
      # Otherwise use a stored refresh token
      self.oauth2_refresh_token = credentials.refresh_token
      self.client_id = credentials.client_id
      self.client_secret = credentials.client_secret

  def CleanupIndexes(self, index_yaml):
    """Removes unused datastore indexes.

    Args:
      index_yaml: The parsed yaml file with index data.
    """
    rpcserver = self._GetRpcServer()
    response = rpcserver.Send('/api/datastore/index/diff',
                              app_id=self.project, payload=index_yaml.ToYAML())
    unused_new_indexes, notused_indexes = (
        datastore_index.ParseMultipleIndexDefinitions(response))

    # Get confirmation from user which indexes should be deleted.
    deletions = datastore_index.IndexDefinitions(indexes=[])
    if notused_indexes.indexes:
      for index in notused_indexes.indexes:
        msg = ('This index is no longer defined in your index.yaml file.\n{0}'
               .format(str(index.ToYAML())))
        prompt = 'Do you want to delete this index'
        if console_io.PromptContinue(msg, prompt, default=True):
          deletions.indexes.append(index)

    # Do deletions of confirmed indexes.
    if deletions.indexes:
      response = rpcserver.Send('/api/datastore/index/delete',
                                app_id=self.project, payload=deletions.ToYAML())
      not_deleted = datastore_index.ParseIndexDefinitions(response)

      # Notify the user when indexes are not deleted.
      if not_deleted.indexes:
        not_deleted_count = len(not_deleted.indexes)
        if not_deleted_count == 1:
          warning_message = ('An index was not deleted.  Most likely this is '
                             'because it no longer exists.\n\n')
        else:
          warning_message = ('%d indexes were not deleted.  Most likely this '
                             'is because they no longer exist.\n\n'
                             % not_deleted_count)
        for index in not_deleted.indexes:
          warning_message += index.ToYAML()
        log.warning(warning_message)

  def GetLogs(self, service, version, severity, vhost, include_vhost,
              include_all, num_days, end_date, output_file):
    """Get application logs for the given version of the service.

    Args:
      service: str, The service of the app to fetch logs from.
      version: str, The version of the app to fetch logs for.
      severity: int, App log severity to request (0-4); None for request logs
        only.
      vhost: str, The virtual host of log messages to get. None for all hosts.
      include_vhost: bool, If true, the virtual host is included in log
        messages.
      include_all: bool, If true, we add to the log message everything we know
        about the request.
      num_days: int, Number of days worth of logs to export; 0 for all
        available.
      end_date: datetime.date, Date object representing last day of logs to
        return.  If None, today is used.
      output_file: Output file name or '-' for standard output.
    """
    rpcserver = self._GetRpcServer()
    requestor = logs_requestor.LogsRequester(
        rpcserver, self.project, service, version, severity, vhost,
        include_vhost, include_all)
    requestor.DownloadLogs(num_days, end_date, output_file)

  def GetLogsAppend(self, service, version, severity, vhost, include_vhost,
                    include_all, end_date, output_file):
    """Get application logs and append them to an existing file.

    Args:
      service: str, The service of the app to fetch logs from.
      version: str, The version of the app to fetch logs for.
      severity: int, App log severity to request (0-4); None for request logs
        only.
      vhost: str, The virtual host of log messages to get. None for all hosts.
      include_vhost: bool, If true, the virtual host is included in log
        messages.
      include_all: bool, If true, we add to the log message everything we know
        about the request.
      end_date: datetime.date, Date object representing last day of logs to
        return.  If None, today is used.
      output_file: Output file name or '-' for standard output.
    """
    rpcserver = self._GetRpcServer()
    requestor = logs_requestor.LogsRequester(
        rpcserver, self.project, service, version, severity, vhost,
        include_vhost, include_all)
    requestor.DownloadLogsAppend(end_date, output_file)

  def PrepareVmRuntime(self):
    """Prepare the application for vm runtimes and return state."""
    rpcserver = self._GetRpcServer(timeout_max_errors=5)
    rpcserver.Send('/api/vms/prepare', app_id=self.project)

  # TODO(b/29059251): vm_name and instance id are different, this API client
  # needs the VM name. The Zeus API will use instance id instead.
  def SetManagedByGoogle(self, service, version, vm_name=None, wait=True):
    """Sets a service version (and optionally an instance) to Google managed.

    This will reboot the machine and restore the instance with a fresh runtime.

    Args:
      service: str, The service to update.
      version: str, The version of the service to update.
      vm_name: str, The vm name of the instance to update.
      wait: bool, True to wait until it takes effect.
    """
    self._SetManagedBy(service, version, vm_name, '/api/vms/lock', wait)

  def SetManagedBySelf(self, service, version, vm_name=None, wait=True):
    """Sets a service version (optionally a single instance) as self managed.

    This is the 'break the glass' mode that lets you ssh into the machine and
    debug.

    Args:
      service: str, The service to update.
      version: str, The version of the service to update.
      vm_name: str, The vm name of the instance to update.
      wait: bool, True to wait until it takes effect.
    """
    self._SetManagedBy(service, version, vm_name, '/api/vms/debug', wait)

  def _SetManagedBy(self, service, version, vm_name, url, wait):
    """Switches a service version between management modes.

    Args:
      service: str, The service to update.
      version: str, The version of the service to update.
      vm_name: str, The vm name of the instance to update.
      url: str, The URL of the API to call to make the update.
      wait: bool, True to wait until it takes effect.

    Raises:
      Error: if changing the instance debug state failed.
    """
    rpcserver = self._GetRpcServer()
    kwargs = {'app_id': self.project,
              'version_match': version,
              'module': service}
    if vm_name:
      kwargs['instance'] = vm_name

    rpcserver.Send(url, **kwargs)

    if wait:
      def GetState():
        yaml_data = rpcserver.Send(
            '/api/vms/debugstate', app_id=self.project, version_match=version,
            module=service)
        state = yaml.safe_load(yaml_data)
        done = state['state'] != 'PENDING'
        return (done, (state['state'], state['message']))

      def PrintRetryMessage((unused_state, msg), delay):
        log.status.Print('{0}.  Will try again in {1} seconds.'
                         .format(msg, delay))

      _, (state, message) = util.RetryWithBackoff(
          GetState, PrintRetryMessage, initial_delay=1, backoff_factor=2,
          max_delay=5, max_tries=20)
      if state == 'ERROR':
        raise Error(message)

  def StartService(self, service, version):
    """Starts serving a the given version of the service.

    This only works if scaling is set to manual.

    Args:
      service: str, The service to start.
      version: str, The version of the service to start.
    """
    self._GetRpcServer().Send('/api/modules/start', app_id=self.project,
                              module=service, version=version)

  def StopService(self, service, version):
    """Stop serving a the given version of the service.

    This only works if scaling is set to manual.

    Args:
      service: str, The service to stop.
      version: str, The version of the service to stop.
    """
    self._GetRpcServer().Send('/api/modules/stop', app_id=self.project,
                              module=service, version=version)

  def UpdateConfig(self, config_name, parsed_yaml):
    """Updates any of the supported config file types.

    Args:
      config_name: str, The name of the config to deploy.
      parsed_yaml: The parsed object corresponding to that config type.

    Raises:
      UnknownConfigType: If config_name is not a value config type.

    Returns:
      Whatever the underlying update methods return.
    """
    if config_name == yaml_parsing.ConfigYamlInfo.CRON:
      return self.UpdateCron(parsed_yaml)
    if config_name == yaml_parsing.ConfigYamlInfo.DISPATCH:
      return self.UpdateDispatch(parsed_yaml)
    if config_name == yaml_parsing.ConfigYamlInfo.DOS:
      return self.UpdateDos(parsed_yaml)
    if config_name == yaml_parsing.ConfigYamlInfo.INDEX:
      return self.UpdateIndexes(parsed_yaml)
    if config_name == yaml_parsing.ConfigYamlInfo.QUEUE:
      return self.UpdateQueues(parsed_yaml)
    raise UnknownConfigType(
        'Config type [{0}] is not a known config type'.format(config_name))

  def UpdateCron(self, cron_yaml):
    """Updates any new or changed cron definitions.

    Args:
      cron_yaml: The parsed yaml file with cron data.
    """
    self._GetRpcServer().Send('/api/cron/update',
                              app_id=self.project, payload=cron_yaml.ToYAML())

  def UpdateDispatch(self, dispatch_yaml):
    """Updates new or changed dispatch definitions.

    Args:
      dispatch_yaml: The parsed yaml file with dispatch data.
    """
    self._GetRpcServer().Send('/api/dispatch/update',
                              app_id=self.project,
                              payload=dispatch_yaml.ToYAML())

  def UpdateDos(self, dos_yaml):
    """Updates any new or changed dos definitions.

    Args:
      dos_yaml: The parsed yaml file with dos data.
    """
    self._GetRpcServer().Send('/api/dos/update',
                              app_id=self.project, payload=dos_yaml.ToYAML())

  def UpdateIndexes(self, index_yaml):
    """Updates indexes.

    Args:
      index_yaml: The parsed yaml file with index data.
    """
    self._GetRpcServer().Send('/api/datastore/index/add',
                              app_id=self.project, payload=index_yaml.ToYAML())

  def UpdateQueues(self, queue_yaml):
    """Updates any new or changed task queue definitions.

    Args:
      queue_yaml: The parsed yaml file with queue data.
    """
    self._GetRpcServer().Send('/api/queue/update',
                              app_id=self.project, payload=queue_yaml.ToYAML())

  def _GetRpcServer(self, timeout_max_errors=2):
    """Returns an instance of an AbstractRpcServer.

    Args:
      timeout_max_errors: How many timeout errors to retry.
    Returns:
      A new AbstractRpcServer, on which RPC calls can be made.
    """
    log.debug('Host: {0}'.format(self.server))

    if self._IsGceEnvironment():
      credentials = oauth2client_gce.AppAssertionCredentials()
    else:
      credentials = None

    # In this case, the get_user_credentials parameters to the RPC server
    # constructor is actually an OAuth2Parameters.

    get_user_credentials = (
        appengine_rpc_httplib2.HttpRpcServerOAuth2.OAuth2Parameters(
            access_token=self.oauth2_access_token,
            client_id=self.client_id,
            client_secret=self.client_secret,
            scope=APPCFG_SCOPES,
            refresh_token=self.oauth2_refresh_token,
            credential_file=None,
            token_uri=None,
            credentials=credentials))
    # Also set gflags flag... this is a bit of a hack.
    if hasattr(appengine_rpc_httplib2.tools, 'FLAGS'):
      appengine_rpc_httplib2.tools.FLAGS.auth_local_webserver = True

    server = RpcServerClass(
        self.server,
        get_user_credentials,
        util.GetUserAgent(),
        util.GetSourceName(),
        host_override=None,
        save_cookies=True,
        auth_tries=3,
        timeout_max_errors=timeout_max_errors,
        account_type='HOSTED_OR_GOOGLE',
        secure=True,
        ignore_certs=self.ignore_bad_certs,
        http_object=http.Http())
    # TODO(user) Hack to avoid failure due to missing cacerts.txt resource.
    server.certpath = None
    # Don't use a cert file if the user passed ignore-bad-certs.
    server.cert_file_available = not self.ignore_bad_certs
    return util.RPCServer(server)

  def _IsGceEnvironment(self):
    """Determine if we are running in a GCE environment.

    Returns:
      True if we are running in a GCE environment.

    Raises:
      Error: The user has requested authentication for a service account but the
      environment is not correct for that to work.
    """
    if self.authenticate_service_account:
      # Avoid hard-to-understand errors later by checking that we have a
      # metadata service (so we are in a GCE VM) and that the VM is configured
      # with access to the appengine.admin scope.
      url = '%s/%s/scopes' % (METADATA_BASE, SERVICE_ACCOUNT_BASE)
      try:
        req = urllib2.Request(url, headers={'Metadata-Flavor': 'Google'})
        vm_scopes_string = urllib2.urlopen(req).read()
      except urllib2.URLError, e:
        raise Error(
            'Could not obtain scope list from metadata service: %s: %s. This '
            'may be because we are not running in a Google Compute Engine VM.' %
            (url, e))
      vm_scopes = vm_scopes_string.split()
      missing = list(set(self.oauth_scopes).difference(vm_scopes))
      if missing:
        raise Error(
            'You are currently logged into gcloud using a service account '
            'which does not have the appropriate access to [{0}]. The account '
            'has the following scopes: [{1}].  It needs [{2}] in order to '
            'succeed.\nPlease recreate this VM instance with the missing '
            'scopes. You may also log into a standard account that has the '
            'appropriate access by using `gcloud auth login`.'
            .format(self.project, ', '.join(vm_scopes), ', '.join(missing)))
      return True
    else:
      return False