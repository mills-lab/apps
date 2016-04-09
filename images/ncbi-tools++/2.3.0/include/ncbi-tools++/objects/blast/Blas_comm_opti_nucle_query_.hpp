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

/// @file Blas_comm_opti_nucle_query_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'blast.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_BLAST_BLAS_COMM_OPTI_NUCLE_QUERY_BASE_HPP
#define OBJECTS_BLAST_BLAS_COMM_OPTI_NUCLE_QUERY_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>
#include <objects/blast/Blast4_strand_type.hpp>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CBlast4_common_options_discontiguous_megablast;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_BLAST_EXPORT CBlast4_common_options_nucleotide_query_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CBlast4_common_options_nucleotide_query_Base(void);
    // destructor
    virtual ~CBlast4_common_options_nucleotide_query_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef list< EBlast4_strand_type > TStrand_type_list;
    typedef CBlast4_common_options_discontiguous_megablast TDisco_megablast_options;

    // getters
    // setters

    /// one per query
    /// optional
    /// typedef list< EBlast4_strand_type > TStrand_type_list
    ///  Check whether the Strand_type_list data member has been assigned a value.
    bool IsSetStrand_type_list(void) const;
    /// Check whether it is safe or not to call GetStrand_type_list method.
    bool CanGetStrand_type_list(void) const;
    void ResetStrand_type_list(void);
    const TStrand_type_list& GetStrand_type_list(void) const;
    TStrand_type_list& SetStrand_type_list(void);

    /// optional
    /// typedef CBlast4_common_options_discontiguous_megablast TDisco_megablast_options
    ///  Check whether the Disco_megablast_options data member has been assigned a value.
    bool IsSetDisco_megablast_options(void) const;
    /// Check whether it is safe or not to call GetDisco_megablast_options method.
    bool CanGetDisco_megablast_options(void) const;
    void ResetDisco_megablast_options(void);
    const TDisco_megablast_options& GetDisco_megablast_options(void) const;
    void SetDisco_megablast_options(TDisco_megablast_options& value);
    TDisco_megablast_options& SetDisco_megablast_options(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CBlast4_common_options_nucleotide_query_Base(const CBlast4_common_options_nucleotide_query_Base&);
    CBlast4_common_options_nucleotide_query_Base& operator=(const CBlast4_common_options_nucleotide_query_Base&);

    // data
    Uint4 m_set_State[1];
    list< EBlast4_strand_type > m_Strand_type_list;
    CRef< TDisco_megablast_options > m_Disco_megablast_options;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CBlast4_common_options_nucleotide_query_Base::IsSetStrand_type_list(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CBlast4_common_options_nucleotide_query_Base::CanGetStrand_type_list(void) const
{
    return true;
}

inline
const CBlast4_common_options_nucleotide_query_Base::TStrand_type_list& CBlast4_common_options_nucleotide_query_Base::GetStrand_type_list(void) const
{
    return m_Strand_type_list;
}

inline
CBlast4_common_options_nucleotide_query_Base::TStrand_type_list& CBlast4_common_options_nucleotide_query_Base::SetStrand_type_list(void)
{
    m_set_State[0] |= 0x1;
    return m_Strand_type_list;
}

inline
bool CBlast4_common_options_nucleotide_query_Base::IsSetDisco_megablast_options(void) const
{
    return m_Disco_megablast_options.NotEmpty();
}

inline
bool CBlast4_common_options_nucleotide_query_Base::CanGetDisco_megablast_options(void) const
{
    return IsSetDisco_megablast_options();
}

inline
const CBlast4_common_options_nucleotide_query_Base::TDisco_megablast_options& CBlast4_common_options_nucleotide_query_Base::GetDisco_megablast_options(void) const
{
    if (!CanGetDisco_megablast_options()) {
        ThrowUnassigned(1);
    }
    return (*m_Disco_megablast_options);
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BLAST_BLAS_COMM_OPTI_NUCLE_QUERY_BASE_HPP