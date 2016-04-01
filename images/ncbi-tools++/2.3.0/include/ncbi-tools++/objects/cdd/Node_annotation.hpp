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

/// @file Node_annotation.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'cdd.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Node_annotation_.hpp


#ifndef OBJECTS_CDD_NODE_ANNOTATION_HPP
#define OBJECTS_CDD_NODE_ANNOTATION_HPP


// generated includes
#include <objects/cdd/Node_annotation_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_CDD_EXPORT CNode_annotation : public CNode_annotation_Base
{
    typedef CNode_annotation_Base Tparent;
public:
    // constructor
    CNode_annotation(void);
    // destructor
    ~CNode_annotation(void);

private:
    // Prohibit copy constructor and assignment operator
    CNode_annotation(const CNode_annotation& value);
    CNode_annotation& operator=(const CNode_annotation& value);

};

/////////////////// CNode_annotation inline methods

// constructor
inline
CNode_annotation::CNode_annotation(void)
{
}


/////////////////// end of CNode_annotation inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_CDD_NODE_ANNOTATION_HPP
/* Original file checksum: lines: 86, chars: 2506, CRC32: bfb2dc0b */
