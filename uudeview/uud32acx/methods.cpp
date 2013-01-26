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

// UUDeview ActiveX Control methods

#include "stdafx.h"
#include "uud32acx.h"
#include "Uud32acxCtl.h"
#include "comdef.h"
#pragma hdrstop

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define SKIP 0

#define EOS '\0'

//
// Reset
//
void CUud32acxCtrl::Reset() 
{

uCacheValid = false;		// Cached pointer array no longer valid

InfoClear();

if (m_xFileAuto)
	XFileDel();				// User requested Auto Delete

XFList.RemoveAll();		// Always clear the list

UUCleanUp();

}



//
// Load a file
//

long CUud32acxCtrl::DLoad(LPCTSTR file2load) 
{

uCacheValid = false;		// Cached pointer array no longer valid

infovalid = false;				// Info becomes invalid with every load

PunchOptions();					// Set the options

NewStep();					// Let the owner know we're starting a new step

return(UULoadFile((char *) file2load, (char *) file2load, 0));
}



//
// Decode a file to a specific name
//

long CUud32acxCtrl::DFileTo(short row, LPCTSTR outname) 
{
	uulist *ptr = GetUulp(row);

if (ptr == NULL)
	ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

if (ptr->filename == NULL || (ptr->state & UUFILE_NODATA))
	return(UURET_NODATA);		// Do data to decode

	char *syserr;
	DWORD lasterr;
	short rc;

PunchOptions();					// Set the options

NewStep();					// Let the owner know we're starting a new step

rc = UUDecode(ptr);		// Decode and get errors

if (ptr->binfile == NULL)
	return(rc);			// Couldn't decode/create temp

if (FExist(outname)) {	// Deal with an existing output file
	if (OwriteOK()) {			// Overwriting is OK
		if (DeleteFile(outname) == FALSE) {		// Try to delete it
			MessageHandler("Could not delete existing output file", UUMSG_ERROR);
			return(UURET_IOERR);
			}
		}
	else {						// Overwriting not OK
		MessageHandler("Output file exists", UUMSG_ERROR);
		return(UURET_EXISTS);
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

#if defined(_DEBUG)					// In development mode, I want to see the low-level messages
	CString wrk;
	wrk.Format("Move \"%s\" to \"%s\" failed, error %ld (%s) [%ld]",
		ptr->binfile, outname, lasterr,
		(LastMessage.IsEmpty()) ? "NoLastMessage" : (const char *) LastMessage,
		::GetLastError());

	::MessageBox(NULL, wrk, "Move Error", MB_OK | MB_TASKMODAL);
#endif

	return(UURET_IOERR);
	}

_FP_free(ptr->binfile);			// Temp file is gone, wasted by MoveFile
ptr->binfile = NULL;

ptr->state = (ptr->state & ~UUFILE_TMPFILE) | UUFILE_DECODED;

return(rc);
}



//
// Encode function
//

long CUud32acxCtrl::Encode(
LPCTSTR iname, 
LPCTSTR oname, 
LPCTSTR nameinfile, 
long encoding, 
long lines, 
long headers, 
const VARIANT FAR& destvar, 
const VARIANT FAR& fromvar, 
const VARIANT FAR& subjectvar) 
{
	FILE *outf;
	int rc, partno;
	char *onp, *extp, *partname;
	const char *dest, *from, *subject;
	CString deststr, fromstr, subjstr;

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
	onp = (char *) nameinfile;				// Caller has specified a name
else {								// Generate our own
	if ((onp = strrchr(iname, '\\')) == NULL) {		// Look for last slash
		if ((onp = strrchr(iname, ':')) == NULL)
			onp = (char *) iname;			// No colons, either
		else
			onp++;					// Point just past colon
		}
	else
		onp++;						// Point just past last slash
	}

PunchOptions();

if (lines == 0 && (extp = strrchr(oname, '.')) != NULL) 	// Set single-part extension
	UUSetOption(UUOPT_ENCEXT, 0, extp+1);

if (headers) {							// User wants headers
	if (lines == 0) {					// Single file
		if (!OwriteOK() && FExist(oname)) {		// Can't overwrite output file
			MessageHandler("Output file exists", UUMSG_ERROR);
			return(UURET_EXISTS);
			}

		if ((outf = fopen(oname, "w")) == NULL) {
			MessageHandler("Could not open output file", 1);
			return(UURET_IOERR);
			}

		NewStep();					// Warn the owner

		if (headers == UUVBE_SIMPLE)
			rc = UUEncodeMulti(outf, NULL, (char *) iname, encoding, onp, NULL, 0);
		else
			rc = UUE_PrepSingle(outf, NULL, (char *) iname, encoding, onp, 0,
				(char *) dest, (char *) from, (char *) subject, (headers == UUVBE_MAIL));

		fclose(outf);
		}
	else {								// Multi part
		CString partlocal(oname);		// Copy the output name
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

			if (!OwriteOK() && FExist(partname)) {		// Can't overwrite output file
				MessageHandler("Output file exists", UUMSG_ERROR);
				return(UURET_EXISTS);
				}

			if ((outf = fopen(partname, "w")) == NULL) {
				MessageHandler("Error opening output file.", 1);
				return(UURET_IOERR);
				}

			NewStep();					// Warn the owner

			crc32_t csto = -1;

			if (headers == UUVBE_SIMPLE)
				rc = UUEncodePartial(outf, NULL, (char *) iname, encoding, onp, NULL,
					0, partno++, (int) lines, &csto);
			else
				rc = UUE_PrepPartial(outf, NULL, (char *) iname, encoding, onp, 0,
					partno++, (int) lines, 0, (char *) dest, (char *) from, (char *) subject,
					(headers == UUVBE_MAIL));

			fclose(outf);
			} while (rc == UURET_CONT);

		partlocal.ReleaseBuffer();		// OK to release buffer, though it'll get destroyed anyway
		}
	}
else {
	NewStep();					// Warn the owner
	rc = UUEncodeToFile(NULL, (char *) iname, encoding, onp, (char *) oname, (int) lines);
	}

return(rc);
}



//
// Remove a file from the Decode List
//

void CUud32acxCtrl::DRemove(short row) 
{

uulist *todel = GetUulp(row);

if (todel == NULL)
	ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

if (todel == UUGlobalFileList) {	// First item in list!
	UUGlobalFileList = todel->NEXT;	// Delink top...
	if (todel->NEXT != NULL)
		(todel->NEXT)->PREV = NULL;	// Nothing above the next
	}
else {								// Prev can't be null...
	(todel->PREV)->NEXT = todel->NEXT;	// Shunt previous past delete target
	if (todel->NEXT != NULL)		// There's something after this...
		(todel->NEXT)->PREV = todel->PREV;	// Next bypasses target
	}

todel->NEXT = NULL;					// Artificial end-of-list for killlist
UUkilllist(todel);					// Delete the item and its dependants

uCacheValid = false;					// Cache not set

}



//
// Filter a filename
//

STRING CUud32acxCtrl::FileFilter(LPCTSTR inp) 
{
	bool extflag = false;		// Got one extension
	char *src, *wp;
	char c, wrk[MAX_PATH + 2];
	int len;
	CString res;

len = strlen(inp);		// Read original string length

#if OCX
if (len == 0)
	return(SysAllocStringByteLen(inp, 0));					// Might as well just send it back
#else
if (len == 0)
	return(res);
#endif

src = (char *) inp + len - 1;		// Point to end of incoming string data

wp = wrk + len;						// End of work buffer
*wp-- = EOS;

while (len-- > 0) {
	c = *src--;						// Read one character

#if SKIP			// For now, turn off mult-dot filtering
	if (c == '.') {					// One extension only, please
		if (!extflag) {
			*wp-- = '.';
			extflag = true;
			}
		}
	else 
#endif

	if ((c >= 0 && c < ' ') || strchr("<>:\"|?*\'\\/", c) != NULL)
		*wp-- = '_';				// Replace unacceptables with underscore
	else
		*wp-- = c;					// Copy everything else
	}

wp++;								// Point to first char
while (*wp == '.')
	wp++;							// Can't begin filename with dot(s)

res = wp;

#if OCX
res.OemToAnsi();

return(res.AllocSysString());
#else
return(res);
#endif
}



//
// Decode a file to an output directory
//

long CUud32acxCtrl::QuickDecode(LPCTSTR File2Decode, LPCTSTR OutputPath, BOOL XFile) 
{
	long rc;

Reset();				// Start with everything clear

if ((rc = DLoad(File2Decode)) != UURET_OK)	// Load the source file
	return(rc);			// Couldn't load

CString prefix(OutputPath);	// Make a copy of the Output Path string

if (prefix.IsEmpty()) {	// No prefix string supplied
	GetTempPath(256, prefix.GetBuffer(256));	// Read the temporary path
	prefix.ReleaseBuffer();		// Hand off to CString
	}

char trail = prefix[prefix.GetLength() - 1];	// Read the last character

if (trail != ':' && trail != '\\')	// Output path must end in slash or colon...
	prefix += '\\';			// Add the slash

short maxIndex = GetDFCount();	// Read the maximum file number
#if OCX
BSTR b,c;
#endif
CString outname;

for (short row=0; row < maxIndex; row++)
	if (GetDFileFlags(row) & UUFILE_OK) {		// Ready to decode
#if OCX
		outname = (b = GetDFile(row));
		outname = (c = FileFilter(outname));
		SysFreeString(b);
		SysFreeString(c);
		outname = prefix + outname;				// Create the full path
#else
		outname = prefix + FileFilter(GetDFile(row));
#endif
		rc = DFileTo(row, outname);
	    if (rc != UURET_OK)	// Read the current 
			return(rc);
		SetDFile(row, outname);					// Return the full (filtered) path
		if (XFile)
			XFList.AddTail(outname);	// User wants these files added to X list
		}

return(UURET_OK);			// Got it!
}



#if OCX
//
// Implement the GetLastError method
//
// Returns True if there was an error, False otherwise
//


BOOL CUud32acxCtrl::GLError(long FAR* errNo, BSTR FAR* errMessage) 
{
	long lasterr;
	char *syserr;

if ((lasterr = ::GetLastError()) == 0)
	return FALSE;				// No errors to process

SysFreeString(*errMessage);		// Kill the old BSTR

if (::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ARGUMENT_ARRAY,
				  NULL, lasterr, GetUserDefaultLangID(), (LPTSTR) &syserr, 0, NULL) == 0)
	*errMessage = SysAllocStringByteLen("Unknown Error", 13);	// Couldn't convert error number to string
else {
	*errMessage = SysAllocStringByteLen(syserr, strlen(syserr));	// Send back converted error string
	LocalFree(syserr);		// Discard the error string after passing it on
	}

*errNo = lasterr;			// Save it

::SetLastError(0);			// Make sure last error is clear

return TRUE;
}
#endif
