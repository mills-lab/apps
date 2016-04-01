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

/// @file ID2S_Bioseq_place_Info_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqsplit.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQSPLIT_ID2S_BIOSEQ_PLACE_INFO_BASE_HPP
#define OBJECTS_SEQSPLIT_ID2S_BIOSEQ_PLACE_INFO_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CID2S_Bioseq_Ids;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_ID2_EXPORT CID2S_Bioseq_place_Info_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CID2S_Bioseq_place_Info_Base(void);
    // destructor
    virtual ~CID2S_Bioseq_place_Info_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef int TBioseq_set;
    typedef CID2S_Bioseq_Ids TSeq_ids;

    // getters
    // setters

    /// mandatory
    /// typedef int TBioseq_set
    ///  Check whether the Bioseq_set data member has been assigned a value.
    bool IsSetBioseq_set(void) const;
    /// Check whether it is safe or not to call GetBioseq_set method.
    bool CanGetBioseq_set(void) const;
    void ResetBioseq_set(void);
    TBioseq_set GetBioseq_set(void) const;
    void SetBioseq_set(TBioseq_set value);
    TBioseq_set& SetBioseq_set(void);

    /// mandatory
    /// typedef CID2S_Bioseq_Ids TSeq_ids
    ///  Check whether the Seq_ids data member has been assigned a value.
    bool IsSetSeq_ids(void) const;
    /// Check whether it is safe or not to call GetSeq_ids method.
    bool CanGetSeq_ids(void) const;
    void ResetSeq_ids(void);
    const TSeq_ids& GetSeq_ids(void) const;
    void SetSeq_ids(TSeq_ids& value);
    TSeq_ids& SetSeq_ids(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CID2S_Bioseq_place_Info_Base(const CID2S_Bioseq_place_Info_Base&);
    CID2S_Bioseq_place_Info_Base& operator=(const CID2S_Bioseq_place_Info_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Bioseq_set;
    CRef< TSeq_ids > m_Seq_ids;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CID2S_Bioseq_place_Info_Base::IsSetBioseq_set(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CID2S_Bioseq_place_Info_Base::CanGetBioseq_set(void) const
{
    return IsSetBioseq_set();
}

inline
void CID2S_Bioseq_place_Info_Base::ResetBioseq_set(void)
{
    m_Bioseq_set = 0;
    m_set_State[0] &= ~0x3;
}

inline
CID2S_Bioseq_place_Info_Base::TBioseq_set CID2S_Bioseq_place_Info_Base::GetBioseq_set(void) const
{
    if (!CanGetBioseq_set()) {
        ThrowUnassigned(0);
    }
    return m_Bioseq_set;
}

inline
void CID2S_Bioseq_place_Info_Base::SetBioseq_set(CID2S_Bioseq_place_Info_Base::TBioseq_set value)
{
    m_Bioseq_set = value;
    m_set_State[0] |= 0x3;
}

inline
CID2S_Bioseq_place_Info_Base::TBioseq_set& CID2S_Bioseq_place_Info_Base::SetBioseq_set(void)
{
#ifdef _DEBUG
    if (!IsSetBioseq_set()) {
        memset(&m_Bioseq_set,UnassignedByte(),sizeof(m_Bioseq_set));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Bioseq_set;
}

inline
bool CID2S_Bioseq_place_Info_Base::IsSetSeq_ids(void) const
{
    return m_Seq_ids.NotEmpty();
}

inline
bool CID2S_Bioseq_place_Info_Base::CanGetSeq_ids(void) const
{
    return true;
}

inline
const CID2S_Bioseq_place_Info_Base::TSeq_ids& CID2S_Bioseq_place_Info_Base::GetSeq_ids(void) const
{
    if ( !m_Seq_ids ) {
        const_cast<CID2S_Bioseq_place_Info_Base*>(this)->ResetSeq_ids();
    }
    return (*m_Seq_ids);
}

inline
CID2S_Bioseq_place_Info_Base::TSeq_ids& CID2S_Bioseq_place_Info_Base::SetSeq_ids(void)
{
    if ( !m_Seq_ids ) {
        ResetSeq_ids();
    }
    return (*m_Seq_ids);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQSPLIT_ID2S_BIOSEQ_PLACE_INFO_BASE_HPP
