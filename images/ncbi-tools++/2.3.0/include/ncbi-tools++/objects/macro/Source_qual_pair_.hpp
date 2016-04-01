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

/// @file Source_qual_pair_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_SOURCE_QUAL_PAIR_BASE_HPP
#define OBJECTS_MACRO_SOURCE_QUAL_PAIR_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <objects/macro/Source_qual.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CSource_qual_pair_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CSource_qual_pair_Base(void);
    // destructor
    virtual ~CSource_qual_pair_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef ESource_qual TField_from;
    typedef ESource_qual TField_to;

    // getters
    // setters

    /// mandatory
    /// typedef ESource_qual TField_from
    ///  Check whether the Field_from data member has been assigned a value.
    bool IsSetField_from(void) const;
    /// Check whether it is safe or not to call GetField_from method.
    bool CanGetField_from(void) const;
    void ResetField_from(void);
    TField_from GetField_from(void) const;
    void SetField_from(TField_from value);
    TField_from& SetField_from(void);

    /// mandatory
    /// typedef ESource_qual TField_to
    ///  Check whether the Field_to data member has been assigned a value.
    bool IsSetField_to(void) const;
    /// Check whether it is safe or not to call GetField_to method.
    bool CanGetField_to(void) const;
    void ResetField_to(void);
    TField_to GetField_to(void) const;
    void SetField_to(TField_to value);
    TField_to& SetField_to(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CSource_qual_pair_Base(const CSource_qual_pair_Base&);
    CSource_qual_pair_Base& operator=(const CSource_qual_pair_Base&);

    // data
    Uint4 m_set_State[1];
    ESource_qual m_Field_from;
    ESource_qual m_Field_to;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CSource_qual_pair_Base::IsSetField_from(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CSource_qual_pair_Base::CanGetField_from(void) const
{
    return IsSetField_from();
}

inline
void CSource_qual_pair_Base::ResetField_from(void)
{
    m_Field_from = (ncbi::objects::ESource_qual)(0);
    m_set_State[0] &= ~0x3;
}

inline
CSource_qual_pair_Base::TField_from CSource_qual_pair_Base::GetField_from(void) const
{
    if (!CanGetField_from()) {
        ThrowUnassigned(0);
    }
    return m_Field_from;
}

inline
void CSource_qual_pair_Base::SetField_from(CSource_qual_pair_Base::TField_from value)
{
    m_Field_from = value;
    m_set_State[0] |= 0x3;
}

inline
CSource_qual_pair_Base::TField_from& CSource_qual_pair_Base::SetField_from(void)
{
#ifdef _DEBUG
    if (!IsSetField_from()) {
        memset(&m_Field_from,UnassignedByte(),sizeof(m_Field_from));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Field_from;
}

inline
bool CSource_qual_pair_Base::IsSetField_to(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CSource_qual_pair_Base::CanGetField_to(void) const
{
    return IsSetField_to();
}

inline
void CSource_qual_pair_Base::ResetField_to(void)
{
    m_Field_to = (ncbi::objects::ESource_qual)(0);
    m_set_State[0] &= ~0xc;
}

inline
CSource_qual_pair_Base::TField_to CSource_qual_pair_Base::GetField_to(void) const
{
    if (!CanGetField_to()) {
        ThrowUnassigned(1);
    }
    return m_Field_to;
}

inline
void CSource_qual_pair_Base::SetField_to(CSource_qual_pair_Base::TField_to value)
{
    m_Field_to = value;
    m_set_State[0] |= 0xc;
}

inline
CSource_qual_pair_Base::TField_to& CSource_qual_pair_Base::SetField_to(void)
{
#ifdef _DEBUG
    if (!IsSetField_to()) {
        memset(&m_Field_to,UnassignedByte(),sizeof(m_Field_to));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Field_to;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_SOURCE_QUAL_PAIR_BASE_HPP
