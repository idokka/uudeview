#if !defined(AFX_UUD32ACXCTL_H__6FC838B4_A54A_11D0_8988_444553540000__INCLUDED_)
#define AFX_UUD32ACXCTL_H__6FC838B4_A54A_11D0_8988_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/*
 * This file is part of the UUDeview ActiveX Control, a powerful,
 * simple and friendly multi-part multi-file encoder/decoder
 * software component.
 *
 *	Copyright (c) 1997, 2001 by:
 *		Michael Newcomb <miken@miken.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * --> Commercial reuse is prohibited <--
 *
 */

#include "uudcpp.h"

#include <afxtempl.h>

extern bool FExist(const char *filename);

#if !defined(OCX)
#if defined(_USRDLL)
#define OCX 1
#else
#define OCX 0
#endif
#endif


typedef unsigned long crc32_t;

// Uud32acxCtl.h : Declaration of the CUud32acxCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CUud32acxCtrl : See Uud32acxCtl.cpp for implementation.

#if OCX
class CUud32acxCtrl : public COleControl, private UUDWrap
{
	DECLARE_DYNCREATE(CUud32acxCtrl)
#else
class CUud32acxCtrl : private UUDWrap
{
#endif

// Constructor
public:
	CUud32acxCtrl();
	~CUud32acxCtrl();

#if OCX
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUud32acxCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL
#else
	void OnResetState();
#endif

// Implementation
protected:
	void NewStep(void);

#if OCX
	DECLARE_OLECREATE_EX(CUud32acxCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CUud32acxCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CUud32acxCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CUud32acxCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CUud32acxCtrl)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
#endif

#if OCX
// Dispatch maps
	//{{AFX_DISPATCH(CUud32acxCtrl)
	BOOL m_fastMode;
	afx_msg void OnFastModeChanged();
	BOOL m_bracketPolicy;
	afx_msg void OnBracketPolicyChanged();
	BOOL m_verbose;
	afx_msg void OnVerboseChanged();
	short m_desperate;
	afx_msg void OnDesperateChanged();
	BOOL m_ignoreReply;
	afx_msg void OnIgnoreReplyChanged();
	BOOL m_overwrite;
	afx_msg void OnOverwriteChanged();
	CString m_outputPath;
	afx_msg void OnOutputPathChanged();
	BOOL m_dumb;
	afx_msg void OnDumbChanged();
	BOOL m_xFileAuto;
	afx_msg void OnXFileAutoChanged();
	BOOL m_useText;
	afx_msg void OnUseTextChanged();
	BOOL m_strictMime;
	afx_msg void OnStrictMIMEChanged();
	BOOL m_removeAfter;
	afx_msg void OnRemoveAfterChanged();
	CString m_tempFolder;
	afx_msg void OnTempFolderChanged();
	BOOL m_strictFilenames;
	afx_msg void OnStrictFilenamesChanged();
	afx_msg BSTR GetLibVersion();
	afx_msg void SetLibVersion(LPCTSTR lpszNewValue);
	afx_msg short GetDFCount();
	afx_msg void SetDFCount(short nNewValue);
	afx_msg BSTR GetLastMessage();
	afx_msg void SetLastMessage(LPCTSTR lpszNewValue);
	afx_msg short GetXFileCount();
	afx_msg void SetXFileCount(short nNewValue);
	afx_msg BSTR GetLicensee();
	afx_msg void SetLicensee(LPCTSTR lpszNewValue);
	afx_msg void Reset();
	afx_msg long DLoad(LPCTSTR file2load);
	afx_msg long DFileTo(short row, LPCTSTR toname);
	afx_msg long Encode(LPCTSTR InFileName, LPCTSTR OutFileName, LPCTSTR NameInFile, long EncodeMode, long LinesPerFile, long Headers, const VARIANT FAR& DestAddr, const VARIANT FAR& FromAddr, const VARIANT FAR& Subject);
	afx_msg void DRemove(short row);
	afx_msg BSTR FileFilter(LPCTSTR FileName);
	afx_msg long QuickDecode(LPCTSTR File2Decode, LPCTSTR OutputPath, BOOL XFile);
	afx_msg BOOL XFileDel();
	afx_msg BOOL XFileAdd(LPCTSTR File2Add);
	afx_msg BOOL ClipboardFile(long hWnd, LPCTSTR Filename, short CFMode);
	afx_msg BOOL CRC32(LPCTSTR Filename, long FAR* crc);
	afx_msg BOOL GLError(long FAR* errNo, BSTR FAR* errMessage);
	afx_msg BSTR GetDFile(short row);
	afx_msg void SetDFile(short row, LPCTSTR lpszNewValue);
	afx_msg long GetDFileFlags(short row);
	afx_msg void SetDFileFlags(short row, long nNewValue);
	afx_msg BSTR GetDFileInfo(short row);
	afx_msg void SetDFileInfo(short row, LPCTSTR lpszNewValue);
	afx_msg BSTR GetDFileStatus(short row);
	afx_msg void SetDFileStatus(short row, LPCTSTR lpszNewValue);
	afx_msg VARIANT GetDFileDetail(short row, short SelectInfo, short SubIndex);
	afx_msg void SetDFileDetail(short row, short SelectInfo, short SubIndex, const VARIANT FAR& newValue);
	afx_msg BSTR GetXFile(short row);
	afx_msg void SetXFile(short row, LPCTSTR lpszNewValue);
	//}}AFX_DISPATCH
#else							// Not making OCX
public:
	CWnd *owner;				// Used for message transmissions
	int cancelFlag;				// Cancel...

	BOOL m_fastMode;
	BOOL m_bracketPolicy;
	BOOL m_verbose;
	short m_desperate;
	BOOL m_ignoreReply;
	BOOL m_overwrite;
	CString m_outputPath;
	BOOL m_dumb;
	BOOL m_xFileAuto;
	BOOL m_useText;
	BOOL m_strictMime;
	BOOL m_removeAfter;
	BOOL m_strictFilenames;

	CString m_tempFolder;

	afx_msg CString GetLibVersion();
	afx_msg void SetLibVersion(LPCTSTR lpszNewValue);

	afx_msg short GetDFCount();
	afx_msg void SetDFCount(short nNewValue);

	afx_msg CString GetLastMessage();
	afx_msg void SetLastMessage(LPCTSTR lpszNewValue);

	afx_msg short GetXFileCount();
	afx_msg void SetXFileCount(short nNewValue);

	afx_msg void Reset();

	afx_msg long DLoad(LPCTSTR file2load);

	afx_msg long DFileTo(short row, LPCTSTR toname);

	afx_msg long Encode(LPCTSTR InFileName, LPCTSTR OutFileName, LPCTSTR NameInFile, long EncodeMode, long LinesPerFile, long Headers, const VARIANT FAR& DestAddr, const VARIANT FAR& FromAddr, const VARIANT FAR& Subject);

	afx_msg void DRemove(short row);

	afx_msg CString FileFilter(LPCTSTR FileName);

	afx_msg long QuickDecode(LPCTSTR File2Decode, LPCTSTR OutputPath, BOOL XFile);

	afx_msg BOOL XFileDel();

	afx_msg BOOL XFileAdd(LPCTSTR File2Add);

	afx_msg BOOL ClipboardFile(long hWnd, LPCTSTR Filename, short CFMode);

	afx_msg CString GetDFile(short row);
	afx_msg void SetDFile(short row, LPCTSTR lpszNewValue);

	afx_msg long GetDFileFlags(short row);
	afx_msg void SetDFileFlags(short row, long nNewValue);

	afx_msg CString GetDFileInfo(short row);
	afx_msg void SetDFileInfo(short row, LPCTSTR lpszNewValue);

	afx_msg CString GetDFileStatus(short row);
	afx_msg void SetDFileStatus(short row, LPCTSTR lpszNewValue);

//	afx_msg VARIANT GetDFileDetail(short row, short SelectInfo, short SubIndex);
//	afx_msg void SetDFileDetail(short row, short SelectInfo, short SubIndex, const VARIANT FAR& newValue);

	afx_msg CString GetXFile(short row);
	afx_msg void SetXFile(short row, LPCTSTR lpszNewValue);
#endif

#if OCX
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CUud32acxCtrl)
	void FireMessage(BSTR FAR* Message, short Level)
		{FireEvent(eventidMessage,EVENT_PARAM(VTS_PBSTR  VTS_I2), Message, Level);}
	void FireProgress(long CurrentAction, BSTR FAR* CurrentFile, short PartNo, short TotalParts, long CurrentFileSize, short Percent, BOOL FAR* Cancel)
		{FireEvent(eventidProgress,EVENT_PARAM(VTS_I4  VTS_PBSTR  VTS_I2  VTS_I2  VTS_I4  VTS_I2  VTS_PBOOL), CurrentAction, CurrentFile, PartNo, TotalParts, CurrentFileSize, Percent, Cancel);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()


// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CUud32acxCtrl)
	dispidLibVersion = 15L,
	dispidDFCount = 16L,
	dispidFastMode = 1L,
	dispidBracketPolicy = 2L,
	dispidVerbose = 3L,
	dispidDesperate = 4L,
	dispidIgnoreReply = 5L,
	dispidOverwrite = 6L,
	dispidOutputPath = 7L,
	dispidLastMessage = 17L,
	dispidDumb = 8L,
	dispidXFileCount = 18L,
	dispidXFileAuto = 9L,
	dispidUseText = 10L,
	dispidLicensee = 19L,
	dispidStrictMIME = 11L,
	dispidRemoveAfter = 12L,
	dispidTempFolder = 13L,
	dispidStrictFilenames = 14L,
	dispidReset = 20L,
	dispidDLoad = 21L,
	dispidDFile = 32L,
	dispidDFileFlags = 33L,
	dispidDFileTo = 22L,
	dispidDFileInfo = 34L,
	dispidDFileStatus = 35L,
	dispidEncode = 23L,
	dispidDRemove = 24L,
	dispidDFileDetail = 36L,
	dispidFileFilter = 25L,
	dispidQuickDecode = 26L,
	dispidXFileDel = 27L,
	dispidXFile = 37L,
	dispidXFileAdd = 28L,
	dispidClipboardFile = 29L,
	dispidCRC32 = 30L,
	dispidGetLastError = 31L,
	eventidMessage = 1L,
	eventidProgress = 2L,
	//}}AFX_DISP_ID
	};
#endif

// My Stuff
public:
	int UUInfoHandler(void *opaque, char *uugen_inbuffer);

	void MessageHandler(char *message, int level);
	int BusyCallback(uuprogress *);

	void InfoClear(void);			// Dump the Info list

	class InfoClass {		// Master Information List
		public:
			InfoClass();
			CString info;
			enum {
				ILS_UNK,			// Info unknown
				ILS_NO,				// No info
				ILS_YES				// Yes, there is info
				} state;
		};

	CArray<InfoClass, InfoClass&> infolist; // The information list

	bool infovalid;			// Info list is valid

	char *info_buffer;		// Info accumulator
	char *info_pointer;		// Point into the accumulator buffer

	int AppendInfo(const char *inbuf);		// Append to the Info buffer

	CString LastMessage;	// The last message from the library

	bool uCacheValid;
	uulist **uCache;		// Array of cached uulist pointers
	short uCacheSize;		// Current size of cache array
	short uCacheCount;		// Number of items in array

	void uCacheBuild(void);	// Create the UUlist * cache

	inline uulist *GetUulp(short row) {		// Get a uulist pointer
		if (!uCacheValid)
			uCacheBuild();

		return((row < 0 || row >= uCacheCount) ? NULL : uCache[row]);
		}

	void PunchOptions(void);	// Copy the options to UUDeview library

	char *tempnam(const char *dir, const char *prefix) const; 	// Create a temporary filename

#if OCX
	inline bool DesignMode(void) { return(AmbientUserMode() == 0); }	// We are in design mode
#endif

	CStringList XFList;			// List of files to delete

#if !OCX
public:
	inline bool DesignMode() { return(false); }
	inline void GetNotSupported() { }
	inline void SetNotSupported() { }

	void ThrowError(int estat, int estring) { }

//
// Enums from UUD32acx control

enum {			// Message types
	uudMsgMessage = 0,	/* just a message, nothing important */
	uudMsgNote = 1,		/* something that should be noticed */
	uudMsgWarning =	2,	/* important msg, processing continues */
	uudMsgError = 3,	/* processing has been terminated */
	uudMsgFatal = 4,	/* decoder cannot process further requests */
	uudMsgPanic = 5		/* recovery impossible, app must terminate */
	};

enum {			// Return Codes
	uudRetOK = 0,		/* everything went fine */
	uudRetIOErr = 1,	/* I/O Error - examine errno */
	uudRetNoMem = 2,	/* not enough memory */
	uudRetIllVal = 3,	/* illegal value for operation */
	uudRetNoData = 4,	/* decoder didn't find any data */
	uudRetNoEnd = 5,	/* encoded data wasn't ended properly */
	uudRetUnsup = 6,	/* unsupported function encoding */
	uudRetExists = 7,	/* file exists decoding */
//		uudRetCont = 8,		/* continue -- special from ScanPart */
	uudRetCancel = 9	/* operation canceled */
	};

enum {				// File Status Mask
	uudFileRead = 0,		/* Read in, but not further processed */
	uudFileMisPart = 1,		/* Missing Parts detected */
	uudFileNoBegin = 2,		/* No 'begin' found */
	uudFileNoEnd = 4,		/* No 'end' found */
	uudFileNoData = 8,		/* File does not contain valid uudata */
	uudFileOK = 16,			/* All Parts found, ready to decode */
	uudFileError = 32,		/* Error while decoding */
	uudFileDecoded = 64,	/* Successfully decoded */
	uudFileTmpFile = 128,	/* Temporary decoded file exists */
	uudFileGenFn = 256
	};

enum {			// Action codes
	uudActIdle = 0,		/* we don't do anything */
	uudActScanning = 1,	/* scanning an input file */
	uudActDecoding = 2,	/* decoding into a temp file */
	uudActCopying = 3,	/* copying temp to target */
	uudActEncoding = 4,	/* encoding a file */
	uudActNewStep = 9
	};

enum {				// DFileDetail constants
	uudLDState = 0,			// uulist.state
	uudLDMode = 1,			// uulist.mode
	uudLDBegin = 2,			// uulist.begin
	uudLDEnd = 3,			// uulist.end
	uudLDUuDet = 4,			// uulist.uudet
	uudLDFlags = 5,			// uulist.flags
	uudLDSize = 6,			// uulist.size
	uudLDFileName = 7,		// uulist.filename
	uudLDSubF = 8,			// uulist.subfname
	uudLDMIMEID = 9,		// uulist.mimeid
	uudLDMIMEType = 10,		// uulist.mimetype
	uudLDBinFile = 11,		// uulist.binfile
	uudLDHavePart = 12,		// uulist.haveparts[subscr]
	uudLDMissPart = 13,		// uulist.msparts[subscr]
	uudLDUFPart = 14,		// uulist.thisfile[subscr].partno
	uudLDUFrSubj = 15,		// uulist.thisfile[subscr].data.subject
	uudLDUFrOrg = 16,		// uulist.thisfile[subscr].data.origin
	uudLDUFrSFN = 17,		// uulist.thisfile[subscr].data.sfname
	uudLDUFrStart = 18,		// uulist.thisfile[subscr].data.startpos
	uudLDUFrLength = 19,	// uulist.thisfile[subscr].data.length
	uudLDUFrCount = 20		// Number of subparts
	};

enum {				// Encoding mode constants
	uudEncUU = 1,	/* UUencoded data   */
	uudEncB64 = 2,	/* Mime-Base64 data */
	uudEncXX = 3,	/* XXencoded data   */
	uudEncBinHex = 4,	/* Binhex encoded   */
	uudEncPlainText = 5,	/* Plain-Text encoded (MIME) */
	uudEncQuotedPrintable = 6,	/* Quoted-Printable (MIME)   */
	uudEncyEnc = 7	// yEnc
	};

enum {				// Encoding mode constants
	uudEncHUud = 0,		// No MIME headers (use standard headers)
	uudEncHSimple = 1,		// Simple MIME (no addressing)
	uudEncHMail = 2,		// MIME E-mail format
	uudEncHNews = 3		// MIME News format
	};

enum {				// Encoding mode constants
	uudCFcff = 0,
	uudCFc2nf = 1,
	uudCFac2f = 2
	};

#if !defined(IDS_BADFLS)
#define IDS_BADFLS	0
#define IDS_OOM		0
#endif

#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUD32ACXCTL_H__6FC838B4_A54A_11D0_8988_444553540000__INCLUDED)
