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

/// @file T3Request_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'taxon3.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TAXON3_T3REQUEST_BASE_HPP
#define OBJECTS_TAXON3_T3REQUEST_BASE_HPP

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
class COrg_ref;
class CSequenceOfInt;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_TAXON3_EXPORT CT3Request_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CT3Request_Base(void);
    // destructor
    virtual ~CT3Request_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();


    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,  ///< No variant selected
        e_Taxid,
        e_Name,
        e_Org,
        e_Join
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 5 ///< == e_Join+1
    };

    /// Reset the whole object
    virtual void Reset(void);

    /// Reset the selection (set it to e_not_set).
    virtual void ResetSelection(void);

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
    typedef int TTaxid;
    typedef string TName;
    typedef COrg_ref TOrg;
    typedef CSequenceOfInt TJoin;

    // getters
    // setters

    // typedef int TTaxid
    bool IsTaxid(void) const;
    TTaxid GetTaxid(void) const;
    TTaxid& SetTaxid(void);
    void SetTaxid(TTaxid value);

    // typedef string TName
    bool IsName(void) const;
    const TName& GetName(void) const;
    TName& SetName(void);
    void SetName(const TName& value);

    // typedef COrg_ref TOrg
    bool IsOrg(void) const;
    const TOrg& GetOrg(void) const;
    TOrg& SetOrg(void);
    void SetOrg(TOrg& value);

    // typedef CSequenceOfInt TJoin
    bool IsJoin(void) const;
    const TJoin& GetJoin(void) const;
    TJoin& SetJoin(void);
    void SetJoin(TJoin& value);


private:
    // copy constructor and assignment operator
    CT3Request_Base(const CT3Request_Base& );
    CT3Request_Base& operator=(const CT3Request_Base& );
    // choice state
    E_Choice m_choice;
    // helper methods
    void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);

    static const char* const sm_SelectionNames[];
    // data
    union {
        TTaxid m_Taxid;
        NCBI_NS_NCBI::CUnionBuffer<NCBI_NS_STD::string> m_string;
        NCBI_NS_NCBI::CSerialObject *m_object;
    };
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CT3Request_Base::E_Choice CT3Request_Base::Which(void) const
{
    return m_choice;
}

inline
void CT3Request_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CT3Request_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CT3Request_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CT3Request_Base::IsTaxid(void) const
{
    return m_choice == e_Taxid;
}

inline
CT3Request_Base::TTaxid CT3Request_Base::GetTaxid(void) const
{
    CheckSelected(e_Taxid);
    return m_Taxid;
}

inline
CT3Request_Base::TTaxid& CT3Request_Base::SetTaxid(void)
{
    Select(e_Taxid, NCBI_NS_NCBI::eDoNotResetVariant);
    return m_Taxid;
}

inline
void CT3Request_Base::SetTaxid(CT3Request_Base::TTaxid value)
{
    Select(e_Taxid, NCBI_NS_NCBI::eDoNotResetVariant);
    m_Taxid = value;
}

inline
bool CT3Request_Base::IsName(void) const
{
    return m_choice == e_Name;
}

inline
const CT3Request_Base::TName& CT3Request_Base::GetName(void) const
{
    CheckSelected(e_Name);
    return *m_string;
}

inline
CT3Request_Base::TName& CT3Request_Base::SetName(void)
{
    Select(e_Name, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_string;
}

inline
bool CT3Request_Base::IsOrg(void) const
{
    return m_choice == e_Org;
}

inline
bool CT3Request_Base::IsJoin(void) const
{
    return m_choice == e_Join;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TAXON3_T3REQUEST_BASE_HPP