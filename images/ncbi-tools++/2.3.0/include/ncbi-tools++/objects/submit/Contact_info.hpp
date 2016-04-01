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

/// @file Contact_info.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'submit.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: Contact_info_.hpp


#ifndef OBJECTS_SUBMIT_CONTACT_INFO_HPP
#define OBJECTS_SUBMIT_CONTACT_INFO_HPP


// generated includes
#include <objects/submit/Contact_info_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class NCBI_SUBMIT_EXPORT CContact_info : public CContact_info_Base
{
    typedef CContact_info_Base Tparent;
public:
    // constructor
    CContact_info(void);
    // destructor
    ~CContact_info(void);

private:
    // Prohibit copy constructor and assignment operator
    CContact_info(const CContact_info& value);
    CContact_info& operator=(const CContact_info& value);

};

/////////////////// CContact_info inline methods

// constructor
inline
CContact_info::CContact_info(void)
{
}


/////////////////// end of CContact_info inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_SUBMIT_CONTACT_INFO_HPP
/* Original file checksum: lines: 86, chars: 2467, CRC32: 5871d8e */
