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

/// @file ID2S_Chunk_Content_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'seqsplit.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_SEQSPLIT_ID2S_CHUNK_CONTENT_BASE_HPP
#define OBJECTS_SEQSPLIT_ID2S_CHUNK_CONTENT_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CID2S_Bioseq_place_Info;
class CID2S_Seq_annot_Info;
class CID2S_Seq_annot_place_Info;
class CID2S_Seq_assembly_Info;
class CID2S_Seq_data_Info;
class CID2S_Seq_descr_Info;
class CID2S_Seq_feat_Ids_Info;
class CID2S_Seq_map_Info;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// Description of information in this chunk
/// Place means id of Bioseq or Bioseq-set
class NCBI_ID2_EXPORT CID2S_Chunk_Content_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CID2S_Chunk_Content_Base(void);
    // destructor
    virtual ~CID2S_Chunk_Content_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();


    /// Choice variants.
    enum E_Choice {
        e_not_set = 0,      ///< No variant selected
        e_Seq_descr,        ///< place of Seq-descrs
        e_Seq_annot,        ///< locations and types of annotations
        e_Seq_assembly,     ///< place of assembly history
        e_Seq_map,          ///< place of sequence map
        e_Seq_data,         ///< place of sequence data
        e_Seq_annot_place,  ///< place of Seq-annots
        e_Bioseq_place,     ///< place of Bioseqs
        e_Feat_ids          ///< ids of features
    };
    /// Maximum+1 value of the choice variant enumerator.
    enum E_ChoiceStopper {
        e_MaxChoice = 9 ///< == e_Feat_ids+1
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
    typedef CID2S_Seq_descr_Info TSeq_descr;
    typedef CID2S_Seq_annot_Info TSeq_annot;
    typedef CID2S_Seq_assembly_Info TSeq_assembly;
    typedef CID2S_Seq_map_Info TSeq_map;
    typedef CID2S_Seq_data_Info TSeq_data;
    typedef CID2S_Seq_annot_place_Info TSeq_annot_place;
    typedef list< CRef< CID2S_Bioseq_place_Info > > TBioseq_place;
    typedef list< CRef< CID2S_Seq_feat_Ids_Info > > TFeat_ids;

    // getters
    // setters

    // typedef CID2S_Seq_descr_Info TSeq_descr
    bool IsSeq_descr(void) const;
    const TSeq_descr& GetSeq_descr(void) const;
    TSeq_descr& SetSeq_descr(void);
    void SetSeq_descr(TSeq_descr& value);

    // typedef CID2S_Seq_annot_Info TSeq_annot
    bool IsSeq_annot(void) const;
    const TSeq_annot& GetSeq_annot(void) const;
    TSeq_annot& SetSeq_annot(void);
    void SetSeq_annot(TSeq_annot& value);

    // typedef CID2S_Seq_assembly_Info TSeq_assembly
    bool IsSeq_assembly(void) const;
    const TSeq_assembly& GetSeq_assembly(void) const;
    TSeq_assembly& SetSeq_assembly(void);
    void SetSeq_assembly(TSeq_assembly& value);

    // typedef CID2S_Seq_map_Info TSeq_map
    bool IsSeq_map(void) const;
    const TSeq_map& GetSeq_map(void) const;
    TSeq_map& SetSeq_map(void);
    void SetSeq_map(TSeq_map& value);

    // typedef CID2S_Seq_data_Info TSeq_data
    bool IsSeq_data(void) const;
    const TSeq_data& GetSeq_data(void) const;
    TSeq_data& SetSeq_data(void);
    void SetSeq_data(TSeq_data& value);

    // typedef CID2S_Seq_annot_place_Info TSeq_annot_place
    bool IsSeq_annot_place(void) const;
    const TSeq_annot_place& GetSeq_annot_place(void) const;
    TSeq_annot_place& SetSeq_annot_place(void);
    void SetSeq_annot_place(TSeq_annot_place& value);

    // typedef list< CRef< CID2S_Bioseq_place_Info > > TBioseq_place
    bool IsBioseq_place(void) const;
    const TBioseq_place& GetBioseq_place(void) const;
    TBioseq_place& SetBioseq_place(void);

    // typedef list< CRef< CID2S_Seq_feat_Ids_Info > > TFeat_ids
    bool IsFeat_ids(void) const;
    const TFeat_ids& GetFeat_ids(void) const;
    TFeat_ids& SetFeat_ids(void);


private:
    // copy constructor and assignment operator
    CID2S_Chunk_Content_Base(const CID2S_Chunk_Content_Base& );
    CID2S_Chunk_Content_Base& operator=(const CID2S_Chunk_Content_Base& );
    // choice state
    E_Choice m_choice;
    // helper methods
    void DoSelect(E_Choice index, CObjectMemoryPool* pool = 0);

    static const char* const sm_SelectionNames[];
    // data
    union {
        NCBI_NS_NCBI::CUnionBuffer<TBioseq_place> m_Bioseq_place;
        NCBI_NS_NCBI::CUnionBuffer<TFeat_ids> m_Feat_ids;
        NCBI_NS_NCBI::CSerialObject *m_object;
    };
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
CID2S_Chunk_Content_Base::E_Choice CID2S_Chunk_Content_Base::Which(void) const
{
    return m_choice;
}

inline
void CID2S_Chunk_Content_Base::CheckSelected(E_Choice index) const
{
    if ( m_choice != index )
        ThrowInvalidSelection(index);
}

inline
void CID2S_Chunk_Content_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset, NCBI_NS_NCBI::CObjectMemoryPool* pool)
{
    if ( reset == NCBI_NS_NCBI::eDoResetVariant || m_choice != index ) {
        if ( m_choice != e_not_set )
            ResetSelection();
        DoSelect(index, pool);
    }
}

inline
void CID2S_Chunk_Content_Base::Select(E_Choice index, NCBI_NS_NCBI::EResetVariant reset)
{
    Select(index, reset, 0);
}

inline
bool CID2S_Chunk_Content_Base::IsSeq_descr(void) const
{
    return m_choice == e_Seq_descr;
}

inline
bool CID2S_Chunk_Content_Base::IsSeq_annot(void) const
{
    return m_choice == e_Seq_annot;
}

inline
bool CID2S_Chunk_Content_Base::IsSeq_assembly(void) const
{
    return m_choice == e_Seq_assembly;
}

inline
bool CID2S_Chunk_Content_Base::IsSeq_map(void) const
{
    return m_choice == e_Seq_map;
}

inline
bool CID2S_Chunk_Content_Base::IsSeq_data(void) const
{
    return m_choice == e_Seq_data;
}

inline
bool CID2S_Chunk_Content_Base::IsSeq_annot_place(void) const
{
    return m_choice == e_Seq_annot_place;
}

inline
bool CID2S_Chunk_Content_Base::IsBioseq_place(void) const
{
    return m_choice == e_Bioseq_place;
}

inline
const CID2S_Chunk_Content_Base::TBioseq_place& CID2S_Chunk_Content_Base::GetBioseq_place(void) const
{
    CheckSelected(e_Bioseq_place);
    return *m_Bioseq_place;
}

inline
CID2S_Chunk_Content_Base::TBioseq_place& CID2S_Chunk_Content_Base::SetBioseq_place(void)
{
    Select(e_Bioseq_place, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_Bioseq_place;
}

inline
bool CID2S_Chunk_Content_Base::IsFeat_ids(void) const
{
    return m_choice == e_Feat_ids;
}

inline
const CID2S_Chunk_Content_Base::TFeat_ids& CID2S_Chunk_Content_Base::GetFeat_ids(void) const
{
    CheckSelected(e_Feat_ids);
    return *m_Feat_ids;
}

inline
CID2S_Chunk_Content_Base::TFeat_ids& CID2S_Chunk_Content_Base::SetFeat_ids(void)
{
    Select(e_Feat_ids, NCBI_NS_NCBI::eDoNotResetVariant);
    return *m_Feat_ids;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQSPLIT_ID2S_CHUNK_CONTENT_BASE_HPP