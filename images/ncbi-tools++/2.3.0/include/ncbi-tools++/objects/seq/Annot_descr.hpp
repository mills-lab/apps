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

/// @file Annot_descr.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'seq.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Annot_descr_.hpp


#ifndef OBJECTS_SEQ_ANNOT_DESCR_HPP
#define OBJECTS_SEQ_ANNOT_DESCR_HPP


// generated includes
#include <objects/seq/Annot_descr_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_SEQ_EXPORT CAnnot_descr : public CAnnot_descr_Base
{
    typedef CAnnot_descr_Base Tparent;
public:
    // constructor
    CAnnot_descr(void);
    // destructor
    ~CAnnot_descr(void);

private:
    // Prohibit copy constructor and assignment operator
    CAnnot_descr(const CAnnot_descr& value);
    CAnnot_descr& operator=(const CAnnot_descr& value);

};

/////////////////// CAnnot_descr inline methods

// constructor
inline
CAnnot_descr::CAnnot_descr(void)
{
}


/////////////////// end of CAnnot_descr inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SEQ_ANNOT_DESCR_HPP
/* Original file checksum: lines: 86, chars: 2430, CRC32: c53656a8 */
