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

/// @file Cdd_Viewer_Rect_.hpp
/// Data storage class.
///
/// This file was generated by application DATATOOL
/// using the following specifications:
/// 'cdd.asn'.
///
/// ATTENTION:
///   Don't edit or commit this file into CVS as this file will
///   be overridden (by DATATOOL) without warning!

#ifndef OBJECTS_CDD_CDD_VIEWER_RECT_BASE_HPP
#define OBJECTS_CDD_CDD_VIEWER_RECT_BASE_HPP

// standard includes
#include <serial/serialbase.hpp>
BEGIN_NCBI_SCOPE

#ifndef BEGIN_objects_SCOPE
#  define BEGIN_objects_SCOPE BEGIN_SCOPE(objects)
#  define END_objects_SCOPE END_SCOPE(objects)
#endif
BEGIN_objects_SCOPE // namespace ncbi::objects::


// generated classes

/////////////////////////////////////////////////////////////////////////////
/// Cdd projects store a set of CDs, typically related to each other
/// relationships would be specified using the ancestors fields in the
/// individual CD objects. For use with CD-Tree, a program to visualize
/// curated CD hierarchies and evidence for hierarchical family structures.
class NCBI_CDD_EXPORT CCdd_Viewer_Rect_Base : public CSerialObject
{
    typedef CSerialObject Tparent;
public:
    // constructor
    CCdd_Viewer_Rect_Base(void);
    // destructor
    virtual ~CCdd_Viewer_Rect_Base(void);

    // type info
    DECLARE_INTERNAL_TYPE_INFO();

    // types
    typedef int TTop;
    typedef int TLeft;
    typedef int TWidth;
    typedef int THeight;

    // getters
    // setters

    /// top coordinate
    /// mandatory
    /// typedef int TTop
    ///  Check whether the Top data member has been assigned a value.
    bool IsSetTop(void) const;
    /// Check whether it is safe or not to call GetTop method.
    bool CanGetTop(void) const;
    void ResetTop(void);
    TTop GetTop(void) const;
    void SetTop(TTop value);
    TTop& SetTop(void);

    /// left  coordinate
    /// mandatory
    /// typedef int TLeft
    ///  Check whether the Left data member has been assigned a value.
    bool IsSetLeft(void) const;
    /// Check whether it is safe or not to call GetLeft method.
    bool CanGetLeft(void) const;
    void ResetLeft(void);
    TLeft GetLeft(void) const;
    void SetLeft(TLeft value);
    TLeft& SetLeft(void);

    /// width 
    /// mandatory
    /// typedef int TWidth
    ///  Check whether the Width data member has been assigned a value.
    bool IsSetWidth(void) const;
    /// Check whether it is safe or not to call GetWidth method.
    bool CanGetWidth(void) const;
    void ResetWidth(void);
    TWidth GetWidth(void) const;
    void SetWidth(TWidth value);
    TWidth& SetWidth(void);

    /// height
    /// mandatory
    /// typedef int THeight
    ///  Check whether the Height data member has been assigned a value.
    bool IsSetHeight(void) const;
    /// Check whether it is safe or not to call GetHeight method.
    bool CanGetHeight(void) const;
    void ResetHeight(void);
    THeight GetHeight(void) const;
    void SetHeight(THeight value);
    THeight& SetHeight(void);

    /// Reset the whole object
    virtual void Reset(void);


private:
    // Prohibit copy constructor and assignment operator
    CCdd_Viewer_Rect_Base(const CCdd_Viewer_Rect_Base&);
    CCdd_Viewer_Rect_Base& operator=(const CCdd_Viewer_Rect_Base&);

    // data
    Uint4 m_set_State[1];
    int m_Top;
    int m_Left;
    int m_Width;
    int m_Height;
};






///////////////////////////////////////////////////////////
///////////////////// inline methods //////////////////////
///////////////////////////////////////////////////////////
inline
bool CCdd_Viewer_Rect_Base::IsSetTop(void) const
{
    return ((m_set_State[0] & 0x3) != 0);
}

inline
bool CCdd_Viewer_Rect_Base::CanGetTop(void) const
{
    return IsSetTop();
}

inline
void CCdd_Viewer_Rect_Base::ResetTop(void)
{
    m_Top = 0;
    m_set_State[0] &= ~0x3;
}

inline
CCdd_Viewer_Rect_Base::TTop CCdd_Viewer_Rect_Base::GetTop(void) const
{
    if (!CanGetTop()) {
        ThrowUnassigned(0);
    }
    return m_Top;
}

inline
void CCdd_Viewer_Rect_Base::SetTop(CCdd_Viewer_Rect_Base::TTop value)
{
    m_Top = value;
    m_set_State[0] |= 0x3;
}

inline
CCdd_Viewer_Rect_Base::TTop& CCdd_Viewer_Rect_Base::SetTop(void)
{
#ifdef _DEBUG
    if (!IsSetTop()) {
        memset(&m_Top,UnassignedByte(),sizeof(m_Top));
    }
#endif
    m_set_State[0] |= 0x1;
    return m_Top;
}

inline
bool CCdd_Viewer_Rect_Base::IsSetLeft(void) const
{
    return ((m_set_State[0] & 0xc) != 0);
}

inline
bool CCdd_Viewer_Rect_Base::CanGetLeft(void) const
{
    return IsSetLeft();
}

inline
void CCdd_Viewer_Rect_Base::ResetLeft(void)
{
    m_Left = 0;
    m_set_State[0] &= ~0xc;
}

inline
CCdd_Viewer_Rect_Base::TLeft CCdd_Viewer_Rect_Base::GetLeft(void) const
{
    if (!CanGetLeft()) {
        ThrowUnassigned(1);
    }
    return m_Left;
}

inline
void CCdd_Viewer_Rect_Base::SetLeft(CCdd_Viewer_Rect_Base::TLeft value)
{
    m_Left = value;
    m_set_State[0] |= 0xc;
}

inline
CCdd_Viewer_Rect_Base::TLeft& CCdd_Viewer_Rect_Base::SetLeft(void)
{
#ifdef _DEBUG
    if (!IsSetLeft()) {
        memset(&m_Left,UnassignedByte(),sizeof(m_Left));
    }
#endif
    m_set_State[0] |= 0x4;
    return m_Left;
}

inline
bool CCdd_Viewer_Rect_Base::IsSetWidth(void) const
{
    return ((m_set_State[0] & 0x30) != 0);
}

inline
bool CCdd_Viewer_Rect_Base::CanGetWidth(void) const
{
    return IsSetWidth();
}

inline
void CCdd_Viewer_Rect_Base::ResetWidth(void)
{
    m_Width = 0;
    m_set_State[0] &= ~0x30;
}

inline
CCdd_Viewer_Rect_Base::TWidth CCdd_Viewer_Rect_Base::GetWidth(void) const
{
    if (!CanGetWidth()) {
        ThrowUnassigned(2);
    }
    return m_Width;
}

inline
void CCdd_Viewer_Rect_Base::SetWidth(CCdd_Viewer_Rect_Base::TWidth value)
{
    m_Width = value;
    m_set_State[0] |= 0x30;
}

inline
CCdd_Viewer_Rect_Base::TWidth& CCdd_Viewer_Rect_Base::SetWidth(void)
{
#ifdef _DEBUG
    if (!IsSetWidth()) {
        memset(&m_Width,UnassignedByte(),sizeof(m_Width));
    }
#endif
    m_set_State[0] |= 0x10;
    return m_Width;
}

inline
bool CCdd_Viewer_Rect_Base::IsSetHeight(void) const
{
    return ((m_set_State[0] & 0xc0) != 0);
}

inline
bool CCdd_Viewer_Rect_Base::CanGetHeight(void) const
{
    return IsSetHeight();
}

inline
void CCdd_Viewer_Rect_Base::ResetHeight(void)
{
    m_Height = 0;
    m_set_State[0] &= ~0xc0;
}

inline
CCdd_Viewer_Rect_Base::THeight CCdd_Viewer_Rect_Base::GetHeight(void) const
{
    if (!CanGetHeight()) {
        ThrowUnassigned(3);
    }
    return m_Height;
}

inline
void CCdd_Viewer_Rect_Base::SetHeight(CCdd_Viewer_Rect_Base::THeight value)
{
    m_Height = value;
    m_set_State[0] |= 0xc0;
}

inline
CCdd_Viewer_Rect_Base::THeight& CCdd_Viewer_Rect_Base::SetHeight(void)
{
#ifdef _DEBUG
    if (!IsSetHeight()) {
        memset(&m_Height,UnassignedByte(),sizeof(m_Height));
    }
#endif
    m_set_State[0] |= 0x40;
    return m_Height;
}

///////////////////////////////////////////////////////////
////////////////// end of inline methods //////////////////
///////////////////////////////////////////////////////////





END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE


#endif // OBJECTS_CDD_CDD_VIEWER_RECT_BASE_HPP