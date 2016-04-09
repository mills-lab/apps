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

/// @file MSEnzymes_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'omssa.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_OMSSA_MSENZYMES_BASE_HPP
#define OBJECTS_OMSSA_MSENZYMES_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/// enumerate enzymes
enum EMSEnzymes {
    eMSEnzymes_trypsin           =   0,
    eMSEnzymes_argc              =   1,
    eMSEnzymes_cnbr              =   2,
    eMSEnzymes_chymotrypsin      =   3,
    eMSEnzymes_formicacid        =   4,
    eMSEnzymes_lysc              =   5,
    eMSEnzymes_lysc_p            =   6,
    eMSEnzymes_pepsin_a          =   7,
    eMSEnzymes_tryp_cnbr         =   8,
    eMSEnzymes_tryp_chymo        =   9,
    eMSEnzymes_trypsin_p         =  10,
    eMSEnzymes_whole_protein     =  11,
    eMSEnzymes_aspn              =  12,
    eMSEnzymes_gluc              =  13,
    eMSEnzymes_aspngluc          =  14,
    eMSEnzymes_top_down          =  15,
    eMSEnzymes_semi_tryptic      =  16,
    eMSEnzymes_no_enzyme         =  17,
    eMSEnzymes_chymotrypsin_p    =  18,
    eMSEnzymes_aspn_de           =  19,
    eMSEnzymes_gluc_de           =  20,
    eMSEnzymes_lysn              =  21,
    eMSEnzymes_thermolysin_p     =  22,
    eMSEnzymes_semi_chymotrypsin =  23,
    eMSEnzymes_semi_gluc         =  24,
    eMSEnzymes_max               =  25,
    eMSEnzymes_none              = 255
};

/// Access to EMSEnzymes's attributes (values, names) as defined in spec
NCBI_OMSSA_EXPORT const NCBI_NS_NCBI::CEnumeratedTypeValues* ENUM_METHOD_NAME(EMSEnzymes)(void);


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_OMSSA_MSENZYMES_BASE_HPP