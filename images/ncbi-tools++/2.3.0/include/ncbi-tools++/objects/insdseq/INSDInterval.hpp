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

/// @file INSDInterval.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'insdseq.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: INSDInterval_.hpp


#ifndef OBJECTS_INSDSEQ_INSDINTERVAL_HPP
#define OBJECTS_INSDSEQ_INSDINTERVAL_HPP


// generated includes
#include <objects/insdseq/INSDInterval_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_INSDSEQ_EXPORT CINSDInterval : public CINSDInterval_Base
{
    typedef CINSDInterval_Base Tparent;
public:
    // constructor
    CINSDInterval(void);
    // destructor
    ~CINSDInterval(void);

private:
    // Prohibit copy constructor and assignment operator
    CINSDInterval(const CINSDInterval& value);
    CINSDInterval& operator=(const CINSDInterval& value);

};

/////////////////// CINSDInterval inline methods

// constructor
inline
CINSDInterval::CINSDInterval(void)
{
}


/////////////////// end of CINSDInterval inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_INSDSEQ_INSDINTERVAL_HPP
/* Original file checksum: lines: 86, chars: 2473, CRC32: 6643a716 */
