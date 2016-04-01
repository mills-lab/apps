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

/// @file ViewDataLink_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'gbproj.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_GBPROJ_VIEWDATALINK_BASE_HPP
#define OBJECTS_GBPROJ_VIEWDATALINK_BASE_HPP

// extra headers
#include <objects/gbproj/gbproj_export.h>

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <string>
#include <vector>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_GBPROJ_EXPORT CViewDataLink_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CViewDataLink_Base(void);
    // destructor
    virtual ~CViewDataLink_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    /////////////////////////////////////////////////////////////////////////////
    ///- fingerprint of object to show in view
    class NCBI_GBPROJ_EXPORT C_Fingerprint : public CSerialObject
    {
        typedef CSerialObject Tparent;
    public:
        // constructor
        C_Fingerprint(void);
        // destructor
        ~C_Fingerprint(void);
    
        // type info
        DECLARE_INTERNAL_TYPE_INFO();
    
    
        /// Choice variants.
        enum E_Choice {
            e_not_set = 0,  ///< No variant selected
            e_Crc32,
            e_Md5
        };
        /// Maximum+1 value of the choice variant enumerator.
        enum E_ChoiceStopper {
            e_MaxChoice = 3 ///< == e_Md5+1
        };
    
        /// Reset the whole object
        void Reset(void);
    
        /// Reset the selection (set it to e_not_set).
        void ResetSelection(void);
    
        /// Which variant is currently selected.
        E_Choice Which(void) const;
    
        /// Verify selection, throw exception if it differs from the expected.
        void CheckSelected(E_Choice index) const;
    
        /// Throw 'InvalidSelection' exception.
        NCBI_NORETURN void ThrowInvalidSelection(E_Choice index) const;
    
        /// Retrieve selection name (for diagnostic purposes).
        static string SelectionName(E_Choice index);
    
        /// Select the requested variant if needed.
        void Select(E_Choice index, EResetVariant reset = eDoResetVariant);
        /// Select the requested variant if needed,
        /// allocating CObject variants from memory pool.
        void Select(E_Choice index,
                    EResetVariant reset,
                    CObjectMemoryPool* pool);
    
        // types
        typedef int TCrc32;
        typedef vector< char > TMd5;
    
        // getters
        // setters
    
        // typedef int TCrc32
        bool IsCrc32(void) const;
        TCrc32 GetCrc32(void) const;
        TCrc32& SetCrc32(void);
        void SetCrc32(TCrc32 value);
    
        // typedef vector< char > TMd5
        bool IsMd5(void) const;
        const TMd5& GetMd5(void) const;
        TMd5& SetMd5(void);
    
    
    private:
        // copy constructor and assignment operator
        C_Fingerprint(const C_Fingerprint& );
        C_Fingerprint& operator=(const C_Fingerprint& );
        // choice state
        E_Choice m_choice;
        // helper methods
        void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);
    
        static const char* const sm_SelectionNames[];
        // data
        union {
            TCrc32 m_Crc32;
            NCBI_NS_NCBI::CUnionBuffer<TMd5> m_Md5;
            void* m_dummy_pointer_for_alignment;
        };
    };
    // types
    typedef int TProject_item_id;
    typedef C_Fingerprint TFingerprint;
    typedef string TType;

    // getters
    // setters

    ///- if both are absent - link goes to project
    ///- if both present - fingerprinted object inside project item
    ///- if only project-item-id present - link goes to project item
    ///- project item id
    /// optional
    /// typedef int TProject_item_id
    ///  Check whether the Project_item_id data member has been assigned a value.
    bool IsSetProject_item_id(void) const;
    /// Check whether it is safe or not to call GetProject_item_id method.
    bool CanGetProject_item_id(void) const;
    void ResetProject_item_id(void);
    TProject_item_id GetProject_item_id(void) const;
    void SetProject_item_id(TProject_item_id value);
    TProject_item_id& SetProject_item_id(void);

    /// optional
    /// typedef C_Fingerprint TFingerprint
    ///  Check whether the Fingerprint data member has been assigned a value.
    bool IsSetFingerprint(void) const;
    /// Check whether it is safe or not to call GetFingerprint method.
    bool CanGetFingerprint(void) const;
    void ResetFingerprint(void);
    const TFingerprint& GetFingerprint(void) const;
    void SetFingerprint(TFingerprint& value);
    TFingerprint& SetFingerprint(void);

    /// mandatory
    /// typedef string TType
    ///  Check whether the Type data member has been assigned a value.
    bool IsSetType(void) const;
    /// Check whether it is safe or not to call GetType method.
    bool CanGetType(void) const;
    void ResetType(void);
    const TType& GetType(void) const;
    void SetType(const TType& value);
    TType& SetType(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CViewDataLink_Base(const CViewDataLink_Base&);
    CViewDataLink_Base& operator=(const CViewDataLink_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Project_item_id;
    CRef< TFingerprint > m_Fingerprint;
    string m_Type;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CViewDataLink_Base::C_Fingerprint::E_Choice CViewDataLink_Base::C_Fingerprint::Which(void) const
{
    return m_choice;
}

inline
void CViewDataLink_Base::C_Fingerprint::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CViewDataLink_Base::C_Fingerprint::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CViewDataLink_Base::C_Fingerprint::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CViewDataLink_Base::C_Fingerprint::IsCrc32(void) const
{
    return m_choice == e_Crc32;
}

inline
CViewDataLink_Base::C_Fingerprint::TCrc32 CViewDataLink_Base::C_Fingerprint::GetCrc32(void) const
{
    CheckSelected(e_Crc32);
    return m_Crc32;
}

inline
CViewDataLink_Base::C_Fingerprint::TCrc32& CViewDataLink_Base::C_Fingerprint::SetCrc32(void)
{
    Select(e_Crc32, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Crc32;
}

inline
void CViewDataLink_Base::C_Fingerprint::SetCrc32(CViewDataLink_Base::C_Fingerprint::TCrc32 value)
{
    Select(e_Crc32, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Crc32 = value;
}

inline
bool CViewDataLink_Base::C_Fingerprint::IsMd5(void) const
{
    return m_choice == e_Md5;
}

inline
const CViewDataLink_Base::C_Fingerprint::TMd5& CViewDataLink_Base::C_Fingerprint::GetMd5(void) const
{
    CheckSelected(e_Md5);
    return *m_Md5;
}

inline
CViewDataLink_Base::C_Fingerprint::TMd5& CViewDataLink_Base::C_Fingerprint::SetMd5(void)
{
    Select(e_Md5, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_Md5;
}

inline
bool CViewDataLink_Base::IsSetProject_item_id(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CViewDataLink_Base::CanGetProject_item_id(void) const
{
    return IsSetProject_item_id();
}

inline
void CViewDataLink_Base::ResetProject_item_id(void)
{
    m_Project_item_id = 0;
    m_set_State[0] &= ~0x3;
}

inline
CViewDataLink_Base::TProject_item_id CViewDataLink_Base::GetProject_item_id(void) const
{
    if (!CanGetProject_item_id()) {
        ThrowUnassigned(0);
    }
    return m_Project_item_id;
}

inline
void CViewDataLink_Base::SetProject_item_id(CViewDataLink_Base::TProject_item_id value)
{
    m_Project_item_id = value;
    m_set_State[0] |= 0x3;
}

inline
CViewDataLink_Base::TProject_item_id& CViewDataLink_Base::SetProject_item_id(void)
{
#ifdef _DEBUG
    if (!IsSetProject_item_id()) {
        memset(&m_Project_item_id,UnassignedByte(),sizeof(m_Project_item_id));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Project_item_id;
}

inline
bool CViewDataLink_Base::IsSetFingerprint(void) const
{
    return m_Fingerprint.NotEmpty();
}

inline
bool CViewDataLink_Base::CanGetFingerprint(void) const
{
    return IsSetFingerprint();
}

inline
const CViewDataLink_Base::TFingerprint& CViewDataLink_Base::GetFingerprint(void) const
{
    if (!CanGetFingerprint()) {
        ThrowUnassigned(1);
    }
    return (*m_Fingerprint);
}

inline
bool CViewDataLink_Base::IsSetType(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CViewDataLink_Base::CanGetType(void) const
{
    return IsSetType();
}

inline
const CViewDataLink_Base::TType& CViewDataLink_Base::GetType(void) const
{
    if (!CanGetType()) {
        ThrowUnassigned(2);
    }
    return m_Type;
}

inline
void CViewDataLink_Base::SetType(const CViewDataLink_Base::TType& value)
{
    m_Type = value;
    m_set_State[0] |= 0x30;
}

inline
CViewDataLink_Base::TType& CViewDataLink_Base::SetType(void)
{
#ifdef _DEBUG
    if (!IsSetType()) {
        m_Type = UnassignedString();
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


#endif // OBJECTS_GBPROJ_VIEWDATALINK_BASE_HPP
