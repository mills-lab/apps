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

/// @file Sort_fields_action_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_SORT_FIELDS_ACTION_BASE_HPP
#define OBJECTS_MACRO_SORT_FIELDS_ACTION_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <objects/macro/Sort_order.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CConstraint_choice_set;
class CField_type;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CSort_fields_action_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CSort_fields_action_Base(void);
    // destructor
    virtual ~CSort_fields_action_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef CField_type TField;
    typedef ESort_order TOrder;
    typedef CConstraint_choice_set TConstraint;

    // getters
    // setters

    /// mandatory
    /// typedef CField_type TField
    ///  Check whether the Field data member has been assigned a value.
    bool IsSetField(void) const;
    /// Check whether it is safe or not to call GetField method.
    bool CanGetField(void) const;
    void ResetField(void);
    const TField& GetField(void) const;
    void SetField(TField& value);
    TField& SetField(void);

    /// mandatory
    /// typedef ESort_order TOrder
    ///  Check whether the Order data member has been assigned a value.
    bool IsSetOrder(void) const;
    /// Check whether it is safe or not to call GetOrder method.
    bool CanGetOrder(void) const;
    void ResetOrder(void);
    TOrder GetOrder(void) const;
    void SetOrder(TOrder value);
    TOrder& SetOrder(void);

    /// optional
    /// typedef CConstraint_choice_set TConstraint
    ///  Check whether the Constraint data member has been assigned a value.
    bool IsSetConstraint(void) const;
    /// Check whether it is safe or not to call GetConstraint method.
    bool CanGetConstraint(void) const;
    void ResetConstraint(void);
    const TConstraint& GetConstraint(void) const;
    void SetConstraint(TConstraint& value);
    TConstraint& SetConstraint(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CSort_fields_action_Base(const CSort_fields_action_Base&);
    CSort_fields_action_Base& operator=(const CSort_fields_action_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TField > m_Field;
    ESort_order m_Order;
    CRef< TConstraint > m_Constraint;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CSort_fields_action_Base::IsSetField(void) const
{
    return m_Field.NotEmpty();
}

inline
bool CSort_fields_action_Base::CanGetField(void) const
{
    return true;
}

inline
const CSort_fields_action_Base::TField& CSort_fields_action_Base::GetField(void) const
{
    if ( !m_Field ) {
        const_cast<CSort_fields_action_Base*>(this)->ResetField();
    }
    return (*m_Field);
}

inline
CSort_fields_action_Base::TField& CSort_fields_action_Base::SetField(void)
{
    if ( !m_Field ) {
        ResetField();
    }
    return (*m_Field);
}

inline
bool CSort_fields_action_Base::IsSetOrder(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CSort_fields_action_Base::CanGetOrder(void) const
{
    return IsSetOrder();
}

inline
void CSort_fields_action_Base::ResetOrder(void)
{
    m_Order = (ncbi::objects::ESort_order)(0);
    m_set_State[0] &= ~0xc;
}

inline
CSort_fields_action_Base::TOrder CSort_fields_action_Base::GetOrder(void) const
{
    if (!CanGetOrder()) {
        ThrowUnassigned(1);
    }
    return m_Order;
}

inline
void CSort_fields_action_Base::SetOrder(CSort_fields_action_Base::TOrder value)
{
    m_Order = value;
    m_set_State[0] |= 0xc;
}

inline
CSort_fields_action_Base::TOrder& CSort_fields_action_Base::SetOrder(void)
{
#ifdef _DEBUG
    if (!IsSetOrder()) {
        memset(&m_Order,UnassignedByte(),sizeof(m_Order));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Order;
}

inline
bool CSort_fields_action_Base::IsSetConstraint(void) const
{
    return m_Constraint.NotEmpty();
}

inline
bool CSort_fields_action_Base::CanGetConstraint(void) const
{
    return IsSetConstraint();
}

inline
const CSort_fields_action_Base::TConstraint& CSort_fields_action_Base::GetConstraint(void) const
{
    if (!CanGetConstraint()) {
        ThrowUnassigned(2);
    }
    return (*m_Constraint);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_SORT_FIELDS_ACTION_BASE_HPP