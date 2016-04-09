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

/// @file Mim_page_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'mim.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MIM_MIM_PAGE_BASE_HPP
#define OBJECTS_MIM_MIM_PAGE_BASE_HPP

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
class NCBI_MIM_EXPORT CMim_page_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CMim_page_Base(void);
    // destructor
    virtual ~CMim_page_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef string TFrom;
    typedef string TTo;

    // getters
    // setters

    /// mandatory
    /// typedef string TFrom
    ///  Check whether the From data member has been assigned a value.
    bool IsSetFrom(void) const;
    /// Check whether it is safe or not to call GetFrom method.
    bool CanGetFrom(void) const;
    void ResetFrom(void);
    const TFrom& GetFrom(void) const;
    void SetFrom(const TFrom& value);
    TFrom& SetFrom(void);

    /// optional
    /// typedef string TTo
    ///  Check whether the To data member has been assigned a value.
    bool IsSetTo(void) const;
    /// Check whether it is safe or not to call GetTo method.
    bool CanGetTo(void) const;
    void ResetTo(void);
    const TTo& GetTo(void) const;
    void SetTo(const TTo& value);
    TTo& SetTo(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CMim_page_Base(const CMim_page_Base&);
    CMim_page_Base& operator=(const CMim_page_Base&);

    // data
    Uint4 m_set_State[1];
    string m_From;
    string m_To;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CMim_page_Base::IsSetFrom(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CMim_page_Base::CanGetFrom(void) const
{
    return IsSetFrom();
}

inline
const CMim_page_Base::TFrom& CMim_page_Base::GetFrom(void) const
{
    if (!CanGetFrom()) {
        ThrowUnassigned(0);
    }
    return m_From;
}

inline
void CMim_page_Base::SetFrom(const CMim_page_Base::TFrom& value)
{
    m_From = value;
    m_set_State[0] |= 0x3;
}

inline
CMim_page_Base::TFrom& CMim_page_Base::SetFrom(void)
{
#ifdef _DEBUG
    if (!IsSetFrom()) {
        m_From = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1;
    return m_From;
}

inline
bool CMim_page_Base::IsSetTo(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CMim_page_Base::CanGetTo(void) const
{
    return IsSetTo();
}

inline
const CMim_page_Base::TTo& CMim_page_Base::GetTo(void) const
{
    if (!CanGetTo()) {
        ThrowUnassigned(1);
    }
    return m_To;
}

inline
void CMim_page_Base::SetTo(const CMim_page_Base::TTo& value)
{
    m_To = value;
    m_set_State[0] |= 0xc;
}

inline
CMim_page_Base::TTo& CMim_page_Base::SetTo(void)
{
#ifdef _DEBUG
    if (!IsSetTo()) {
        m_To = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_To;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MIM_MIM_PAGE_BASE_HPP