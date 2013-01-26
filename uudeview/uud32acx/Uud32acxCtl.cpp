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

// Uud32acxCtl.cpp : Implementation of the UUDeview ActiveX Control class.

#include "stdafx.h"
#include "uud32acx.h"
#include "Uud32acxCtl.h"
#include "Uud32acxPpg.h"
#include "comdef.h"
#pragma hdrstop

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#if OCX
//
// Property Exchange Shortcut class
//

#define PD(T,VN) BOOL Pe(const char *cname, T *v, T *def = NULL) { \
	return(ExchangeProp(cname, VN, v, def)); }

class PropEx : public CPropExchange {
	public:
		PD(short, VT_I2)
		PD(long, VT_I4)
		PD(BOOL, VT_BOOL)
		PD(CString, VT_BSTR)
		PD(CY, VT_CY)
		PD(float, VT_R4)
		PD(double, VT_R8)
	};

#undef PD

IMPLEMENT_DYNCREATE(CUud32acxCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CUud32acxCtrl, COleControl)
	//{{AFX_MSG_MAP(CUud32acxCtrl)
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CUud32acxCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CUud32acxCtrl)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "FastMode", m_fastMode, OnFastModeChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "BracketPolicy", m_bracketPolicy, OnBracketPolicyChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "Verbose", m_verbose, OnVerboseChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "Desperate", m_desperate, OnDesperateChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "IgnoreReply", m_ignoreReply, OnIgnoreReplyChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "Overwrite", m_overwrite, OnOverwriteChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "OutputPath", m_outputPath, OnOutputPathChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "Dumb", m_dumb, OnDumbChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "XFileAuto", m_xFileAuto, OnXFileAutoChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "UseText", m_useText, OnUseTextChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "StrictMIME", m_strictMime, OnStrictMIMEChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "RemoveAfter", m_removeAfter, OnRemoveAfterChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "TempFolder", m_tempFolder, OnTempFolderChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CUud32acxCtrl, "StrictFilenames", m_strictFilenames, OnStrictFilenamesChanged, VT_BOOL)
	DISP_PROPERTY_EX(CUud32acxCtrl, "LibVersion", GetLibVersion, SetLibVersion, VT_BSTR)
	DISP_PROPERTY_EX(CUud32acxCtrl, "DFCount", GetDFCount, SetDFCount, VT_I2)
	DISP_PROPERTY_EX(CUud32acxCtrl, "LastMessage", GetLastMessage, SetLastMessage, VT_BSTR)
	DISP_PROPERTY_EX(CUud32acxCtrl, "XFileCount", GetXFileCount, SetXFileCount, VT_I2)
	DISP_PROPERTY_EX(CUud32acxCtrl, "Licensee", GetLicensee, SetLicensee, VT_BSTR)
	DISP_FUNCTION(CUud32acxCtrl, "Reset", Reset, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CUud32acxCtrl, "DLoad", DLoad, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CUud32acxCtrl, "DFileTo", DFileTo, VT_I4, VTS_I2 VTS_BSTR)
	DISP_FUNCTION(CUud32acxCtrl, "Encode", Encode, VT_I4, VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CUud32acxCtrl, "DRemove", DRemove, VT_EMPTY, VTS_I2)
	DISP_FUNCTION(CUud32acxCtrl, "FileFilter", FileFilter, VT_BSTR, VTS_BSTR)
	DISP_FUNCTION(CUud32acxCtrl, "QuickDecode", QuickDecode, VT_I4, VTS_BSTR VTS_BSTR VTS_BOOL)
	DISP_FUNCTION(CUud32acxCtrl, "XFileDel", XFileDel, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CUud32acxCtrl, "XFileAdd", XFileAdd, VT_BOOL, VTS_BSTR)
	DISP_FUNCTION(CUud32acxCtrl, "ClipboardFile", ClipboardFile, VT_BOOL, VTS_I4 VTS_BSTR VTS_I2)
	DISP_FUNCTION(CUud32acxCtrl, "CRC32", CRC32, VT_BOOL, VTS_BSTR VTS_PI4)
	DISP_FUNCTION(CUud32acxCtrl, "GetLastError", GLError, VT_BOOL, VTS_PI4 VTS_PBSTR)
	DISP_PROPERTY_PARAM(CUud32acxCtrl, "DFile", GetDFile, SetDFile, VT_BSTR, VTS_I2)
	DISP_PROPERTY_PARAM(CUud32acxCtrl, "DFileFlags", GetDFileFlags, SetDFileFlags, VT_I4, VTS_I2)
	DISP_PROPERTY_PARAM(CUud32acxCtrl, "DFileInfo", GetDFileInfo, SetDFileInfo, VT_BSTR, VTS_I2)
	DISP_PROPERTY_PARAM(CUud32acxCtrl, "DFileStatus", GetDFileStatus, SetDFileStatus, VT_BSTR, VTS_I2)
	DISP_PROPERTY_PARAM(CUud32acxCtrl, "DFileDetail", GetDFileDetail, SetDFileDetail, VT_VARIANT, VTS_I2 VTS_I2 VTS_I2)
	DISP_PROPERTY_PARAM(CUud32acxCtrl, "XFile", GetXFile, SetXFile, VT_BSTR, VTS_I2)
	DISP_STOCKPROP_CAPTION()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CUud32acxCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CUud32acxCtrl, COleControl)
	//{{AFX_EVENT_MAP(CUud32acxCtrl)
	EVENT_CUSTOM("Message", FireMessage, VTS_PBSTR  VTS_I2)
	EVENT_CUSTOM("Progress", FireProgress, VTS_I4  VTS_PBSTR  VTS_I2  VTS_I2  VTS_I4  VTS_I2  VTS_PBOOL)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CUud32acxCtrl, 1)
	PROPPAGEID(CUud32acxPropPage::guid)
END_PROPPAGEIDS(CUud32acxCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CUud32acxCtrl, "UUD32ACX.Uud32acxCtrl.1",
	0x6fc838a6, 0xa54a, 0x11d0, 0x89, 0x88, 0x44, 0x45, 0x53, 0x54, 0, 0)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CUud32acxCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DUud32acx =
		{ 0x6fc838a4, 0xa54a, 0x11d0, { 0x89, 0x88, 0x44, 0x45, 0x53, 0x54, 0, 0 } };
const IID BASED_CODE IID_DUud32acxEvents =
		{ 0x6fc838a5, 0xa54a, 0x11d0, { 0x89, 0x88, 0x44, 0x45, 0x53, 0x54, 0, 0 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwUud32acxOleMisc =
	OLEMISC_INVISIBLEATRUNTIME |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CUud32acxCtrl, IDS_UUD32ACX, _dwUud32acxOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CUud32acxCtrl::CUud32acxCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CUud32acxCtrl

BOOL CUud32acxCtrl::CUud32acxCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_UUD32ACX,
			IDB_UUD32ACX,
			afxRegApartmentThreading,
			_dwUud32acxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}
#endif							// OCX

/////////////////////////////////////////////////////////////////////////////
// CUud32acxCtrl::CUud32acxCtrl - Constructor

CUud32acxCtrl::CUud32acxCtrl()
{

#if OCX
	InitializeIIDs(&IID_DUud32acx, &IID_DUud32acxEvents);

	SetInitialSize(38, 38);
#endif

	infovalid = false;

	info_buffer = NULL;

	uCache = NULL;
	uCacheValid = false;

	m_fastMode = 0;
	m_bracketPolicy = 0;
	m_verbose = 0;
	m_desperate = 0;
	m_ignoreReply = 0;
	m_overwrite = 0;
	m_dumb = 0;
	m_xFileAuto = 0;
	m_useText = 0;
	m_strictMime = 0;
	m_removeAfter = 0;
	m_strictFilenames = 0;

}


/////////////////////////////////////////////////////////////////////////////
// CUud32acxCtrl::~CUud32acxCtrl - Destructor

CUud32acxCtrl::~CUud32acxCtrl()
{
	if (m_xFileAuto)
		XFileDel();				// User requested Auto Delete

	if (info_buffer != NULL)
		free(info_buffer);			// Destroy the info_buffer

	if (uCache != NULL)
		delete [] uCache;
}


#if OCX
/////////////////////////////////////////////////////////////////////////////
// CUud32acxCtrl::OnDraw - Drawing function

void CUud32acxCtrl::OnDraw(
CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	CBitmap bitmap;
	BITMAP  bmp;
	CPictureHolder picHolder;
	CRect rcSrcBounds;

	// Load UUDeview bitmap
	bitmap.LoadBitmap(IDB_UUDBUTN);
	bitmap.GetObject(sizeof(BITMAP), &bmp);
	rcSrcBounds.right = bmp.bmWidth;
	rcSrcBounds.bottom = bmp.bmHeight;

	// Create picture and render
	picHolder.CreateFromBitmap((HBITMAP)bitmap.m_hObject, NULL, FALSE);
	picHolder.Render(pdc, rcBounds, rcSrcBounds);

}

/////////////////////////////////////////////////////////////////////////////
// CUud32acxCtrl::DoPropExchange - Persistence support

void CUud32acxCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PropEx *p = (PropEx *) pPX;
	BOOL T = TRUE, F = FALSE;
	short Z = 0;
	CString cs;

	cs.Empty();

	p->Pe("FastMode", &m_fastMode, &F);
	p->Pe("BracketPolicy", &m_bracketPolicy, &F);
	p->Pe("Verbose", &m_verbose, &F);
	p->Pe("Desperate", &m_desperate, &Z);
	p->Pe("IgnoreReply", &m_ignoreReply, &F);
	p->Pe("Overwrite", &m_overwrite, &F);
	p->Pe("OutputPath", &m_outputPath, &cs);
	p->Pe("Dumb", &m_dumb, &F);
	p->Pe("XFileAuto", &m_xFileAuto, &F);
	p->Pe("UseText", &m_useText, &F);
	p->Pe("StrictMIME", &m_strictMime, &F);
	p->Pe("RemoveAfter", &m_removeAfter, &F);
	p->Pe("TempFolder", &m_tempFolder, &cs);
	p->Pe("StrictFilenames", &m_strictFilenames, &F);

}
#endif								// OCX


/////////////////////////////////////////////////////////////////////////////
// CUud32acxCtrl::OnResetState - Reset control to default state

void CUud32acxCtrl::OnResetState()
{
#if OCX
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
#endif

uCacheValid = false;		// Cached pointer array no longer valid

if (m_xFileAuto)
	XFileDel();				// User requested Auto Delete

XFList.RemoveAll();		// Clear the X Files list

InfoClear();

UUCleanUp();

ResetVars();

}


#if OCX
/////////////////////////////////////////////////////////////////////////////
// CUud32acxCtrl::AboutBox - Display an "About" box to the user

void CUud32acxCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_UUD32ACX);
	dlgAbout.DoModal();
}



/**/
/**
*
* FExist checks to see if a file already exists.
*
* It returns TRUE if the file exists.
*
**/

bool FExist(
const char *filename)
{

if (GetFileAttributes(filename) == 0xFFFFFFFF &&	// Couldn't read attributes (good!)
	GetLastError() == ERROR_FILE_NOT_FOUND)
	return(false);					// File doesn't exist

return(true);
}
#endif


//
// uCacheBuild creates the array of uulist *'s
//

void CUud32acxCtrl::uCacheBuild(void)
{
	uulist *up, **cp;

uCacheCount = 0;

for (up=UUGlobalFileList; up != NULL; up=up->NEXT)
	uCacheCount++;					// Count the number of files

if (uCacheCount == 0) {			// Nothing in list, no point in building cache
	uCacheValid = true;
	return;
	}

if (uCache == NULL || uCacheCount >= uCacheSize) {
	if (uCache != NULL)
		delete [] uCache;			// Get rid of the old array

	uCache = new uulist *[uCacheCount + 1];	// Create the array
	uCacheSize = uCacheCount;
	}

cp = uCache;					// Point to the array of cached pointers

for (up=UUGlobalFileList; up != NULL; up=up->NEXT)
	*cp++ = up;

uCacheValid = true;

}


#if OCX
//
// Message Handler
//

void CUud32acxCtrl::MessageHandler(char *message, int level)
{

LastMessage = message;			// Stash the message for future retrieval

BSTR wrk = LastMessage.AllocSysString();	// Make a BSTR

FireMessage(&wrk, (short) level);		// Fire the event handler

}


//
// Progress Handler
//

int CUud32acxCtrl::BusyCallback(uuprogress *u)
{
	BOOL cflag = FALSE;

CString cf(u->curfile);				// Read the current file
cf.OemToAnsi();

BSTR wrk = cf.AllocSysString();			// Create a system string

FireProgress(u->action, &wrk, (short) u->partno, (short) u->numparts,
	u->fsize, (short) u->percent, &cflag);

SysFreeString(wrk);

return(cflag); 
}



//
// Alter flags
//

void CUud32acxCtrl::OnFastModeChanged() 
{

	BoundPropertyChanged(dispidFastMode);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnBracketPolicyChanged() 
{
	BoundPropertyChanged(dispidBracketPolicy);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnVerboseChanged() 
{
	BoundPropertyChanged(dispidVerbose);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnDesperateChanged() 
{

if (m_desperate < 0)			// Limit the Desperate values
	m_desperate = 0;
else if (m_desperate > 2)
	m_desperate = 2;

	BoundPropertyChanged(dispidDesperate);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnIgnoreReplyChanged() 
{
	BoundPropertyChanged(dispidIgnoreReply);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnOverwriteChanged() 
{
	BoundPropertyChanged(dispidOverwrite);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnOutputPathChanged() 
{
	BoundPropertyChanged(dispidOutputPath);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnDumbChanged() 
{
	BoundPropertyChanged(dispidDumb);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnXFileAutoChanged() 
{
	BoundPropertyChanged(dispidXFileAuto);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnUseTextChanged() 
{
	BoundPropertyChanged(dispidUseText);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnStrictMIMEChanged() 
{
	BoundPropertyChanged(dispidStrictMIME);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnRemoveAfterChanged() 
{
	BoundPropertyChanged(dispidRemoveAfter);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnTempFolderChanged() 
{
	BoundPropertyChanged(dispidTempFolder);

	SetModifiedFlag();
}

void CUud32acxCtrl::OnStrictFilenamesChanged() 
{
	BoundPropertyChanged(dispidStrictFilenames);

	SetModifiedFlag();
}

#endif									// OCX


//
// InfoList implementation
//

CUud32acxCtrl::InfoClass::InfoClass()
{

state = ILS_UNK;

}

void CUud32acxCtrl::InfoClear(void)
{
	int ub = infolist.GetUpperBound();
	InfoClass *ip = infolist.GetData();

while (ub-- > 0)
	ip++->state = InfoClass::ILS_UNK;

infovalid = true;				// Info is OK after clear

}



//
// Copy options to UUD library
//

void CUud32acxCtrl::PunchOptions(void)
{

	UUSetOption(UUOPT_FAST, m_fastMode, NULL);
	UUSetOption(UUOPT_DUMBNESS, m_dumb, NULL);
	UUSetOption(UUOPT_BRACKPOL, m_bracketPolicy, NULL);

	UUSetOption(UUOPT_VERBOSE, m_verbose, NULL);
	UUSetOption(UUOPT_DEBUG, m_verbose, NULL);

	UUSetOption(UUOPT_DESPERATE, m_desperate, NULL);
	UUSetOption(UUOPT_TINYB64, m_desperate, NULL);

	UUSetOption(UUOPT_IGNREPLY, m_ignoreReply, NULL);
	UUSetOption(UUOPT_OVERWRITE, m_overwrite, NULL);

	UUSetOption(UUOPT_USETEXT, m_useText, NULL);

	UUSetOption(UUOPT_REMOVE, m_removeAfter, NULL);
	UUSetOption(UUOPT_MOREMIME, m_strictMime, NULL);
	UUSetOption(UUOPT_STRICTFN, m_strictFilenames, NULL);

}



//
// Create a temporary file
//

char *CUud32acxCtrl::tempnam(const char *dir, const char *prefix) const
{
	char wrk[MAX_PATH], opp[MAX_PATH];
	UINT rc;

	if (dir != NULL && *dir != EOS)
		rc = GetTempFileName(dir, prefix, 0, opp);
	else if (!m_tempFolder.IsEmpty())
		rc = GetTempFileName(m_tempFolder, prefix, 0, opp);
	else
	{
		wrk[0] = EOS;
		GetTempPath(sizeof(wrk), wrk);
		rc = GetTempFileName(wrk, prefix, 0, opp);
	}

return((rc == 0) ? NULL : strdup(opp));
}

