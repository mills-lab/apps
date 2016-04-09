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

/// @file CDSGenePr_constraint_field.hpp
/// User-defined methods of the data storage class.
///
/// This file was originally generated by application DATATOOL
/// using the following specifications:
/// 'macro.asn'.
///
/// New methods or data members can be added to it if needed.
/// See also: CDSGenePr_constraint_field_.hpp


#ifndef OBJECTS_MACRO_CDSGENEPR_CONSTRAINT_FIELD_HPP
#define OBJECTS_MACRO_CDSGENEPR_CONSTRAINT_FIELD_HPP


// generated includes
#include <objects/macro/CDSGenePr_constraint_field_.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

/////////////////////////////////////////////////////////////////////////////
class CCDSGeneProt_constraint_field : public CCDSGeneProt_constraint_field_Base
{
    typedef CCDSGeneProt_constraint_field_Base Tparent;
public:
    // constructor
    CCDSGeneProt_constraint_field(void);
    // destructor
    ~CCDSGeneProt_constraint_field(void);

private:
    // Prohibit copy constructor and assignment operator
    CCDSGeneProt_constraint_field(const CCDSGeneProt_constraint_field& value);
    CCDSGeneProt_constraint_field& operator=(const CCDSGeneProt_constraint_field& value);

};

/////////////////// CCDSGeneProt_constraint_field inline methods

// constructor
inline
CCDSGeneProt_constraint_field::CCDSGeneProt_constraint_field(void)
{
}


/////////////////// end of CCDSGeneProt_constraint_field inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_MACRO_CDSGENEPR_CONSTRAINT_FIELD_HPP
/* Original file checksum: lines: 86, chars: 2735, CRC32: 59527884 */