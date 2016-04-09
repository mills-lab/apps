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

/// @file HG_Gene_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'homologene.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_HOMOLOGENE_HG_GENE_BASE_HPP
#define OBJECTS_HOMOLOGENE_HG_GENE_BASE_HPP

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
class CHG_Domain;
class CHG_Link;
class CSeq_loc;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class CHG_Gene_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CHG_Gene_Base(void);
    // destructor
    virtual ~CHG_Gene_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef int TGeneid;
    typedef int TOtherid;
    typedef string TSymbol;
    typedef list< string > TAliases;
    typedef string TTitle;
    typedef int TTaxid;
    typedef int TProt_gi;
    typedef string TProt_acc;
    typedef int TProt_len;
    typedef int TNuc_gi;
    typedef string TNuc_acc;
    typedef list< CRef< CHG_Link > > TGene_links;
    typedef list< CRef< CHG_Link > > TProt_links;
    typedef list< CRef< CHG_Domain > > TDomains;
    typedef string TChr;
    typedef CSeq_loc TLocation;
    typedef string TLocus_tag;

    // getters
    // setters

    /// mandatory
    /// typedef int TGeneid
    ///  Check whether the Geneid data member has been assigned a value.
    bool IsSetGeneid(void) const;
    /// Check whether it is safe or not to call GetGeneid method.
    bool CanGetGeneid(void) const;
    void ResetGeneid(void);
    TGeneid GetGeneid(void) const;
    void SetGeneid(TGeneid value);
    TGeneid& SetGeneid(void);

    /// internal use only!!!!!
    /// optional
    /// typedef int TOtherid
    ///  Check whether the Otherid data member has been assigned a value.
    bool IsSetOtherid(void) const;
    /// Check whether it is safe or not to call GetOtherid method.
    bool CanGetOtherid(void) const;
    void ResetOtherid(void);
    TOtherid GetOtherid(void) const;
    void SetOtherid(TOtherid value);
    TOtherid& SetOtherid(void);

    /// optional
    /// typedef string TSymbol
    ///  Check whether the Symbol data member has been assigned a value.
    bool IsSetSymbol(void) const;
    /// Check whether it is safe or not to call GetSymbol method.
    bool CanGetSymbol(void) const;
    void ResetSymbol(void);
    const TSymbol& GetSymbol(void) const;
    void SetSymbol(const TSymbol& value);
    TSymbol& SetSymbol(void);

    /// optional
    /// typedef list< string > TAliases
    ///  Check whether the Aliases data member has been assigned a value.
    bool IsSetAliases(void) const;
    /// Check whether it is safe or not to call GetAliases method.
    bool CanGetAliases(void) const;
    void ResetAliases(void);
    const TAliases& GetAliases(void) const;
    TAliases& SetAliases(void);

    /// mandatory
    /// typedef string TTitle
    ///  Check whether the Title data member has been assigned a value.
    bool IsSetTitle(void) const;
    /// Check whether it is safe or not to call GetTitle method.
    bool CanGetTitle(void) const;
    void ResetTitle(void);
    const TTitle& GetTitle(void) const;
    void SetTitle(const TTitle& value);
    TTitle& SetTitle(void);

    ///taxid of gene node
    /// mandatory
    /// typedef int TTaxid
    ///  Check whether the Taxid data member has been assigned a value.
    bool IsSetTaxid(void) const;
    /// Check whether it is safe or not to call GetTaxid method.
    bool CanGetTaxid(void) const;
    void ResetTaxid(void);
    TTaxid GetTaxid(void) const;
    void SetTaxid(TTaxid value);
    TTaxid& SetTaxid(void);

    /// optional
    /// typedef int TProt_gi
    ///  Check whether the Prot_gi data member has been assigned a value.
    bool IsSetProt_gi(void) const;
    /// Check whether it is safe or not to call GetProt_gi method.
    bool CanGetProt_gi(void) const;
    void ResetProt_gi(void);
    TProt_gi GetProt_gi(void) const;
    void SetProt_gi(TProt_gi value);
    TProt_gi& SetProt_gi(void);

    /// optional
    /// typedef string TProt_acc
    ///  Check whether the Prot_acc data member has been assigned a value.
    bool IsSetProt_acc(void) const;
    /// Check whether it is safe or not to call GetProt_acc method.
    bool CanGetProt_acc(void) const;
    void ResetProt_acc(void);
    const TProt_acc& GetProt_acc(void) const;
    void SetProt_acc(const TProt_acc& value);
    TProt_acc& SetProt_acc(void);

    /// optional
    /// typedef int TProt_len
    ///  Check whether the Prot_len data member has been assigned a value.
    bool IsSetProt_len(void) const;
    /// Check whether it is safe or not to call GetProt_len method.
    bool CanGetProt_len(void) const;
    void ResetProt_len(void);
    TProt_len GetProt_len(void) const;
    void SetProt_len(TProt_len value);
    TProt_len& SetProt_len(void);

    /// optional
    /// typedef int TNuc_gi
    ///  Check whether the Nuc_gi data member has been assigned a value.
    bool IsSetNuc_gi(void) const;
    /// Check whether it is safe or not to call GetNuc_gi method.
    bool CanGetNuc_gi(void) const;
    void ResetNuc_gi(void);
    TNuc_gi GetNuc_gi(void) const;
    void SetNuc_gi(TNuc_gi value);
    TNuc_gi& SetNuc_gi(void);

    /// optional
    /// typedef string TNuc_acc
    ///  Check whether the Nuc_acc data member has been assigned a value.
    bool IsSetNuc_acc(void) const;
    /// Check whether it is safe or not to call GetNuc_acc method.
    bool CanGetNuc_acc(void) const;
    void ResetNuc_acc(void);
    const TNuc_acc& GetNuc_acc(void) const;
    void SetNuc_acc(const TNuc_acc& value);
    TNuc_acc& SetNuc_acc(void);

    /// optional
    /// typedef list< CRef< CHG_Link > > TGene_links
    ///  Check whether the Gene_links data member has been assigned a value.
    bool IsSetGene_links(void) const;
    /// Check whether it is safe or not to call GetGene_links method.
    bool CanGetGene_links(void) const;
    void ResetGene_links(void);
    const TGene_links& GetGene_links(void) const;
    TGene_links& SetGene_links(void);

    /// optional
    /// typedef list< CRef< CHG_Link > > TProt_links
    ///  Check whether the Prot_links data member has been assigned a value.
    bool IsSetProt_links(void) const;
    /// Check whether it is safe or not to call GetProt_links method.
    bool CanGetProt_links(void) const;
    void ResetProt_links(void);
    const TProt_links& GetProt_links(void) const;
    TProt_links& SetProt_links(void);

    /// optional
    /// typedef list< CRef< CHG_Domain > > TDomains
    ///  Check whether the Domains data member has been assigned a value.
    bool IsSetDomains(void) const;
    /// Check whether it is safe or not to call GetDomains method.
    bool CanGetDomains(void) const;
    void ResetDomains(void);
    const TDomains& GetDomains(void) const;
    TDomains& SetDomains(void);

    /// optional
    /// typedef string TChr
    ///  Check whether the Chr data member has been assigned a value.
    bool IsSetChr(void) const;
    /// Check whether it is safe or not to call GetChr method.
    bool CanGetChr(void) const;
    void ResetChr(void);
    const TChr& GetChr(void) const;
    void SetChr(const TChr& value);
    TChr& SetChr(void);

    /// location on the genome
    /// optional
    /// typedef CSeq_loc TLocation
    ///  Check whether the Location data member has been assigned a value.
    bool IsSetLocation(void) const;
    /// Check whether it is safe or not to call GetLocation method.
    bool CanGetLocation(void) const;
    void ResetLocation(void);
    const TLocation& GetLocation(void) const;
    void SetLocation(TLocation& value);
    TLocation& SetLocation(void);

    /// optional
    /// typedef string TLocus_tag
    ///  Check whether the Locus_tag data member has been assigned a value.
    bool IsSetLocus_tag(void) const;
    /// Check whether it is safe or not to call GetLocus_tag method.
    bool CanGetLocus_tag(void) const;
    void ResetLocus_tag(void);
    const TLocus_tag& GetLocus_tag(void) const;
    void SetLocus_tag(const TLocus_tag& value);
    TLocus_tag& SetLocus_tag(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CHG_Gene_Base(const CHG_Gene_Base&);
    CHG_Gene_Base& operator=(const CHG_Gene_Base&);

    // data
    Uint4 m_set_State[2];
    int m_Geneid;
    int m_Otherid;
    string m_Symbol;
    list< string > m_Aliases;
    string m_Title;
    int m_Taxid;
    int m_Prot_gi;
    string m_Prot_acc;
    int m_Prot_len;
    int m_Nuc_gi;
    string m_Nuc_acc;
    list< CRef< CHG_Link > > m_Gene_links;
    list< CRef< CHG_Link > > m_Prot_links;
    list< CRef< CHG_Domain > > m_Domains;
    string m_Chr;
    CRef< TLocation > m_Location;
    string m_Locus_tag;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CHG_Gene_Base::IsSetGeneid(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CHG_Gene_Base::CanGetGeneid(void) const
{
    return IsSetGeneid();
}

inline
void CHG_Gene_Base::ResetGeneid(void)
{
    m_Geneid = 0;
    m_set_State[0] &= ~0x3;
}

inline
CHG_Gene_Base::TGeneid CHG_Gene_Base::GetGeneid(void) const
{
    if (!CanGetGeneid()) {
        ThrowUnassigned(0);
    }
    return m_Geneid;
}

inline
void CHG_Gene_Base::SetGeneid(CHG_Gene_Base::TGeneid value)
{
    m_Geneid = value;
    m_set_State[0] |= 0x3;
}

inline
CHG_Gene_Base::TGeneid& CHG_Gene_Base::SetGeneid(void)
{
#ifdef _DEBUG
    if (!IsSetGeneid()) {
        memset(&m_Geneid,UnassignedByte(),sizeof(m_Geneid));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Geneid;
}

inline
bool CHG_Gene_Base::IsSetOtherid(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CHG_Gene_Base::CanGetOtherid(void) const
{
    return IsSetOtherid();
}

inline
void CHG_Gene_Base::ResetOtherid(void)
{
    m_Otherid = 0;
    m_set_State[0] &= ~0xc;
}

inline
CHG_Gene_Base::TOtherid CHG_Gene_Base::GetOtherid(void) const
{
    if (!CanGetOtherid()) {
        ThrowUnassigned(1);
    }
    return m_Otherid;
}

inline
void CHG_Gene_Base::SetOtherid(CHG_Gene_Base::TOtherid value)
{
    m_Otherid = value;
    m_set_State[0] |= 0xc;
}

inline
CHG_Gene_Base::TOtherid& CHG_Gene_Base::SetOtherid(void)
{
#ifdef _DEBUG
    if (!IsSetOtherid()) {
        memset(&m_Otherid,UnassignedByte(),sizeof(m_Otherid));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Otherid;
}

inline
bool CHG_Gene_Base::IsSetSymbol(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CHG_Gene_Base::CanGetSymbol(void) const
{
    return IsSetSymbol();
}

inline
const CHG_Gene_Base::TSymbol& CHG_Gene_Base::GetSymbol(void) const
{
    if (!CanGetSymbol()) {
        ThrowUnassigned(2);
    }
    return m_Symbol;
}

inline
void CHG_Gene_Base::SetSymbol(const CHG_Gene_Base::TSymbol& value)
{
    m_Symbol = value;
    m_set_State[0] |= 0x30;
}

inline
CHG_Gene_Base::TSymbol& CHG_Gene_Base::SetSymbol(void)
{
#ifdef _DEBUG
    if (!IsSetSymbol()) {
        m_Symbol = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Symbol;
}

inline
bool CHG_Gene_Base::IsSetAliases(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CHG_Gene_Base::CanGetAliases(void) const
{
    return true;
}

inline
const CHG_Gene_Base::TAliases& CHG_Gene_Base::GetAliases(void) const
{
    return m_Aliases;
}

inline
CHG_Gene_Base::TAliases& CHG_Gene_Base::SetAliases(void)
{
    m_set_State[0] |= 0x40;
    return m_Aliases;
}

inline
bool CHG_Gene_Base::IsSetTitle(void) const
{
    return ((m_set_State[0] & 0x300) != 0);
}

inline
bool CHG_Gene_Base::CanGetTitle(void) const
{
    return IsSetTitle();
}

inline
const CHG_Gene_Base::TTitle& CHG_Gene_Base::GetTitle(void) const
{
    if (!CanGetTitle()) {
        ThrowUnassigned(4);
    }
    return m_Title;
}

inline
void CHG_Gene_Base::SetTitle(const CHG_Gene_Base::TTitle& value)
{
    m_Title = value;
    m_set_State[0] |= 0x300;
}

inline
CHG_Gene_Base::TTitle& CHG_Gene_Base::SetTitle(void)
{
#ifdef _DEBUG
    if (!IsSetTitle()) {
        m_Title = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100;
    return m_Title;
}

inline
bool CHG_Gene_Base::IsSetTaxid(void) const
{
    return ((m_set_State[0] & 0xc00) != 0);
}

inline
bool CHG_Gene_Base::CanGetTaxid(void) const
{
    return IsSetTaxid();
}

inline
void CHG_Gene_Base::ResetTaxid(void)
{
    m_Taxid = 0;
    m_set_State[0] &= ~0xc00;
}

inline
CHG_Gene_Base::TTaxid CHG_Gene_Base::GetTaxid(void) const
{
    if (!CanGetTaxid()) {
        ThrowUnassigned(5);
    }
    return m_Taxid;
}

inline
void CHG_Gene_Base::SetTaxid(CHG_Gene_Base::TTaxid value)
{
    m_Taxid = value;
    m_set_State[0] |= 0xc00;
}

inline
CHG_Gene_Base::TTaxid& CHG_Gene_Base::SetTaxid(void)
{
#ifdef _DEBUG
    if (!IsSetTaxid()) {
        memset(&m_Taxid,UnassignedByte(),sizeof(m_Taxid));
    }
#endif
    m_set_State[0] |= 0x400;
    return m_Taxid;
}

inline
bool CHG_Gene_Base::IsSetProt_gi(void) const
{
    return ((m_set_State[0] & 0x3000) != 0);
}

inline
bool CHG_Gene_Base::CanGetProt_gi(void) const
{
    return IsSetProt_gi();
}

inline
void CHG_Gene_Base::ResetProt_gi(void)
{
    m_Prot_gi = 0;
    m_set_State[0] &= ~0x3000;
}

inline
CHG_Gene_Base::TProt_gi CHG_Gene_Base::GetProt_gi(void) const
{
    if (!CanGetProt_gi()) {
        ThrowUnassigned(6);
    }
    return m_Prot_gi;
}

inline
void CHG_Gene_Base::SetProt_gi(CHG_Gene_Base::TProt_gi value)
{
    m_Prot_gi = value;
    m_set_State[0] |= 0x3000;
}

inline
CHG_Gene_Base::TProt_gi& CHG_Gene_Base::SetProt_gi(void)
{
#ifdef _DEBUG
    if (!IsSetProt_gi()) {
        memset(&m_Prot_gi,UnassignedByte(),sizeof(m_Prot_gi));
    }
#endif
    m_set_State[0] |= 0x1000;
    return m_Prot_gi;
}

inline
bool CHG_Gene_Base::IsSetProt_acc(void) const
{
    return ((m_set_State[0] & 0xc000) != 0);
}

inline
bool CHG_Gene_Base::CanGetProt_acc(void) const
{
    return IsSetProt_acc();
}

inline
const CHG_Gene_Base::TProt_acc& CHG_Gene_Base::GetProt_acc(void) const
{
    if (!CanGetProt_acc()) {
        ThrowUnassigned(7);
    }
    return m_Prot_acc;
}

inline
void CHG_Gene_Base::SetProt_acc(const CHG_Gene_Base::TProt_acc& value)
{
    m_Prot_acc = value;
    m_set_State[0] |= 0xc000;
}

inline
CHG_Gene_Base::TProt_acc& CHG_Gene_Base::SetProt_acc(void)
{
#ifdef _DEBUG
    if (!IsSetProt_acc()) {
        m_Prot_acc = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x4000;
    return m_Prot_acc;
}

inline
bool CHG_Gene_Base::IsSetProt_len(void) const
{
    return ((m_set_State[0] & 0x30000) != 0);
}

inline
bool CHG_Gene_Base::CanGetProt_len(void) const
{
    return IsSetProt_len();
}

inline
void CHG_Gene_Base::ResetProt_len(void)
{
    m_Prot_len = 0;
    m_set_State[0] &= ~0x30000;
}

inline
CHG_Gene_Base::TProt_len CHG_Gene_Base::GetProt_len(void) const
{
    if (!CanGetProt_len()) {
        ThrowUnassigned(8);
    }
    return m_Prot_len;
}

inline
void CHG_Gene_Base::SetProt_len(CHG_Gene_Base::TProt_len value)
{
    m_Prot_len = value;
    m_set_State[0] |= 0x30000;
}

inline
CHG_Gene_Base::TProt_len& CHG_Gene_Base::SetProt_len(void)
{
#ifdef _DEBUG
    if (!IsSetProt_len()) {
        memset(&m_Prot_len,UnassignedByte(),sizeof(m_Prot_len));
    }
#endif
    m_set_State[0] |= 0x10000;
    return m_Prot_len;
}

inline
bool CHG_Gene_Base::IsSetNuc_gi(void) const
{
    return ((m_set_State[0] & 0xc0000) != 0);
}

inline
bool CHG_Gene_Base::CanGetNuc_gi(void) const
{
    return IsSetNuc_gi();
}

inline
void CHG_Gene_Base::ResetNuc_gi(void)
{
    m_Nuc_gi = 0;
    m_set_State[0] &= ~0xc0000;
}

inline
CHG_Gene_Base::TNuc_gi CHG_Gene_Base::GetNuc_gi(void) const
{
    if (!CanGetNuc_gi()) {
        ThrowUnassigned(9);
    }
    return m_Nuc_gi;
}

inline
void CHG_Gene_Base::SetNuc_gi(CHG_Gene_Base::TNuc_gi value)
{
    m_Nuc_gi = value;
    m_set_State[0] |= 0xc0000;
}

inline
CHG_Gene_Base::TNuc_gi& CHG_Gene_Base::SetNuc_gi(void)
{
#ifdef _DEBUG
    if (!IsSetNuc_gi()) {
        memset(&m_Nuc_gi,UnassignedByte(),sizeof(m_Nuc_gi));
    }
#endif
    m_set_State[0] |= 0x40000;
    return m_Nuc_gi;
}

inline
bool CHG_Gene_Base::IsSetNuc_acc(void) const
{
    return ((m_set_State[0] & 0x300000) != 0);
}

inline
bool CHG_Gene_Base::CanGetNuc_acc(void) const
{
    return IsSetNuc_acc();
}

inline
const CHG_Gene_Base::TNuc_acc& CHG_Gene_Base::GetNuc_acc(void) const
{
    if (!CanGetNuc_acc()) {
        ThrowUnassigned(10);
    }
    return m_Nuc_acc;
}

inline
void CHG_Gene_Base::SetNuc_acc(const CHG_Gene_Base::TNuc_acc& value)
{
    m_Nuc_acc = value;
    m_set_State[0] |= 0x300000;
}

inline
CHG_Gene_Base::TNuc_acc& CHG_Gene_Base::SetNuc_acc(void)
{
#ifdef _DEBUG
    if (!IsSetNuc_acc()) {
        m_Nuc_acc = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x100000;
    return m_Nuc_acc;
}

inline
bool CHG_Gene_Base::IsSetGene_links(void) const
{
    return ((m_set_State[0] & 0xc00000) != 0);
}

inline
bool CHG_Gene_Base::CanGetGene_links(void) const
{
    return true;
}

inline
const CHG_Gene_Base::TGene_links& CHG_Gene_Base::GetGene_links(void) const
{
    return m_Gene_links;
}

inline
CHG_Gene_Base::TGene_links& CHG_Gene_Base::SetGene_links(void)
{
    m_set_State[0] |= 0x400000;
    return m_Gene_links;
}

inline
bool CHG_Gene_Base::IsSetProt_links(void) const
{
    return ((m_set_State[0] & 0x3000000) != 0);
}

inline
bool CHG_Gene_Base::CanGetProt_links(void) const
{
    return true;
}

inline
const CHG_Gene_Base::TProt_links& CHG_Gene_Base::GetProt_links(void) const
{
    return m_Prot_links;
}

inline
CHG_Gene_Base::TProt_links& CHG_Gene_Base::SetProt_links(void)
{
    m_set_State[0] |= 0x1000000;
    return m_Prot_links;
}

inline
bool CHG_Gene_Base::IsSetDomains(void) const
{
    return ((m_set_State[0] & 0xc000000) != 0);
}

inline
bool CHG_Gene_Base::CanGetDomains(void) const
{
    return true;
}

inline
const CHG_Gene_Base::TDomains& CHG_Gene_Base::GetDomains(void) const
{
    return m_Domains;
}

inline
CHG_Gene_Base::TDomains& CHG_Gene_Base::SetDomains(void)
{
    m_set_State[0] |= 0x4000000;
    return m_Domains;
}

inline
bool CHG_Gene_Base::IsSetChr(void) const
{
    return ((m_set_State[0] & 0x30000000) != 0);
}

inline
bool CHG_Gene_Base::CanGetChr(void) const
{
    return IsSetChr();
}

inline
const CHG_Gene_Base::TChr& CHG_Gene_Base::GetChr(void) const
{
    if (!CanGetChr()) {
        ThrowUnassigned(14);
    }
    return m_Chr;
}

inline
void CHG_Gene_Base::SetChr(const CHG_Gene_Base::TChr& value)
{
    m_Chr = value;
    m_set_State[0] |= 0x30000000;
}

inline
CHG_Gene_Base::TChr& CHG_Gene_Base::SetChr(void)
{
#ifdef _DEBUG
    if (!IsSetChr()) {
        m_Chr = UnassignedString();
    }
#endif
    m_set_State[0] |= 0x10000000;
    return m_Chr;
}

inline
bool CHG_Gene_Base::IsSetLocation(void) const
{
    return m_Location.NotEmpty();
}

inline
bool CHG_Gene_Base::CanGetLocation(void) const
{
    return IsSetLocation();
}

inline
const CHG_Gene_Base::TLocation& CHG_Gene_Base::GetLocation(void) const
{
    if (!CanGetLocation()) {
        ThrowUnassigned(15);
    }
    return (*m_Location);
}

inline
bool CHG_Gene_Base::IsSetLocus_tag(void) const
{
    return ((m_set_State[1] & 0x3) != 0);
}

inline
bool CHG_Gene_Base::CanGetLocus_tag(void) const
{
    return IsSetLocus_tag();
}

inline
const CHG_Gene_Base::TLocus_tag& CHG_Gene_Base::GetLocus_tag(void) const
{
    if (!CanGetLocus_tag()) {
        ThrowUnassigned(16);
    }
    return m_Locus_tag;
}

inline
void CHG_Gene_Base::SetLocus_tag(const CHG_Gene_Base::TLocus_tag& value)
{
    m_Locus_tag = value;
    m_set_State[1] |= 0x3;
}

inline
CHG_Gene_Base::TLocus_tag& CHG_Gene_Base::SetLocus_tag(void)
{
#ifdef _DEBUG
    if (!IsSetLocus_tag()) {
        m_Locus_tag = UnassignedString();
    }
#endif
    m_set_State[1] |= 0x1;
    return m_Locus_tag;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_HOMOLOGENE_HG_GENE_BASE_HPP