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

/// @file PrintTemplateSet_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'objprt.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_OBJPRT_PRINTTEMPLATESET_BASE_HPP
#define OBJECTS_OBJPRT_PRINTTEMPLATESET_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>

// generated includes
#include <list>

BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// forward declarations
class CPrintTemplate;


// generated classes

/////////////////////////////////////////////////////////////////////////////
class NCBI_OBJPRT_EXPORT CPrintTemplateSet_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CPrintTemplateSet_Base(void);
    // destructor
    virtual ~CPrintTemplateSet_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef list< CRef< CPrintTemplate > > Tdata;

    // getters
    // setters

    /// mandatory
    /// typedef list< CRef< CPrintTemplate > > Tdata
    ///  Check whether the  data member has been assigned a value.
    bool IsSet(void) const;
    /// Check whether it is safe or not to call Get method.
    bool CanGet(void) const;
    void Reset(void);
    const Tdata& Get(void) const;
    Tdata& Set(void);
    /// Conversion operator to 'const Tdata' type.
    operator const Tdata& (void) const;

    /// Conversion operator to 'Tdata' type.
    operator Tdata& (void);




private:
    // Prohibit copy constructor and assignment operator
    CPrintTemplateSet_Base(const CPrintTemplateSet_Base&);
    CPrintTemplateSet_Base& operator=(const CPrintTemplateSet_Base&);

    // data
    Uint4 m_set_State[1];
    list< CRef< CPrintTemplate > > m_data;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CPrintTemplateSet_Base::IsSet(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CPrintTemplateSet_Base::CanGet(void) const
{
    return true;
}

inline
const CPrintTemplateSet_Base::Tdata& CPrintTemplateSet_Base::Get(void) const
{
    return m_data;
}

inline
CPrintTemplateSet_Base::Tdata& CPrintTemplateSet_Base::Set(void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

inline
CPrintTemplateSet_Base::operator const CPrintTemplateSet_Base::Tdata& (void) const
{
    return m_data;
}

inline
CPrintTemplateSet_Base::operator CPrintTemplateSet_Base::Tdata& (void)
{
    m_set_State[0] |= 0x1;
    return m_data;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_OBJPRT_PRINTTEMPLATESET_BASE_HPP