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

/// @file Biostruc_residue_graph_set_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'mmdb1.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MMDB1_BIOSTRUC_RESIDUE_GRAPH_SET_BASE_HPP
#define OBJECTS_MMDB1_BIOSTRUC_RESIDUE_GRAPH_SET_BASE_HPP

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
class CBiomol_descr;
class CBiostruc_id;
class CResidue_graph;


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// A biostruc residue graph set is a collection of residue graphs.  The object
/// type is intended as a means to record dictionaries containing the chemical
/// subgraphs of "standard" residue types, which are used as a means to 
/// simplify discription of the covalent structure of a biomolecular assembly.
/// The standard residue graph dictionary supplied with the MMDB database 
/// contains 20 standard L amino acids and 8 standard ribonucleotide groups. 
/// These graphs are complete, including explicit hydrogen atoms and separate 
/// instances for the terminal polypeptide and polynucleotide residues. 
class NCBI_MMDB1_EXPORT CBiostruc_residue_graph_set_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CBiostruc_residue_graph_set_Base(void);
    // destructor
    virtual ~CBiostruc_residue_graph_set_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef list< CRef< CBiostruc_id > > TId;
    typedef list< CRef< CBiomol_descr > > TDescr;
    typedef list< CRef< CResidue_graph > > TResidue_graphs;

    // getters
    // setters

    /// optional
    /// typedef list< CRef< CBiostruc_id > > TId
    ///  Check whether the Id data member has been assigned a value.
    bool IsSetId(void) const;
    /// Check whether it is safe or not to call GetId method.
    bool CanGetId(void) const;
    void ResetId(void);
    const TId& GetId(void) const;
    TId& SetId(void);

    /// optional
    /// typedef list< CRef< CBiomol_descr > > TDescr
    ///  Check whether the Descr data member has been assigned a value.
    bool IsSetDescr(void) const;
    /// Check whether it is safe or not to call GetDescr method.
    bool CanGetDescr(void) const;
    void ResetDescr(void);
    const TDescr& GetDescr(void) const;
    TDescr& SetDescr(void);

    /// mandatory
    /// typedef list< CRef< CResidue_graph > > TResidue_graphs
    ///  Check whether the Residue_graphs data member has been assigned a value.
    bool IsSetResidue_graphs(void) const;
    /// Check whether it is safe or not to call GetResidue_graphs method.
    bool CanGetResidue_graphs(void) const;
    void ResetResidue_graphs(void);
    const TResidue_graphs& GetResidue_graphs(void) const;
    TResidue_graphs& SetResidue_graphs(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CBiostruc_residue_graph_set_Base(const CBiostruc_residue_graph_set_Base&);
    CBiostruc_residue_graph_set_Base& operator=(const CBiostruc_residue_graph_set_Base&);

    // data
    Uint4 m_set_State[1];
    list< CRef< CBiostruc_id > > m_Id;
    list< CRef< CBiomol_descr > > m_Descr;
    list< CRef< CResidue_graph > > m_Residue_graphs;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CBiostruc_residue_graph_set_Base::IsSetId(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CBiostruc_residue_graph_set_Base::CanGetId(void) const
{
    return true;
}

inline
const CBiostruc_residue_graph_set_Base::TId& CBiostruc_residue_graph_set_Base::GetId(void) const
{
    return m_Id;
}

inline
CBiostruc_residue_graph_set_Base::TId& CBiostruc_residue_graph_set_Base::SetId(void)
{
    m_set_State[0] |= 0x1;
    return m_Id;
}

inline
bool CBiostruc_residue_graph_set_Base::IsSetDescr(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CBiostruc_residue_graph_set_Base::CanGetDescr(void) const
{
    return true;
}

inline
const CBiostruc_residue_graph_set_Base::TDescr& CBiostruc_residue_graph_set_Base::GetDescr(void) const
{
    return m_Descr;
}

inline
CBiostruc_residue_graph_set_Base::TDescr& CBiostruc_residue_graph_set_Base::SetDescr(void)
{
    m_set_State[0] |= 0x4;
    return m_Descr;
}

inline
bool CBiostruc_residue_graph_set_Base::IsSetResidue_graphs(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CBiostruc_residue_graph_set_Base::CanGetResidue_graphs(void) const
{
    return true;
}

inline
const CBiostruc_residue_graph_set_Base::TResidue_graphs& CBiostruc_residue_graph_set_Base::GetResidue_graphs(void) const
{
    return m_Residue_graphs;
}

inline
CBiostruc_residue_graph_set_Base::TResidue_graphs& CBiostruc_residue_graph_set_Base::SetResidue_graphs(void)
{
    m_set_State[0] |= 0x10;
    return m_Residue_graphs;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MMDB1_BIOSTRUC_RESIDUE_GRAPH_SET_BASE_HPP
