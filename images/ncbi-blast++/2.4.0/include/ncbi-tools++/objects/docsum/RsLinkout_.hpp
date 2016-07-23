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

/// @file RsLinkout_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'docsum.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_DOCSUM_RSLINKOUT_BASE_HPP
#define OBJECTS_DOCSUM_RSLINKOUT_BASE_HPP

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
///link data for another resource
class NCBI_DOCSUM_EXPORT CRsLinkout_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CRsLinkout_Base(void);
    // destructor
    virtual ~CRsLinkout_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    class NCBI_DOCSUM_EXPORT C_Attlist : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Attlist(void);
        // destructor
        ~C_Attlist(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
        // types
        typedef string TResourceId;
        typedef string TLinkValue;
    
        // getters
        // setters
    
        ///BaseURLList.url_id
        /// mandatory
        /// typedef string TResourceId
        ///  Check whether the ResourceId data member has been assigned a value.
        bool IsSetResourceId(void) const;
        /// Check whether it is safe or not to call GetResourceId method.
        bool CanGetResourceId(void) const;
        void ResetResourceId(void);
        const TResourceId& GetResourceId(void) const;
        void SetResourceId(const TResourceId& value);
        TResourceId& SetResourceId(void);
    
        ///value to append to ResourceURL.base-url for complete
        ///						link
        /// mandatory
        /// typedef string TLinkValue
        ///  Check whether the LinkValue data member has been assigned a value.
        bool IsSetLinkValue(void) const;
        /// Check whether it is safe or not to call GetLinkValue method.
        bool CanGetLinkValue(void) const;
        void ResetLinkValue(void);
        const TLinkValue& GetLinkValue(void) const;
        void SetLinkValue(const TLinkValue& value);
        TLinkValue& SetLinkValue(void);
    
        /// Reset the whole object
        void Reset(void);
    
    
    private:
        // Prohibit copy constructor and assignment operator
        C_Attlist(const C_Attlist&);
        C_Attlist& operator=(const C_Attlist&);
    
        // data
        Uint4 m_set_State[1];
        string m_ResourceId;
        string m_LinkValue;
    };
    // types
    typedef C_Attlist TAttlist;

    // getters
    // setters

    /// mandatory
    /// typedef C_Attlist TAttlist
    ///  Check whether the Attlist data member has been assigned a value.
    bool IsSetAttlist(void) const;
    /// Check whether it is safe or not to call GetAttlist method.
    bool CanGetAttlist(void) const;
    void ResetAttlist(void);
    const TAttlist& GetAttlist(void) const;
    void SetAttlist(TAttlist& value);
    TAttlist& SetAttlist(void);

    ///link data for another resource
    /// mandatory
    ///  Check whether the RsLinkout data member has been assigned a value.
    bool IsSetRsLinkout(void) const;
    /// Check whether it is safe or not to call GetRsLinkout method.
    bool CanGetRsLinkout(void) const;
    void ResetRsLinkout(void);
    void SetRsLinkout(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CRsLinkout_Base(const CRsLinkout_Base&);
    CRsLinkout_Base& operator=(const CRsLinkout_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TAttlist > m_Attlist;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CRsLinkout_Base::C_Attlist::IsSetResourceId(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CRsLinkout_Base::C_Attlist::CanGetResourceId(void) const
{
    return IsSetResourceId();
}

inline
const CRsLinkout_Base::C_Attlist::TResourceId& CRsLinkout_Base::C_Attlist::GetResourceId(void) const
{
    if (!CanGetResourceId()) {
        ThrowUnassigned(0);
    }
    return m_ResourceId;
}

inline
void CRsLinkout_Base::C_Attlist::SetResourceId(const CRsLinkout_Base::C_Attlist::TResourceId& value)
{
    m_ResourceId = value;
    m_set_State[0] |= 0x3;
}

inline
CRsLinkout_Base::C_Attlist::TResourceId& CRsLinkout_Base::C_Attlist::SetResourceId(void)
{
#ifdef _DEBUG
    if (!IsSetResourceId()) {
        m_ResourceId = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_ResourceId;
}

inline
bool CRsLinkout_Base::C_Attlist::IsSetLinkValue(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CRsLinkout_Base::C_Attlist::CanGetLinkValue(void) const
{
    return IsSetLinkValue();
}

inline
const CRsLinkout_Base::C_Attlist::TLinkValue& CRsLinkout_Base::C_Attlist::GetLinkValue(void) const
{
    if (!CanGetLinkValue()) {
        ThrowUnassigned(1);
    }
    return m_LinkValue;
}

inline
void CRsLinkout_Base::C_Attlist::SetLinkValue(const CRsLinkout_Base::C_Attlist::TLinkValue& value)
{
    m_LinkValue = value;
    m_set_State[0] |= 0xc;
}

inline
CRsLinkout_Base::C_Attlist::TLinkValue& CRsLinkout_Base::C_Attlist::SetLinkValue(void)
{
#ifdef _DEBUG
    if (!IsSetLinkValue()) {
        m_LinkValue = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_LinkValue;
}

inline
bool CRsLinkout_Base::IsSetAttlist(void) const
{
    return m_Attlist.NotEmpty();
}

inline
bool CRsLinkout_Base::CanGetAttlist(void) const
{
    return true;
}

inline
const CRsLinkout_Base::TAttlist& CRsLinkout_Base::GetAttlist(void) const
{
    if ( !m_Attlist ) {
        const_cast<CRsLinkout_Base*>(this)->ResetAttlist();
    }
    return (*m_Attlist);
}

inline
CRsLinkout_Base::TAttlist& CRsLinkout_Base::SetAttlist(void)
{
    if ( !m_Attlist ) {
        ResetAttlist();
    }
    return (*m_Attlist);
}

inline
bool CRsLinkout_Base::IsSetRsLinkout(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CRsLinkout_Base::CanGetRsLinkout(void) const
{
    return false;
}

inline
void CRsLinkout_Base::ResetRsLinkout(void)
{
    m_set_State[0] &= ~0xc;
}

inline
void CRsLinkout_Base::SetRsLinkout(void)
{
    m_set_State[0] |= 0xc;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_DOCSUM_RSLINKOUT_BASE_HPP