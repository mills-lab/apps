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

/// @file Mim_cit_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'mim.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MIM_MIM_CIT_BASE_HPP
#define OBJECTS_MIM_MIM_CIT_BASE_HPP

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
class NCBI_MIM_EXPORT CMim_cit_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CMim_cit_Base(void);
    // destructor
    virtual ~CMim_cit_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef int TNumber;
    typedef string TAuthor;
    typedef string TOthers;
    typedef int TYear;

    // getters
    // setters

    /// mandatory
    /// typedef int TNumber
    ///  Check whether the Number data member has been assigned a value.
    bool IsSetNumber(void) const;
    /// Check whether it is safe or not to call GetNumber method.
    bool CanGetNumber(void) const;
    void ResetNumber(void);
    TNumber GetNumber(void) const;
    void SetNumber(TNumber value);
    TNumber& SetNumber(void);

    /// mandatory
    /// typedef string TAuthor
    ///  Check whether the Author data member has been assigned a value.
    bool IsSetAuthor(void) const;
    /// Check whether it is safe or not to call GetAuthor method.
    bool CanGetAuthor(void) const;
    void ResetAuthor(void);
    const TAuthor& GetAuthor(void) const;
    void SetAuthor(const TAuthor& value);
    TAuthor& SetAuthor(void);

    /// mandatory
    /// typedef string TOthers
    ///  Check whether the Others data member has been assigned a value.
    bool IsSetOthers(void) const;
    /// Check whether it is safe or not to call GetOthers method.
    bool CanGetOthers(void) const;
    void ResetOthers(void);
    const TOthers& GetOthers(void) const;
    void SetOthers(const TOthers& value);
    TOthers& SetOthers(void);

    /// mandatory
    /// typedef int TYear
    ///  Check whether the Year data member has been assigned a value.
    bool IsSetYear(void) const;
    /// Check whether it is safe or not to call GetYear method.
    bool CanGetYear(void) const;
    void ResetYear(void);
    TYear GetYear(void) const;
    void SetYear(TYear value);
    TYear& SetYear(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CMim_cit_Base(const CMim_cit_Base&);
    CMim_cit_Base& operator=(const CMim_cit_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Number;
    string m_Author;
    string m_Others;
    int m_Year;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CMim_cit_Base::IsSetNumber(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CMim_cit_Base::CanGetNumber(void) const
{
    return IsSetNumber();
}

inline
void CMim_cit_Base::ResetNumber(void)
{
    m_Number = 0;
    m_set_State[0] &= ~0x3;
}

inline
CMim_cit_Base::TNumber CMim_cit_Base::GetNumber(void) const
{
    if (!CanGetNumber()) {
        ThrowUnassigned(0);
    }
    return m_Number;
}

inline
void CMim_cit_Base::SetNumber(CMim_cit_Base::TNumber value)
{
    m_Number = value;
    m_set_State[0] |= 0x3;
}

inline
CMim_cit_Base::TNumber& CMim_cit_Base::SetNumber(void)
{
#ifdef _DEBUG
    if (!IsSetNumber()) {
        memset(&m_Number,UnassignedByte(),sizeof(m_Number));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Number;
}

inline
bool CMim_cit_Base::IsSetAuthor(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CMim_cit_Base::CanGetAuthor(void) const
{
    return IsSetAuthor();
}

inline
const CMim_cit_Base::TAuthor& CMim_cit_Base::GetAuthor(void) const
{
    if (!CanGetAuthor()) {
        ThrowUnassigned(1);
    }
    return m_Author;
}

inline
void CMim_cit_Base::SetAuthor(const CMim_cit_Base::TAuthor& value)
{
    m_Author = value;
    m_set_State[0] |= 0xc;
}

inline
CMim_cit_Base::TAuthor& CMim_cit_Base::SetAuthor(void)
{
#ifdef _DEBUG
    if (!IsSetAuthor()) {
        m_Author = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Author;
}

inline
bool CMim_cit_Base::IsSetOthers(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CMim_cit_Base::CanGetOthers(void) const
{
    return IsSetOthers();
}

inline
const CMim_cit_Base::TOthers& CMim_cit_Base::GetOthers(void) const
{
    if (!CanGetOthers()) {
        ThrowUnassigned(2);
    }
    return m_Others;
}

inline
void CMim_cit_Base::SetOthers(const CMim_cit_Base::TOthers& value)
{
    m_Others = value;
    m_set_State[0] |= 0x30;
}

inline
CMim_cit_Base::TOthers& CMim_cit_Base::SetOthers(void)
{
#ifdef _DEBUG
    if (!IsSetOthers()) {
        m_Others = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Others;
}

inline
bool CMim_cit_Base::IsSetYear(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CMim_cit_Base::CanGetYear(void) const
{
    return IsSetYear();
}

inline
void CMim_cit_Base::ResetYear(void)
{
    m_Year = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CMim_cit_Base::TYear CMim_cit_Base::GetYear(void) const
{
    if (!CanGetYear()) {
        ThrowUnassigned(3);
    }
    return m_Year;
}

inline
void CMim_cit_Base::SetYear(CMim_cit_Base::TYear value)
{
    m_Year = value;
    m_set_State[0] |= 0xc0;
}

inline
CMim_cit_Base::TYear& CMim_cit_Base::SetYear(void)
{
#ifdef _DEBUG
    if (!IsSetYear()) {
        memset(&m_Year,UnassignedByte(),sizeof(m_Year));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Year;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MIM_MIM_CIT_BASE_HPP