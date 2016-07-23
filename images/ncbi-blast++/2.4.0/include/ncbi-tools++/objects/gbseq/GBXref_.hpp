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

/// @file GBXref_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gbseq.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GBSEQ_GBXREF_BASE_HPP
#define OBJECTS_GBSEQ_GBXREF_BASE_HPP

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


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_GBSEQ_EXPORT CGBXref_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGBXref_Base(void);
    // destructor
    virtual ~CGBXref_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TDbname;
    typedef string TId;

    // getters
    // setters

    /// mandatory
    /// typedef string TDbname
    ///  Check whether the Dbname data member has been assigned a value.
    bool IsSetDbname(void) const;
    /// Check whether it is safe or not to call GetDbname method.
    bool CanGetDbname(void) const;
    void ResetDbname(void);
    const TDbname& GetDbname(void) const;
    void SetDbname(const TDbname& value);
    TDbname& SetDbname(void);

    /// mandatory
    /// typedef string TId
    ///  Check whether the Id data member has been assigned a value.
    bool IsSetId(void) const;
    /// Check whether it is safe or not to call GetId method.
    bool CanGetId(void) const;
    void ResetId(void);
    const TId& GetId(void) const;
    void SetId(const TId& value);
    TId& SetId(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CGBXref_Base(const CGBXref_Base&);
    CGBXref_Base& operator=(const CGBXref_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Dbname;
    string m_Id;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CGBXref_Base::IsSetDbname(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CGBXref_Base::CanGetDbname(void) const
{
    return IsSetDbname();
}

inline
const CGBXref_Base::TDbname& CGBXref_Base::GetDbname(void) const
{
    if (!CanGetDbname()) {
        ThrowUnassigned(0);
    }
    return m_Dbname;
}

inline
void CGBXref_Base::SetDbname(const CGBXref_Base::TDbname& value)
{
    m_Dbname = value;
    m_set_State[0] |= 0x3;
}

inline
CGBXref_Base::TDbname& CGBXref_Base::SetDbname(void)
{
#ifdef _DEBUG
    if (!IsSetDbname()) {
        m_Dbname = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Dbname;
}

inline
bool CGBXref_Base::IsSetId(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CGBXref_Base::CanGetId(void) const
{
    return IsSetId();
}

inline
const CGBXref_Base::TId& CGBXref_Base::GetId(void) const
{
    if (!CanGetId()) {
        ThrowUnassigned(1);
    }
    return m_Id;
}

inline
void CGBXref_Base::SetId(const CGBXref_Base::TId& value)
{
    m_Id = value;
    m_set_State[0] |= 0xc;
}

inline
CGBXref_Base::TId& CGBXref_Base::SetId(void)
{
#ifdef _DEBUG
    if (!IsSetId()) {
        m_Id = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Id;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GBSEQ_GBXREF_BASE_HPP