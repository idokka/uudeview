/*
 * This file is part of uudeview 32, a simple and friendly multi-part multi-
 * file uudecoder  program.
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

/**
*
* UUDW32 contains functions useful to UUDeview for Windows 32
*
**/
#include "windows.h"
#include "ole2.h"
#include "stdio.h"
#include "string.h"

#include "config.h"
#include "uudeview.h"
#include "uuint.h"

#include "miken.h"


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

#define UUVBLD_MAX		17			// Largest possible value

extern char *last_message = NULL;



/**/
/**
*
* UUDecodeOptionMenu shows a popup menu that allows the user to set the
*  decoding options
*
**/

VBoolean UUEXPORT UUDecodeOptionMenu(		// Returns FALSE for error or TRUE for OK
HWND owner,							// Form's window handle
HWND button,						// Button's window handle
short checked[])					// Current menu selections
{
	int i, nondef;
	short *iptr;
	HMENU mh;
	RECT r;
	char **msp;
	static char * msl_list[] ={
		"&1 part per file",
		"D&umb mode",
		"A&lternate bracket [] policy",
		"D&esperate mode",
		"&Ignore RE:plies",
		"Output o&verwrite OK",
		"&Pause on Errors"
	};

if ((mh = CreatePopupMenu()) == NULL)
	return(VBFALSE);					// Couldn't create menu

iptr = checked;			// Point to status
nondef = FALSE;			// Start with no non-defaults

for (i=0; i < (sizeof(msl_list) / sizeof(char **)); i++)
	if (*iptr++) {
		nondef = TRUE;	// Find out if any options are on (non-default)
		break;
		}

if (AppendMenu(mh, (nondef) ? MF_STRING : (MF_STRING | MF_GRAYED), 100, "&Default") == FALSE || 	// Couldn't add "defaults" menu item
    AppendMenu(mh, MF_SEPARATOR, 0, NULL) == FALSE) {	// Add separator
	DestroyMenu(mh);
	return(VBFALSE);
	}


msp = msl_list;
iptr = checked;

for (i=0; i < (sizeof(msl_list) / sizeof(char **)); i++)
	if (AppendMenu(mh,
		 (*iptr++) ? (MF_STRING | MF_CHECKED) : (MF_STRING | MF_UNCHECKED),
		 i + 1, *msp++) == FALSE) {	// Couldn't add menu item
		DestroyMenu(mh);
		return(VBFALSE);
		}

GetWindowRect(button, &r);

i = TrackPopupMenu(mh, TPM_LEFTALIGN | TPM_LEFTBUTTON, 
				   r.left, r.bottom, 0, owner, NULL);	// Pop up the menu

DestroyMenu(mh);					// Delete the menu we created

return((i) ? VBTRUE : VBFALSE);		// TPM sends back C true
}


/**/
/**
*
* SETSTR does the equivalent of a SysReallocStr except it accepts
*  a C-style string
*
**/

void SETSTR(
BSTR *dest,
char *source)
{

SysFreeString(*dest);			// Free the old string

*dest = (source == NULL) ? SysAllocStringByteLen("(NULL)", 6) :	// Guard against null strings
	SysAllocStringByteLen(source, strlen(source));

}



/**/
/**
*
* SETSTRL does the equivalent of a SysReallocStr except it accepts
*  a C-style string
*
* This version accepts a length.
*
**/

void SETSTRL(
BSTR *dest,
char *source,
unsigned int len)
{

SysFreeString(*dest);			// Free the old string

*dest = (source == NULL) ? SysAllocStringByteLen("(NULL)", 6) :	// Guard against null strings
	SysAllocStringByteLen(source, len);

}


/**/
/**
*
* FExist checks to see if a file already exists.
*
* It returns TRUE if the file exists.
*
**/

boolean FExist(
const char *filename)
{

if (GetFileAttributes(filename) == 0xFFFFFFFF &&	// Couldn't read attributes (good!)
	GetLastError() == ERROR_FILE_NOT_FOUND)
	return(FALSE);					// File doesn't exist

return(TRUE);
}


/**/
/**
*
* UUVBFileFilter formats an incoming filename to be acceptable
*  to Win32 file systems.
*
* Needed because VB uses BSTRs and the UU Lib file filter mechanism
*  uses malloc'ed strings
*
**/

BSTR UUEXPORT UUVBFileFilter(		// Returns filtered string
BSTR inp)
{
	boolean extflag = FALSE;		// Got one extension
	LPSTR src, wrk, wp;
	char c;
	int len;

len = SysStringByteLen(inp);		// Read original string length

if (len == 0)
	return(inp);					// Might as well just send it back

if ((wrk = _alloca(len + 2)) == NULL)	// Create temporary work buffer
	return(NULL);					// Out of memory???  In the real world we'd throw

src = (LPSTR) inp + len - 1;		// Point to end of incoming string data

wp = wrk + len;						// End of work buffer
*wp-- = EOS;

while (len-- > 0) {
	c = *src--;						// Read one character
	if (c == '.') {					// One extension only, please
		if (!extflag) {
			*wp-- = '.';
			extflag = TRUE;
			}
		}
	else if ((c >= 0 && c < ' ') || strchr("<>:\"|", c) != NULL)
		*wp-- = '_';				// Replace unacceptables with underscore
	else
		*wp-- = c;					// Copy everything else
	}

if (*++wp == '.')
	wp++;							// Can't begin filename with dot

return(SysAllocStringByteLen(wp, strlen(wp)));
}



/**/
/**
*
* UUVBDecode is really just a more efficient version of UUDecodeToFile;
*  It uses MoveFile, which "renames" when on the same drive and uses mem-mapped
*  copy across drives, instead of manually trying to copy the file in chunks.
*
* Allows you to pass the output name and get the flags after the decode operation
*
**/

VBoolean UUEXPORT UUVBDecode(	// Returns TRUE if everything went OK
uulist *ptr,					// File List item to decode
short *flags,					// Flags after operation
BSTR outname,					// Output name
int *uuret,						// UUDecodeToTemp return value
DWORD *moveret)					// Errors from the Move operation
{
	char *syserr;
	DWORD lasterr;
#ifdef _DEBUG
	char wrk[256];
#endif

if (!ListPointerCheck(ptr))
	return(VBFALSE);

*uuret = UUDecodeToTemp(ptr);	// Decode and get errors

*flags = ptr->state;			// Return the flags

*moveret = lasterr = NO_ERROR;	// Start with clear Move return code

if (ptr->binfile == NULL)
	return(VBFALSE);			// Couldn't decode/create temp

if (FExist((LPSTR) outname)) {	// Deal with an existing output file
	if (OwriteOK()) {			// Overwriting is OK
		if (DeleteFile((LPSTR) outname) == FALSE) {		// Try to delete it
			UUMCapture(NULL, "Could not delete existing output file", UUMSG_ERROR);
			return(VBFALSE);
			}
		}
	else {						// Overwriting not OK
		UUMCapture(NULL, "Output file exists", UUMSG_ERROR);
		return(VBFALSE);
		}
	}							// Output file doesn't exist.  OK to go.

if (MoveFile(ptr->binfile, (LPSTR) outname) == FALSE) {				// Something went wrong during move
	lasterr = GetLastError();	// Read the error code
	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ARGUMENT_ARRAY,
					  NULL, lasterr, GetUserDefaultLangID(), (LPTSTR) &syserr, 0, NULL) == 0)
		UUMCapture(NULL, "Unknown Error", UUMSG_ERROR);	// Couldn't convert error number to string
	else {
		UUMCapture(NULL, syserr, UUMSG_ERROR);	// Got a conversion
		LocalFree(syserr);		// Discard the error string after passing it on
		}

#ifdef _DEBUG					// In development mode, I want to see the low-level messages
	sprintf(wrk, "Move \"%s\" to \"%s\" failed, error %ld (%s) [%ld]", 
		ptr->binfile, (LPSTR) outname, lasterr, 
		(last_message == NULL) ? "NoLastMessage" : last_message,
		GetLastError());

	MessageBox(NULL, wrk, "Move Error", MB_OK | MB_TASKMODAL);
#endif

	*moveret = lasterr;			// Store the error code.

	return(VBFALSE);
	}

_FP_free(ptr->binfile);			// Temp file is gone, wasted by MoveFile
ptr->binfile = NULL;

*moveret = NO_ERROR;			// No errors.

return((*uuret == UURET_OK) ? VBTRUE : VBFALSE);
}



/**/
/**
*
* UUAddOptionMenu shows a popup menu that allows the user to add
*  files or the clipboard
*
**/

VBoolean UUEXPORT UUAddOptionMenu(		// Returns FALSE for error or TRUE for OK
HWND owner,							// Form's window handle
HWND button)						// Button's window handle
{
	int i;
	HMENU mh;
	RECT r;
	char **msp;
	static char * msl_list[] ={
		"&Files...",
		"&Clipboard"
		};

if ((mh = CreatePopupMenu()) == NULL)
	return(VBFALSE);					// Couldn't create menu

msp = msl_list;

for (i=0; i < (sizeof(msl_list) / sizeof(char **)); i++)
	if (AppendMenu(mh, MF_STRING, i + 20, *msp++) == FALSE) {	// Couldn't add menu item
		DestroyMenu(mh);
		return(VBFALSE);
		}

GetWindowRect(button, &r);

i = TrackPopupMenu(mh, TPM_LEFTALIGN | TPM_LEFTBUTTON, 
				   r.left, r.bottom, 0, owner, NULL);	// Pop up the menu

DestroyMenu(mh);					// Delete the menu we created

return((i) ? VBTRUE : VBFALSE);		// TPM sends back C true
}



/**/
/**
*
* UUVBStringToFile takes a string and writes it to a temporary file.
*
* Meant to be used with VB's Clipboard.text
*
* If wfn is empty (len = 0), a new temporary file is created.  Otherwise,
*  the file named in wfn is opened for appending.
*
**/

VBoolean UUEXPORT UUVBStringToFile(		// Returns TRUE if everything worked
BSTR towrite,						// The string to write
BSTR *wfn,							// Temporary filename generated
int *lenp)							// Return storage for length (in K)
{
	BOOL rc;
	DWORD written, eof;
	HANDLE fh;
	int len;
	char *tfn;				// Pointer to filename

if ((len = SysStringByteLen(towrite)) == 0)		// Read original string length
	return(VBFALSE);				// String is empty

if (SysStringByteLen(*wfn) == 0) {	// The original filename is empty
	if ((tfn = _tempnam(NULL, "Clip")) == NULL)
		return(VBFALSE);			// Couldn't create temporary name

	if ((tfn = realloc(tfn, strlen(tfn) + 5)) == NULL)
		return(VBFALSE);			// Make room for extension

	strcat(tfn,".tmp");				// Make sure it has a tmp extension

	if ((fh = CreateFile(tfn, GENERIC_WRITE, 0, NULL, CREATE_NEW, 
		 FILE_ATTRIBUTE_NORMAL, NULL)) == INVALID_HANDLE_VALUE) {
		free(tfn);
		return(VBFALSE);
		}

	rc = WriteFile(fh, towrite, len, &written, NULL);	// Write it out

	CloseHandle(fh);				// Close the file

	if (rc == FALSE)				// Couldn't write file
		DeleteFile(tfn);			// Delete Temporary 
	else {
		SETSTR(wfn, tfn);			// Return the temporary filename
		*lenp = len / 1024;			// Return the number of K in the file
		}

	free(tfn);						// No matter what happens, free the generated filename
	}
else {								// Filename already supplied
	if ((fh = CreateFile((LPSTR) *wfn, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 
		 FILE_ATTRIBUTE_NORMAL, NULL)) == INVALID_HANDLE_VALUE) {
		return(VBFALSE);
		}

	eof = SetFilePointer(fh, 0, NULL, FILE_END);	// Point to end of file and get size

	rc = WriteFile(fh, towrite, len, &written, NULL);	// Write it out

	CloseHandle(fh);				// Close the file

	if (rc == FALSE)				// Couldn't write file
		DeleteFile((LPSTR) *wfn);			// Delete Temporary 
	else
		*lenp = (eof + len) / 1024;			// Return the number of K in the file
	}

return((rc == TRUE) ? VBTRUE : VBFALSE);
}



/**/
/**
*
* UUVBListData retrieves information about an item in the decode File List
*
* Returns TRUE if the data item arrived OK
*
**/

VBoolean UUEXPORT UUVBListData(
uulist *l,						// Member of the file list
short itemno,					// Which item to retrieve
short subscr,					// Subscript for list-style items
VARIANT *vp)					// Return pointer
{
	VARIANT lv;
	char *cp;
	int *ip, len, slen;
	struct _uufile *ufp;
	static VARTYPE vtlist[UUVBLD_MAX + 1] ={	// Variant types to return for each item
		VT_I2,					// STATE	
		VT_I2,					// MODE		
		VT_I4,					// BEGIN	
		VT_I4,					// END		
		VT_I2,					// UUDET	
		VT_I4,					// FLAGS	
		VT_I4,					// SIZE		
		VT_BSTR,				// FILEN	
		VT_BSTR,				// SUBF		
		VT_BSTR,				// MIMEID	
		VT_BSTR,				// MIMETYPE	
		VT_BSTR,				// BINFILE	
		VT_I4,					// HAVEPART	
		VT_I4,					// MISSPART 
		VT_I2,					// UFPART	
		VT_BSTR,				// UFRSUBJ
		VT_BSTR,				// UFRORG
		VT_BSTR					// UFRSFN
		};

if (itemno < 0 || itemno > UUVBLD_MAX || subscr < 0 || subscr > 255 || !ListPointerCheck(l)) {
	UUMCapture(NULL, "Invalid parameter", UUMSG_ERROR);
	return(VBFALSE);
	}

VariantInit(&lv);

switch (itemno) {
	case UUVBLD_STATE:
		lv.iVal = l->state;
		break;

	case UUVBLD_MODE:
		lv.iVal = l->mode;
		break;
	
	case UUVBLD_BEGIN:
		lv.lVal = l->begin;
		break;
	
	case UUVBLD_END:
		lv.lVal = l->end;
		break;
	
	case UUVBLD_UUDET:
		lv.iVal = l->uudet;
		break;
	
	case UUVBLD_FLAGS:
		lv.lVal = l->flags;
		break;
	
	case UUVBLD_SIZE:
		lv.lVal = l->size;
		break;
	
	case UUVBLD_FILEN:
		cp = l->filename;
		break;

	case UUVBLD_SUBF:
		cp = l->subfname;
		break;

	case UUVBLD_MIMEID:
		cp = l->mimeid;
		break;

	case UUVBLD_MIMETYPE:
		cp = l->mimetype;
		break;

	case UUVBLD_BINFILE:
		cp = l->binfile;
		break;

	case UUVBLD_HAVEPART:
	case UUVBLD_MISSPART:
		ip = ((itemno == UUVBLD_HAVEPART) ? l->haveparts : l->misparts)
			+ subscr;
		if (IsBadReadPtr(ip, sizeof(int))) {
			UUMCapture(NULL, "Invalid subscript", UUMSG_ERROR);
			return(VBFALSE);
			}
		lv.lVal = *ip;
		break;

	case UUVBLD_UFPART:
		for (ufp=l->thisfile; ufp != NULL && subscr > 0; subscr--)
			ufp = ufp->NEXT;
		if (ufp == NULL) {
			UUMCapture(NULL, "Invalid subscript", UUMSG_ERROR);
			return(VBFALSE);
			}
		lv.iVal = ufp->partno;
		break;


	case UUVBLD_UFRSUBJ:
	case UUVBLD_UFRORG:
	case UUVBLD_UFRSFN:	
		for (ufp=l->thisfile; ufp != NULL && subscr > 0; subscr--)
			ufp = ufp->NEXT;
		if (ufp == NULL || ufp->data == NULL) {
			UUMCapture(NULL, "Invalid subscript or no data", UUMSG_ERROR);
			return(VBFALSE);
			}
		switch (itemno) {
			case UUVBLD_UFRSUBJ:
				cp = ufp->data->subject;
				break;

			case UUVBLD_UFRORG:
				cp = ufp->data->origin;
				break;

			case UUVBLD_UFRSFN:	
				cp = ufp->data->sfname;
				break;
			}
		break;
	}

lv.vt = vtlist[itemno];			// Set the type of the variant

if (lv.vt == VT_BSTR) { 			// This is a string
	if (cp == NULL || *cp == EOS)	// The empty string
		lv.bstrVal = SysAllocStringByteLen(" ", 0);
	else {
		slen = strlen(cp);
		len = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cp, slen, NULL, 0);	// Length of converted string
		lv.bstrVal = SysAllocStringByteLen(NULL, len * sizeof(WCHAR));	// Make space
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, cp, slen, lv.bstrVal, len);	// Do the conversion
		}
	}

VariantClear(vp);				// Destroy any existing contents of variant

*vp = lv;						// Substitute the contents of our variant

return(VBTRUE);
}



/**/
/**
*
* UUVBGetOption reads back an option from the library
*
**/

VBoolean UUEXPORT UUVBGetOption(
short option,
int *ival,
BSTR *sval)
{
	char wrk[256];

wrk[0] = EOS;				// Make sure string starts empty

if (UUGetOption(option, ival, wrk, sizeof(wrk)) == -1)
	return(VBFALSE);		// Couldn't read option

SETSTR(sval, wrk);

return(VBTRUE);
}
