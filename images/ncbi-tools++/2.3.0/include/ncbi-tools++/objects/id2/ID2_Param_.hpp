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

/// @file ID2_Param_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'id2.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_ID2_ID2_PARAM_BASE_HPP
#define OBJECTS_ID2_ID2_PARAM_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <string>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_ID2_EXPORT CID2_Param_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CID2_Param_Base(void);
    // destructor
    virtual ~CID2_Param_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    enum EType {
        eType_set_value   = 1,  ///< no response expected
        eType_get_value   = 2,  ///< this option is for client only  server replies with its value of param if known  server omits this param in reply if unknown to server
        eType_force_value = 3,  ///< no direct response expected,  but if the param or its value is not supported  an error is reported and the request is not be completed
        eType_use_package = 4  ///< use named package  value should be unset
    };
    
    /// Access to EType's attributes (values, names) as defined in spec
    static const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EType)(void);
    
    // types
    typedef string TName;
    typedef list< string > TValue;
    typedef EType TType;

    // getters
    // setters

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

    /// optional
    /// typedef list< string > TValue
    ///  Check whether the Value data member has been assigned a value.
    bool IsSetValue(void) const;
    /// Check whether it is safe or not to call GetValue method.
    bool CanGetValue(void) const;
    void ResetValue(void);
    const TValue& GetValue(void) const;
    TValue& SetValue(void);

    /// optional with default eType_set_value
    /// typedef EType TType
    ///  Check whether the Type data member has been assigned a value.
    bool IsSetType(void) const;
    /// Check whether it is safe or not to call GetType method.
    bool CanGetType(void) const;
    void ResetType(void);
    void SetDefaultType(void);
    TType GetType(void) const;
    void SetType(TType value);
    TType& SetType(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CID2_Param_Base(const CID2_Param_Base&);
    CID2_Param_Base& operator=(const CID2_Param_Base&);

    // data
    Uint4 m_set_State[1];
    string m_Name;
    list< string > m_Value;
    EType m_Type;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CID2_Param_Base::IsSetName(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CID2_Param_Base::CanGetName(void) const
{
    return IsSetName();
}

inline
const CID2_Param_Base::TName& CID2_Param_Base::GetName(void) const
{
    if (!CanGetName()) {
        ThrowUnassigned(0);
    }
    return m_Name;
}

inline
void CID2_Param_Base::SetName(const CID2_Param_Base::TName& value)
{
    m_Name = value;
    m_set_State[0] |= 0x3;
}

inline
CID2_Param_Base::TName& CID2_Param_Base::SetName(void)
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
bool CID2_Param_Base::IsSetValue(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CID2_Param_Base::CanGetValue(void) const
{
    return true;
}

inline
const CID2_Param_Base::TValue& CID2_Param_Base::GetValue(void) const
{
    return m_Value;
}

inline
CID2_Param_Base::TValue& CID2_Param_Base::SetValue(void)
{
    m_set_State[0] |= 0x4;
    return m_Value;
}

inline
bool CID2_Param_Base::IsSetType(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CID2_Param_Base::CanGetType(void) const
{
    return true;
}

inline
void CID2_Param_Base::ResetType(void)
{
    m_Type = eType_set_value;
    m_set_State[0] &= ~0x30;
}

inline
void CID2_Param_Base::SetDefaultType(void)
{
    ResetType();
}

inline
CID2_Param_Base::TType CID2_Param_Base::GetType(void) const
{
    return m_Type;
}

inline
void CID2_Param_Base::SetType(CID2_Param_Base::TType value)
{
    m_Type = value;
    m_set_State[0] |= 0x30;
}

inline
CID2_Param_Base::TType& CID2_Param_Base::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        memset(&m_Type,UnassignedByte(),sizeof(m_Type));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Type;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ID2_ID2_PARAM_BASE_HPP
