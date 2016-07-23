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

/// @file GB_block_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqblock.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQBLOCK_GB_BLOCK_BASE_HPP
#define OBJECTS_SEQBLOCK_GB_BLOCK_BASE_HPP

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


// forward declarations
class CDate;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// GenBank specific descriptions
class NCBI_SEQBLOCK_EXPORT CGB_block_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CGB_block_Base(void);
    // destructor
    virtual ~CGB_block_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef list< string > TExtra_accessions;
    typedef string TSource;
    typedef list< string > TKeywords;
    typedef string TOrigin;
    typedef string TDate;
    typedef CDate TEntry_date;
    typedef string TDiv;
    typedef string TTaxonomy;

    // getters
    // setters

    /// optional
    /// typedef list< string > TExtra_accessions
    ///  Check whether the Extra_accessions data member has been assigned a value.
    bool IsSetExtra_accessions(void) const;
    /// Check whether it is safe or not to call GetExtra_accessions method.
    bool CanGetExtra_accessions(void) const;
    void ResetExtra_accessions(void);
    const TExtra_accessions& GetExtra_accessions(void) const;
    TExtra_accessions& SetExtra_accessions(void);

    /// source line
    /// optional
    /// typedef string TSource
    ///  Check whether the Source data member has been assigned a value.
    bool IsSetSource(void) const;
    /// Check whether it is safe or not to call GetSource method.
    bool CanGetSource(void) const;
    void ResetSource(void);
    const TSource& GetSource(void) const;
    void SetSource(const TSource& value);
    TSource& SetSource(void);

    /// optional
    /// typedef list< string > TKeywords
    ///  Check whether the Keywords data member has been assigned a value.
    bool IsSetKeywords(void) const;
    /// Check whether it is safe or not to call GetKeywords method.
    bool CanGetKeywords(void) const;
    void ResetKeywords(void);
    const TKeywords& GetKeywords(void) const;
    TKeywords& SetKeywords(void);

    /// optional
    /// typedef string TOrigin
    ///  Check whether the Origin data member has been assigned a value.
    bool IsSetOrigin(void) const;
    /// Check whether it is safe or not to call GetOrigin method.
    bool CanGetOrigin(void) const;
    void ResetOrigin(void);
    const TOrigin& GetOrigin(void) const;
    void SetOrigin(const TOrigin& value);
    TOrigin& SetOrigin(void);

    /// OBSOLETE old form Entry Date
    /// optional
    /// typedef string TDate
    ///  Check whether the Date data member has been assigned a value.
    bool IsSetDate(void) const;
    /// Check whether it is safe or not to call GetDate method.
    bool CanGetDate(void) const;
    void ResetDate(void);
    const TDate& GetDate(void) const;
    void SetDate(const TDate& value);
    TDate& SetDate(void);

    /// replaces date
    /// optional
    /// typedef CDate TEntry_date
    ///  Check whether the Entry_date data member has been assigned a value.
    bool IsSetEntry_date(void) const;
    /// Check whether it is safe or not to call GetEntry_date method.
    bool CanGetEntry_date(void) const;
    void ResetEntry_date(void);
    const TEntry_date& GetEntry_date(void) const;
    void SetEntry_date(TEntry_date& value);
    TEntry_date& SetEntry_date(void);

    /// GenBank division
    /// optional
    /// typedef string TDiv
    ///  Check whether the Div data member has been assigned a value.
    bool IsSetDiv(void) const;
    /// Check whether it is safe or not to call GetDiv method.
    bool CanGetDiv(void) const;
    void ResetDiv(void);
    const TDiv& GetDiv(void) const;
    void SetDiv(const TDiv& value);
    TDiv& SetDiv(void);

    /// continuation line of organism
    /// optional
    /// typedef string TTaxonomy
    ///  Check whether the Taxonomy data member has been assigned a value.
    bool IsSetTaxonomy(void) const;
    /// Check whether it is safe or not to call GetTaxonomy method.
    bool CanGetTaxonomy(void) const;
    void ResetTaxonomy(void);
    const TTaxonomy& GetTaxonomy(void) const;
    void SetTaxonomy(const TTaxonomy& value);
    TTaxonomy& SetTaxonomy(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CGB_block_Base(const CGB_block_Base&);
    CGB_block_Base& operator=(const CGB_block_Base&);

    // data
    Uint4 m_set_State[1];
    list< string > m_Extra_accessions;
    string m_Source;
    list< string > m_Keywords;
    string m_Origin;
    string m_Date;
    CRef< TEntry_date > m_Entry_date;
    string m_Div;
    string m_Taxonomy;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CGB_block_Base::IsSetExtra_accessions(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CGB_block_Base::CanGetExtra_accessions(void) const
{
    return true;
}

inline
const CGB_block_Base::TExtra_accessions& CGB_block_Base::GetExtra_accessions(void) const
{
    return m_Extra_accessions;
}

inline
CGB_block_Base::TExtra_accessions& CGB_block_Base::SetExtra_accessions(void)
{
    m_set_State[0] |= 0x1;
    return m_Extra_accessions;
}

inline
bool CGB_block_Base::IsSetSource(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CGB_block_Base::CanGetSource(void) const
{
    return IsSetSource();
}

inline
const CGB_block_Base::TSource& CGB_block_Base::GetSource(void) const
{
    if (!CanGetSource()) {
        ThrowUnassigned(1);
    }
    return m_Source;
}

inline
void CGB_block_Base::SetSource(const CGB_block_Base::TSource& value)
{
    m_Source = value;
    m_set_State[0] |= 0xc;
}

inline
CGB_block_Base::TSource& CGB_block_Base::SetSource(void)
{
#ifdef _DEBUG
    if (!IsSetSource()) {
        m_Source = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Source;
}

inline
bool CGB_block_Base::IsSetKeywords(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CGB_block_Base::CanGetKeywords(void) const
{
    return true;
}

inline
const CGB_block_Base::TKeywords& CGB_block_Base::GetKeywords(void) const
{
    return m_Keywords;
}

inline
CGB_block_Base::TKeywords& CGB_block_Base::SetKeywords(void)
{
    m_set_State[0] |= 0x10;
    return m_Keywords;
}

inline
bool CGB_block_Base::IsSetOrigin(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CGB_block_Base::CanGetOrigin(void) const
{
    return IsSetOrigin();
}

inline
const CGB_block_Base::TOrigin& CGB_block_Base::GetOrigin(void) const
{
    if (!CanGetOrigin()) {
        ThrowUnassigned(3);
    }
    return m_Origin;
}

inline
void CGB_block_Base::SetOrigin(const CGB_block_Base::TOrigin& value)
{
    m_Origin = value;
    m_set_State[0] |= 0xc0;
}

inline
CGB_block_Base::TOrigin& CGB_block_Base::SetOrigin(void)
{
#ifdef _DEBUG
    if (!IsSetOrigin()) {
        m_Origin = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Origin;
}

inline
bool CGB_block_Base::IsSetDate(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CGB_block_Base::CanGetDate(void) const
{
    return IsSetDate();
}

inline
const CGB_block_Base::TDate& CGB_block_Base::GetDate(void) const
{
    if (!CanGetDate()) {
        ThrowUnassigned(4);
    }
    return m_Date;
}

inline
void CGB_block_Base::SetDate(const CGB_block_Base::TDate& value)
{
    m_Date = value;
    m_set_State[0] |= 0x300;
}

inline
CGB_block_Base::TDate& CGB_block_Base::SetDate(void)
{
#ifdef _DEBUG
    if (!IsSetDate()) {
        m_Date = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Date;
}

inline
bool CGB_block_Base::IsSetEntry_date(void) const
{
    return m_Entry_date.NotEmpty();
}

inline
bool CGB_block_Base::CanGetEntry_date(void) const
{
    return IsSetEntry_date();
}

inline
const CGB_block_Base::TEntry_date& CGB_block_Base::GetEntry_date(void) const
{
    if (!CanGetEntry_date()) {
        ThrowUnassigned(5);
    }
    return (*m_Entry_date);
}

inline
bool CGB_block_Base::IsSetDiv(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CGB_block_Base::CanGetDiv(void) const
{
    return IsSetDiv();
}

inline
const CGB_block_Base::TDiv& CGB_block_Base::GetDiv(void) const
{
    if (!CanGetDiv()) {
        ThrowUnassigned(6);
    }
    return m_Div;
}

inline
void CGB_block_Base::SetDiv(const CGB_block_Base::TDiv& value)
{
    m_Div = value;
    m_set_State[0] |= 0x3000;
}

inline
CGB_block_Base::TDiv& CGB_block_Base::SetDiv(void)
{
#ifdef _DEBUG
    if (!IsSetDiv()) {
        m_Div = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_Div;
}

inline
bool CGB_block_Base::IsSetTaxonomy(void) const
{
    return ((m_set_State[0] & 0xc000) != 0);
}

inline
bool CGB_block_Base::CanGetTaxonomy(void) const
{
    return IsSetTaxonomy();
}

inline
const CGB_block_Base::TTaxonomy& CGB_block_Base::GetTaxonomy(void) const
{
    if (!CanGetTaxonomy()) {
        ThrowUnassigned(7);
    }
    return m_Taxonomy;
}

inline
void CGB_block_Base::SetTaxonomy(const CGB_block_Base::TTaxonomy& value)
{
    m_Taxonomy = value;
    m_set_State[0] |= 0xc000;
}

inline
CGB_block_Base::TTaxonomy& CGB_block_Base::SetTaxonomy(void)
{
#ifdef _DEBUG
    if (!IsSetTaxonomy()) {
        m_Taxonomy = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4000;
    return m_Taxonomy;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQBLOCK_GB_BLOCK_BASE_HPP