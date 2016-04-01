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

/// @file PC_DBTracking_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'pcsubstance.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_PCSUBSTANCE_PC_DBTRACKING_BASE_HPP
#define OBJECTS_PCSUBSTANCE_PC_DBTRACKING_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CDate;
class CObject_id;
class CPub;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// External DB Tracking Information
class NCBI_PCSUBSTANCE_EXPORT CPC_DBTracking_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPC_DBTracking_Base(void);
    // destructor
    virtual ~CPC_DBTracking_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TName;
    typedef CObject_id TSource_id;
    typedef CDate TDate;
    typedef string TDescription;
    typedef CPub TPub;

    // getters
    // setters

    /// Unique Name of External Database
    /// mandatory
    /// typedef string TName
    ///  Check whether the Name data member has been assigned a value.
    bool IsSetName(void) const;
    /// Check whether it is safe or not to call GetName method.
    bool CanGetName(void) const;
    void ResetName(void);
    const TName& GetName(void) const;
    void SetName(const TName& value);
    TName& SetName(void);

    /// Primary Unique ID used by External DB
    /// mandatory
    /// typedef CObject_id TSource_id
    ///  Check whether the Source_id data member has been assigned a value.
    bool IsSetSource_id(void) const;
    /// Check whether it is safe or not to call GetSource_id method.
    bool CanGetSource_id(void) const;
    void ResetSource_id(void);
    const TSource_id& GetSource_id(void) const;
    void SetSource_id(TSource_id& value);
    TSource_id& SetSource_id(void);

    /// External Database Release Date
    /// optional
    /// typedef CDate TDate
    ///  Check whether the Date data member has been assigned a value.
    bool IsSetDate(void) const;
    /// Check whether it is safe or not to call GetDate method.
    bool CanGetDate(void) const;
    void ResetDate(void);
    const TDate& GetDate(void) const;
    void SetDate(TDate& value);
    TDate& SetDate(void);

    /// External Database Release Code/Description
    /// optional
    /// typedef string TDescription
    ///  Check whether the Description data member has been assigned a value.
    bool IsSetDescription(void) const;
    /// Check whether it is safe or not to call GetDescription method.
    bool CanGetDescription(void) const;
    void ResetDescription(void);
    const TDescription& GetDescription(void) const;
    void SetDescription(const TDescription& value);
    TDescription& SetDescription(void);

    /// Data Submission to same DB by original Author
    /// optional
    /// typedef CPub TPub
    ///  Check whether the Pub data member has been assigned a value.
    bool IsSetPub(void) const;
    /// Check whether it is safe or not to call GetPub method.
    bool CanGetPub(void) const;
    void ResetPub(void);
    const TPub& GetPub(void) const;
    void SetPub(TPub& value);
    TPub& SetPub(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CPC_DBTracking_Base(const CPC_DBTracking_Base&);
    CPC_DBTracking_Base& operator=(const CPC_DBTracking_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Name;
    CRef< TSource_id > m_Source_id;
    CRef< TDate > m_Date;
    string m_Description;
    CRef< TPub > m_Pub;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPC_DBTracking_Base::IsSetName(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CPC_DBTracking_Base::CanGetName(void) const
{
    return IsSetName();
}

inline
const CPC_DBTracking_Base::TName& CPC_DBTracking_Base::GetName(void) const
{
    if (!CanGetName()) {
        ThrowUnassigned(0);
    }
    return m_Name;
}

inline
void CPC_DBTracking_Base::SetName(const CPC_DBTracking_Base::TName& value)
{
    m_Name = value;
    m_set_State[0] |= 0x3;
}

inline
CPC_DBTracking_Base::TName& CPC_DBTracking_Base::SetName(void)
{
#ifdef _DEBUG
    if (!IsSetName()) {
        m_Name = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Name;
}

inline
bool CPC_DBTracking_Base::IsSetSource_id(void) const
{
    return m_Source_id.NotEmpty();
}

inline
bool CPC_DBTracking_Base::CanGetSource_id(void) const
{
    return true;
}

inline
const CPC_DBTracking_Base::TSource_id& CPC_DBTracking_Base::GetSource_id(void) const
{
    if ( !m_Source_id ) {
        const_cast<CPC_DBTracking_Base*>(this)->ResetSource_id();
    }
    return (*m_Source_id);
}

inline
CPC_DBTracking_Base::TSource_id& CPC_DBTracking_Base::SetSource_id(void)
{
    if ( !m_Source_id ) {
        ResetSource_id();
    }
    return (*m_Source_id);
}

inline
bool CPC_DBTracking_Base::IsSetDate(void) const
{
    return m_Date.NotEmpty();
}

inline
bool CPC_DBTracking_Base::CanGetDate(void) const
{
    return IsSetDate();
}

inline
const CPC_DBTracking_Base::TDate& CPC_DBTracking_Base::GetDate(void) const
{
    if (!CanGetDate()) {
        ThrowUnassigned(2);
    }
    return (*m_Date);
}

inline
bool CPC_DBTracking_Base::IsSetDescription(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CPC_DBTracking_Base::CanGetDescription(void) const
{
    return IsSetDescription();
}

inline
const CPC_DBTracking_Base::TDescription& CPC_DBTracking_Base::GetDescription(void) const
{
    if (!CanGetDescription()) {
        ThrowUnassigned(3);
    }
    return m_Description;
}

inline
void CPC_DBTracking_Base::SetDescription(const CPC_DBTracking_Base::TDescription& value)
{
    m_Description = value;
    m_set_State[0] |= 0xc0;
}

inline
CPC_DBTracking_Base::TDescription& CPC_DBTracking_Base::SetDescription(void)
{
#ifdef _DEBUG
    if (!IsSetDescription()) {
        m_Description = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Description;
}

inline
bool CPC_DBTracking_Base::IsSetPub(void) const
{
    return m_Pub.NotEmpty();
}

inline
bool CPC_DBTracking_Base::CanGetPub(void) const
{
    return IsSetPub();
}

inline
const CPC_DBTracking_Base::TPub& CPC_DBTracking_Base::GetPub(void) const
{
    if (!CanGetPub()) {
        ThrowUnassigned(4);
    }
    return (*m_Pub);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_PCSUBSTANCE_PC_DBTRACKING_BASE_HPP
