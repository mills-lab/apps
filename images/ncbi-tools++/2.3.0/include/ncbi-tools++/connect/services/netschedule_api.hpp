#ifndef CONN___NETSCHEDULE_API__HPP
#define CONN___NETSCHEDULE_API__HPP

/*  $Id: netschedule_api.hpp 470759 2015-06-18 17:19:51Z ivanov $
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 * Authors:  Anatoliy Kuznetsov, Maxim Didenko, Victor Joukov, Dmitry Kazimirov
 *
 * File Description:
 *   NetSchedule client API.
 *
 */


/// @file netschedule_api.hpp
/// NetSchedule client specs.
///

#include "netschedule_key.hpp"
#include "netschedule_api_expt.hpp"
#include "netservice_api.hpp"
#include "compound_id.hpp"

#include <corelib/plugin_manager.hpp>

BEGIN_NCBI_SCOPE


/// @internal
const unsigned int kNetScheduleMaxDBDataSize = 2048;

/// @internal
const unsigned int kNetScheduleMaxDBErrSize = 4096;


/// Defines whether the job queue is paused, and if so, defines
/// the pause mode set by the administrator.
enum ENetScheduleQueuePauseMode {
    eNSQ_NoPause,
    eNSQ_WithPullback,
    eNSQ_WithoutPullback
};

/** @addtogroup NetScheduleClient
 *
 * @{
 */

class CNetScheduleSubmitter;
class CNetScheduleExecutor;
class CNetScheduleJobReader;
class CNetScheduleAdmin;

struct CNetScheduleJob;

struct SNetScheduleAPIImpl;

/// Client API for NCBI NetSchedule server.
///
/// This API is logically divided into two sections:
/// Job Submitter API and Worker Node API.
///
/// As objects of this class are only smart pointers to the real
/// implementation, it is advisable that these objects are
/// allocated on the stack rather than the heap.
///
/// @sa CNetServiceException, CNetScheduleException
///

class NCBI_XCONNECT_EXPORT CNetScheduleAPI
{
    NCBI_NET_COMPONENT(NetScheduleAPI);

    /// Defines how this object must be initialized.
    enum EAppRegistry {
        eAppRegistry
    };

    /// Creates an instance of CNetScheduleAPI and initializes
    /// it with parameters read from the application registry.
    /// @param use_app_reg
    ///   Selects this constructor.
    ///   The parameter is not used otherwise.
    /// @param conf_section
    ///   Name of the registry section to look for the configuration
    ///   parameters in.  If empty string is passed, then the section
    ///   name "netschedule_api" will be used.
    explicit CNetScheduleAPI(EAppRegistry use_app_reg,
        const string& conf_section = kEmptyStr);

    /// Constructs a CNetScheduleAPI object and initializes it with
    /// parameters read from the specified registry object.
    /// @param reg
    ///   Registry to get the configuration parameters from.
    /// @param conf_section
    ///   Name of the registry section to look for the configuration
    ///   parameters in.  If empty string is passed, then the section
    ///   name "netschedule_api" will be used.
    explicit CNetScheduleAPI(const IRegistry& reg,
        const string& conf_section = kEmptyStr);

    /// Constructs a CNetScheduleAPI object and initializes it with
    /// parameters read from the specified configuration object.
    /// @param conf
    ///   A CConfig object to get the configuration parameters from.
    /// @param conf_section
    ///   Name of the configuration section where to look for the
    ///   parameters.  If empty string is passed, then the section
    ///   name "netschedule_api" will be used.
    explicit CNetScheduleAPI(CConfig* conf,
        const string& conf_section = kEmptyStr);

    /// Construct the client without linking it to any particular
    /// server. Actual server (host and port) will be extracted from the
    /// job key
    ///
    /// @param service_name
    ///    Name of the service to connect to (format:
    ///    LB service name or host:port)
    /// @param client_name
    ///    Name of the client program (project)
    /// @param queue_name
    ///    Name of the job queue
    ///
    CNetScheduleAPI(const string& service_name,
                    const string& client_name,
                    const string& queue_name);

    /// Set program version (like: MyProgram v. 1.2.3)
    ///
    /// Program version is passed to NetSchedule queue so queue
    /// controls versions and does not allow obsolete clients
    /// to connect and submit or execute jobs
    ///
    void SetProgramVersion(const string& pv);

    /// Get program version string
    const string& GetProgramVersion() const;

    /// Return Queue name
    const string& GetQueueName() const;
    // -----------------------------------------------------------------

    /// Job status codes
    enum EJobStatus
    {
        eJobNotFound = -1, ///< No such job
        ePending     = 0,  ///< Waiting for execution
        eRunning     = 1,  ///< Running on a worker node
        // One deprecated job state is omitted here.
        // It had the numeric value of 2.
        eCanceled    = 3,  ///< Explicitly canceled
        eFailed      = 4,  ///< Failed to run (execution timeout)
        eDone        = 5,  ///< Job is ready (computed successfully)
        eReading     = 6,  ///< Job has its output been reading
        eConfirmed   = 7,  ///< Final state - read confirmed
        eReadFailed  = 8,  ///< Final state - read failed
        eDeleted     = 9,  ///< The job has been wiped out of the database.

        eLastStatus        ///< Fake status (do not use)
    };

    /// Printable status type
    static
    string StatusToString(EJobStatus status);

    /// Parse status string into enumerator value
    ///
    /// Acceptable string values:
    ///   Pending, Running, Canceled, Failed, Done, Reading,
    ///   Confirmed, ReadFailed,
    /// Abbreviated
    ///   Pend, Run, Return, Cancel, Fail
    ///
    /// @return eJobNotFound if string cannot be parsed
    static
    EJobStatus StringToStatus(const CTempString& status_str);

    /// Job masks
    ///
    enum EJobMask {
        eEmptyMask    = 0,
        /// Exclusive job - the node executes only this job, even if
        /// there are processor resources
        eExclusiveJob = (1 << 0),
        // Not implemented yet ---v
        /// This jobs comes to the node before every regular jobs
        eOutOfOrder   = (1 << 1),
        /// This job will be scheduled to every active node
        eForEachNode  = (1 << 2),
        /// This job should be interpreted by client library, not client itself
        /// Can contain control information, e.g. instruction for node to die
        eSystemJob    = (1 << 3),
        //                     ---^
        eUserMask     = (1 << 16) ///< User's masks start from here
    };
    typedef unsigned TJobMask;

    /// Create an instance of CNetScheduleSubmitter.
    CNetScheduleSubmitter GetSubmitter();

    /// Create an instance of CNetScheduleExecutor.
    CNetScheduleExecutor GetExecutor();

    /// Create an instance of CNetScheduleJobReader.
    ///
    /// @param group
    ///     Restrict job retrieval to the specified job group name.
    /// @param affinity
    ///     Restrict job retrieval to the specified affinity.
    ///
    CNetScheduleJobReader GetJobReader(const string& group = kEmptyStr,
            const string& affinity = kEmptyStr);

    CNetScheduleAdmin GetAdmin();

    CNetService GetService();

    struct SServerParams {
        size_t max_input_size;
        size_t max_output_size;
    };

    const SServerParams& GetServerParams();

    typedef map<string, string> TQueueParams;
    void GetQueueParams(const string& queue_name, TQueueParams& queue_params);
    void GetQueueParams(TQueueParams& queue_params);

    /// Get job details
    EJobStatus GetJobDetails(
            CNetScheduleJob& job,
            time_t* job_exptime = NULL,
            ENetScheduleQueuePauseMode* pause_mode = NULL);

    /// Update the progress_message field of the job structure.
    /// Prior to calling this method, the caller must set the
    /// id field of the job structure.
    void GetProgressMsg(CNetScheduleJob& job);

    void SetCommunicationTimeout(const STimeout& to)
        {GetService().GetServerPool().SetCommunicationTimeout(to);}

    void SetClientNode(const string& client_node);

    void SetClientSession(const string& client_session);

    enum EClientType {
        eCT_Auto,
        eCT_Admin,
        eCT_Submitter,
        eCT_WorkerNode,
        eCT_Reader,
    };

    void SetClientType(EClientType client_type);

    enum ENetScheduleWarningType {
        eWarnUnknown,
        eWarnAffinityNotFound,
        eWarnAffinityNotPreferred,
        eWarnAffinityAlreadyPreferred,
        eWarnGroupNotFound,
        eWarnJobNotFound,
        eWarnJobAlreadyCanceled,
        eWarnJobAlreadyDone,
        eWarnJobAlreadyFailed,
        eWarnJobPassportOnlyMatch,
        eWarnNoParametersChanged,
        eWarnConfigFileNotChanged,
        eWarnAlertNotFound,
        eWarnAlertAlreadyAcknowledged,
        eWarnSubmitsDisabledForServer,
        eWarnQueueAlreadyPaused,
        eWarnQueueNotPaused,
        eWarnCommandObsolete,
    };
    static ENetScheduleWarningType ExtractWarningType(string& warn_msg);
    static const char* WarningTypeToString(
            ENetScheduleWarningType warning_type);

    /// @internal
    void UpdateAuthString();

    /// This method is for use by the grid_cli utility only.
    /// @internal
    void EnableWorkerNodeCompatMode();

    /// This method is for use by the grid_cli utility only.
    /// @internal
    void UseOldStyleAuth();

    /// Extract one of the servers comprising this service
    /// as a separate NetSchedule API object.
    /// This method is for use by the grid_cli utility only.
    /// @internal
    CNetScheduleAPI GetServer(CNetServer::TInstance server);

    /// This method is for use by the grid_cli utility only.
    /// @internal
    void SetEventHandler(INetEventHandler* event_handler);

    /// This method is for use by worker nodes.
    /// @internal
    void SetAuthParam(const string& param_name, const string& param_value);

    /// @internal
    CCompoundIDPool GetCompoundIDPool();
};


////////////////////////////////////////////////////////////////////////////////
////
/// Job description
///
struct CNetScheduleJob
{
    explicit CNetScheduleJob(const string& _input = kEmptyStr,
            const string& _affinity = kEmptyStr,
            CNetScheduleAPI::TJobMask _mask = CNetScheduleAPI::eEmptyMask) :
        input(_input),
        affinity(_affinity),
        mask(_mask),
        ret_code(0)
    {
    }

    void Reset()
    {
        input.erase();
        affinity.erase();
        client_ip.erase();
        session_id.erase();
        page_hit_id.erase();
        mask = CNetScheduleAPI::eEmptyMask;
        job_id.erase();
        ret_code = 0;
        output.erase();
        error_msg.erase();
        progress_msg.erase();
        group.erase();
        auth_token.erase();
        server = NULL;
    }
    // input parameters

    /// Input data. Arbitrary string that contains input data
    /// for the job. It is suggested to use NetCache to keep
    /// the actual data and pass NetCache key as job input.
    string input;

    string affinity;

    string client_ip;
    string session_id;
    string page_hit_id;

    CNetScheduleAPI::TJobMask  mask;

    /// Job key.
    string job_id;
    /// Job return code.
    int ret_code;
    /// Job result data.
    string output;
    string error_msg;
    string progress_msg;

    string group;

    string auth_token;

    /// The server the job belongs to.
    CNetServer server;
};

struct SNetScheduleSubmitterImpl;

/// Smart pointer to the job submission part of the NetSchedule API.
/// Objects of this class are returned by
/// CNetScheduleAPI::GetSubmitter().  It is possible to have several
/// submitters per one CNetScheduleAPI object.
///
/// @sa CNetScheduleAPI, CNetScheduleExecutor
class NCBI_XCONNECT_EXPORT CNetScheduleSubmitter
{
    NCBI_NET_COMPONENT(NetScheduleSubmitter);

    /// Submit job.
    /// @note on success job.job_id will be set.
    string SubmitJob(CNetScheduleJob& job);

    /// Submit job batch.
    /// Method automatically splits the submission into reasonable sized
    /// transactions, so there is no limit on the input batch size.
    ///
    /// Every job in the job list receives job id
    ///
    void SubmitJobBatch(vector<CNetScheduleJob>& jobs,
            const string& job_group = kEmptyStr);

    /// Incremental retrieval of jobs that are done or failed.
    ///
    /// @param job_id
    ///    Placeholder for storing the identifier of the job that's
    ///    done or failed.
    /// @param auth_token
    ///    Placeholder for storing a reading reservation token, which
    ///    guarantees that no other caller will be given the same
    ///    job for reading.
    /// @param job_status
    ///    Placeholder for storing the status of the job,
    ///    either eDone or eFailed.
    /// @param timeout
    ///    Number of seconds to wait before the status of jobs is
    ///    automatically reverted to the original one ('Done' or
    ///    'Failed').  If zero, the default timeout of the NetSchedule
    ///    queue will be used instead.
    /// @param job_group
    ///    Only consider jobs belonging to the specified group.
    /// @return
    ///    True if a job that's done or failed has been returned
    ///    via the job_id references. False if no servers reported
    ///    jobs marked as either done or failed.
    bool Read(string* job_id,
        string* auth_token,
        CNetScheduleAPI::EJobStatus* job_status,
        unsigned timeout = 0,
        const string& job_group = kEmptyStr);

    /// Mark the specified job as successfully retrieved.
    /// The job will change its status to 'Confirmed' after
    /// this operation.
    ///
    /// @param job_id
    ///    Job key returned by Read().
    /// @param auth_token
    ///    Reservation token returned by Read().
    void ReadConfirm(const string& job_id, const string& auth_token);

    /// Refuse from processing the results of the specified job.
    /// The job will change its status back to the original one
    /// ('Done' or 'Failed') after this operation.
    ///
    /// @param job_id
    ///    Job key returned by Read().
    /// @param auth_token
    ///    Reservation token returned by Read().
    void ReadRollback(const string& job_id, const string& auth_token);

    /// Refuse from processing the results of the specified job
    /// and increase its counter of failed job result retrievals.
    /// If this counter exceeds the failed_read_retries parameter
    /// specified in the configuration file, the job will permanently
    /// change its status to 'ReadFailed'.
    ///
    /// @param job_id
    ///    Job key returned by Read().
    /// @param auth_token
    ///    Reservation token returned by Read().
    /// @param error_message
    ///    This message can be used to describe the cause why the
    ///    job results could not be read.
    void ReadFail(const string& job_id, const string& auth_token,
        const string& error_message = kEmptyStr);

    /// Submit job to server and wait for the result.
    /// This function should be used if we expect that job execution
    /// infrastructure is capable of finishing job in the specified
    /// time frame. This method can save a lot of round trips with the
    /// NetSchedule server (comparing to series of GetStatus calls).
    ///
    /// @param job
    ///    NetSchedule job description structure
    /// @param wait_time
    ///    Time in seconds function waits for the job to finish.
    ///    If job does not finish in the output parameter will hold the empty
    ///    string.
    ///
    /// @return job status
    ///
    /// @note the result fields of the job description structure will be set
    ///    if the job is finished during specified time.
    ///
    CNetScheduleAPI:: EJobStatus SubmitJobAndWait(CNetScheduleJob& job,
                                                  unsigned       wait_time);

    /// Cancel job
    ///
    /// @param job_key
    ///    Job key
    void CancelJob(const string& job_key);

    /// Cancel job group
    ///
    /// @param job_group
    ///    Group ID.
    /// @param job_statuses
    ///    Optional comma-separated list of job statuses
    void CancelJobGroup(const string& job_group,
            const string& job_statuses = kEmptyStr);

    /// Get progress message
    ///
    /// @param job
    ///    NetSchedule job description structure. The message is taken
    ///    from the progress_msg field.
    ///
    /// @sa PutProgressMsg
    ///
    void GetProgressMsg(CNetScheduleJob& job);

    /// Get the current status of the specified job. Unlike the similar
    /// method from CNetScheduleExecutor, this method prolongs the lifetime
    /// of the job on the server.
    ///
    /// @param job_key
    ///    NetSchedule job key.
    /// @param job_exptime
    ///    Number of seconds since EPOCH when the job will expire
    ///    on the server.
    /// @param pause_mode
    ///    Queue pause mode set by the administrator.
    ///
    /// @return The current job status. eJobNotFound is returned if the job
    ///         cannot be found (job record has expired).
    ///
    CNetScheduleAPI::EJobStatus GetJobStatus(
            const string& job_key,
            time_t* job_exptime = NULL,
            ENetScheduleQueuePauseMode* pause_mode = NULL);

    /// Get full information about the specified job.
    ///
    /// @param job
    ///    A reference to the job description structure. The job key
    ///    is taken from the job_key field. Upon return, the structure
    ///    will be filled with the current information about the job,
    ///    including its input and output.
    /// @param job_exptime
    ///    Number of seconds since EPOCH when the job will expire
    ///    on the server.
    ///
    /// @return The current job status.
    ///
    CNetScheduleAPI::EJobStatus GetJobDetails(
            CNetScheduleJob& job,
            time_t* job_exptime = NULL,
            ENetScheduleQueuePauseMode* pause_mode = NULL);
};

////////////////////////////////////////////////////////////////////////////////
////
struct SNetScheduleExecutorImpl;

/// Smart pointer to a part of the NetSchedule API that does job
/// retrieval and processing on the worker node side.
/// Objects of this class are returned by
/// CNetScheduleAPI::GetExecutor().
///
/// @sa CNetScheduleAPI, CNetScheduleSubmitter
class NCBI_XCONNECT_EXPORT CNetScheduleExecutor
{
    NCBI_NET_COMPONENT(NetScheduleExecutor);

    /// Affinity matching modes.
    ///
    /// @note Explicitly specified affinities are always searched first.
    ///
    enum EJobAffinityPreference {
        ePreferredAffsOrAnyJob,
        ePreferredAffinities,
        eClaimNewPreferredAffs,
        eAnyJob,
        eExplicitAffinitiesOnly,
    };

    /// Set preferred method of requesting jobs with affinities.
    ///
    void SetAffinityPreference(EJobAffinityPreference aff_pref);

    /// Retrieve jobs from the specified group only.
    ///
    void SetJobGroup(const string& job_group);

    /// Get a pending job.
    ///
    /// When function returns TRUE, job information is written to the 'job'
    /// structure, and job status is changed to eRunning. This client
    /// (the worker node) becomes responsible for execution or returning of
    /// the job. If there are no jobs in the queue, the function returns
    /// FALSE immediately and this call has to be repeated.
    ///
    /// @param job
    ///     NetSchedule job description structure.
    ///
    /// @param affinity_list
    ///     Comma-separated list of affinity tokens.
    ///
    /// @param deadline
    ///     Deadline for waiting for a matching job to appear in the queue.
    ///
    /// @return
    ///     TRUE if job has been returned from the queue and its input
    ///     fields are set.
    ///     FALSE means queue is empty or for some other reason NetSchedule
    ///     decided not to give a job to this node (e.g. no jobs with
    ///     matching affinities).
    ///
    bool GetJob(CNetScheduleJob&  job,
                const string&     affinity_list = kEmptyStr,
                CDeadline*        dealine = NULL);

    /// The same as GetJob(CNetScheduleJob&, EJobAffinityPreference,
    ///                    const string&, CDeadline*),
    /// except it accepts integer wait time in seconds instead of CDeadline.
    bool GetJob(CNetScheduleJob& job,
                unsigned         wait_time,
                const string&    affinity_list = kEmptyStr);

    /// @deprecated
    ///     Use GetJob() instead.
    ///
    /// Wait for a new job in the queue.
    ///
    /// @param job
    ///    NetSchedule job description structure
    ///
    /// @param wait_time
    ///    Time in seconds function waits for new jobs to arrive.
    ///    If there are no jobs in the period of time,
    ///    the function returns FALSE.
    ///
    /// @param affinity_list
    ///    Comma-separated list of affinity tokens.
    ///
    /// @sa GetJob
    ///
    NCBI_DEPRECATED
    bool WaitJob(CNetScheduleJob& job, unsigned wait_time,
            const string& affinity_list = kEmptyStr)
    {
        return GetJob(job, wait_time, affinity_list);
    }


    /// Put job result (job should be received by GetJob() or WaitJob())
    ///
    /// @param job
    ///     NetSchedule job description structure. its ret_code
    ///     and output fields should be set
    ///
    void PutResult(const CNetScheduleJob& job);

    /// Put job interim (progress) message.
    ///
    /// @note The progress message must be first saved to a NetCache blob,
    ///       then (using this method) the key of that blob must be set
    ///       as the job progress message. The blob can be overwritten then
    ///       in NetCache directly without notifying the NetSchedule server.
    ///
    /// @param job
    ///     NetSchedule job description structure. its progerss_msg
    ///     field should be set to a NetCache key that contains the
    ///     actual progress message.
    ///
    /// @sa GetProgressMsg
    ///
    void PutProgressMsg(const CNetScheduleJob& job);

    /// Get progress message
    ///
    /// @param job
    ///    NetSchedule job description structure. The message is taken from
    ///    progress_msg filed
    ///
    /// @sa PutProgressMsg
    ///
    void GetProgressMsg(CNetScheduleJob& job);


    /// Submit job failure diagnostics. This method indicates that
    /// job failed because of some fatal, unrecoverable error.
    ///
    /// @param job
    ///     NetSchedule job description structure. its error_msg
    ///     and optionally ret_code and output fields should be set
    ///
    /// @param no_retries
    ///     Instruct NetSchedule to fail the job permanently.
    ///     The job will not be rerun regardless of whether retries
    ///     are enabled for the queue or not.
    ///
    void PutFailure(const CNetScheduleJob& job, bool no_retries = false);

    /// Reschedule a job with new affinity and/or group information.
    ///
    /// This method requires that the following fields of the specified
    /// CNetScheduleJob structure are filled: 'job_id', 'auth_token',
    /// 'affinity' and/or 'group'.
    void Reschedule(const CNetScheduleJob& job);

    /// Get the current status of the specified job. Unlike the similar
    /// method from CNetScheduleSubmitter, this method does not prolong
    /// the lifetime of the job on the server.
    ///
    /// @param job_key
    ///    NetSchedule job key.
    /// @param job_exptime
    ///    Number of seconds since EPOCH when the job will expire
    ///    on the server.
    /// @param pause_mode
    ///    Queue pause mode set by the administrator.
    ///
    /// @return The current job status. eJobNotFound is returned if the job
    ///         cannot be found (job record has expired).
    ///
    CNetScheduleAPI::EJobStatus GetJobStatus(
            const CNetScheduleJob& job,
            time_t* job_exptime = NULL,
            ENetScheduleQueuePauseMode* pause_mode = NULL);

    NCBI_DEPRECATED
    CNetScheduleAPI::EJobStatus GetJobStatus(
            const string& job_key,
            time_t* job_exptime = NULL,
            ENetScheduleQueuePauseMode* pause_mode = NULL)
    {
        CNetScheduleJob job;
        job.job_id = job_key;
        return GetJobStatus(job, job_exptime, pause_mode);
    }

    /// Switch the job back to the "Pending" status so that it can be
    /// run again on a different worker node.
    ///
    /// The node may decide to return the job if it cannot be processed
    /// at the moment (not enough resources, the node is shutting down,
    /// etc.)
    ///
    void ReturnJob(const CNetScheduleJob& job);

    /// Increment job execution timeout
    ///
    /// When node picks up the job for execution it may periodically
    /// communicate to the server that job is still alive and
    /// prolong job execution timeout, so job server does not try to
    /// reschedule.
    ///
    /// @param runtime_inc
    ///    Estimated time in seconds(from the current moment) to
    ///    finish the job.
    void JobDelayExpiration(const CNetScheduleJob& job, unsigned runtime_inc);

    /// Retrieve queue parameters from the server.
    const CNetScheduleAPI::SServerParams& GetServerParams();

    /// Unregister client-listener. After this call, the
    /// server will not try to send any notification messages or
    /// maintain job affinity for the client.
    void ClearNode();

    void AddPreferredAffinities(const vector<string>& affs_to_add)
        { ChangePreferredAffinities(&affs_to_add, NULL); }

    void DeletePreferredAffinities(const vector<string>& affs_to_del)
        { ChangePreferredAffinities(NULL, &affs_to_del); }

    void ChangePreferredAffinities(const vector<string>* affs_to_add,
        const vector<string>* affs_to_delete);

    /// Return Queue name
    const string& GetQueueName();
    const string& GetClientName();
    const string& GetServiceName();
};

// Definition for backward compatibility.
typedef CNetScheduleExecutor CNetScheduleExecuter;


struct SNetScheduleJobReaderImpl;

/// Smart pointer to a part of the NetSchedule API that allows to
/// retrieve completed jobs.
/// Objects of this class are returned by CNetScheduleAPI::GetJobReader().
///
/// @sa CNetScheduleAPI
///
class NCBI_XCONNECT_EXPORT CNetScheduleJobReader
{
    NCBI_NET_COMPONENT(NetScheduleJobReader);

    /// @deprecated
    ///     Use GetJobReader(group, ...) instead.
    ///
    NCBI_DEPRECATED
    void SetJobGroup(const string& group_name);

    /// @deprecated
    ///     Use GetJobReader(..., affinity) instead.
    ///
    NCBI_DEPRECATED
    void SetAffinity(const string& affinity);

    /// Possible outcomes of ReadNextJob() calls.
    enum EReadNextJobResult {
        eRNJ_JobReady,      ///< A job is returned.
        eRNJ_NotReady,      ///< No matching jobs are ready for reading.
        eRNJ_Timeout = eRNJ_NotReady,
        eRNJ_NoMoreJobs,    ///< No matching jobs.
        eRNJ_Interrupt,     ///< ReadNextJob() has been interrupted.
    };

    /// Wait and return the next completed job.
    ///
    /// @param job     Structure to fill with information about the job.
    ///                The following fields of the structure will be filled:
    ///                - job_id
    ///                - auth_token
    ///                - affinity
    ///                - client_ip
    ///                - session_id
    ///                - page_hit_id
    ///
    /// @param job_status Pointer to a variable where to store the final
    ///                   status of the job.
    ///
    /// @param timeout Timeout to wait for job completion.
    ///                If NULL, the method returns immediately.
    ///
    EReadNextJobResult ReadNextJob(CNetScheduleJob* job,
        CNetScheduleAPI::EJobStatus* job_status,
        const CTimeout* timeout = NULL);

    /// Abort waiting for a completed job in the above method.
    /// Can be called from a signal handler or a parallel thread.
    ///
    void InterruptReading();
};

////////////////////////////////////////////////////////////////////////////////
////

struct SNetScheduleAdminImpl;

class NCBI_XCONNECT_EXPORT CNetScheduleAdmin
{
    NCBI_NET_COMPONENT(NetScheduleAdmin);

    /// Status map, shows number of jobs in each status
    typedef map<string, unsigned> TStatusMap;

    /// Returns statuses for a given affinity token
    /// @param status_map
    ///    Status map (status to job count)
    /// @param affinity_token
    ///    Affinity token (optional)
    /// @param job_group
    ///    Only jobs belonging to the specified group (optional)
    void StatusSnapshot(TStatusMap& status_map,
            const string& affinity_token = kEmptyStr,
            const string& job_group = kEmptyStr);

    /// Create an instance of the given queue class.
    /// @param qname
    ///    Name of the queue to create
    /// @param qclass
    ///    Parameter set described in config file in a qclass_<qname> section.
    /// @param description
    ///    Brief free text description of the queue.
    void CreateQueue(
        const string& qname,
        const string& qclass,
        const string& description = kEmptyStr);

    /// Delete queue
    /// Applicable only to queues, created through CreateQueue method
    /// @param qname
    ///    Name of the queue to delete.
    void DeleteQueue(const string& qname);


    /// Shutdown level
    ///
    enum EShutdownLevel {
        eNoShutdown = 0,    ///< No Shutdown was requested
        eNormalShutdown,    ///< Normal shutdown was requested
        eShutdownImmediate, ///< Urgent shutdown was requested
        eDie,               ///< A serious error occurred, the server shuts down
        eDrain              ///< Wait for all server data to expire.
    };

    /// Enable server drain mode.
    ///
    void SwitchToDrainMode(ESwitch on_off);

    /// Shutdown the server daemon.
    ///
    void ShutdownServer(EShutdownLevel level = eNormalShutdown);

    /// Cancel all jobs in the queue (optionally with particular statuses).
    ///
    /// @param job_statuses
    ///    Optional comma-separated list of job statuses
    void CancelAllJobs(const string& job_statuses = kEmptyStr);

    void DumpJob(CNcbiOstream& out, const string& job_key);
    CNetServerMultilineCmdOutput DumpJob(const string& job_key);

    void ReloadServerConfig();

    //////////////////////////////////////////////////////
    /// Print version string
    void PrintServerVersion(CNcbiOstream& output_stream);

    struct SWorkerNodeInfo {
        string name;
        string prog;
        string host;
        unsigned short port;
        CTime last_access;
    };

    void GetWorkerNodes(list<SWorkerNodeInfo>& worker_nodes);

    void PrintConf(CNcbiOstream& output_stream);

    enum EStatisticsOptions
    {
        eStatisticsAll,
        eStatisticsBrief,
        eStatisticsClients
    };

    void PrintServerStatistics(CNcbiOstream& output_stream,
        EStatisticsOptions opt = eStatisticsBrief);

    void PrintHealth(CNcbiOstream& output_stream);

    // Two versions of DumpQueue to keep the code compile compatible
    void DumpQueue(CNcbiOstream& output_stream,
        const string& start_after_job = kEmptyStr,
        size_t job_count = 0,
        const string& job_statuses = kEmptyStr,
        const string& job_group = kEmptyStr);
    void DumpQueue(CNcbiOstream& output_stream,
        const string& start_after_job,
        size_t job_count,
        CNetScheduleAPI::EJobStatus status,
        const string& job_group = kEmptyStr);

    typedef map<string, string> TQueueInfo;
    // Get information on a particular queue of a particular server.
    void GetQueueInfo(CNetServer server, const string& queue_name,
            TQueueInfo& queue_info);
    // The same as above, but for any random server in the service.
    void GetQueueInfo(const string& queue_name, TQueueInfo& queue_info);
    // Return information on the current queue.
    void GetQueueInfo(CNetServer server, TQueueInfo& queue_info);
    // The same as above, but for any random server in the service.
    void GetQueueInfo(TQueueInfo& queue_info);
    void PrintQueueInfo(const string& queue_name, CNcbiOstream& output_stream);

    struct SServerQueueList {
        CNetServer server;
        list<string> queues;

        SServerQueueList(SNetServerImpl* server_impl) : server(server_impl) {}
    };

    typedef list<SServerQueueList> TQueueList;

    void GetQueueList(TQueueList& result);
};


NCBI_DECLARE_INTERFACE_VERSION(SNetScheduleAPIImpl, "xnetschedule_api", 1,0, 0);


/////////////////////////////////////////////////////////////////////////////
//
/// @internal
extern NCBI_XCONNECT_EXPORT const char* const kNetScheduleAPIDriverName;

/// @internal
extern NCBI_XCONNECT_EXPORT
void g_AppendClientIPAndSessionID(string& cmd,
        const string* default_session = NULL);

/// @internal
extern NCBI_XCONNECT_EXPORT
void g_AppendHitID(string& cmd);

/// @internal
extern NCBI_XCONNECT_EXPORT
void g_AppendClientIPSessionIDHitID(string& cmd,
        const string* default_session = NULL);

/// @internal
extern NCBI_XCONNECT_EXPORT
int g_ParseNSOutput(const string& attr_string, const char* const* attr_names,
        string* attr_values, int attr_count);

/// @internal
void NCBI_XCONNECT_EXPORT NCBI_EntryPoint_xnetscheduleapi(
     CPluginManager<SNetScheduleAPIImpl>::TDriverInfoList&   info_list,
     CPluginManager<SNetScheduleAPIImpl>::EEntryPointRequest method);

/// @internal
class NCBI_XCONNECT_EXPORT CNetScheduleNotificationHandler
{
public:
    CNetScheduleNotificationHandler();

    bool ReceiveNotification(string* server_host = NULL);

    bool WaitForNotification(const CDeadline& deadline,
                             string*          server_host = NULL);

    unsigned short GetPort() const {return m_UDPPort;}

    const string& GetMessage() const {return m_Message;}

    void PrintPortNumber();

// Submitter methods.
public:
    void SubmitJob(CNetScheduleSubmitter::TInstance submitter,
            CNetScheduleJob& job,
            unsigned wait_time,
            CNetServer* server = NULL);

    bool CheckJobStatusNotification(const string& job_id,
            CNetScheduleAPI::EJobStatus* job_status,
            int* last_event_index = NULL);

    // This method requires calling SubmitJob prior with wait_time set
    CNetScheduleAPI::EJobStatus WaitForJobCompletion(CNetScheduleJob& job,
            CDeadline& deadline, CNetScheduleAPI ns_api);

    bool RequestJobWatching(CNetScheduleAPI::TInstance ns_api,
            const string& job_id,
            const CDeadline& deadline,
            CNetScheduleAPI::EJobStatus* job_status,
            int* last_event_index);

    enum EJobStatusMask {
        fJSM_Pending        = 1 << CNetScheduleAPI::ePending,
        fJSM_Running        = 1 << CNetScheduleAPI::eRunning,
        fJSM_Canceled       = 1 << CNetScheduleAPI::eCanceled,
        fJSM_Failed         = 1 << CNetScheduleAPI::eFailed,
        fJSM_Done           = 1 << CNetScheduleAPI::eDone,
        fJSM_Reading        = 1 << CNetScheduleAPI::eReading,
        fJSM_Confirmed      = 1 << CNetScheduleAPI::eConfirmed,
        fJSM_ReadFailed     = 1 << CNetScheduleAPI::eReadFailed,
        fJSM_Deleted        = 1 << CNetScheduleAPI::eDeleted
    };
    typedef int TJobStatusMask;

    CNetScheduleAPI::EJobStatus WaitForJobEvent(
            const string& job_key,
            CDeadline& deadline,
            CNetScheduleAPI ns_api,
            TJobStatusMask status_mask,
            int last_event_index = kMax_Int,
            int *new_event_index = NULL);

// Worker node methods.
public:
    static string MkBaseGETCmd(
        CNetScheduleExecutor::EJobAffinityPreference affinity_preference,
        const string& affinity_list);
    void CmdAppendTimeoutGroupAndClientInfo(string& cmd,
            const CDeadline* deadline, const string& job_group);
    bool RequestJob(CNetScheduleExecutor::TInstance executor,
                    CNetScheduleJob& job,
                    const string& cmd);
    bool CheckRequestJobNotification(CNetScheduleExecutor::TInstance executor,
                                     CNetServer* server);

protected:
    CDatagramSocket m_UDPSocket;
    unsigned short m_UDPPort;

    char m_Buffer[1024];
    string m_Message;
};

/// @internal
inline unsigned s_GetRemainingSeconds(const CDeadline& deadline)
{
    unsigned sec;
    unsigned nanosec;

    deadline.GetRemainingTime().GetNano(&sec, &nanosec);

    if (nanosec > 0)
        ++sec;

    return sec;
}

/* @} */


END_NCBI_SCOPE


#endif  /* CONN___NETSCHEDULE_API__HPP */
