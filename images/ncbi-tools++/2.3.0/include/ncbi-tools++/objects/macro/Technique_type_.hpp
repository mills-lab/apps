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

/// @file Technique_type_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_MACRO_TECHNIQUE_TYPE_BASE_HPP
#define OBJECTS_MACRO_TECHNIQUE_TYPE_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

enum ETechnique_type {
    eTechnique_type_unknown            =  0,
    eTechnique_type_standard           =  1,
    eTechnique_type_est                =  2,
    eTechnique_type_sts                =  3,
    eTechnique_type_survey             =  4,
    eTechnique_type_genetic_map        =  5,
    eTechnique_type_physical_map       =  6,
    eTechnique_type_derived            =  7,
    eTechnique_type_concept_trans      =  8,
    eTechnique_type_seq_pept           =  9,
    eTechnique_type_both               = 10,
    eTechnique_type_seq_pept_overlap   = 11,
    eTechnique_type_seq_pept_homol     = 12,
    eTechnique_type_concept_trans_a    = 13,
    eTechnique_type_htgs_1             = 14,
    eTechnique_type_htgs_2             = 15,
    eTechnique_type_htgs_3             = 16,
    eTechnique_type_fli_cDNA           = 17,
    eTechnique_type_htgs_0             = 18,
    eTechnique_type_htc                = 19,
    eTechnique_type_wgs                = 20,
    eTechnique_type_barcode            = 21,
    eTechnique_type_composite_wgs_htgs = 22,
    eTechnique_type_tsa                = 23,
    eTechnique_type_other              = 24
};

/// Access to ETechnique_type's attributes (values, names) as defined in spec
 const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(ETechnique_type)(void);


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_TECHNIQUE_TYPE_BASE_HPP
