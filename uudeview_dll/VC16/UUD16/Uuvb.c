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
* UUDeview functions related to Visual Basic operation
*
**/
#include "windows.h"

#if !defined(_WIN32)
#include "vbapi.h"				// The magic of VB API
#else
#include "ole2.h"
#endif

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "stdarg.h"
#include "io.h"
#include "malloc.h"

#include "config.h"
#include "uudeview.h"
#include "uuint.h"

#include "crc32.h"

#include "miken.h"				// My UUDeview definitions

extern uuprogress progress;		// The global progress structure

typedef unsigned char boolean;

static boolean micalled;		// Has master init been called?

static int cancel_flag;			// User wants to cancel

#define INFO_SZ 16384				// Size for Info buffer
static char *info_buffer = NULL;	// Storage for Info queries
static char *info_pointer;			// Pointer to where we are in the info buffer

static HWND owner_whdl;			// Handle of owner window

// UUVBEncode control constants
#define UUVBE_NONE		0		// No MIME headers (use standard headers)
#define UUVBE_SIMPLE	1		// Simple MIME (no addressing)
#define UUVBE_MAIL		2		// MIME E-mail format
#define UUVBE_NEWS		3		// MIME News format

//
// Info storage list
//
typedef struct infolist_struct {
	char *info;					// The info
	uulist *key;				// What it matches to
	short len;
	struct infolist_struct *next;
	} IL_S;
	
static IL_S *infolist;

//
// Kill list management
//
typedef struct kill_list_struct {
	char *kfname;				// File to kill
	struct kill_list_struct *next;
	} KL_S;
	
static KL_S *kill_list;			// Files to kill on shutdown
     
//
// Message list management
//
typedef struct msg_list_struct {
	char *msg;					// Message
	int level;					// Severity
	struct msg_list_struct *next;
	} ML_S;
	
static ML_S *msg_list;			// List of messages


//
// Testing My Sprintf
#define MST 0

#if MST
static FILE *bogey = NULL;
#endif


/**/
/**
*
* safecat appends a string to the end of a buffer, as long as there's
*  room for the new string.
*
* Returns TRUE if the string was appended OK.
*
**/

static boolean safecat(			// Returns the source buffer
char *buf,						// Buffer to add the string to
int bufmax,						// Size of buffer
char *append)					// What to append
{
	int len;

if (append == NULL)				// We should NEVER see this, but better safe than sorry!
	append = "(NULL)";

len = strlen(buf);

if (len+(int) strlen(append)+1 >= bufmax)	// Don't forget the NUL
	return(FALSE);				// Not enough room!

strcpy(buf+len, append);		// Tack the append string on...

return(TRUE);
}



/**/
/**
*
* UUMCapture picks up messages from the UU library
*
* If the owner handle is set, it sends a message (WM_USER + 2)
*  to the owner window
*
**/

void UUMCapture(
void *opaque,
char *message,
int level)
{
	ML_S *nm;

if ((nm = malloc(sizeof(ML_S))) == NULL)
	return;							// Couldn't allocate new structure
	
nm->msg = strdup(message);			// Store the message
nm->level = level;
nm->next = msg_list;				// Link it in
msg_list = nm;

#if SKIP
if (owner_whdl != 0)				// The owner handle has been set
	SendMessage(owner_whdl, WM_USER + 2, 
		(WPARAM) level, 					// The wparam is the severity
		(LPARAM) last_message);	// The lparam is a pointer to the message string

if (owner_whdl != 0)				// The owner handle has been set
	SendMessage(owner_whdl, WM_USER + 2, 
		(WPARAM) level, 					// The wparam is the severity
		(LPARAM) uulib_msgstring);	// The lparam is a pointer to the message string
#endif

}



/**/
/**
*
* ListPointerCheck returns TRUE if a pointer is OK
*  for memory access
*
**/

boolean ListPointerCheck(
uulist *u)
{

if (IsBadWritePtr(u, sizeof(uulist))) {
	UUMCapture(NULL, "Illegal List Pointer", UUMSG_ERROR);
	return(FALSE);
	}

return(TRUE);
}




/**/
/**
*
* BusyHandler captures the progress info
*
* If the owner window handle has been set, a progress message WM_USER + 1
*  is sent to it.
*
**/

static int BusyHandler(
void *opaque, 						// Opaque pointer passed down from DLL
uuprogress *uup)                       // Progress info
{

if (owner_whdl != 0)				// The owner handle has been set
	SendMessage(owner_whdl, WM_USER + 1, 
		progress.percent, 					// The wparam is the percent completed
		MAKELONG(progress.partno, progress.numparts));	// The lparam is totalparts>:currentpart

#if WIN16	
Yield();
#endif
          
return(cancel_flag);
}



/**/
/**
*
* infolist_clear dumps anything currently on the Info list
*
**/

static void infolist_clear(void)
{
	IL_S *c, *n;
	
for (c=infolist; c != NULL; c=n) {
	if (c->info != NULL)
		free(c->info);
	n = c->next;
	free(c);
	}
	
infolist = NULL;
	
}



/**/
/**
*
* killlist_kill steps through the Kill list, deleting as it goes
*
**/

static void killlist_kill(void)
{
	KL_S *klp, *kn;
	
for (klp=kill_list; klp != NULL; klp=kn) {
	kn = klp->next;
	unlink(klp->kfname);				// Delete the kill file
	free(klp->kfname);					// Free the allocated memory
	free(klp);							// Destroy this structure
	}
	
kill_list = NULL;						// Destroy the Kill list
	
}



/**/
/**
*
* killlist_add appends a filename to the Kill list
*
**/

static void killlist_add(
const char *stoa)						// String to add
{
	KL_S *ns;
	
if ((ns = malloc(sizeof(KL_S))) == NULL)
	return;								// It didn't work!
	
ns->kfname = strdup(stoa);				// Duplicate the file to kill

ns->next = kill_list;					// Set pointer to next

kill_list = ns;							// Point to new head of list

}


/**/
/**
*
* msglist_kill empties the Message List
*
**/

static void msglist_kill(void)
{
	ML_S *c, *n;
	
for (c=msg_list; c != NULL; c=n) {
	n = c->next;
	free(c->msg);
	free(c);
	}
	
msg_list = NULL;
	
}

                
                
/**/
/**
*
* UUVBInit sets up for operation under Visual Basic
*
**/

void UUEXPORT UUVBInit(void)
{

msglist_kill();

if (micalled) 						// Master UUInit has been called
	UUCleanUp();
	
UUInitialize();

if (!micalled) {
	micalled = TRUE;

	UUSetOption(UUOPT_VERBOSE, 0, NULL);	// Shut off verbose mode by default
	UUSetMsgCallback(NULL, UUMCapture);	// Set the message callback
	UUSetBusyCallback(NULL, BusyHandler, -1);	// Set the callback loop--call every time
	}
	
cancel_flag = FALSE;			// Make sure the cancel flag is clear

infolist_clear();					// Make sure there's no current Info list

}



/**/
/**
*
* UUVBShutdown cleans up after the calling process before the
*  app unloads
*
**/

void UUEXPORT UUVBShutdown(void)
{

if (micalled)
	UUCleanUp();				// Dump any structures, etc.
	
msglist_kill();

if (info_buffer != NULL) {		// Dump an Info buffer (why's it here?)
	free(info_buffer);
	info_buffer = NULL;
	}

#if MST	
if (bogey != NULL) {
	fclose(bogey);
	bogey = NULL;
	}
#endif

infolist_clear();					// Make sure there's no current Info list

killlist_kill();					// Kill everything on the Kill list

}



/**/
/**
*
* UUVBOwnerWindow sets the owner window handle
*
* Returns old handle
*
**/

HWND UUEXPORT UUVBOwnerWindow(
HWND owner)
{
	HWND o_o;
	
o_o = owner_whdl;

owner_whdl = owner;				// Store the owner's window handle

return(o_o);
}



/**/
/**
*
* UUVBMessage gets the TOP message (if any) from the UU DLL.
*
* It also _clears_ the message list
*
* It returns TRUE if a message was found.
*
* The message is cleared after it has been retrieved
*
**/

VBoolean UUEXPORT UUVBMessage(		// Returns TRUE if a message was returned
VBSTRP str,
short *level)
{
	char *p;
	
if (msg_list == NULL) {				// Nothing there
	SETSTR(str, "No errors");
	level = 0;
	
	return(VBFALSE);				// No error located
	}

for (p=msg_list->msg; *p != EOS; p++)
	if (!isprint(*p))
		*p = ' ';			// Kill non-printable chars
	
SETSTR(str, msg_list->msg);	// Set the new string

*level = (short) msg_list->level;

msglist_kill();				// Empty the message list

return(VBTRUE);				// Flag it
}



/**/
/**
*
* UUVBMessageFIFO gets the FIRST message (if any) from the UU DLL.
*
* It returns TRUE if a message was found.
*
* The message is cleared after it has been retrieved
*
**/

VBoolean UUEXPORT UUVBMessageFIFO(		// Returns TRUE if a message was returned
VBSTRP str,
short *level)
{
	char *p;                    
	ML_S *m, *lm;
	
if (msg_list == NULL) {				// Nothing there
	SETSTR(str, "No errors");
	level = 0;
	
	return(VBFALSE);				// No error located
	}
	
m = msg_list;

while (m->next != NULL) {				// Walk to end of list
	lm = m;							// Store the "previous" message
	m = m->next;
	}

for (p=m->msg; *p != EOS; p++)
	if (!isprint(*p))
		*p = ' ';			// Kill non-printable chars
	
SETSTR(str, m->msg);	// Set the new string

*level = (short) m->level;

free(m->msg);				// Let the message itself go
free(m);					// Let the structure go

if (m == msg_list) 			// This is the top
	msg_list = NULL;		// List is now empty
else
	lm->next = NULL;		// Ground "previous" item

return(VBTRUE);				// Flag it
}



/**/
/**
*
* UUVBListWalk steps through the current file list.
*
* Returns TRUE if there are more items in the list, FALSE otherwise
*
**/

VBoolean UUEXPORT UUVBListWalk(		// Returns True if there are more items in the list
uulist *lup,					// Current item pointer
VBSTRP fname,					// Filename return
VBSTRP status,					// State of this object translated to ASCII
short *flags,					// State bitmask
uulist **next)					// "Next" item in list
{
	char wrk[256];				// Accumulator for "State"
	char cbuf[64], *cp;
	int i, testpat, *iptr;
	uufile *ufp;
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

if (UUGlobalFileList == NULL || !ListPointerCheck(lup))
	return(VBFALSE);				// No list in memory

SETSTR(fname, (lup->state & UUFILE_NODATA) ? "(No Data)" :	// No data found
	lup->filename);	// Transfer the filename

strcpy(wrk, (lup->uudet > 0) ? enc_list[lup->uudet-1] : "(No encoding)");	// Copy the encoding type

testpat = lup->state;			// Read the Test Pattern

smp = mask_list;				// Point to the mask list

for (i=sizeof(mask_list) / sizeof(struct state_mask); i>0; i--, smp++)
	if (testpat & smp->maskbits) {	// This state is on
		strcat(wrk, ", ");		// Add a comma
		strcat(wrk, smp->meaning);	// Append the definition
		}

if (lup->misparts != NULL) {	// There is a missing-parts list
	strcat(wrk, "; Missing parts: ");
	i = 0;
	for (iptr=lup->misparts; *iptr != 0; iptr++) {	// List ends with 0
		if (i++ > 0 && !safecat(wrk, sizeof(wrk), ","))
			break;				// Add a comma between second and following
		if (!safecat(wrk, sizeof(wrk), _itoa(*iptr, cbuf, 10)))
			break;				// No room for converted number
		}
	}

if (lup->thisfile != NULL) {	// There's a list of parts attached to this
	safecat(wrk, sizeof(wrk), "; From: ");
	i = 0;						// Downmarket "not the first file" flag...
	cbuf[0] = EOS;				// Compare buffer is empty
	for (ufp=lup->thisfile; ufp != NULL; ufp=ufp->NEXT)
		if (ufp->data != NULL) {	// Something to do.
			if (!strcmp(ufp->data->sfname, cbuf))
				continue;		// We've already counted this file
			strncpy(cbuf, ufp->data->sfname, sizeof(cbuf)-1);
			if (i++ > 0 && !safecat(wrk, sizeof(wrk), "+"))
				break;				// Got to add a plus sign before this filename...
			if (!safecat(wrk, sizeof(wrk), 
					((cp = strrchr(ufp->data->sfname, '\\')) != NULL) ? cp+1 : ufp->data->sfname))
				break;				// Out of room; stop here!
			}
	}

SETSTR(status, wrk);			// Store the status

*flags = testpat;				// Store the flags

*next = lup->NEXT;				// Point to next element

return((lup->NEXT != NULL) ? VBTRUE : VBFALSE);
}



/**/
/**
*
* UUVBListFirst gets the first item in the file list.
*
**/

VBoolean UUEXPORT UUVBListFirst(				// False if list is empty
uulist **first)						// Way to pass back list header
{

if (UUGlobalFileList == NULL)
	return(VBFALSE);				// No list in memory

*first = UUGlobalFileList;

return(VBTRUE);
}



/**/
/**
*
* UUVBListDelete removes an item from the file list.
*
* It returns TRUE if the operation completed OK.
*
**/

VBoolean UUEXPORT UUVBListDelete(			// Error return; always OK (TRUE) for now
uulist *todel)						// File list item to delete
{

if (!ListPointerCheck(todel))
	return(VBFALSE);				// Pointer is illegal

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

return(VBTRUE);						// So far, got no errors to report!
}



/**/
/**
*
* InfoAcc accumulates Info from a file
*
**/

static int InfoAcc(				// Returns NZ if the buffer is full
void *opaque,					// The opaque pointer, though we aren't using it
char *infoline)					// The incoming info
{
	int len;

len = strlen(infoline);

if ((info_pointer - info_buffer) + len + 3 >= INFO_SZ)
	return(1);					// Too much

strcpy(info_pointer, infoline);		// Append the incoming line

info_pointer += len - 1;			// This is where the next line will go (less the newline)

*info_pointer++ = '\r';			// Put a CRLF at the end of every line
*info_pointer++ = '\n';

return(0);						// OK to get more data
}



/**/
/**
*
* UUVBGetInfo reads Info from an item in the File List
*
**/

short UUEXPORT UUVBGetInfo(		// Returns the status code from UUInfoFile
uulist *item,					// The item that needs to be info'd
VBSTRP info)						// Return area
{
	int rc, len;

if (UUGlobalFileList == NULL)
	return(VBFALSE);				// No list in memory

if ((info_buffer = malloc(INFO_SZ)) == NULL)
	return(VBFALSE);			// Allocate storage for info

info_pointer = info_buffer;		// Point to the start of the buffer

if ((rc = UUInfoFile(item, NULL, InfoAcc)) == UURET_OK)	{	// Everything worked
	len = info_pointer - info_buffer;
	info_pointer--;				// Point to last character...

	while (len > 0 && isspace(*info_pointer)) {		// Remove trailing spaces
		len--;
		info_pointer--;
		}
              
	SETSTRL(info, info_buffer, len);
	}

free(info_buffer);				// Don't need accumulator any more

info_buffer = NULL;

return(rc);
}



/**/
/**
*
* UUVBPercent reads the percent from the progress data
*
**/

short UUEXPORT UUVBPercent(void)
{

if (progress.percent < 0)
	return(0);
else if (progress.percent > 100)
	return(100);
else       
	return(progress.percent);

}



/**/
/**
*
* UUVBProgressPart reads the part number and total number of parts
*
**/

void UUEXPORT UUVBProgressPart(
short *partno,
short *totalparts)
{

*partno = progress.partno;
*totalparts = progress.numparts;

}



/**/
/**
*
* Read the Windows version info
*
**/

void UUEXPORT GetWindowsVer(
short *win_minor,
short *win_major,
short *dos_minor,
short *dos_major)
{         
	union gwu {
		unsigned long l;
		struct gwv_s {
			unsigned long wminor : 8;
			unsigned long wmajor : 8;
			unsigned long dmajor : 8;
			unsigned long dminor : 8;
			} gs;
		} gu;
		
gu.l = GetVersion();

*win_major = (short) gu.gs.wmajor;
*win_minor = (short) gu.gs.wminor;
*dos_major = (short) gu.gs.dmajor;
*dos_minor = (short) gu.gs.dminor;

}

        
        
/**/
/**
*
* Read the library version
*
**/

RETVBSTR UUEXPORT UUVBLibVersion(void)
{
	int isto;
	char wrk[256];
	
UUGetOption(UUOPT_VERSION, &isto, wrk, sizeof(wrk)-1);

#if defined(_DEBUG)
strcat(wrk, " " __TIME__ " [DEBUG]");
#else
strcat(wrk, " " __TIME__);
#endif

return(MAKERETSTR(wrk, strlen(wrk)));	// Send back the current file name
}



/**/
/**
*
* Cancel Flag set/clear
*
* Returns the old flag value
*
**/

short UUEXPORT UUVBCancel(
short flag)
{
	short rc;
             
rc = cancel_flag;
             
cancel_flag = flag;
     
return(rc);     
}



/**/
/**
*
* msprintf protected print function
*
* Returns the total number of characters added.
*
**/

static int msprintf(
char *buffer, 
char *limit,
char *format,
va_list ap)
{
  	char *fmtp, *stringp, wrk[32], *startpos;
  	int intval;

#if MST
if (bogey == NULL)
	bogey = fopen("h:\\bogey.txt", "w");
	
fprintf(bogey, "\n\nmsprintf(\"%s\"); Limit=%d\n",
	format, limit-buffer);
#endif

limit -= 10;				// Give me a safety margin

#if MST
memset(buffer, 0, limit-buffer);		// Clear the buffer for testing so I can see what's happening
#endif

startpos = buffer;
	
fmtp = format;

while (*fmtp != EOS && buffer < limit)
	if (*fmtp == '%') {
		fmtp++;				// Skip the percent sign
		switch (*fmtp++) {
			#if MST
			case EOS:
				fputs("% End %\n", bogey);
				fmtp--;		// Make sure it finds the null
				break;
			#endif
				
			case 's':		// String                
				stringp = va_arg(ap, char *);
				#if MST
				if (IsBadReadPtr(stringp, 10))
					fprintf(bogey, "%% INVALID!! String : %Fp %%\n", stringp);
				else
					fprintf(bogey, "%% String : %Fp [%d] '%-10.10s' %%\n", 
						stringp, strlen(stringp), stringp);
				#endif						
				while (*stringp && buffer < limit)
					*buffer++ = *stringp++;
				break;
			
			case 'd':
				intval = va_arg(ap, int);
				#if MST
				fprintf(bogey, "%% Int : %d %%\n", intval);
				#endif
				itoa(intval, wrk, 10);
				for (stringp=wrk; *stringp && buffer < limit; stringp++)
					*buffer++ = *stringp;
				break;
				      
			#if MST
			default:
				fprintf(bogey, "%% Unknown percent '%c' %%", *(fmtp-1));
				break;
			#endif
			}
		}
	else {        
		#if SKIP
		fputc(*fmtp, bogey);
		#endif
		*buffer++ = *fmtp++;
		}
		      
#if MST 
fprintf(bogey, "\n----------------- %d bytes --------------------\n", buffer-startpos);
fwrite(startpos, sizeof(char), buffer-startpos, bogey);
fputs("\n----------------------------------------\n", bogey);
#endif

*buffer = EOS;
  		
return((int) (buffer - startpos));
}


/**/
/**
*
* My version of UUMessage.
*
* Handle the printing of messages. Works like printf.
*
**/

int UUMessage(
char *file, 						// File that UUMessage is called from
int line, 							// Line UUMessage is called from
int level, 							// Error level
char *format, ...)					// Formatting string
{
	char *msgptr;
	va_list ap;

va_start (ap, format);

if (level > 5)
	level = 5;

if (uu_debug) {
// 	sprintf (uulib_msgstring, "%s(%d): %s", file, line, msgnames[level]);
 	msgptr = uulib_msgstring + sprintf(uulib_msgstring, "%s(%d): %s", file, line, msgnames[level]);
	}
else {
 	strcpy(uulib_msgstring, msgnames[level]);
 	msgptr = uulib_msgstring + strlen(uulib_msgstring);
	}

if (uu_MsgCallback && (level>UUMSG_NOTE || uu_verbose)) {
// 	vsprintf (msgptr, format, ap);
	msprintf(msgptr, uulib_msgstring + 1000, format, ap);
	
 	(*uu_MsgCallback) (uu_MsgCBArg, uulib_msgstring, level);
	}

va_end (ap);

return(UURET_OK);
}


/**/
/**
*
* OwriteOK returns NZ if we can just overwrite output files
*
**/

boolean OwriteOK(void)
{
	int osta;
	char wrk[16];

wrk[0] = EOS;

UUGetOption(UUOPT_OVERWRITE, &osta, wrk, sizeof(wrk));

return(osta);
}



/**/
/**
*
* UUVBEncode is my front end to the "non-mail" encoding function(s)
*
* Returns TRUE if everything worked.
*
**/

VBoolean UUEXPORT UUVBEncode(
char *iname,						// Name of input file
char *oname,						// Name of output file
char *nameinfile,					// Name on recipient's system
short encoding,						// Type of encoding (from header)
long lines,							// Number of lines per file (<=0 means one file)
short headers,						// Header mode: 0=Off, 1=Simple MIME, 2=Mail, 3=News
char *dest,							// Destination (e-mail addr or newsgroup)
char *from,							// From (person sending message)
char *subject)						// Subject (of message)
{
	FILE *outf;
	int rc, partno;
	char *onp, *extp, *partname;
	crc32_t lcr = 0;
	
if (nameinfile != NULL && *nameinfile != EOS)
	onp = nameinfile;				// Caller has specified a name
else {								// Generate our own
	if ((onp = strrchr(iname, '\\')) == NULL) {		// Look for last slash
		if ((onp = strrchr(iname, ':')) == NULL)
			onp = iname;			// No colons, either
		else
			onp++;					// Point just past colon
		}
	else
		onp++;						// Point just past last slash
	}
	
if (lines == 0 && (extp = strrchr(oname, '.')) != NULL) 	// Set single-part extension
	UUSetOption(UUOPT_ENCEXT, 0, extp+1);
	
if (headers) {							// User wants headers
	if (lines == 0) {					// Single file
		if (!OwriteOK() && FExist(oname)) {		// Can't overwrite output file
			UUMCapture(NULL, "Output file exists", UUMSG_ERROR);
			return(VBFALSE);
			}

		if ((outf = fopen(oname, "w")) == NULL) {
			UUMCapture(NULL, "Could not open output file", 1);
			return(VBFALSE);
			}

		if (headers == UUVBE_SIMPLE)
			rc = UUEncodeMulti(outf, NULL, iname, encoding, onp, NULL, 0);
		else
			rc = UUE_PrepSingle(outf, NULL, iname, encoding, onp, 0,
				dest, from, subject, (headers == UUVBE_MAIL));
		
		fclose(outf);
		}
	else {								// Multi part
		if ((partname = _alloca(strlen(oname) + 10)) == NULL) {
			UUMCapture(NULL, "Out of Stack Space", 1);
			return(VBFALSE);
			}
			
		strcpy(partname, oname);		// Copy the output name into our temp buffer
		
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
				UUMCapture(NULL, "Output file exists", UUMSG_ERROR);
				return(VBFALSE);
				}

			if ((outf = fopen(partname, "w")) == NULL) {
				UUMCapture(NULL, "Error opening output file.", 1);
				return(VBFALSE);
				}
				
			if (headers == UUVBE_SIMPLE)
				rc = UUEncodePartial(outf, NULL, iname, encoding, onp, NULL, 
					0, partno++, (int) lines, &lcr);
			else
				rc = UUE_PrepPartial(outf, NULL, iname, encoding, onp, 0, 
					partno++, (int) lines, 0, dest, from, subject,
					(headers == UUVBE_MAIL));
			
			fclose(outf);
			} while (rc == UURET_CONT);
		}
	}
else
	rc = UUEncodeToFile(NULL, iname, encoding, onp, oname, (int) lines);

return((rc == UURET_OK) ? VBTRUE : VBFALSE);
}



/**/
/**
*
* UUVBGetAllInfo reads all the Info from the File List
*
**/

VBoolean UUEXPORT UUVBGetAllInfo(void)		// Returns TRUE or FALSE (error)
{
	int rc, len;
	uulist *up;
	IL_S *np;
	
infolist_clear();					// Make sure there's no current Info list

if (UUGlobalFileList == NULL)
	return(VBFALSE);				// No list in memory

if ((info_buffer = malloc(INFO_SZ)) == NULL)
	return(VBFALSE);			// Allocate storage for info
	
for (up=UUGlobalFileList; up != NULL; up=up->NEXT) {
	info_pointer = info_buffer;		// Point to the start of the buffer
	
	if ((rc = UUInfoFile(up, NULL, InfoAcc)) != UURET_OK)
		continue;					// Something went wrong
		
	len = info_pointer - info_buffer;
	info_pointer--;				// Point to last character...
	
	while (len > 0 && isspace(*info_pointer)) {		// Remove trailing spaces
		len--;
		info_pointer--;
		}
		
	if (len > 1) {				// Something to save
		*(info_pointer+1) = EOS;
	
		if ((np = malloc(sizeof(IL_S))) == NULL) {
			infolist_clear();
			return(VBFALSE);
			}
			
		np->info = strdup(info_buffer);
		np->key = up;
		np->len = len;
		np->next = infolist;
		
		infolist = np;
		}
	}

free(info_buffer);				// Don't need accumulator any more

info_buffer = NULL;

return(VBTRUE);
}



/**/
/**
*
* UUVBInfoListExists checks to see if a particular key has any Info stored
*
**/

VBoolean UUEXPORT UUVBInfoListExists(
uulist *look)
{
	IL_S *ilp;	

for (ilp=infolist; ilp != NULL; ilp=ilp->next)
	if (ilp->key == look)
		return(VBTRUE);
		
return(VBFALSE);
}



/**/
/**
*
* UUVBInfoListGet reads back an Info item.  Returns the empty string if
*  no info exists
*
**/

RETVBSTR UUEXPORT UUVBInfoListGet(
uulist *look)
{
	IL_S *ilp;	

for (ilp=infolist; ilp != NULL; ilp=ilp->next)
	if (ilp->key == look)
		return(MAKERETSTR(ilp->info, ilp->len));
		
return(MAKERETSTR(" ", 0));			// Send back the empty string
}



/**/
/**
*
* Read the current temporary filename.  If newname is not null,
*  the function renames the temporary file and "grabs" it away
*  from the library.
*
* In any case, returns the current temporary file name or the
*  empty string if there is a problem.
*
**/

RETVBSTR UUEXPORT UUVBGetDecTemp(
uulist *tord,						// Pointer 
const char *newname)				// New name (only extension currently used)
{                                                         
	char wrk[300], *lastsl, tname[14], *newext;
	static int tempnumber;			// Create filenames in sequence

if (!ListPointerCheck(tord) || tord->binfile == NULL || tord->binfile[0] == EOS)
	return(MAKERETSTR(" ", 0));				// Pointer is illegal or nothing there
	
if (newname == NULL || newname[0] == EOS)	// No new name
	return(MAKERETSTR(tord->binfile, strlen(tord->binfile)));	// Send back the current file name
	
if ((newext = strrchr(newname, '.')) == NULL)	// No new extension??
	return(MAKERETSTR(" ", 0));
	
strcpy(wrk, tord->binfile);			// Make a copy of the original name

sprintf(tname, "UULT%04d%s", tempnumber++, newext);	// Create the new filename

if ((lastsl = strrchr(wrk, '\\')) == NULL) {	// Look for last slash
	strcpy(wrk, tname);				// No path; just copy the new name
	lastsl = wrk;					// Set "last slash" to work buffer
	}
else
	strcpy(lastsl+1, tname);		// Add the new name to the end of the path

if (rename(tord->binfile, wrk) != 0)
	return(MAKERETSTR(" ", 0));		// Coudn't rename file???
	
_FP_free(tord->binfile);			// Temp file not there any more
tord->binfile = NULL;
tord->state	&= ~(UUFILE_TMPFILE | UUFILE_DECODED);	// Clear relevant flags

killlist_add(wrk);					// Add file to kill list

return(MAKERETSTR(wrk, strlen(wrk)));	// Send back new name	
}



/**/
/**
*
* FPOpen opens a file and returns a C File *.  Uses the same syntax
*  as fopen.
*
**/

FILE * UUEXPORT FPOpen(
const char *fname,
const char *mode)
{

	return(fopen(fname, mode));

}



/**/
/**
*
* FPClose closes a C File *.
*
**/

void UUEXPORT FPClose(
FILE *fhandle)
{

fclose(fhandle);

}



/**/
/**
*
* IdentifyOwner lets you know who owns this library
*
**/

RETVBSTR UUEXPORT UUVBIdentifyOwner(void)
{
	static char owner[] = "GPL User";

return(MAKERETSTR(owner, sizeof(owner)));
}
