/* $Id$
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
 */

/// @file Biostruc_history_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'mmdb1.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MMDB1_BIOSTRUC_HISTORY_BASE_HPP
#define OBJECTS_MMDB1_BIOSTRUC_HISTORY_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CBiostruc_replace;
class CBiostruc_source;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// The history of a biostruc indicates it's origin and it's update history
/// within MMDB, the NCBI-maintained molecular structure database.  
class NCBI_MMDB1_EXPORT CBiostruc_history_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CBiostruc_history_Base(void);
    // destructor
    virtual ~CBiostruc_history_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CBiostruc_replace TReplaces;
    typedef CBiostruc_replace TReplaced_by;
    typedef CBiostruc_source TData_source;

    // getters
    // setters

    /// optional
    /// typedef CBiostruc_replace TReplaces
    ///  Check whether the Replaces data member has been assigned a value.
    bool IsSetReplaces(void) const;
    /// Check whether it is safe or not to call GetReplaces method.
    bool CanGetReplaces(void) const;
    void ResetReplaces(void);
    const TReplaces& GetReplaces(void) const;
    void SetReplaces(TReplaces& value);
    TReplaces& SetReplaces(void);

    /// optional
    /// typedef CBiostruc_replace TReplaced_by
    ///  Check whether the Replaced_by data member has been assigned a value.
    bool IsSetReplaced_by(void) const;
    /// Check whether it is safe or not to call GetReplaced_by method.
    bool CanGetReplaced_by(void) const;
    void ResetReplaced_by(void);
    const TReplaced_by& GetReplaced_by(void) const;
    void SetReplaced_by(TReplaced_by& value);
    TReplaced_by& SetReplaced_by(void);

    /// optional
    /// typedef CBiostruc_source TData_source
    ///  Check whether the Data_source data member has been assigned a value.
    bool IsSetData_source(void) const;
    /// Check whether it is safe or not to call GetData_source method.
    bool CanGetData_source(void) const;
    void ResetData_source(void);
    const TData_source& GetData_source(void) const;
    void SetData_source(TData_source& value);
    TData_source& SetData_source(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CBiostruc_history_Base(const CBiostruc_history_Base&);
    CBiostruc_history_Base& operator=(const CBiostruc_history_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TReplaces > m_Replaces;
    CRef< TReplaced_by > m_Replaced_by;
    CRef< TData_source > m_Data_source;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CBiostruc_history_Base::IsSetReplaces(void) const
{
    return m_Replaces.NotEmpty();
}

inline
bool CBiostruc_history_Base::CanGetReplaces(void) const
{
    return IsSetReplaces();
}

inline
const CBiostruc_history_Base::TReplaces& CBiostruc_history_Base::GetReplaces(void) const
{
    if (!CanGetReplaces()) {
        ThrowUnassigned(0);
    }
    return (*m_Replaces);
}

inline
bool CBiostruc_history_Base::IsSetReplaced_by(void) const
{
    return m_Replaced_by.NotEmpty();
}

inline
bool CBiostruc_history_Base::CanGetReplaced_by(void) const
{
    return IsSetReplaced_by();
}

inline
const CBiostruc_history_Base::TReplaced_by& CBiostruc_history_Base::GetReplaced_by(void) const
{
    if (!CanGetReplaced_by()) {
        ThrowUnassigned(1);
    }
    return (*m_Replaced_by);
}

inline
bool CBiostruc_history_Base::IsSetData_source(void) const
{
    return m_Data_source.NotEmpty();
}

inline
bool CBiostruc_history_Base::CanGetData_source(void) const
{
    return IsSetData_source();
}

inline
const CBiostruc_history_Base::TData_source& CBiostruc_history_Base::GetData_source(void) const
{
    if (!CanGetData_source()) {
        ThrowUnassigned(2);
    }
    return (*m_Data_source);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MMDB1_BIOSTRUC_HISTORY_BASE_HPP
