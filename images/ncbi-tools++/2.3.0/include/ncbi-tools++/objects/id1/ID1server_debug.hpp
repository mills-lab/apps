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

/// @file ID1server_debug.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'id1.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: ID1server_debug_.hpp


#ifndef OBJECTS_ID1_ID1SERVER_DEBUG_HPP
#define OBJECTS_ID1_ID1SERVER_DEBUG_HPP


// generated includes
#include <objects/id1/ID1server_debug_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_ID1_EXPORT CID1server_debug : public CID1server_debug_Base
{
    typedef CID1server_debug_Base Tparent;
public:
    // constructor
    CID1server_debug(void);
    // destructor
    ~CID1server_debug(void);

private:
    // Prohibit copy constructor and assignment operator
    CID1server_debug(const CID1server_debug& value);
    CID1server_debug& operator=(const CID1server_debug& value);

};

/////////////////// CID1server_debug inline methods

// constructor
inline
CID1server_debug::CID1server_debug(void)
{
}


/////////////////// end of CID1server_debug inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_ID1_ID1SERVER_DEBUG_HPP
/* Original file checksum: lines: 86, chars: 2506, CRC32: 3e1ae9bc */
