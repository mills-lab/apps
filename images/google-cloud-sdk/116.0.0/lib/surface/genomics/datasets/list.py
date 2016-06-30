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

"""Implementation of gcloud genomics datasets list.
"""

from googlecloudsdk.api_lib.genomics import genomics_util
from googlecloudsdk.calliope import base
from googlecloudsdk.calliope import exceptions
from googlecloudsdk.third_party.apitools.base.py import exceptions as apitools_exceptions
from googlecloudsdk.third_party.apitools.base.py import list_pager


class List(base.ListCommand):
  """List Genomics datasets in a project.

  Prints a table with summary information on datasets in the project.
  """

  def Collection(self):
    return 'genomics.datasets'

  def Run(self, args):
    """Run 'datasets list'.

    Args:
      args: argparse.Namespace, The arguments that this command was invoked
          with.

    Yields:
      The list of datasets for this project.

    Raises:
      HttpException: An http error response was received while executing api
          request.
    """
    apitools_client = genomics_util.GetGenomicsClient()
    request = genomics_util.GetGenomicsMessages().GenomicsDatasetsListRequest(
        projectId=genomics_util.GetProjectId())
    try:
      for resource in list_pager.YieldFromList(
          apitools_client.datasets,
          request,
          limit=args.limit,
          batch_size_attribute='pageSize',
          batch_size=args.limit,  # Use limit if any, else server default.
          field='datasets'):
        yield resource
    except apitools_exceptions.HttpError as error:
      raise exceptions.HttpException(genomics_util.GetErrorMessage(error))
