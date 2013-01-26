/*
 * This file is part of the UUDeview ActiveX Control, a powerful,
 * simple and friendly multi-part multi-file encoder/decoder
 * software component.
 *
 *	Copyright (c) 1997, 2001 by:
 *		Michael Newcomb <miken@miken.com>
 *		Frank Pilhofer	<fp@informatik.uni-frankfurt.de>
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

// UUEngine.cpp : Implementation of CUUEngine
#include "stdafx.h"
#include "UudATL.h"
#include "UUEngine.h"
#include "..\uud32acx\mapdfile.h"

// UUVBListData control items (see uudeview.h)
#define UUVBLD_STATE	0		// uulist.state
#define UUVBLD_MODE		1		// uulist.mode
#define UUVBLD_BEGIN	2		// uulist.begin
#define UUVBLD_END		3		// uulist.end
#define UUVBLD_UUDET	4		// uulist.uudet
#define UUVBLD_FLAGS	5		// uulist.flags
#define UUVBLD_SIZE		6		// uulist.size
#define UUVBLD_FILEN	7		// uulist.filename
#define UUVBLD_SUBF		8		// uulist.subfname
#define UUVBLD_MIMEID	9		// uulist.mimeid
#define UUVBLD_MIMETYPE	10		// uulist.mimetype
#define UUVBLD_BINFILE	11		// uulist.binfile
#define UUVBLD_HAVEPART	12		// uulist.haveparts[subscr]
#define UUVBLD_MISSPART 13		// uulist.msparts[subscr]
#define UUVBLD_UFPART	14		// uulist.thisfile[subscr].partno
#define UUVBLD_UFRSUBJ	15		// uulist.thisfile[subscr].data.subject
#define UUVBLD_UFRORG	16		// uulist.thisfile[subscr].data.origin
#define UUVBLD_UFRSFN	17		// uulist.thisfile[subscr].data.sfname
#define UUVBLD_UFRSTART	18		// uulist.thisfile[subscr].data.start
#define UUVBLD_UFRLEN	19		// uulist.thisfile[subscr].data.length
#define UUVBLD_UFRCOUNT	20		// Number of parts this files has

#define UUVBLD_MAX		20			// Largest possible FileDetail value


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

int main(int argc, char *argv[])
{

return(0);
}


//
// Callbacks for progress and messages
//

static void cbMessage(void *opaque, const char *message, int level)
{
	((CUUEngine *) opaque)->Fire_Message(CComBSTR(message), level);
}


static int cbProgress(void *opaque, uuprogress *u)
{
	BOOL cflag = FALSE;

	((CUUEngine *) opaque)->Fire_Progress(u->action, CComBSTR(u->curfile), 
		(short) u->partno, (short) u->numparts,
		u->fsize, (short) u->percent, &cflag);

return(cflag);
}


/////////////////////////////////////////////////////////////////////////////
// CUUEngine

CUUEngine::CUUEngine()
{

	OWriteOK = false;
	XF_AutoDel = false;

	ue.SetCallbacks(this, cbMessage, cbProgress);

	XFList = NULL;

}


CUUEngine::~CUUEngine()
{

	if (XF_AutoDel)
	{
		BOOL flg = FALSE;

		XFileDel(&flg);
	}
	else
	{
		XFL *xp, *nxp;

		for (xp=XFList; xp != NULL; xp=nxp)
		{
			nxp = xp->next;

			delete xp;
		}
	}

}
	
	
STDMETHODIMP CUUEngine::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IUUEngine
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}



//
// Properties that are get or set to the engine
//

STDMETHODIMP CUUEngine::get_BracketPolicy(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_BRACKPOL);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_BracketPolicy(BOOL newVal)
{

	SetBoolProp(UUOPT_BRACKPOL, newVal);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_Desperate(short *pVal)
{
	*pVal = GetBoolProp(UUOPT_DESPERATE);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_Desperate(short newVal)
{
	SetBoolProp(UUOPT_DESPERATE, newVal);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_Dumb(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_DUMBNESS);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_Dumb(BOOL newVal)
{
	SetBoolProp(UUOPT_DUMBNESS, newVal);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_FastMode(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_FAST);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_FastMode(BOOL newVal)
{
	SetBoolProp(UUOPT_FAST, newVal);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_IgnoreReply(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_IGNREPLY);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_IgnoreReply(BOOL newVal)
{
	SetBoolProp(UUOPT_IGNREPLY, newVal);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_Overwrite(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_OVERWRITE);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_Overwrite(BOOL newVal)
{
	SetBoolProp(UUOPT_OVERWRITE, newVal);

	OWriteOK = (newVal != 0);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_RemoveAfter(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_REMOVE);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_RemoveAfter(BOOL newVal)
{
	SetBoolProp(UUOPT_REMOVE, newVal);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_StrictMIME(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_MOREMIME);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_StrictMIME(BOOL newVal)
{
	SetBoolProp(UUOPT_MOREMIME, newVal);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_UseText(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_USETEXT);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_UseText(BOOL newVal)
{
	SetBoolProp(UUOPT_USETEXT, newVal);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_Verbose(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_VERBOSE);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_Verbose(BOOL newVal)
{
	SetBoolProp(UUOPT_VERBOSE, newVal);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_XFileAuto(BOOL *pVal)
{
	*pVal = XF_AutoDel;

	return S_OK;
}

STDMETHODIMP CUUEngine::put_XFileAuto(BOOL newVal)
{
	XF_AutoDel = (newVal != 0);

	return S_OK;
}



STDMETHODIMP CUUEngine::get_OutputPath(BSTR *pVal)
{
	MString wrk;

	ue.UUGetOption(UUOPT_SAVEPATH, NULL, wrk.GetBuffer(MAX_PATH + 4), MAX_PATH);

	wrk.ToBSTR(pVal);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_OutputPath(BSTR newVal)
{
	MString wrk(newVal);

	ue.UUSetOption(UUOPT_SAVEPATH, 0, wrk.GetBuffer());

	return S_OK;
}



STDMETHODIMP CUUEngine::get_LastMessage(BSTR *pVal)
{
	LastMessage.ToBSTR(pVal);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_LastMessage(BSTR newVal)
{
	LastMessage = newVal;

	return S_OK;
}



STDMETHODIMP CUUEngine::get_StrictFilenames(BOOL *pVal)
{
	*pVal = GetBoolProp(UUOPT_STRICTFN);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_StrictFilenames(BOOL newVal)
{
	SetBoolProp(UUOPT_STRICTFN, newVal);

	return S_OK;
}



//
// Read the library version
//

STDMETHODIMP CUUEngine::get_LibVersion(BSTR *pVal)
{
	MString wrk;

	ue.UUGetOption(UUOPT_VERSION, NULL, wrk.GetBuffer(), MSTRING_DLEN);

	wrk += " " __DATE__ " " __TIME__;

	wrk.ToBSTR(pVal);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_LibVersion(BSTR newVal)
{
	return(CTL_E_SETNOTSUPPORTED);
}




//
// Destination file
//

STDMETHODIMP CUUEngine::get_DFile(short row, BSTR *pVal)
{
	uulist *up = ue.GetUulp(row);
	MString res;

	if (up == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	res = (up->filename == NULL || (up->state & UUFILE_NODATA)) ? 
			"(No Data)" : up->filename;

	res.ToBSTR(pVal);

return S_OK;
}

STDMETHODIMP CUUEngine::put_DFile(short row, BSTR newVal)
{
	uulist *up = ue.GetUulp(row);

	if (up == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	MString wrk(newVal);

	ue.UURenameFile(up, wrk.GetBuffer());

	return S_OK;
}



//
// Decoded file count
//

STDMETHODIMP CUUEngine::get_DFCount(short *pVal)
{
	*pVal = ue.GetCacheCount();

	return S_OK;
}

STDMETHODIMP CUUEngine::put_DFCount(short newVal)
{
	return(CTL_E_SETNOTSUPPORTED);
}



//
// Decoded file flags
//

STDMETHODIMP CUUEngine::get_DFileFlags(short row, long *pVal)
{
	uulist *up = ue.GetUulp(row);

	if (up == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	long rc = up->state;				// Starting state

	if (up->filename == NULL)
		rc |= UUFILE_NODATA;			// No data in file

	if (up->thisfile != NULL && up->thisfile->data != NULL && up->thisfile->data->genfn)
		rc |= UUFILE_GENFN;				// Generated file

	*pVal = rc;

	return S_OK;
}

STDMETHODIMP CUUEngine::put_DFileFlags(short row, long newVal)
{
	uulist *up = ue.GetUulp(row);

	if (up == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	up->state = (short) newVal;

	return S_OK;
}



//
// Temporary folder control
//

STDMETHODIMP CUUEngine::get_TempFolder(BSTR *pVal)
{
	ue.temp_folder.ToBSTR(pVal);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_TempFolder(BSTR newVal)
{
	ue.temp_folder = newVal;

	return S_OK;
}



//
// Read file detail
//

STDMETHODIMP CUUEngine::get_DFileDetail(short row, short itemno, short subscr, VARIANT *pVal)
{
	MString cs;
	CComVariant lv;
	int *ip;
	struct _uufile *ufp;
	long lct;

	uulist *l = ue.GetUulp(row);

	if (l == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	switch (itemno) {
		case UUVBLD_STATE:
			lv = l->state;
			break;

		case UUVBLD_MODE:
			lv = l->mode;
			break;

		case UUVBLD_BEGIN:
			lv = (short) l->begin;
			break;

		case UUVBLD_END:
			lv = (short) l->end;
			break;

		case UUVBLD_UUDET:
			lv = l->uudet;
			break;

		case UUVBLD_FLAGS:
			lv = (short) l->flags;
			break;

		case UUVBLD_SIZE:
			lv = l->size;
			break;

		case UUVBLD_FILEN:
			cs = l->filename;
			break;

		case UUVBLD_SUBF:
			cs = l->subfname;
			break;

		case UUVBLD_MIMEID:
			cs = l->mimeid;
			break;

		case UUVBLD_MIMETYPE:
			cs = l->mimetype;
			break;

		case UUVBLD_BINFILE:
			cs = l->binfile;
			break;

		case UUVBLD_HAVEPART:
		case UUVBLD_MISSPART:
			if (subscr < 0 || subscr > 255)
				return(CTL_E_INVALIDPROPERTYARRAYINDEX);

			ip = ((itemno == UUVBLD_HAVEPART) ? l->haveparts : l->misparts)
				+ subscr;

			if (IsBadReadPtr(ip, sizeof(int)))
				return(CTL_E_INVALIDPROPERTYARRAYINDEX);

			lv = (short) *ip;
			break;

		case UUVBLD_UFPART:
			if (subscr < 0 || subscr > 255)
				return(CTL_E_INVALIDPROPERTYARRAYINDEX);

			for (ufp=l->thisfile; ufp != NULL && subscr > 0; subscr--)
				ufp = ufp->NEXT;

			if (ufp == NULL)
				return(CTL_E_INVALIDPROPERTYARRAYINDEX);

			lv = ufp->partno;
			break;


		case UUVBLD_UFRSUBJ:
		case UUVBLD_UFRORG:
		case UUVBLD_UFRSFN:
		case UUVBLD_UFRSTART:		// uulist.thisfile[subscr].data.start
		case UUVBLD_UFRLEN:			// uulist.thisfile[subscr].data.length
			if (subscr < 0 || subscr > 255)
				return(CTL_E_INVALIDPROPERTYARRAYINDEX);

			for (ufp=l->thisfile; ufp != NULL && subscr > 0; subscr--)
				ufp = ufp->NEXT;

			if (ufp == NULL || ufp->data == NULL)
				return(CTL_E_INVALIDPROPERTYARRAYINDEX);

			switch (itemno) 
			{
				case UUVBLD_UFRSUBJ:
					cs = ufp->data->subject;
					break;

				case UUVBLD_UFRORG:
					cs = ufp->data->origin;
					break;

				case UUVBLD_UFRSFN:
					cs = ufp->data->sfname;
					break;

				case UUVBLD_UFRSTART:		// uulist.thisfile[subscr].data.start
					lv = ufp->data->startpos;
					break;

				case UUVBLD_UFRLEN:			// uulist.thisfile[subscr].data.length
					lv = ufp->data->length;
					break;
			}
			break;

		case UUVBLD_UFRCOUNT:			// Figure out the number of parts this subsection has
			lct = 0;

			ufp = l->thisfile; 

			while (ufp != NULL)
			{
				ufp = ufp->NEXT;
				lct++;
			}

			lv = lct;
			break;

		}

	if (!cs.IsEmpty()) 			// This is a string return
	{
		lv.vt = VT_BSTR;
		cs.ToBSTR(&lv.bstrVal);
	}

	lv.Copy(pVal);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_DFileDetail(short row, short itemno, short subscr, VARIANT newVal)
{
	return(CTL_E_SETNOTSUPPORTED);
}




//
// Number of files on the X Files list
//

STDMETHODIMP CUUEngine::get_XFileCount(short *pVal)
{
	short rc = 0;

	XFL *xp;

	for (xp=XFList; xp != NULL; xp=xp->next)
		rc++;

	*pVal = rc;

	return S_OK;
}

STDMETHODIMP CUUEngine::put_XFileCount(short newVal)
{
	return(CTL_E_SETNOTSUPPORTED);
}



//
// Load a file
//

STDMETHODIMP CUUEngine::DLoad(BSTR toLoad, long *retVal)
{
	ue.Invalidate();

	NewStep();					// Let the owner know we're starting a new step

	MString wrk(toLoad);

	*retVal = ue.UULoadFile(wrk.GetBuffer(), wrk.GetBuffer(), 0);

	return S_OK;
}


//
// Decode a file to someplace
//

STDMETHODIMP CUUEngine::DFileTo(short row, BSTR outn, long *retVal)
{
	uulist *ptr = ue.GetUulp(row);

	if (ptr == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	if (ptr->filename == NULL || (ptr->state & UUFILE_NODATA))
	{
		*retVal = UURET_NODATA;		// Do data to decode
		return(S_OK);
	}

	MString outname(outn);

	char *syserr;
	DWORD lasterr;
	short rc;

	NewStep();					// Let the owner know we're starting a new step

	rc = ue.UUDecode(ptr);		// Decode and get errors

	if (ptr->binfile == NULL)
		return(rc);			// Couldn't decode/create temp

	if (FExist(outname)) {	// Deal with an existing output file
		if (OWriteOK) {			// Overwriting is OK
			if (DeleteFile(outname) == FALSE) {		// Try to delete it
				MessageHandler("Could not delete existing output file", UUMSG_ERROR);
				*retVal = UURET_IOERR;
				return(S_OK);
				}
			}
		else {						// Overwriting not OK
			MessageHandler("Output file exists", UUMSG_ERROR);
			*retVal = UURET_EXISTS;
			return(S_OK);
			}
		}							// Output file doesn't exist.  OK to go.

	if (MoveFile(ptr->binfile, outname) == FALSE) {				// Something went wrong during move
		lasterr = ::GetLastError();	// Read the error code
		if (::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ARGUMENT_ARRAY,
						  NULL, lasterr, GetUserDefaultLangID(), (LPTSTR) &syserr, 0, NULL) == 0)
			MessageHandler("Unknown Error", UUMSG_ERROR);	// Couldn't convert error number to string
		else {
			MessageHandler(syserr, UUMSG_ERROR);	// Got a conversion
			LocalFree(syserr);		// Discard the error string after passing it on
			}

		*retVal = UURET_IOERR;
		return(S_OK);
		}

	free(ptr->binfile);			// Temp file is gone, wasted by MoveFile
	ptr->binfile = NULL;

	ptr->state = (ptr->state & ~UUFILE_TMPFILE) | UUFILE_DECODED;

	*retVal = rc;

	return S_OK;
}


//
// Inform watcher of new step
//

void CUUEngine::NewStep()
{

	BSTR wrk = SysAllocStringByteLen("", 0);			// Create an empty system string
	BOOL cflag = FALSE;

	Fire_Progress(UUACT_NEWSTEP, wrk, 0, 0, 0, 0, &cflag);

	SysFreeString(wrk);

}



//
// Handle messages (obviously)
//

void CUUEngine::MessageHandler(const char *message, int level)
{

	LastMessage = message;

}



//
// Get a file status
//

STDMETHODIMP CUUEngine::get_DFileStatus(short row, BSTR *pVal)
{
	MString wrk;				// Accumulator for "State"
	int testpat;
	struct state_mask {
		int maskbits;
		char *meaning;
		} *smp;
	static struct state_mask mask_list[] ={
		UUFILE_READ,	"Read in",			/* Read in, but not further processed */
		UUFILE_MISPART,	"Missing Parts",	/* Missing Part(s) detected */
		UUFILE_NOBEGIN,	"No Begin found",	/* No 'begin' found */
		UUFILE_NOEND,	"No End found",		/* No 'end' found */
		UUFILE_NODATA,	"No Data in file",	/* File does not contain valid uudata */
		UUFILE_OK,		"Ready to decode",		/* All Parts found, ready to decode */
		UUFILE_ERROR,	"Error during decoding",	/* Error while decoding */
		UUFILE_DECODED,	"Decoded OK"		/* Successfully decoded */
		};
	static char *enc_list[] ={	// Encoding list
		"UU Encoded",
		"Mime-Base64 Encoded",
		"XX Encoded",
		"BinHex Encoded",
		"Plain Text",
		"Quoted-Printable"
		};

	uulist *lup = ue.GetUulp(row);

	if (lup == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	wrk = (lup->uudet > 0) ? enc_list[lup->uudet-1] : "(No encoding)";	// Copy the encoding type

	testpat = lup->state;			// Read the Test Pattern

	smp = mask_list;				// Point to the mask list

	for (int i=(sizeof(mask_list) / sizeof(struct state_mask)); i>0; i--, smp++)
		if (testpat & smp->maskbits) {	// This state is on
			wrk += ", ";		// Add a comma
			wrk += smp->meaning;	// Append the definition
			}

	if (lup->misparts != NULL) {	// There is a missing-parts list
		bool first = true;
		char cbuf[16];

		wrk += "; Missing parts: ";
		for (int *iptr=lup->misparts; *iptr != 0; iptr++) {	// List ends with 0
			if (first)
				first = false;
			else
				wrk += ",";
			wrk +=  _itoa(*iptr, cbuf, 10);
			}
		}

	if (lup->thisfile != NULL) {	// There's a list of parts attached to this
		MString cbuf;				// Compare buffer is empty
		char *cp;
		bool first = true;

		for (uufile *ufp=lup->thisfile; ufp != NULL; ufp=ufp->NEXT)
			if (ufp->data != NULL && ufp->data->sfname != NULL) {	// Something to do.
				if (ufp->data->sfname[0] == EOS || cbuf == ufp->data->sfname)
					continue;		// We've already counted this file
				cbuf = ufp->data->sfname;
				if (first) {
					first = false;
					wrk += "; From: ";
					}
				else
					wrk += ", ";
				wrk += ((cp = strrchr(ufp->data->sfname, '\\')) != NULL) ? cp+1 : ufp->data->sfname;
				}
		}

	wrk.ToBSTR(pVal);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_DFileStatus(short row, BSTR newVal)
{
	return(CTL_E_SETNOTSUPPORTED);
}



//
// Filter out bad characters
//

STDMETHODIMP CUUEngine::FileFilter(BSTR inFile, BSTR *outFile)
{
	bool extflag = false;		// Got one extension
	const char *src;
	char *wp;
	char c, wrk[MAX_PATH + 2];
	int len;
	MString inp(inFile);

	len = lstrlen(inp);		// Read original string length

	if (len == 0)
	{
		SysReAllocString(outFile, inFile);
		return(S_OK);
	}

	if (len >= MAX_PATH)
		len = MAX_PATH;

	src = inp + len - 1;		// Point to end of incoming string data

	wp = wrk + len;						// End of work buffer
	*wp-- = EOS;

	while (len-- > 0) {
		c = *src--;						// Read one character
		if (c == '.') {					// One extension only, please
			if (!extflag) {
				*wp-- = '.';
				extflag = true;
				}
			}
		else if ((c >= 0 && c < ' ') || strchr("<>:\"|?*\'\\/", c) != NULL)
			*wp-- = '_';				// Replace unacceptables with underscore
		else
			*wp-- = c;					// Copy everything else
		}

	wp++;								// Point to first char
	while (*wp == '.')
		wp++;							// Can't begin filename with dot(s)

	inp = wp;

	inp.ToBSTR(outFile);

	return S_OK;
}


//
// Decode a single file
//

STDMETHODIMP CUUEngine::QuickDecode(BSTR File2Decode, BSTR OutputPath, BOOL XFile, long *retVal)
{
	Reset();				// Start with everything clear

	long rc;

	DLoad(File2Decode, &rc);

	if (rc != UURET_OK)	// Load the source file
	{
		*retVal = rc;
		return(S_OK);			// Couldn't load
	}

	MString prefix(OutputPath);	// Make a copy of the Output Path string

	if (prefix.IsEmpty()) 	// No prefix string supplied
		GetTempPath(256, prefix.GetBuffer(256));	// Read the temporary path

	char trail = prefix[prefix.GetLength() - 1];	// Read the last character

	if (trail != ':' && trail != '\\')	// Output path must end in slash or colon...
		prefix += "\\";			// Add the slash

	short maxIndex;
	
	get_DFCount(&maxIndex);	// Read the maximum file number

	CComBSTR tb, tb1, bP, outname;

	prefix.ToBSTR(&bP);

	for (short row=0; row < maxIndex; row++)
	{
		get_DFileFlags(row, &rc);

		if (rc & UUFILE_OK) 		// Ready to decode
		{
			get_DFile(row, &tb);
			FileFilter(tb, &tb1);

			outname = bP;
			
			outname += tb1;

			DFileTo(row, outname, &rc);

			if (rc != UURET_OK)	// Read the current 
			{
				*retVal = rc;
				return(S_OK);
			}

			put_DFile(row, outname);					// Return the full (filtered) path

			if (XFile)
			{
				if (XFList == NULL)
					XFList = new XFL(outname);
				else
					XFList->AddTail(outname);	// User wants these files added to X list
			}
		}
	}

	*retVal = UURET_OK;			// Got it!

	return S_OK;
}


//
// Reset the control
//

STDMETHODIMP CUUEngine::Reset()
{
	ue.Invalidate();			// Make sure the cache is clear

	ue.InfoClear();

	ue.UUCleanUp();

	return S_OK;
}


//
// Read the file information
//

STDMETHODIMP CUUEngine::get_DFileInfo(short row, BSTR *pVal)
{
	MString wrk;

	HRESULT hr = ue.GetInfo(row, wrk);

	if (hr != S_OK)
		return(hr);

	wrk.ToBSTR(pVal);

	return(S_OK);
}

STDMETHODIMP CUUEngine::put_DFileInfo(short row, BSTR newVal)
{
	return(CTL_E_SETNOTSUPPORTED);
}



//
// Read a file from the X Files list
//

STDMETHODIMP CUUEngine::get_XFile(short row, BSTR *pVal)
{
	if (row < 0)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	XFL *xp = XFList;

	while (row-- > 0 && xp != NULL)
		xp = xp->next;

	if (xp == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	xp->fName.CopyTo(pVal);

	return S_OK;
}

STDMETHODIMP CUUEngine::put_XFile(short row, BSTR newVal)
{
	if (row < 0)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	XFL *xp = XFList;

	while (row-- > 0 && xp != NULL)
		xp = xp->next;

	if (xp == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	if (SysStringLen(newVal) == 0)		// Delete this item
	{
		if (xp == XFList)
		{
			XFList = xp->next;
			delete xp;
		}
		else
		{
			XFL *xprev = XFList;

			while (xprev != NULL && xprev->next != xp)
				xprev = xprev->next;			// Get the item AHEAD of the item to be deleted

			if (xprev != NULL)
			{
				xprev->next = xp->next;
				delete xp;
			}
		}
	}
	else
		xp->fName = newVal;			// Just replace the name

	return S_OK;
}



//
// Remove a row
//

STDMETHODIMP CUUEngine::DRemove(short row)
{
	return(ue.DRemove(row));
}


//
// Do an encoding operation
//

STDMETHODIMP CUUEngine::Encode(
BSTR i_iname, BSTR i_oname, BSTR i_nameinfile, 
long encoding, long lines, long headers, 
VARIANT destvar, VARIANT fromvar, VARIANT subjectvar, 
long *retVal)
{
	FILE *outf;
	int rc, partno;
	char *onp, *extp, *partname;
	const char *dest, *from, *subject;
	MString deststr, fromstr, subjstr;
	MString iname(i_iname), oname(i_oname), nameinfile(i_nameinfile);

	dest = (const char *) destvar.bstrVal;
	if (destvar.vt != VT_BSTR || *dest == EOS)
		dest = NULL;
	else {
		deststr = destvar.bstrVal;
		dest = (const char *) deststr;
		}

	from = (const char *) fromvar.bstrVal;
	if (fromvar.vt != VT_BSTR || *from == EOS)
		from = NULL;
	else {
		fromstr = fromvar.bstrVal;
		from = (const char *) fromstr;
		}

	subject = (const char *) subjectvar.bstrVal;
	if (subjectvar.vt != VT_BSTR || *subject == EOS)
		subject = NULL;
	else {
		subjstr = subjectvar.bstrVal;
		subject = (const char *) subjstr;
		}

	if (nameinfile != NULL && nameinfile[0] != EOS)
		onp = nameinfile.GetBuffer();				// Caller has specified a name
	else {								// Generate our own
		if ((onp = strrchr(iname, '\\')) == NULL) {		// Look for last slash
			if ((onp = strrchr(iname, ':')) == NULL)
				onp = iname.GetBuffer();			// No colons, either
			else
				onp++;					// Point just past colon
			}
		else
			onp++;						// Point just past last slash
		}

	if (lines == 0 && (extp = strrchr(oname, '.')) != NULL) 	// Set single-part extension
		ue.UUSetOption(UUOPT_ENCEXT, 0, extp+1);

	if (headers) {							// User wants headers
		if (lines == 0) {					// Single file
			if (!OWriteOK && FExist(oname)) {		// Can't overwrite output file
				MessageHandler("Output file exists", UUMSG_ERROR);
				*retVal = UURET_EXISTS;
				return(S_OK);
				}

			if ((outf = fopen(oname, "w")) == NULL) {
				MessageHandler("Could not open output file", 1);
				*retVal = UURET_IOERR;
				return(S_OK);
				}

			NewStep();					// Warn the owner

			if (headers == UUVBE_SIMPLE)
				rc = ue.UUEncodeMulti(outf, NULL, iname.GetBuffer(), encoding, onp, NULL, 0);
			else
				rc = ue.UUE_PrepSingle(outf, NULL, iname.GetBuffer(), encoding, onp, 0,
					(char *) dest, (char *) from, (char *) subject, (headers == UUVBE_MAIL));

			fclose(outf);
			}
		else {								// Multi part
			MString partlocal(oname);		// Copy the output name
			partname = partlocal.GetBuffer(strlen(oname) + 10);		// Grab the buffer

			if ((extp = strrchr(partname, '.')) == NULL) {	// No extension?  Add one...
				extp = partname + strlen(partname);
				*extp++ = '.';
				}
			else
				extp++;						// Just past the last period

			partno = 1;						// First part

			do {							// Always have at least one...
				sprintf(extp, "%03d", partno);

				if (!OWriteOK && FExist(partname)) {		// Can't overwrite output file
					MessageHandler("Output file exists", UUMSG_ERROR);
					*retVal = UURET_EXISTS;
					return(S_OK);
					}

				if ((outf = fopen(partname, "w")) == NULL) 
				{
					MessageHandler("Error opening output file.", 1);
					*retVal = UURET_IOERR;
					return(S_OK);
				}

				NewStep();					// Warn the owner

				crc32_t lcr = 0;

				if (headers == UUVBE_SIMPLE)
					rc = ue.UUEncodePartial(outf, NULL, iname.GetBuffer(), encoding, onp, NULL,
						0, partno++, (int) lines, &lcr);
				else
					rc = ue.UUE_PrepPartial(outf, NULL, iname.GetBuffer(), encoding, onp, 0,
						partno++, (int) lines, 0, (char *) dest, (char *) from, (char *) subject,
						(headers == UUVBE_MAIL));

				fclose(outf);
				} while (rc == UURET_CONT);

			}
		}
	else {
		NewStep();					// Warn the owner
		rc = ue.UUEncodeToFile(NULL, iname.GetBuffer(), encoding, 
			onp, oname.GetBuffer(), (int) lines);
		}

	*retVal = rc;

	return S_OK;
}



//
// Add XFile
//

STDMETHODIMP CUUEngine::XFileAdd(BSTR toAdd, BOOL *retVal)
{
	if (XFList == NULL)
		XFList = new XFL(toAdd);
	else
		XFList->AddTail(toAdd);

	return S_OK;
}



//
// Delete XFile
//


STDMETHODIMP CUUEngine::XFileDel(BOOL *retVal)
{
	long le;

	if (XFList == NULL)
	{
		*retVal = TRUE;
		return(S_OK);						// OK, just return, nothing there
	}

	XFL *xp = XFList;

	MString wrk;

	for (xp=XFList; xp != NULL; xp=xp->next)
	{
		wrk = xp->fName;

		if (!DeleteFile(wrk)) 
		{
			le = ::GetLastError();
			if (le != ERROR_FILE_NOT_FOUND && le != ERROR_ACCESS_DENIED)
			{
				*retVal = FALSE;
				return(S_OK);					// Something went wrong during delete
			}
		}
	}

	XFL *nxp;

	for (xp=XFList; xp != NULL; xp=nxp)		// Waste the XFiles list
	{
		nxp = xp->next;

		delete xp;
	}

	XFList = NULL;

	*retVal = TRUE;

	return S_OK;
}



//
// Retrieve the last operating system error if any
//

STDMETHODIMP CUUEngine::LastOSError(long *errNo, VARIANT *errMessage, BOOL *gotErr)
{

	long lasterr;
	char *syserr;

	if ((lasterr = ::GetLastError()) == 0)
	{
		*gotErr = FALSE;
		return(S_OK);
	}

	MString erm;

	if (::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ARGUMENT_ARRAY,
					  NULL, lasterr, GetUserDefaultLangID(), (LPTSTR) &syserr, 0, NULL) == 0)
		erm = "Unknown Error";	// Couldn't convert error number to string
	else 
	{
		erm = syserr;	// Send back converted error string
		LocalFree(syserr);		// Discard the error string after passing it on
	}

	*errNo = lasterr;			// Save it

	erm.ToBSTR(errMessage);

	::SetLastError(0);			// Make sure last error is clear

	*gotErr = TRUE;

	return S_OK;
}



/**/
/**
*
* CRC polynomial table
*
**/

static const unsigned long crc32tab[256] = { /* CRC polynomial 0xEDB88320  */
    0x00000000L, 0x77073096L, 0xEE0E612CL, 0x990951BAL, 0x076DC419L, 0x706AF48FL, 0xE963A535L, 0x9E6495A3L,
    0x0EDB8832L, 0x79DCB8A4L, 0xE0D5E91EL, 0x97D2D988L, 0x09B64C2BL, 0x7EB17CBDL, 0xE7B82D07L, 0x90BF1D91L,
    0x1DB71064L, 0x6AB020F2L, 0xF3B97148L, 0x84BE41DEL, 0x1ADAD47DL, 0x6DDDE4EBL, 0xF4D4B551L, 0x83D385C7L,
    0x136C9856L, 0x646BA8C0L, 0xFD62F97AL, 0x8A65C9ECL, 0x14015C4FL, 0x63066CD9L, 0xFA0F3D63L, 0x8D080DF5L,
    0x3B6E20C8L, 0x4C69105EL, 0xD56041E4L, 0xA2677172L, 0x3C03E4D1L, 0x4B04D447L, 0xD20D85FDL, 0xA50AB56BL,
    0x35B5A8FAL, 0x42B2986CL, 0xDBBBC9D6L, 0xACBCF940L, 0x32D86CE3L, 0x45DF5C75L, 0xDCD60DCFL, 0xABD13D59L,
    0x26D930ACL, 0x51DE003AL, 0xC8D75180L, 0xBFD06116L, 0x21B4F4B5L, 0x56B3C423L, 0xCFBA9599L, 0xB8BDA50FL,
    0x2802B89EL, 0x5F058808L, 0xC60CD9B2L, 0xB10BE924L, 0x2F6F7C87L, 0x58684C11L, 0xC1611DABL, 0xB6662D3DL,
    0x76DC4190L, 0x01DB7106L, 0x98D220BCL, 0xEFD5102AL, 0x71B18589L, 0x06B6B51FL, 0x9FBFE4A5L, 0xE8B8D433L,
    0x7807C9A2L, 0x0F00F934L, 0x9609A88EL, 0xE10E9818L, 0x7F6A0DBBL, 0x086D3D2DL, 0x91646C97L, 0xE6635C01L,
    0x6B6B51F4L, 0x1C6C6162L, 0x856530D8L, 0xF262004EL, 0x6C0695EDL, 0x1B01A57BL, 0x8208F4C1L, 0xF50FC457L,
    0x65B0D9C6L, 0x12B7E950L, 0x8BBEB8EAL, 0xFCB9887CL, 0x62DD1DDFL, 0x15DA2D49L, 0x8CD37CF3L, 0xFBD44C65L,
    0x4DB26158L, 0x3AB551CEL, 0xA3BC0074L, 0xD4BB30E2L, 0x4ADFA541L, 0x3DD895D7L, 0xA4D1C46DL, 0xD3D6F4FBL,
    0x4369E96AL, 0x346ED9FCL, 0xAD678846L, 0xDA60B8D0L, 0x44042D73L, 0x33031DE5L, 0xAA0A4C5FL, 0xDD0D7CC9L,
    0x5005713CL, 0x270241AAL, 0xBE0B1010L, 0xC90C2086L, 0x5768B525L, 0x206F85B3L, 0xB966D409L, 0xCE61E49FL,
    0x5EDEF90EL, 0x29D9C998L, 0xB0D09822L, 0xC7D7A8B4L, 0x59B33D17L, 0x2EB40D81L, 0xB7BD5C3BL, 0xC0BA6CADL,
    0xEDB88320L, 0x9ABFB3B6L, 0x03B6E20CL, 0x74B1D29AL, 0xEAD54739L, 0x9DD277AFL, 0x04DB2615L, 0x73DC1683L,
    0xE3630B12L, 0x94643B84L, 0x0D6D6A3EL, 0x7A6A5AA8L, 0xE40ECF0BL, 0x9309FF9DL, 0x0A00AE27L, 0x7D079EB1L,
    0xF00F9344L, 0x8708A3D2L, 0x1E01F268L, 0x6906C2FEL, 0xF762575DL, 0x806567CBL, 0x196C3671L, 0x6E6B06E7L,
    0xFED41B76L, 0x89D32BE0L, 0x10DA7A5AL, 0x67DD4ACCL, 0xF9B9DF6FL, 0x8EBEEFF9L, 0x17B7BE43L, 0x60B08ED5L,
    0xD6D6A3E8L, 0xA1D1937EL, 0x38D8C2C4L, 0x4FDFF252L, 0xD1BB67F1L, 0xA6BC5767L, 0x3FB506DDL, 0x48B2364BL,
    0xD80D2BDAL, 0xAF0A1B4CL, 0x36034AF6L, 0x41047A60L, 0xDF60EFC3L, 0xA867DF55L, 0x316E8EEFL, 0x4669BE79L,
    0xCB61B38CL, 0xBC66831AL, 0x256FD2A0L, 0x5268E236L, 0xCC0C7795L, 0xBB0B4703L, 0x220216B9L, 0x5505262FL,
    0xC5BA3BBEL, 0xB2BD0B28L, 0x2BB45A92L, 0x5CB36A04L, 0xC2D7FFA7L, 0xB5D0CF31L, 0x2CD99E8BL, 0x5BDEAE1DL,
    0x9B64C2B0L, 0xEC63F226L, 0x756AA39CL, 0x026D930AL, 0x9C0906A9L, 0xEB0E363FL, 0x72076785L, 0x05005713L,
    0x95BF4A82L, 0xE2B87A14L, 0x7BB12BAEL, 0x0CB61B38L, 0x92D28E9BL, 0xE5D5BE0DL, 0x7CDCEFB7L, 0x0BDBDF21L,
    0x86D3D2D4L, 0xF1D4E242L, 0x68DDB3F8L, 0x1FDA836EL, 0x81BE16CDL, 0xF6B9265BL, 0x6FB077E1L, 0x18B74777L,
    0x88085AE6L, 0xFF0F6A70L, 0x66063BCAL, 0x11010B5CL, 0x8F659EFFL, 0xF862AE69L, 0x616BFFD3L, 0x166CCF45L,
    0xA00AE278L, 0xD70DD2EEL, 0x4E048354L, 0x3903B3C2L, 0xA7672661L, 0xD06016F7L, 0x4969474DL, 0x3E6E77DBL,
    0xAED16A4AL, 0xD9D65ADCL, 0x40DF0B66L, 0x37D83BF0L, 0xA9BCAE53L, 0xDEBB9EC5L, 0x47B2CF7FL, 0x30B5FFE9L,
    0xBDBDF21CL, 0xCABAC28AL, 0x53B39330L, 0x24B4A3A6L, 0xBAD03605L, 0xCDD70693L, 0x54DE5729L, 0x23D967BFL,
    0xB3667A2EL, 0xC4614AB8L, 0x5D681B02L, 0x2A6F2B94L, 0xB40BBE37L, 0xC30C8EA1L, 0x5A05DF1BL, 0x2D02EF8DL
	};


/**/
/**
*
* crc32 calculates the crc of a buffer
*
**/
#pragma warning(disable : 4035)		// No return value (in EAX)

static unsigned long crc32(
void * buf,
int len)
{

_asm {
	push	esi
	push	edi

	lea		edi, crc32tab		// Point to CRC table
	mov		esi, [buf]			// Point to buffer
	sub		eax, eax			// Clear accumulator
	mov		ecx, [len]			// Read count

	mov		edx, -1				// Start with all f's

cloop:
	lodsb						// *bp++
	xor		al, dl				// (*bp++ ^ (BYTE) crc)

	shr		edx, 8				// Shift right one byte
	xor		edx, [edi+eax*4]	// XOR in value from table
	loop	cloop				// Power through the whole buffer

	pop		edi
	pop		esi

	mov		eax, edx			// Copy the return value
	not		eax
	}

}

#pragma warning(default : 4035)



//
// Calculate a file's CRC32
//

STDMETHODIMP CUUEngine::CRC32(BSTR fileName, long *crc, BOOL *retVal)
{
	MappedFile mf;

	if (!mf.ReadExisting(MString(fileName)))
	{
		*retVal = FALSE;
		return(S_OK);						// Couldn't open file
	}

	*crc = crc32(mf.GetBuffer(), mf.GetMapSize());

	mf.Close();						// Dump the memory map

	*retVal = TRUE;

	return S_OK;
}



//
// Exchange clipboard with file on disk
//

STDMETHODIMP CUUEngine::ClipboardFile(long hWnd, BSTR Filename, short CFMode, BOOL *retVal)
{
	MappedFile mf;
	HANDLE memhdl, fh;
	DWORD fs, fsr;
	BOOL rc = TRUE;
	byte *bp, *bq;

switch (CFMode) {
	case 0:					// File to Clipboard
		if (!mf.ReadExisting(MString(Filename)) || !::OpenClipboard((HWND) hWnd))
		{
			*retVal = FALSE;
			return(S_OK);
		}

		::EmptyClipboard();	// Dump whatever's there

		fs = mf.GetMapSize();		// Read the map size

		if ((memhdl = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, fs + 16)) == NULL) 
		{
			::CloseClipboard();
			*retVal = FALSE;
			return(S_OK);
		}

		bp = (byte *) GlobalLock(memhdl);	// Point to the memory area

		memcpy(bp, mf.GetBuffer(), fs);

		*(bp + fs) = EOS;		// Last character is always a null

		GlobalUnlock(memhdl);	// Let go of the memory handle

		::SetClipboardData(CF_TEXT, memhdl);

		::CloseClipboard();

		mf.Close();			// Let go of the memory mapped file
		break;

	case 1:					// Clipboard to new file
	case 2:					// Append clipboard
		if (!::IsClipboardFormatAvailable(CF_TEXT) || !::OpenClipboard((HWND) hWnd))
		{
			*retVal = FALSE;						// No text on clipboard
			return(S_OK);
		}

		if ((memhdl = ::GetClipboardData(CF_TEXT)) == NULL ||	// Couldn't get handle
			 (bp = (byte *) GlobalLock(memhdl)) == NULL) 
		{	// Couldn't lock it
			::CloseClipboard();					// Let go of clipboard
			*retVal = FALSE;						// No text on clipboard
			return(S_OK);
		}

		fs = GlobalSize(memhdl);				// Read the size of the block

		if ((bq = (byte *) memchr(bp, 0, fs)) != NULL)
			fs = bq - bp;						// Found a null

		if ((fh = CreateFile(MString(Filename), GENERIC_WRITE, 0,
					NULL, (CFMode == 1) ? CREATE_ALWAYS : OPEN_ALWAYS,
					FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL)) ==  INVALID_HANDLE_VALUE)
		{
			*retVal = FALSE;						// No text on clipboard
			return(S_OK);	// Couldn't open file
		}

		if (CFMode == 2)
			SetFilePointer(fh, 0, NULL, FILE_END);		// Point to end of file

		rc = WriteFile(fh, bp, fs, &fsr, NULL);		// Do the return

		GlobalUnlock(memhdl);
		CloseHandle(fh);
		::CloseClipboard();
		*retVal = rc;
		return(S_OK);

	default:
		*retVal = FALSE;						// No text on clipboard
		return(S_OK);		// Illegal operation
	}

	*retVal = TRUE;

return S_OK;
}




//
// Create a temporary file name
//

STDMETHODIMP CUUEngine::CreateTempName(BSTR *tempFilename)
{
	char *tn = ue.tempnam(NULL, "uu");

	MString wrk;

	if (tn != NULL)
	{
		wrk = tn;
		free(tn);
	}
		
	wrk.ToBSTR(tempFilename);

	return S_OK;
}



//
// Load a memory buffer or string into the engine
//

STDMETHODIMP CUUEngine::LoadBuffer(VARIANT buf, VARIANT *tempName, BOOL *retVal)
{
	long ub;
	byte *bp;

	char *tn = ue.tempnam(NULL, "um");		// Create a temporary file name

	if (tn == NULL)
		return(CTL_E_INVALIDUSEOFNULL);

	MString tfn(tn);

	free(tn);				// Always discard the temp name

	tfn.ToBSTR(tempName);		// Export the temporary name

	BOOL rv;

	XFileAdd(tempName->bstrVal, &rv);		// Add to the X Files

	XF_AutoDel = true;			// Active auto delete

	if (buf.vt == (VT_ARRAY | VT_UI1))			// Byte array
	{
		if (SafeArrayGetDim(buf.parray) != 1)
			return(DISP_E_BADVARTYPE);		// Not the right number of dimensions...

		SafeArrayGetUBound(buf.parray, 1, &ub);		// Read array size

//		ub++;			// Number of bytes

		HANDLE outf;
		
		if ((outf = CreateFile(tfn, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 
			 FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL)) == INVALID_HANDLE_VALUE)
			return(CTL_E_PATHFILEACCESSERROR);

		DWORD nbw;			// Number of bytes written

		SafeArrayAccessData(buf.parray, (void **) &bp);

		BOOL rc = WriteFile(outf, bp, ub, &nbw, NULL);

		SafeArrayUnaccessData(buf.parray);

		CloseHandle(outf);

		if (!rc || nbw != (DWORD) ub)
			return(CTL_E_DISKFULL);
	}											// Byte array
	else if (buf.vt == VT_BSTR)			// Plain string
	{
		ub = WideCharToMultiByte(CP_ACP, 0, buf.bstrVal, -1, 
			NULL, 0, NULL, NULL);

		if (ub <= 0)
			return(E_INVALIDARG);			// Couldn't get length

		ub--;				// Drop the trailing null

		MappedFile mf;			// Here's how we're writing the stuff out....

		if (!mf.CreateW(tfn, ub))
			return(CTL_E_PATHFILEACCESSERROR);		// Couldn't create

		WideCharToMultiByte(CP_ACP, 0, buf.bstrVal, -1, 
			(char *) mf.GetBuffer(), ub, NULL, NULL);		// Convert and write to disk

		mf.Close();
	}
	else
		return(DISP_E_TYPEMISMATCH);		// Not a type we understand

	ub = 0;

	HRESULT hr = DLoad(tempName->bstrVal, &ub);

	*retVal = (ub != 0);

	return(hr);		// Load it and return
}

