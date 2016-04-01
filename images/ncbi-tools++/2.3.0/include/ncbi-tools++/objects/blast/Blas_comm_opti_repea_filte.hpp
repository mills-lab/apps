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

/// @file Blas_comm_opti_repea_filte.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'blast.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Blas_comm_opti_repea_filte_.hpp


#ifndef OBJECTS_BLAST_BLAS_COMM_OPTI_REPEA_FILTE_HPP
#define OBJECTS_BLAST_BLAS_COMM_OPTI_REPEA_FILTE_HPP


// generated includes
#include <objects/blast/Blas_comm_opti_repea_filte_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_BLAST_EXPORT CBlast4_common_options_repeats_filtering : public CBlast4_common_options_repeats_filtering_Base
{
    typedef CBlast4_common_options_repeats_filtering_Base Tparent;
public:
    // constructor
    CBlast4_common_options_repeats_filtering(void);
    // destructor
    ~CBlast4_common_options_repeats_filtering(void);

private:
    // Prohibit copy constructor and assignment operator
    CBlast4_common_options_repeats_filtering(const CBlast4_common_options_repeats_filtering& value);
    CBlast4_common_options_repeats_filtering& operator=(const CBlast4_common_options_repeats_filtering& value);

};

/////////////////// CBlast4_common_options_repeats_filtering inline methods

// constructor
inline
CBlast4_common_options_repeats_filtering::CBlast4_common_options_repeats_filtering(void)
{
}


/////////////////// end of CBlast4_common_options_repeats_filtering inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_BLAST_BLAS_COMM_OPTI_REPEA_FILTE_HPP
/* Original file checksum: lines: 86, chars: 2896, CRC32: 1b8981df */
