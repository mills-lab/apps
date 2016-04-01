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

/// @file GCClient_AssemblyInfo_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gencoll_client.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GENOMECOLL_GCCLIENT_ASSEMBLYINFO_BASE_HPP
#define OBJECTS_GENOMECOLL_GCCLIENT_ASSEMBLYINFO_BASE_HPP

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
class CGCClient_AssemblyInfo_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGCClient_AssemblyInfo_Base(void);
    // destructor
    virtual ~CGCClient_AssemblyInfo_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TAccession;
    typedef bool TLatest;
    typedef bool TMajor;
    typedef bool TAnnotated;

    // getters
    // setters

    /// mandatory
    /// typedef string TAccession
    ///  Check whether the Accession data member has been assigned a value.
    bool IsSetAccession(void) const;
    /// Check whether it is safe or not to call GetAccession method.
    bool CanGetAccession(void) const;
    void ResetAccession(void);
    const TAccession& GetAccession(void) const;
    void SetAccession(const TAccession& value);
    TAccession& SetAccession(void);

    /// mandatory
    /// typedef bool TLatest
    ///  Check whether the Latest data member has been assigned a value.
    bool IsSetLatest(void) const;
    /// Check whether it is safe or not to call GetLatest method.
    bool CanGetLatest(void) const;
    void ResetLatest(void);
    TLatest GetLatest(void) const;
    void SetLatest(TLatest value);
    TLatest& SetLatest(void);

    /// mandatory
    /// typedef bool TMajor
    ///  Check whether the Major data member has been assigned a value.
    bool IsSetMajor(void) const;
    /// Check whether it is safe or not to call GetMajor method.
    bool CanGetMajor(void) const;
    void ResetMajor(void);
    TMajor GetMajor(void) const;
    void SetMajor(TMajor value);
    TMajor& SetMajor(void);

    /// mandatory
    /// typedef bool TAnnotated
    ///  Check whether the Annotated data member has been assigned a value.
    bool IsSetAnnotated(void) const;
    /// Check whether it is safe or not to call GetAnnotated method.
    bool CanGetAnnotated(void) const;
    void ResetAnnotated(void);
    TAnnotated GetAnnotated(void) const;
    void SetAnnotated(TAnnotated value);
    TAnnotated& SetAnnotated(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CGCClient_AssemblyInfo_Base(const CGCClient_AssemblyInfo_Base&);
    CGCClient_AssemblyInfo_Base& operator=(const CGCClient_AssemblyInfo_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Accession;
    bool m_Latest;
    bool m_Major;
    bool m_Annotated;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CGCClient_AssemblyInfo_Base::IsSetAccession(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CGCClient_AssemblyInfo_Base::CanGetAccession(void) const
{
    return IsSetAccession();
}

inline
const CGCClient_AssemblyInfo_Base::TAccession& CGCClient_AssemblyInfo_Base::GetAccession(void) const
{
    if (!CanGetAccession()) {
        ThrowUnassigned(0);
    }
    return m_Accession;
}

inline
void CGCClient_AssemblyInfo_Base::SetAccession(const CGCClient_AssemblyInfo_Base::TAccession& value)
{
    m_Accession = value;
    m_set_State[0] |= 0x3;
}

inline
CGCClient_AssemblyInfo_Base::TAccession& CGCClient_AssemblyInfo_Base::SetAccession(void)
{
#ifdef _DEBUG
    if (!IsSetAccession()) {
        m_Accession = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Accession;
}

inline
bool CGCClient_AssemblyInfo_Base::IsSetLatest(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CGCClient_AssemblyInfo_Base::CanGetLatest(void) const
{
    return IsSetLatest();
}

inline
void CGCClient_AssemblyInfo_Base::ResetLatest(void)
{
    m_Latest = 0;
    m_set_State[0] &= ~0xc;
}

inline
CGCClient_AssemblyInfo_Base::TLatest CGCClient_AssemblyInfo_Base::GetLatest(void) const
{
    if (!CanGetLatest()) {
        ThrowUnassigned(1);
    }
    return m_Latest;
}

inline
void CGCClient_AssemblyInfo_Base::SetLatest(CGCClient_AssemblyInfo_Base::TLatest value)
{
    m_Latest = value;
    m_set_State[0] |= 0xc;
}

inline
CGCClient_AssemblyInfo_Base::TLatest& CGCClient_AssemblyInfo_Base::SetLatest(void)
{
#ifdef _DEBUG
    if (!IsSetLatest()) {
        memset(&m_Latest,UnassignedByte(),sizeof(m_Latest));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Latest;
}

inline
bool CGCClient_AssemblyInfo_Base::IsSetMajor(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CGCClient_AssemblyInfo_Base::CanGetMajor(void) const
{
    return IsSetMajor();
}

inline
void CGCClient_AssemblyInfo_Base::ResetMajor(void)
{
    m_Major = 0;
    m_set_State[0] &= ~0x30;
}

inline
CGCClient_AssemblyInfo_Base::TMajor CGCClient_AssemblyInfo_Base::GetMajor(void) const
{
    if (!CanGetMajor()) {
        ThrowUnassigned(2);
    }
    return m_Major;
}

inline
void CGCClient_AssemblyInfo_Base::SetMajor(CGCClient_AssemblyInfo_Base::TMajor value)
{
    m_Major = value;
    m_set_State[0] |= 0x30;
}

inline
CGCClient_AssemblyInfo_Base::TMajor& CGCClient_AssemblyInfo_Base::SetMajor(void)
{
#ifdef _DEBUG
    if (!IsSetMajor()) {
        memset(&m_Major,UnassignedByte(),sizeof(m_Major));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Major;
}

inline
bool CGCClient_AssemblyInfo_Base::IsSetAnnotated(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CGCClient_AssemblyInfo_Base::CanGetAnnotated(void) const
{
    return IsSetAnnotated();
}

inline
void CGCClient_AssemblyInfo_Base::ResetAnnotated(void)
{
    m_Annotated = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CGCClient_AssemblyInfo_Base::TAnnotated CGCClient_AssemblyInfo_Base::GetAnnotated(void) const
{
    if (!CanGetAnnotated()) {
        ThrowUnassigned(3);
    }
    return m_Annotated;
}

inline
void CGCClient_AssemblyInfo_Base::SetAnnotated(CGCClient_AssemblyInfo_Base::TAnnotated value)
{
    m_Annotated = value;
    m_set_State[0] |= 0xc0;
}

inline
CGCClient_AssemblyInfo_Base::TAnnotated& CGCClient_AssemblyInfo_Base::SetAnnotated(void)
{
#ifdef _DEBUG
    if (!IsSetAnnotated()) {
        memset(&m_Annotated,UnassignedByte(),sizeof(m_Annotated));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Annotated;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_GENOMECOLL_GCCLIENT_ASSEMBLYINFO_BASE_HPP
