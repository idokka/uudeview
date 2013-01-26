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

// UUDeview ActiveX Control properties

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


//
// Read the Library version
//

STRING CUud32acxCtrl::GetLibVersion() 
{
	int isto;
	char wrk[256];
	
UUGetOption(UUOPT_VERSION, &isto, wrk, sizeof(wrk)-1);

CString strResult = wrk;

strResult += " " __DATE__ " " __TIME__;

#if OCX
return strResult.AllocSysString();
#else
return(strResult);
#endif
}

void CUud32acxCtrl::SetLibVersion(LPCTSTR lpszNewValue) 
{

	SetNotSupported();			// Can't set library version

}



//
// Access the file list
//

STRING CUud32acxCtrl::GetDFile(short row) 
{
	uulist *up = GetUulp(row);
	CString res;

if (DesignMode())
	GetNotSupported();					// Runtime only

if (up == NULL)
	ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

res = (up->filename == NULL || (up->state & UUFILE_NODATA)) ? 
		"(No Data)" : up->filename;

#if OCX
res.OemToAnsi();

return(res.AllocSysString());
#else
return(res);
#endif
}

void CUud32acxCtrl::SetDFile(short row, LPCTSTR lpszNewValue) 
{
	uulist *up = GetUulp(row);

if (DesignMode())
	SetNotSupported();					// Runtime only

if (up == NULL)
	ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

UURenameFile(up, (char *) lpszNewValue);

}



//
// Maximum number of files on the Decode list
//

short CUud32acxCtrl::GetDFCount() 
{

if (DesignMode())
	GetNotSupported();					// Runtime only

if (!uCacheValid)				// Build the cache if it isn't
	uCacheBuild();

return(uCacheCount);
}


void CUud32acxCtrl::SetDFCount(short nNewValue) 
{

	SetNotSupported();			// Can't set decode file list max

}



//
// Get or Set the flags for a particular file
//

long CUud32acxCtrl::GetDFileFlags(short row) 
{

if (DesignMode())
	GetNotSupported();					// Runtime only

uulist *up = GetUulp(row);

if (up == NULL)
	ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

long rc = up->state;				// Starting state

if (up->filename == NULL)
	rc |= UUFILE_NODATA;			// No data in file

if (up->thisfile != NULL && up->thisfile->data != NULL && up->thisfile->data->genfn)
	rc |= UUFILE_GENFN;				// Generated file

return(rc);
}

void CUud32acxCtrl::SetDFileFlags(short row, long nNewValue) 
{
	uulist *up = GetUulp(row);

if (DesignMode())
	SetNotSupported();					// Runtime only

if (up == NULL)
	ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

up->state = (short) nNewValue;

}



//
// Read File Info
//

#if SKIP
// Info file "callback" handler
static int UUInfoCallback(
void *opaque, 
char *uugen_inbuffer)
{
	
	return(((CUud32acxCtrl *) opaque)->AppendInfo(uugen_inbuffer));

}
#endif


// Actually get the File Info
STRING CUud32acxCtrl::GetDFileInfo(short row) 
{
	CString wrk;				// Accumulator for "State"
	int listlen = 0;
	uulist *up;

if (DesignMode())
	GetNotSupported();					// Runtime only

if (!infovalid)
	InfoClear();				// The information isn't valid

for (up=UUGlobalFileList; up != NULL; up=up->NEXT)
	listlen++;

if (row >= listlen)				// Index must be less than list length
	ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

if (infolist.GetUpperBound() <= listlen)
	infolist.SetSize(listlen + 10, 10);		// Make sure the list is big enough

InfoClass *ip = infolist.GetData() + row;	// Point to the info structure

if (ip->state == InfoClass::ILS_UNK) {		// Need to load the info
	up = GetUulp(row);	// Point to the structure
	if (up->filename == NULL || (up->state & UUFILE_NODATA) || up->uudet == PT_ENCODED)
		ip->state = InfoClass::ILS_NO;		// No info
	else { 
		if (info_buffer == NULL && (info_buffer = (char *) malloc(INFO_BUFFER_SZ)) == NULL)
			ThrowError(CTL_E_OUTOFMEMORY, IDS_OOM);	// Couldn't allocate info buffer

		info_pointer = info_buffer;		// Point to the information buffer
		*info_pointer = EOS;	// Empty buffer

		ip->info.Empty();		// Make sure this list item is empty

		if (UUInfoFile(up, NULL) != UURET_OK)
			ip->state = InfoClass::ILS_NO;	// Info function failed
		else {
			if (info_pointer > info_buffer) {	// Something was retrieved
				ip->info = info_buffer;		// Copy the stored information
				ip->state = InfoClass::ILS_YES;
				}
			else
				ip->state = InfoClass::ILS_NO;
			}
		}
	}

if (ip->state == InfoClass::ILS_YES)
	wrk = ip->info;				// Got some info
else
	wrk.Empty();				// Return the empty string

#if OCX
return wrk.AllocSysString();
#else
return(wrk);
#endif
}

void CUud32acxCtrl::SetDFileInfo(short row, LPCTSTR lpszNewValue) 
{
	SetNotSupported();
}


//
// Add stuff to the info buffer
//
// Return 1 if the buffer is full
//

int CUud32acxCtrl::UUInfoHandler(
void *opaque, 
char *inbuf)
{

int len = strlen(inbuf);		// How long is the add?

int ttl = (info_pointer - info_buffer) + len;

if (ttl > (INFO_BUFFER_SZ - 16))
	return(1);							// Just stop

strcpy(info_pointer, inbuf);	// Append the info line

info_pointer += len;					// Point to next target

if (ttl > 2 && *(info_pointer - 1) == '\n' && *(info_pointer - 2) != '\r') {	// Unix EOL conversion
	*(info_pointer - 1) = '\r';
	*info_pointer++ = '\n';
	*info_pointer = EOS;
	}

return(0);
}


//
// Read file status
//

STRING CUud32acxCtrl::GetDFileStatus(short row) 
{
	CString wrk;				// Accumulator for "State"
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
		"Quoted-Printable",
		"yEnc Encoded"
		};

if (DesignMode())
	GetNotSupported();					// Runtime only

uulist *lup = GetUulp(row);

if (lup == NULL)
	ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

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
			wrk += ',';
		wrk +=  _itoa(*iptr, cbuf, 10);
		}
	}

if (lup->thisfile != NULL) {	// There's a list of parts attached to this
	CString cbuf;				// Compare buffer is empty
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

#if OCX
return wrk.AllocSysString();
#else
return(wrk);
#endif
}

void CUud32acxCtrl::SetDFileStatus(short row, LPCTSTR lpszNewValue) 
{
	SetNotSupported();		// Read only
}



//
// Read the last message from the library (or set it?)
//

STRING CUud32acxCtrl::GetLastMessage() 
{
	CString strResult;

if (DesignMode())
	GetNotSupported();					// Runtime only

strResult = LastMessage;			// Make a copy of the "last message"

LastMessage.Empty();				// Empty it

#if OCX
return strResult.AllocSysString();
#else
return strResult;
#endif
}

void CUud32acxCtrl::SetLastMessage(LPCTSTR lpszNewValue) 
{

LastMessage = lpszNewValue;			// Let the user set the "last message"

}


#if OCX
//
// Read details about a file (for Lou)
//

VARIANT CUud32acxCtrl::GetDFileDetail(short row, short itemno, short subscr) 
{
	CString cs;
	_variant_t lv;
	int *ip;
	struct _uufile *ufp;
	long lct;

if (DesignMode())
	GetNotSupported();					// Runtime only

uulist *l = GetUulp(row);

if (l == NULL)
	ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

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
			ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);
		ip = ((itemno == UUVBLD_HAVEPART) ? l->haveparts : l->misparts)
			+ subscr;
		if (IsBadReadPtr(ip, sizeof(int))) {
			ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);
			return(lv);
			}
		lv = (short) *ip;
		break;

	case UUVBLD_UFPART:
		if (subscr < 0 || subscr > 255)
			ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);
		for (ufp=l->thisfile; ufp != NULL && subscr > 0; subscr--)
			ufp = ufp->NEXT;
		if (ufp == NULL) {
			ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);
			return(lv);
			}
		lv = ufp->partno;
		break;


	case UUVBLD_UFRSUBJ:
	case UUVBLD_UFRORG:
	case UUVBLD_UFRSFN:
	case UUVBLD_UFRSTART:		// uulist.thisfile[subscr].data.start
	case UUVBLD_UFRLEN:			// uulist.thisfile[subscr].data.length
		if (subscr < 0 || subscr > 255)
			ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);

		for (ufp=l->thisfile; ufp != NULL && subscr > 0; subscr--)
			ufp = ufp->NEXT;

		if (ufp == NULL || ufp->data == NULL) 
		{
			ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, IDS_BADFLS);
			return(lv);
		}

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

if (!cs.IsEmpty()) {			// This is a string return
	cs.OemToAnsi();
	lv = cs;
	}

return(lv);
}

void CUud32acxCtrl::SetDFileDetail(short row, short SelectInfo, short SubIndex, const VARIANT FAR& newValue) 
{
	SetNotSupported();
}
#endif


//
// Return the licensee name
//

#if OCX
BSTR CUud32acxCtrl::GetLicensee() 
{
	CString strResult("GNU/Freeware: Commercial Use Prohibited");

//	CString strResult("Serial 1100: Michael Bell, Industrial Economics");

return strResult.AllocSysString();
}

void CUud32acxCtrl::SetLicensee(LPCTSTR lpszNewValue) 
{
	SetNotSupported();
}
#endif
