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

/// @file Convert_from_CDS_options_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_CONVERT_FROM_CDS_OPTIONS_BASE_HPP
#define OBJECTS_MACRO_CONVERT_FROM_CDS_OPTIONS_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// for convert features 
class CConvert_from_CDS_options_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CConvert_from_CDS_options_Base(void);
    // destructor
    virtual ~CConvert_from_CDS_options_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef bool TRemove_mRNA;
    typedef bool TRemove_gene;
    typedef bool TRemove_transcript_id;

    // getters
    // setters

    /// mandatory
    /// typedef bool TRemove_mRNA
    ///  Check whether the Remove_mRNA data member has been assigned a value.
    bool IsSetRemove_mRNA(void) const;
    /// Check whether it is safe or not to call GetRemove_mRNA method.
    bool CanGetRemove_mRNA(void) const;
    void ResetRemove_mRNA(void);
    TRemove_mRNA GetRemove_mRNA(void) const;
    void SetRemove_mRNA(TRemove_mRNA value);
    TRemove_mRNA& SetRemove_mRNA(void);

    /// mandatory
    /// typedef bool TRemove_gene
    ///  Check whether the Remove_gene data member has been assigned a value.
    bool IsSetRemove_gene(void) const;
    /// Check whether it is safe or not to call GetRemove_gene method.
    bool CanGetRemove_gene(void) const;
    void ResetRemove_gene(void);
    TRemove_gene GetRemove_gene(void) const;
    void SetRemove_gene(TRemove_gene value);
    TRemove_gene& SetRemove_gene(void);

    /// mandatory
    /// typedef bool TRemove_transcript_id
    ///  Check whether the Remove_transcript_id data member has been assigned a value.
    bool IsSetRemove_transcript_id(void) const;
    /// Check whether it is safe or not to call GetRemove_transcript_id method.
    bool CanGetRemove_transcript_id(void) const;
    void ResetRemove_transcript_id(void);
    TRemove_transcript_id GetRemove_transcript_id(void) const;
    void SetRemove_transcript_id(TRemove_transcript_id value);
    TRemove_transcript_id& SetRemove_transcript_id(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CConvert_from_CDS_options_Base(const CConvert_from_CDS_options_Base&);
    CConvert_from_CDS_options_Base& operator=(const CConvert_from_CDS_options_Base&);

    // data
    Uint4 m_set_State[1];
    bool m_Remove_mRNA;
    bool m_Remove_gene;
    bool m_Remove_transcript_id;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CConvert_from_CDS_options_Base::IsSetRemove_mRNA(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CConvert_from_CDS_options_Base::CanGetRemove_mRNA(void) const
{
    return IsSetRemove_mRNA();
}

inline
void CConvert_from_CDS_options_Base::ResetRemove_mRNA(void)
{
    m_Remove_mRNA = 0;
    m_set_State[0] &= ~0x3;
}

inline
CConvert_from_CDS_options_Base::TRemove_mRNA CConvert_from_CDS_options_Base::GetRemove_mRNA(void) const
{
    if (!CanGetRemove_mRNA()) {
        ThrowUnassigned(0);
    }
    return m_Remove_mRNA;
}

inline
void CConvert_from_CDS_options_Base::SetRemove_mRNA(CConvert_from_CDS_options_Base::TRemove_mRNA value)
{
    m_Remove_mRNA = value;
    m_set_State[0] |= 0x3;
}

inline
CConvert_from_CDS_options_Base::TRemove_mRNA& CConvert_from_CDS_options_Base::SetRemove_mRNA(void)
{
#ifdef _DEBUG
    if (!IsSetRemove_mRNA()) {
        memset(&m_Remove_mRNA,UnassignedByte(),sizeof(m_Remove_mRNA));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Remove_mRNA;
}

inline
bool CConvert_from_CDS_options_Base::IsSetRemove_gene(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CConvert_from_CDS_options_Base::CanGetRemove_gene(void) const
{
    return IsSetRemove_gene();
}

inline
void CConvert_from_CDS_options_Base::ResetRemove_gene(void)
{
    m_Remove_gene = 0;
    m_set_State[0] &= ~0xc;
}

inline
CConvert_from_CDS_options_Base::TRemove_gene CConvert_from_CDS_options_Base::GetRemove_gene(void) const
{
    if (!CanGetRemove_gene()) {
        ThrowUnassigned(1);
    }
    return m_Remove_gene;
}

inline
void CConvert_from_CDS_options_Base::SetRemove_gene(CConvert_from_CDS_options_Base::TRemove_gene value)
{
    m_Remove_gene = value;
    m_set_State[0] |= 0xc;
}

inline
CConvert_from_CDS_options_Base::TRemove_gene& CConvert_from_CDS_options_Base::SetRemove_gene(void)
{
#ifdef _DEBUG
    if (!IsSetRemove_gene()) {
        memset(&m_Remove_gene,UnassignedByte(),sizeof(m_Remove_gene));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Remove_gene;
}

inline
bool CConvert_from_CDS_options_Base::IsSetRemove_transcript_id(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CConvert_from_CDS_options_Base::CanGetRemove_transcript_id(void) const
{
    return IsSetRemove_transcript_id();
}

inline
void CConvert_from_CDS_options_Base::ResetRemove_transcript_id(void)
{
    m_Remove_transcript_id = 0;
    m_set_State[0] &= ~0x30;
}

inline
CConvert_from_CDS_options_Base::TRemove_transcript_id CConvert_from_CDS_options_Base::GetRemove_transcript_id(void) const
{
    if (!CanGetRemove_transcript_id()) {
        ThrowUnassigned(2);
    }
    return m_Remove_transcript_id;
}

inline
void CConvert_from_CDS_options_Base::SetRemove_transcript_id(CConvert_from_CDS_options_Base::TRemove_transcript_id value)
{
    m_Remove_transcript_id = value;
    m_set_State[0] |= 0x30;
}

inline
CConvert_from_CDS_options_Base::TRemove_transcript_id& CConvert_from_CDS_options_Base::SetRemove_transcript_id(void)
{
#ifdef _DEBUG
    if (!IsSetRemove_transcript_id()) {
        memset(&m_Remove_transcript_id,UnassignedByte(),sizeof(m_Remove_transcript_id));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Remove_transcript_id;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_CONVERT_FROM_CDS_OPTIONS_BASE_HPP