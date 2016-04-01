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

/// @file Taxon2_data_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'taxon1.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_TAXON1_TAXON2_DATA_BASE_HPP
#define OBJECTS_TAXON1_TAXON2_DATA_BASE_HPP

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
class COrg_ref;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_TAXON1_EXPORT CTaxon2_data_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CTaxon2_data_Base(void);
    // destructor
    virtual ~CTaxon2_data_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef COrg_ref TOrg;
    typedef list< string > TBlast_name;
    typedef bool TIs_uncultured;
    typedef bool TIs_species_level;

    // getters
    // setters

    /// Org-ref with Org-name and db filled in
    /// optional
    /// typedef COrg_ref TOrg
    ///  Check whether the Org data member has been assigned a value.
    bool IsSetOrg(void) const;
    /// Check whether it is safe or not to call GetOrg method.
    bool CanGetOrg(void) const;
    void ResetOrg(void);
    const TOrg& GetOrg(void) const;
    void SetOrg(TOrg& value);
    TOrg& SetOrg(void);

    /// inherited blast name
    /// optional
    /// typedef list< string > TBlast_name
    ///  Check whether the Blast_name data member has been assigned a value.
    bool IsSetBlast_name(void) const;
    /// Check whether it is safe or not to call GetBlast_name method.
    bool CanGetBlast_name(void) const;
    void ResetBlast_name(void);
    const TBlast_name& GetBlast_name(void) const;
    TBlast_name& SetBlast_name(void);

    /// belongs to environmental bin
    /// mandatory
    /// typedef bool TIs_uncultured
    ///  Check whether the Is_uncultured data member has been assigned a value.
    bool IsSetIs_uncultured(void) const;
    /// Check whether it is safe or not to call GetIs_uncultured method.
    bool CanGetIs_uncultured(void) const;
    void ResetIs_uncultured(void);
    TIs_uncultured GetIs_uncultured(void) const;
    void SetIs_uncultured(TIs_uncultured value);
    TIs_uncultured& SetIs_uncultured(void);

    /// species level or below
    /// mandatory
    /// typedef bool TIs_species_level
    ///  Check whether the Is_species_level data member has been assigned a value.
    bool IsSetIs_species_level(void) const;
    /// Check whether it is safe or not to call GetIs_species_level method.
    bool CanGetIs_species_level(void) const;
    void ResetIs_species_level(void);
    TIs_species_level GetIs_species_level(void) const;
    void SetIs_species_level(TIs_species_level value);
    TIs_species_level& SetIs_species_level(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CTaxon2_data_Base(const CTaxon2_data_Base&);
    CTaxon2_data_Base& operator=(const CTaxon2_data_Base&);

    // data
    Uint4 m_set_State[1];
    CRef< TOrg > m_Org;
    list< string > m_Blast_name;
    bool m_Is_uncultured;
    bool m_Is_species_level;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CTaxon2_data_Base::IsSetOrg(void) const
{
    return m_Org.NotEmpty();
}

inline
bool CTaxon2_data_Base::CanGetOrg(void) const
{
    return IsSetOrg();
}

inline
const CTaxon2_data_Base::TOrg& CTaxon2_data_Base::GetOrg(void) const
{
    if (!CanGetOrg()) {
        ThrowUnassigned(0);
    }
    return (*m_Org);
}

inline
bool CTaxon2_data_Base::IsSetBlast_name(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CTaxon2_data_Base::CanGetBlast_name(void) const
{
    return true;
}

inline
const CTaxon2_data_Base::TBlast_name& CTaxon2_data_Base::GetBlast_name(void) const
{
    return m_Blast_name;
}

inline
CTaxon2_data_Base::TBlast_name& CTaxon2_data_Base::SetBlast_name(void)
{
    m_set_State[0] |= 0x4;
    return m_Blast_name;
}

inline
bool CTaxon2_data_Base::IsSetIs_uncultured(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CTaxon2_data_Base::CanGetIs_uncultured(void) const
{
    return IsSetIs_uncultured();
}

inline
void CTaxon2_data_Base::ResetIs_uncultured(void)
{
    m_Is_uncultured = 0;
    m_set_State[0] &= ~0x30;
}

inline
CTaxon2_data_Base::TIs_uncultured CTaxon2_data_Base::GetIs_uncultured(void) const
{
    if (!CanGetIs_uncultured()) {
        ThrowUnassigned(2);
    }
    return m_Is_uncultured;
}

inline
void CTaxon2_data_Base::SetIs_uncultured(CTaxon2_data_Base::TIs_uncultured value)
{
    m_Is_uncultured = value;
    m_set_State[0] |= 0x30;
}

inline
CTaxon2_data_Base::TIs_uncultured& CTaxon2_data_Base::SetIs_uncultured(void)
{
#ifdef _DEBUG
    if (!IsSetIs_uncultured()) {
        memset(&m_Is_uncultured,UnassignedByte(),sizeof(m_Is_uncultured));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Is_uncultured;
}

inline
bool CTaxon2_data_Base::IsSetIs_species_level(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CTaxon2_data_Base::CanGetIs_species_level(void) const
{
    return IsSetIs_species_level();
}

inline
void CTaxon2_data_Base::ResetIs_species_level(void)
{
    m_Is_species_level = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CTaxon2_data_Base::TIs_species_level CTaxon2_data_Base::GetIs_species_level(void) const
{
    if (!CanGetIs_species_level()) {
        ThrowUnassigned(3);
    }
    return m_Is_species_level;
}

inline
void CTaxon2_data_Base::SetIs_species_level(CTaxon2_data_Base::TIs_species_level value)
{
    m_Is_species_level = value;
    m_set_State[0] |= 0xc0;
}

inline
CTaxon2_data_Base::TIs_species_level& CTaxon2_data_Base::SetIs_species_level(void)
{
#ifdef _DEBUG
    if (!IsSetIs_species_level()) {
        memset(&m_Is_species_level,UnassignedByte(),sizeof(m_Is_species_level));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Is_species_level;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_TAXON1_TAXON2_DATA_BASE_HPP
