/* $Id: Seq_loc.hpp 475726 2015-08-11 18:12:56Z vasilche $
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
 * Author:  Cliff Clausen, Eugene Vasilchenko, Mati Shomrat
 *
 * File Description:
 *   .......
 *
 * Remark:
 *   This code was originally generated by application DATATOOL
 *   using specifications from the ASN data definition file
 *   'seqloc.asn'.
 *
 * ===========================================================================
 */

#ifndef OBJECTS_SEQLOC_SEQ_LOC_HPP
#define OBJECTS_SEQLOC_SEQ_LOC_HPP


// generated includes
#include <objects/seqloc/Seq_loc_.hpp>
#include <objects/seqloc/Seq_loc_mix.hpp>
#include <objects/seqloc/Packed_seqpnt.hpp>
#include <objects/seqloc/Packed_seqint.hpp>
#include <objects/seqloc/Seq_id.hpp>
#include <objects/seq/seq_id_handle.hpp>
#include <objects/general/Int_fuzz.hpp>
//
////
//#include <corelib/ncbiexpt.hpp>
//#include <util/range.hpp>
//#include <vector>

BEGIN_NCBI_SCOPE
BEGIN_objects_SCOPE // namespace ncbi::objects::

/** @addtogroup OBJECTS_Seqloc
 *
 * @{
 */


class CSeq_id_Handle;
class ISynonymMapper;
class ILengthGetter;
class CSeq_loc_CI;
class CSeq_loc_I;

/// Seq-loc exceptions
class NCBI_SEQ_EXPORT CSeqLocException : public CException
{
public:
    enum EErrCode {
        eNotSet,         ///< Seq-loc is not set
        eMultipleId,     ///< Seq-loc on multiple ids when one id is required
        eUnsupported,    ///< Seq-loc has data that is not supported yet
        eBadLocation,    ///< Seq-loc is incorrectly formed
        eBadIterator,    ///< Seq-loc iterator is in bad state
        eIncomatible,    ///< Seq-loc type is incompatible with operation
        eOutOfRange,     ///< parameter is out of valid range

        eOtherError
    };

    virtual const char* GetErrCodeString(void) const;
    NCBI_EXCEPTION_DEFAULT(CSeqLocException, CException);
};


class NCBI_SEQLOC_EXPORT CSeq_loc : public CSeq_loc_Base
{
public:
    typedef CSeq_loc_Base Tparent;
    typedef CPacked_seqpnt_Base::TPoints TPoints;
    typedef CPacked_seqint_Base::Tdata   TIntervals;
    typedef CSeq_loc_mix_Base::Tdata     TLocations;
    typedef CSeq_id                      TId;
    typedef ENa_strand                   TStrand;
    typedef TSeqPos                      TPoint;
    typedef CPacked_seqint::TRanges      TRanges;

    /// constructors
    CSeq_loc(void);
    CSeq_loc(E_Choice index);
    CSeq_loc(TId& id, TPoint point, TStrand strand = eNa_strand_unknown);
    CSeq_loc(TId& id, const TPoints& points, TStrand strand = eNa_strand_unknown);
    CSeq_loc(TId& id, TPoint from, TPoint to, TStrand strand = eNa_strand_unknown);
    CSeq_loc(TId& id, TRanges ivals, TStrand strand = eNa_strand_unknown);

    // destructor
    virtual ~CSeq_loc(void);

    /// See related functions in util/sequence.hpp:
    ///
    ///   TSeqPos GetLength(const CSeq_loc&, CScope*)
    ///   bool IsOneBioseq(const CSeq_loc&, CScope*)
    ///   const CSeq_id& GetId(const CSeq_loc&, CScope*)
    ///   TSeqPos GetStart(const CSeq_loc&, CScope*)
    ///   sequence::ECompare Compare(const CSeq_loc&, CSeq_loc&, CScope*)
    ///   sequence::SeqLocMerge(...)
    ///

    typedef CRange<TSeqPos> TRange;

    TRange GetTotalRange(void) const;
    void InvalidateTotalRangeCache(void) const;
 
    /// Check if strand is set for any/all part(s) of the seq-loc
    /// depending on the flag.
    bool IsSetStrand(EIsSetStrand flag = eIsSetStrand_Any) const;
    /// Get the location's strand. If no strand is set, returns
    /// eNa_strand_unknown. If different strands are set in different
    /// parts, returns eNa_strand_other. Explicitly set unknown strand
    /// is ignored when combined whith plus or minus strand.
    /// Examples:
    ///   not-set = unknown
    ///   not-set + plus = plus
    ///   unknown + plus = plus
    ///   unknown + both = other
    ///   plus + minus = other
    ENa_strand GetStrand(void) const;
    /// Return true if all ranges have reverse strand
    bool IsReverseStrand(void) const;
    /// Flip the strand (e.g. plus to minus)
    void FlipStrand(void);
    /// Set the strand for all of the location's ranges.
    void SetStrand(ENa_strand strand);
    /// Reset the strand on this location
    void ResetStrand(void);

    /// Return start and stop positions of the seq-loc.
    /// Stop may be less than Start for circular sequences.
    TSeqPos GetStart(ESeqLocExtremes ext) const;
    TSeqPos GetStop (ESeqLocExtremes ext) const;

    /// Special case for circular sequences. No ID is checked for
    /// circular locations. If the sequence is not circular
    /// (seq_len == kInvalidSeqPos) the function works like GetTotalRange()
    TSeqPos GetCircularLength(TSeqPos seq_len) const;

    /// Appends a label suitable for display (e.g., error messages)
    /// label must point to an existing string object
    /// Method just returns if label is null. Note this label is NOT
    /// GenBank-style.
    void GetLabel(string* label) const;

    /// check start or stop of location for e_Lim fuzz
    bool IsPartialStart(ESeqLocExtremes ext) const;
    bool IsPartialStop(ESeqLocExtremes ext) const;

    /// set / remove e_Lim fuzz on start or stop
    /// (lt/gt - indicating partial interval)
    void SetPartialStart(bool val, ESeqLocExtremes ext);
    void SetPartialStop (bool val, ESeqLocExtremes ext);

    /// check if parts of the seq-loc are missing
    bool IsTruncatedStart(ESeqLocExtremes ext) const;
    bool IsTruncatedStop (ESeqLocExtremes ext) const;

    /// set / remove e_Lim fuzz on start or stop
    /// (tl/tr - indicating removed parts of the seq-loc)
    void SetTruncatedStart(bool val, ESeqLocExtremes ext);
    void SetTruncatedStop (bool val, ESeqLocExtremes ext);

    /// Get the id of the location
    /// return NULL if has multiple ids or no id at all.
    const CSeq_id* GetId(void) const;

    /// check that the 'id' field in all parts of the location is the same
    /// as the specifies id.
    /// if the id parameter is NULL will return the location's id (if unique)
    /// @return true on success
    bool CheckId(const CSeq_id*& id, bool may_throw = true) const;
    void InvalidateIdCache(void) const;

    /// set the 'id' field in all parts of this location
    void SetId(CSeq_id& id); // stores id
    void SetId(const CSeq_id& id); // stores a new copy of id

    /// Combine invalidation of all cached values
    void InvalidateCache(void) const;

    /// Override Assign() to incorporate cache invalidation.
    virtual void Assign(const CSerialObject& source,
                        ESerialRecursionMode how = eRecursive);

    /// Override all setters to incorporate cache invalidation.
    void         SetNull(void);
    void         SetEmpty(TEmpty& v);
    TEmpty&      SetEmpty(void);
    void         SetWhole(TWhole& v);
    TWhole&      SetWhole(void);
    void         SetInt(TInt& v);
    TInt&        SetInt(void);
    void         SetPacked_int(TPacked_int& v);
    TPacked_int& SetPacked_int(void);
    void         SetPnt(TPnt& v);
    TPnt&        SetPnt(void);
    void         SetPacked_pnt(TPacked_pnt& v);
    TPacked_pnt& SetPacked_pnt(void);
    void         SetMix(TMix& v);
    TMix&        SetMix(void);
    void         SetEquiv(TEquiv& v);
    TEquiv&      SetEquiv(void);
    void         SetBond(TBond& v);
    TBond&       SetBond(void);
    void         SetFeat(TFeat& v);
    TFeat&       SetFeat(void);

    /// Invalidate id/range cache after deserialization.
    void PostRead(void) const;

    /// Compare locations.
    int Compare(const CSeq_loc& loc) const;

    /// Used as a helper for determining which pieces of a
    /// CSeq_loc to compare.
    class ISubLocFilter {
    public:
        virtual ~ISubLocFilter() {}
        // Returns true for pieces we should use.
        // Must be able to handle "NULL" input
        virtual bool operator()( const CSeq_id *id ) const = 0;
    };

    /// Compare first-level sub-locations sequentially to order them
    /// by biological "complexity". More "complex" location will come last.
    /// Sub-locations are checked in Seq-loc-mix and Packed-seqint.
    /// Minus strand locations' order is reversed.
    /// Seq-ids are not checked in this method, unless you set
    /// filter, which will allow the user to pick which parts to skip.
    int CompareSubLoc(const CSeq_loc& loc, ENa_strand strand, 
        const ISubLocFilter *filter = NULL) const;

    /// Simple adding of seq-locs.
    void Add(const CSeq_loc& other);

    void ChangeToMix(void);
    /// Works only if location is currently an interval, point,
    /// packed-int (handled trivially), or a mix built recursively from these.
    void ChangeToPackedInt(void);

    /// CSeq_loc operations
    ///
    /// Flags for operations:
    /// fStrand_Ignore - if set, strands will be ignored and any ranges
    /// may be merged/sorted. If not set, ranges on plus and minus strands
    /// are treated as different sub-sets. In some operations strand may
    /// still be checked (see fMerge_Abutting and order of ranges).
    ///
    /// NOTE: merge flags do not sort ranges, so only overlaps bewtween
    /// neighbor ranges can be detected. To merge all overlappig ranges
    /// add fSort flag. The only exception is fSortAndMerge_All which
    /// already includes fSort;
    ///
    /// fMerge_Contained - merges (removes) any range which is completely
    /// contained in another range.
    /// fMerge_Abutting - merge abutting ranges. Also forces merging of
    /// contained ranges. Even if fStrand_Ignore is set, only the ranges
    /// with the correct order are merged (e.g. loc2.to == loc1.from must be
    /// true if loc1.strand is minus).
    /// fMerge_Overlapping - merge overlapping ranges. Also forces merging of
    /// contained ranges.
    /// fMerge_All - merge any ranges if possible (contained, overlapping,
    /// abutting). The flag does not force sorting, so only neighbor ranges
    /// can be merged. To sort ranges before merging add fSort flag or use
    /// fSortAndMerge_All.
    /// fSortAndMerge_All - combination of fSort and fMerge_All.
    /// fMerge_SingleRange - creates a single range, covering all original ranges.
    /// Strand is set to the first strand in the original seq-loc, regardless of the
    /// strand flag.
    ///
    /// fSort - forces sorting of the resulting ranges. All ranges on the
    /// same ID are grouped together, but the order of IDs is undefined. Strand
    /// is reset to plus and minuns (in strand-preserve mode) or unknown (in
    /// strand-ignore mode). NULLs are always merged to a single NULL. The order
    /// of locations for each ID is: NULL, whole, empty, plus strand intervals,
    /// minus strand intervals.

    enum EOpFlags {
        fStrand_Ignore         = 1<<0,
        fMerge_Contained       = 1<<1,
        fMerge_AbuttingOnly    = 1<<2,
        fMerge_Abutting        = fMerge_AbuttingOnly | fMerge_Contained,
        fMerge_OverlappingOnly = 1<<3,
        fMerge_Overlapping     = fMerge_OverlappingOnly | fMerge_Contained,
        fMerge_All             = fMerge_Abutting | fMerge_Overlapping,
        fMerge_SingleRange     = 1<<4,
        fSort                  = 1<<5,
        fSortAndMerge_All      = fSort | fMerge_All
    };
    typedef int TOpFlags;

    /// All functions create and return a new seq-loc object.
    /// Optional synonym mapper may be provided to detect and convert
    /// synonyms of a bioseq. Length getter is used by Subtract() to
    /// calculate real sequence length.

    /// Merge ranges depending on flags, return a new seq-loc object.
    CRef<CSeq_loc> Merge(TOpFlags        flags,
                         ISynonymMapper* syn_mapper) const;

    /// Add seq-loc, merge/sort resulting ranges depending on flags.
    /// Return a new seq-loc object.
    CRef<CSeq_loc> Add(const CSeq_loc& other,
                       TOpFlags        flags,
                       ISynonymMapper* syn_mapper) const;

    /// Subtract seq-loc from this, merge/sort resulting ranges depending on
    /// flags. Return a new seq-loc object.
    CRef<CSeq_loc> Subtract(const CSeq_loc& other,
                            TOpFlags        flags,
                            ISynonymMapper* syn_mapper,
                            ILengthGetter*  len_getter) const;

    /// Find the intersection with the seq-loc, merge/sort resulting
    /// ranges depending on flags. Return a new seq-loc object.
    CRef<CSeq_loc> Intersect(const CSeq_loc& other,
                             TOpFlags        flags,
                             ISynonymMapper* syn_mapper) const;

    /// Make CSeq_loc look like an STL container
    typedef CSeq_loc_CI                  const_iterator;
    const_iterator begin(void) const;
    const_iterator end(void) const;

private:
    // Prohibit copy constructor & assignment operator
    CSeq_loc(const CSeq_loc&);
    CSeq_loc& operator= (const CSeq_loc&);

    TRange x_UpdateTotalRange(void) const;
    TRange x_CalculateTotalRangeCheckId(const CSeq_id*& id) const;
    bool x_CheckId(const CSeq_id*& id, bool may_throw = true) const;
    bool x_UpdateId(const CSeq_id*& total_id, const CSeq_id* id,
                    bool may_throw = true) const;
    void x_ChangeToMix(const CSeq_loc& other);
    void x_ChangeToPackedInt(const CSeq_interval& other);
    void x_ChangeToPackedInt(const CSeq_loc& other);
    void x_ChangeToPackedPnt(const CSeq_loc& other);

    /// Compare single-id locations, or throw an exception if any location
    /// is multi-id.
    int x_CompareSingleId(const CSeq_loc& loc, const CSeq_id* id1,
                          const CSeq_id* id2) const;

    enum {
        kDirtyCache = -2,
        kSeveralIds = -3
    };

    mutable volatile TSeqPos m_TotalRangeCacheFrom;
    mutable volatile TSeqPos m_TotalRangeCacheToOpen;
    // Seq-id for the whole seq-loc or null if multiple IDs were found
    mutable const CSeq_id* volatile m_IdCache;
};


/// Interface for mapping IDs to the best synonym. Should provide
/// GetBestSynonym() method which returns the ID which should replace
/// the original one in the destination seq-loc.
class ISynonymMapper
{
public:
    ISynonymMapper(void) {}
    virtual ~ISynonymMapper(void) {}

    virtual CSeq_id_Handle GetBestSynonym(const CSeq_id& id) = 0;
};


/// Interface for getting bioseq length. Should provide GetLength()
/// method.
class ILengthGetter
{
public:
    ILengthGetter(void) {}
    virtual ~ILengthGetter(void) {}

    virtual TSeqPos GetLength(const CSeq_id& id) = 0;
};


// Simple location structure: id/from/to
struct NCBI_SEQLOC_EXPORT SSeq_loc_CI_RangeInfo {
    SSeq_loc_CI_RangeInfo(void);
    ~SSeq_loc_CI_RangeInfo(void);

    void SetStrand(ENa_strand strand);

    typedef CSeq_loc::TRange    TRange;

    CSeq_id_Handle      m_IdHandle;
    CConstRef<CSeq_id>  m_Id;
    TRange              m_Range;
    bool                m_IsSetStrand;
    ENa_strand          m_Strand;
    CConstRef<CSeq_loc> m_Loc;
    pair<CConstRef<CInt_fuzz>, CConstRef<CInt_fuzz> > m_Fuzz;
};


class CSeq_loc_CI_Impl;

/// Seq-loc iterator class -- iterates all intervals from a seq-loc
/// in the correct order.
class NCBI_SEQLOC_EXPORT CSeq_loc_CI
{
public:
    /// Options for empty locations processing
    enum EEmptyFlag {
        eEmpty_Skip,    /// ignore empty locations
        eEmpty_Allow    /// treat empty locations as usual
    };
    enum ESeqLocOrder {
        eOrder_Positional,    /// Iterate sub-locations in positional order
        eOrder_Biological     /// Iterate sub-locations in biological order
    };
    typedef CSeq_loc::TRange TRange;

    /// constructors
    CSeq_loc_CI(void);
    CSeq_loc_CI(const CSeq_loc& loc,
                EEmptyFlag empty_flag = eEmpty_Skip,
                ESeqLocOrder order = eOrder_Biological);
    /// construct iterator at a different position in the same location
    /// @sa GetPos()
    CSeq_loc_CI(const CSeq_loc_CI& iter, size_t pos);
    /// destructor
    virtual ~CSeq_loc_CI(void);

    CSeq_loc_CI(const CSeq_loc_CI& iter);
    CSeq_loc_CI& operator= (const CSeq_loc_CI& iter);

    CSeq_loc_CI& operator++ (void);
    DECLARE_OPERATOR_BOOL(x_IsValid());

    bool operator== (const CSeq_loc_CI& iter) const;
    bool operator!= (const CSeq_loc_CI& iter) const;

    /// Location of type equiv define set of equivalent locations.
    /// Each equiv set consist of several equivalent parts.
    /// Each equiv part can contain equiv location too,
    /// so equiv sets are recursive.

    /// Return true if current position is part of a bond
    bool IsInBond(void) const;
    /// Return true if current position is A part of a bond
    bool IsBondA(void) const;
    /// Return true if current position is B part of a bond
    bool IsBondB(void) const;
    /// Return iterators that cover bond of current position
    /// result.first is the first segment in the equiv set
    /// result.second is the first segment after the equiv set
    pair<CSeq_loc_CI, CSeq_loc_CI> GetBondRange(void) const;

    /// Return true if location has equiv parts
    bool HasEquivSets(void) const;
    /// Return true if current position is in some equiv part
    bool IsInEquivSet(void) const;
    /// Return number of recursuve equiv parts current position in
    size_t GetEquivSetsCount(void) const;
    /// Return iterators that cover equiv set of current position
    /// result.first is the first segment in the equiv set
    /// result.second is the first segment after the equiv set
    /// level specify equiv set if there are more than one of them
    /// level = 0 is the smallest equiv set (innermost)
    pair<CSeq_loc_CI, CSeq_loc_CI> GetEquivSetRange(size_t level = 0) const;
    /// Return iterators that cover equiv part of current position
    /// result.first is the first segment in the equiv part
    /// result.second is the first segment after the equiv part
    /// level specify equiv set if there are more than one of them
    /// level = 0 is the smallest equiv set (innermost)
    pair<CSeq_loc_CI, CSeq_loc_CI> GetEquivPartRange(size_t level = 0) const;

    /// Get seq_id of the current location
    const CSeq_id& GetSeq_id(void) const;
    CSeq_id_Handle GetSeq_id_Handle(void) const;

    /// Get the range
    TRange         GetRange(void) const;
    /// Get strand
    bool IsSetStrand(void) const;
    ENa_strand GetStrand(void) const;

    /// Get seq-loc for the current iterator position. New CSeq_loc object may
    /// be created if the current range is a part of a packed/mixed seq-loc.
    /// The resulting seq-loc will always include only one range (which may
    /// be whole or empty).
    /// @sa GetEmbeddingSeq_loc
    CConstRef<CSeq_loc> GetRangeAsSeq_loc(void) const;

    /// Get the nearest seq-loc containing the current range.
    /// For packed/mixed locations the embedding seq-loc may
    /// include other ranges.
    /// @note Don't ever confuse it with GetRangeAsSeq_loc!
    const CSeq_loc& GetEmbeddingSeq_loc(void) const;

    /// @deprecated You probably actually wanted to use GetRangeAsSeq_loc
    /// or GetEmbeddingSeq_loc instead.
    NCBI_DEPRECATED const CSeq_loc& GetSeq_loc(void) const;

    // Return null if non-fuzzy 
    const CInt_fuzz* GetFuzzFrom(void) const;
    const CInt_fuzz* GetFuzzTo  (void) const;

    /// True if the current location is a whole sequence
    bool           IsWhole(void) const;
    /// True if the current location is empty
    bool           IsEmpty(void) const;
    /// True if the current location is a single point
    bool           IsPoint(void) const;

    /// Reset the iterator to the initial state
    void Rewind(void);

    /// Get number of ranges.
    size_t GetSize(void) const;

    /// Get iterator's position.
    size_t GetPos(void) const;

    /// Set iterator's position.
    void SetPos(size_t pos);

protected:
    const SSeq_loc_CI_RangeInfo& x_GetRangeInfo(void) const;

    CRef<CSeq_loc_CI_Impl> m_Impl;

    // Check the iterator position
    bool x_IsValid(void) const;
    // Check the position, throw exception if not valid
    virtual const char* x_GetIteratorType(void) const;
    void x_CheckValid(const char* where) const;
    void x_ThrowNotValid(const char* where) const;

    size_t m_Index;
};


/// Seq-loc iterator class -- iterates all intervals from a seq-loc
/// in the correct order.
class NCBI_SEQLOC_EXPORT CSeq_loc_I : public CSeq_loc_CI
{
public:
    /// Options for creation modified locations
    /// Bond and equiv types are preserved if possible
    enum EMakeType {
        eMake_CompactType, /// use most compact Seq-loc type (default)
        eMake_PreserveType /// keep original Seq-loc type if possible
    };

    /// constructors
    CSeq_loc_I(void);
    CSeq_loc_I(CSeq_loc& loc);
    /// construct iterator at a different position in the same location
    /// @sa GetPos()
    CSeq_loc_I(const CSeq_loc_I& iter, size_t pos);
    /// destructor
    virtual ~CSeq_loc_I(void);

    /// return true of any part was changed since initialization
    bool HasChanges(void) const;

    /// return constructed CSeq_loc with all changes
    CRef<CSeq_loc> MakeSeq_loc(EMakeType make_type = eMake_CompactType) const;

    /// Delete current element, and make iterator to point to the next element.
    /// All other iterators of the same CSeq_loc object will become invalid.
    /// If the deleted element is contained in any equiv set then the equiv set
    /// and its corresponding part will be reduced in size appropriately,
    /// and if the part and/or the set become empty after the deletion
    /// they will be removed completely.
    void Delete(void);

    /// Set of Insert*() methods.
    /// All of them insert new element before the one the iterator points to.
    /// If the iterator is at the end of CSeq_loc then the new element is
    /// inserted after the last element of the CSeq_loc.
    /// After the insertion this iterator will point to the element
    /// it was pointing before (or end), and the result iterator will point
    /// to the inserted element.
    /// All other iterators of the same CSeq_loc object will become invalid.
    /// If the insertion point is completely within an equiv set (excluding
    /// the equiv set boundary) the equiv set will be expanded appropriately.
    /// If the insertion point is completely within an equiv part (excluding
    /// the equiv part boundary) the new element is added to that equiv part.
    /// If the insertion point is between two equiv parts of the same set
    /// then the new element is appended to the part just before
    /// the insertion point.
    /// The effect of the insertion on equiv sets can be modified
    /// by calling SetEquivMode(EEquivMode).
    /// @sa SetEquivMode()
    CSeq_loc_I InsertNull(void);

    /// Insert new element before the current one (@sa InsertNull()).
    CSeq_loc_I InsertEmpty(const CSeq_id_Handle& id);
    /// Insert new element before the current one (@sa InsertNull()).
    CSeq_loc_I InsertEmpty(const CSeq_id& id)
        {
            return InsertEmpty(CSeq_id_Handle::GetHandle(id));
        }
    /// Insert new element before the current one (@sa InsertNull()).
    CSeq_loc_I InsertWhole(const CSeq_id_Handle& id);
    /// Insert new element before the current one (@sa InsertNull()).
    CSeq_loc_I InsertWhole(const CSeq_id& id)
        {
            return InsertWhole(CSeq_id_Handle::GetHandle(id));
        }

    /// Insert new element before the current one (@sa InsertNull()).
    /// The strand value eNa_strand_unknown produces strand field not set,
    /// If eNa_strand_unknown is expicitly required, call SetStrand().
    CSeq_loc_I InsertInterval(const CSeq_id_Handle& id,
                              const TRange& range,
                              ENa_strand strand = eNa_strand_unknown);
    /// Insert new element before the current one (@sa InsertNull()).
    /// The strand value eNa_strand_unknown produces strand field not set,
    /// If eNa_strand_unknown is expicitly required, call SetStrand().
    CSeq_loc_I InsertInterval(const CSeq_id& id,
                              const TRange& range,
                              ENa_strand strand = eNa_strand_unknown)
        {
            return InsertInterval(CSeq_id_Handle::GetHandle(id), range, strand);
        }
    /// Insert new element before the current one (@sa InsertNull()).
    /// The strand value eNa_strand_unknown produces strand field not set,
    /// If eNa_strand_unknown is expicitly required, call SetStrand().
    CSeq_loc_I InsertInterval(const CSeq_id& id,
                              TSeqPos from, TSeqPos to,
                              ENa_strand strand = eNa_strand_unknown)
        {
            return InsertInterval(id, TRange(from, to), strand);
        }
    /// Insert new element before the current one (@sa InsertNull()).
    /// The strand value eNa_strand_unknown produces strand field not set,
    /// If eNa_strand_unknown is expicitly required, call SetStrand().
    CSeq_loc_I InsertInterval(const CSeq_id_Handle& id,
                              TSeqPos from, TSeqPos to,
                              ENa_strand strand = eNa_strand_unknown)
        {
            return InsertInterval(id, TRange(from, to), strand);
        }

    /// Insert new element before the current one (@sa InsertNull()).
    /// The strand value eNa_strand_unknown produces strand field not set,
    /// If eNa_strand_unknown is expicitly required, call SetStrand().
    CSeq_loc_I InsertPoint(const CSeq_id_Handle& id,
                           TSeqPos pos,
                           ENa_strand strand = eNa_strand_unknown);
    /// Insert new element before the current one (@sa InsertNull()).
    /// The strand value eNa_strand_unknown produces strand field not set,
    /// If eNa_strand_unknown is expicitly required, call SetStrand().
    CSeq_loc_I InsertPoint(const CSeq_id& id,
                           TSeqPos pos,
                           ENa_strand strand = eNa_strand_unknown)
        {
            return InsertPoint(CSeq_id_Handle::GetHandle(id), pos, strand);
        }

    /// Set seq_id of the current location
    void SetSeq_id_Handle(const CSeq_id_Handle& id);
    /// Set seq_id of the current location
    void SetSeq_id(const CSeq_id& id)
        {
            SetSeq_id_Handle(CSeq_id_Handle::GetHandle(id));
        }

    /// Set the range
    void SetRange(const TRange& range);
    /// Set the range from position
    void SetFrom(TSeqPos from);
    /// Set the range to position
    void SetTo(TSeqPos to);
    /// Set the range from and to positions
    void SetPoint(TSeqPos pos);

    /// Reset the range strand
    void ResetStrand(void);
    /// Set the range strand
    void SetStrand(ENa_strand strand);

    /// Reset fuzz from
    void ResetFuzzFrom(void);
    /// Change fuzz from
    void SetFuzzFrom(CInt_fuzz& fuzz);
    /// Reset fuzz to
    void ResetFuzzTo(void);
    /// Change fuzz to values
    void SetFuzzTo(CInt_fuzz& fuzz);
    /// Reset fuzz of a point
    void ResetFuzz(void);
    /// Change fuzz of a point
    void SetFuzz(CInt_fuzz& fuzz);

    /// Return iterators that cover equiv set of current position
    /// result.first is the first segment in the equiv set
    /// result.second is the first segment after the equiv set
    /// level specify equiv set if there are more than one of them
    /// level = 0 is the smallest equiv set (innermost)
    pair<CSeq_loc_I, CSeq_loc_I> GetEquivSetRange(size_t level = 0) const;
    /// Return iterators that cover equiv part of current position
    /// result.first is the first segment in the equiv part
    /// result.second is the first segment after the equiv part
    /// level specify equiv set if there are more than one of them
    /// level = 0 is the smallest equiv set (innermost)
    pair<CSeq_loc_I, CSeq_loc_I> GetEquivPartRange(size_t level = 0) const;

    /// This enum defines a way equiv sets are expanded or created
    /// when one of Insert*() methods is called.
    enum EEquivMode {
        /// By default no equiv sets are created or expanded except
        /// if insertion point is completely inside of an equiv or its part.
        eEquiv_none,

        /// A new equiv set will be created, even if the insertion point
        /// is already inside of an existing equiv, so that new equiv set may
        /// become a sub-unit of an exisiting equiv set.
        /// The new equiv set will contain one part with the inserted element
        /// as its content.
        /// The mode will switch to eEquiv_append after the insertion.
        eEquiv_new_equiv,

        /// New equiv part will be started with the inserted element.
        /// If the insertion point is not in or near any existing equiv part
        /// then exception is thrown.
        /// If...
        /// A. the insertion point is exactly between two equiv sets
        /// then a new equiv part will be created at the end of the first set
        /// with the inserted element as its content.
        /// B. the insertion point is at a boundary of any equiv part
        /// then a new equiv part will be created at this point
        /// with the inserted element as its content.
        /// C. the insertion point is in the middle of existing part
        /// then the existing part will be split at the insertion point
        /// and new element will be added to the second part after splitting.
        /// 
        /// The mode will switch to eEquiv_append after the insertion.
        eEquiv_new_part,

        /// If the insertion point is just after any equiv part, including
        /// the last one in an equiv, then the inserted element is appended
        /// to the part, and the equiv mode will remain eEquiv_append.
        /// Otherwise the equiv mode will switch to eEquiv_none.
        /// Change the mode to eEquiv_none explicitly if you want to stop
        /// expanding existing equiv.
        eEquiv_append,

        /// If the insertion point is just before any equiv part, including
        /// the first one in an equiv, then the inserted element is prepended
        /// to the part, and the equiv mode will remain eEquiv_prepend.
        /// Otherwise the equiv mode will switch to eEquiv_none.
        /// Change the mode to eEquiv_none explicitly if you want to stop
        /// expanding existing equiv.
        eEquiv_prepend
    };
    /// Change equiv modification mode
    /// @sa InsertNull()
    void SetEquivMode(EEquivMode mode);
    /// Change equiv modification mode to add new equiv set for the next
    /// insert operation.
    /// @sa SetEquivMode()
    void StartNewEquiv(void)
        {
            SetEquivMode(eEquiv_new_equiv);
        }
    /// Change equiv modification mode to add new equiv part for the next
    /// insert operation.
    /// @sa SetEquivMode()
    void StartNewEquivPart(void)
        {
            SetEquivMode(eEquiv_new_part);
        }
    /// Change equiv modification mode to normal behavior that will only
    /// update existing equiv sets.
    /// @sa SetEquivMode()
    void StopEquiv(void)
        {
            SetEquivMode(eEquiv_none);
        }
    /// Get equiv modification mode.
    /// @sa SetEquivMode()
    EEquivMode GetEquivMode(void) const;

    /// Remove equiv set, all pieces that are part of the set will be
    /// preserved as independent pieces.
    void RemoveEquiv(size_t level = 0);
    /// Create equiv set with one part from current position to
    /// the position pointed by end_it argument exclusive.
    /// The end_it position must be after current position.
    /// If there are any conflicts with existing equiv sets or bond pairs
    /// no new equiv set will be made and an exception will be thrown.
    /// New set's level will be assigned depending on its size in relation
    /// to existing overlapping equiv sets.
    void MakeEquiv(const CSeq_loc_I& end_it);
    /// Create equiv set with one part from current position to
    /// the position pointed by end_it argument exclusive.
    /// The end_it position must be after current position.
    /// If there are any conflicts with existing equiv sets or bond pairs
    /// no new equiv set will be made and an exception will be thrown.
    void MakeEquivPartBreak(size_t level = 0);

    /// Remove bond at current position - it may be either A or B part
    void RemoveBond(void);
    /// Make bond at current position (only A)
    /// The current part must be a point
    /// If current posision is already a bond A part, it will be updated
    void MakeBondA(void);
    /// Make bond at current position with the next position (A and B)
    /// The current and next parts must be points
    /// If current posision is already a bond A part, it will be updated
    void MakeBondAB(void);
    /// Make bond at previous position with the current position (A and B)
    /// The current and previous parts must be points
    /// If previous posision is already a bond A part, it will be updated
    void MakeBondB(void);

protected:
    using CSeq_loc_CI::x_GetRangeInfo;
    SSeq_loc_CI_RangeInfo& x_GetRangeInfo(void);

    void x_SetSeq_id_Handle(SSeq_loc_CI_RangeInfo& info,
                            const CSeq_id_Handle& id);

    bool x_IsValidForInsert(void) const;
    void x_CheckValidForInsert(const char* where) const;
    virtual const char* x_GetIteratorType(void) const;
};


/////////////////// CSeq_loc inline methods

inline
void CSeq_loc::InvalidateTotalRangeCache(void) const
{
    m_TotalRangeCacheFrom = TSeqPos(kDirtyCache);
}


inline 
void CSeq_loc::InvalidateIdCache(void) const
{
    m_IdCache = NULL;
}


inline 
void CSeq_loc::InvalidateCache(void) const
{
    InvalidateTotalRangeCache();
    InvalidateIdCache();
}


// constructor
inline
CSeq_loc::CSeq_loc(void)
{
    InvalidateCache();
}


inline
CSeq_loc::TRange CSeq_loc::GetTotalRange(void) const
{
    TSeqPos range_from  = m_TotalRangeCacheFrom;
    if ( range_from == TSeqPos(kDirtyCache) ) {
        return x_UpdateTotalRange();
    }
    else {
        TSeqPos range_to_open  = m_TotalRangeCacheToOpen;
        return COpenRange<TSeqPos>(range_from, range_to_open);
    }
}


inline
bool CSeq_loc::CheckId(const CSeq_id*& id, bool may_throw) const
{
    const CSeq_id* my_id = m_IdCache;
    if ( my_id == NULL ) {
        if ( !x_CheckId(my_id, may_throw) ) {
            return false;
        }
        m_IdCache = my_id;
    }
    return x_UpdateId(id, my_id, may_throw);
}


inline
const CSeq_id* CSeq_loc::GetId(void) const
{
    const CSeq_id* sip = NULL;
    return CheckId(sip, false) ? sip : NULL;
}


inline
void CSeq_loc::SetId(const CSeq_id& id)
{
    InvalidateIdCache();
    CRef<CSeq_id> nc_id(new CSeq_id);
    nc_id->Assign(id);
    SetId(*nc_id);
    m_IdCache = nc_id.GetPointer();
}


inline
void CSeq_loc::SetNull(void)
{
    InvalidateIdCache();
    Tparent::SetNull();
}

#define DEFINE_NCBI_SEQ_LOC_SETTERS(x) \
inline                                 \
void CSeq_loc::Set##x(T##x& v)         \
{                                      \
    InvalidateCache();                 \
    Tparent::Set##x(v);                \
}                                      \
                                       \
inline                                 \
CSeq_loc::T##x& CSeq_loc::Set##x(void) \
{                                      \
    InvalidateCache();                 \
    return Tparent::Set##x();          \
}

DEFINE_NCBI_SEQ_LOC_SETTERS(Empty)
DEFINE_NCBI_SEQ_LOC_SETTERS(Whole)
DEFINE_NCBI_SEQ_LOC_SETTERS(Int)
DEFINE_NCBI_SEQ_LOC_SETTERS(Packed_int)
DEFINE_NCBI_SEQ_LOC_SETTERS(Pnt)
DEFINE_NCBI_SEQ_LOC_SETTERS(Packed_pnt)
DEFINE_NCBI_SEQ_LOC_SETTERS(Mix)
DEFINE_NCBI_SEQ_LOC_SETTERS(Equiv)
DEFINE_NCBI_SEQ_LOC_SETTERS(Bond)
DEFINE_NCBI_SEQ_LOC_SETTERS(Feat)

#undef DEFINE_NCBI_SEQ_LOC_SETTERS

inline
bool CSeq_loc::IsReverseStrand(void) const
{
    return IsReverse(GetStrand());    
}


/////////////////// end of CSeq_loc inline methods

/////////////////// CSeq_loc_CI inline methods

inline
void SSeq_loc_CI_RangeInfo::SetStrand(ENa_strand strand)
{
    m_IsSetStrand = true;
    m_Strand = strand;
}

inline
void CSeq_loc_CI::x_CheckValid(const char* where) const
{
    if ( !x_IsValid() )
        x_ThrowNotValid(where);
}

inline
CSeq_loc_CI& CSeq_loc_CI::operator++ (void)
{
    x_CheckValid("operator++");
    ++m_Index;
    return *this;
}

inline
const CSeq_id& CSeq_loc_CI::GetSeq_id(void) const
{
    x_CheckValid("GetSeq_id()");
    return *x_GetRangeInfo().m_Id;
}

inline
CSeq_id_Handle CSeq_loc_CI::GetSeq_id_Handle(void) const
{
    x_CheckValid("GetSeq_id_Handle()");
    return x_GetRangeInfo().m_IdHandle;
}

inline
CSeq_loc_CI::TRange CSeq_loc_CI::GetRange(void) const
{
    x_CheckValid("GetRange()");
    return x_GetRangeInfo().m_Range;
}

inline
bool CSeq_loc_CI::IsSetStrand(void) const
{
    x_CheckValid("IsSetStrand()");
    return x_GetRangeInfo().m_IsSetStrand;
}

inline
ENa_strand CSeq_loc_CI::GetStrand(void) const
{
    x_CheckValid("GetStrand()");
    return x_GetRangeInfo().m_Strand;
}

inline
const CInt_fuzz* CSeq_loc_CI::GetFuzzFrom(void) const
{
    x_CheckValid("GetFuzzFrom()");
    return x_GetRangeInfo().m_Fuzz.first;
}

inline
const CInt_fuzz* CSeq_loc_CI::GetFuzzTo(void) const
{
    x_CheckValid("GetFuzzTo()");
    return x_GetRangeInfo().m_Fuzz.second;
}

inline
bool CSeq_loc_CI::IsWhole(void) const
{
    x_CheckValid("IsWhole()");
    return x_GetRangeInfo().m_Range.IsWhole();
}

inline
bool CSeq_loc_CI::IsEmpty(void) const
{
    x_CheckValid("IsEmpty()");
    return x_GetRangeInfo().m_Range.Empty();
}

inline
bool CSeq_loc_CI::IsPoint(void) const
{
    x_CheckValid("IsPoint()");
    return x_GetRangeInfo().m_Range.GetLength() == 1;
}

inline
size_t CSeq_loc_CI::GetPos(void) const
{
    return m_Index;
}

inline
void CSeq_loc_CI::Rewind(void)
{
    m_Index = 0;
}

/////////////////// CSeq_loc_I inline methods

inline
void CSeq_loc_I::x_CheckValidForInsert(const char* where) const
{
    if ( !x_IsValidForInsert() )
        x_ThrowNotValid(where);
}

NCBISER_HAVE_POST_READ(CSeq_loc)

/////////////////// end of CSeq_loc_CI inline methods


/* @} */


END_objects_SCOPE // namespace ncbi::objects::
END_NCBI_SCOPE

#endif // OBJECTS_SEQLOC_SEQ_LOC_HPP
