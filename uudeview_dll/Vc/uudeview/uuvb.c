/**
*
* UUDeview functions related to Visual Basic operation
*
**/
#include "windows.h"
#include "ole2.h"

#include "stdio.h"
#include "ctype.h"

#include "config.h"
#include "uudeview.h"
#include "uuint.h"

extern void TOOLEXPORT _FP_free (void *ptr);	// Frank's version of free

static boolean micalled;		// Has master init been called?

static char *last_message = NULL;	// Last message from UU library
static int last_severity;			// Severity of last message

#define INFO_SZ 16384				// Size for Info buffer
static char *info_buffer = NULL;	// Storage for Info queries
static char *info_pointer;			// Pointer to where we are in the info buffer

#define EOS '\0'				// The ever-popular end-of-string

#define SKIP 0					// Cutting out code...

// VB uses mutant TRUE and FALSE...
#define VBTRUE  (-1)
#define VBFALSE (0)

typedef short VBoolean;			// VB can't use a byte like normal people


/**/
/**
*
* Some constants I've designed
*
**/

// UUVBEncode control constants
#define UUVBE_NONE		0		// No MIME headers (use standard headers)
#define UUVBE_SIMPLE	1		// Simple MIME (no addressing)
#define UUVBE_MAIL		2		// MIME E-mail format
#define UUVBE_NEWS		3		// MIME News format



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
* OwriteOK returns NZ if we can just overwrite output files
*
**/

static boolean OwriteOK(void)
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
* UUMCapture picks up messages from the UU library
*
**/

static void UUMCapture(
void *opaque,
char *message,
int level)
{

if (last_message != NULL) {
	free(last_message);
	last_message = NULL;
	}

last_message = strdup(message);
last_severity = level;

}



/**/
/**
*
* ListPointerCheck returns TRUE if a pointer is OK
*  for memory access
*
**/

static boolean ListPointerCheck(
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
* UUVBInit sets up for operation under Visual Basic
*
**/

void UUEXPORT UUVBInit(void)
{

if (last_message != NULL) {
	free(last_message);
	last_message = NULL;
	last_severity = 0;
	}

if (micalled) 						// Master UUInit has been called
	UUCleanUp();

UUInitialize();

if (!micalled) {
	micalled = TRUE;

	UUSetOption(UUOPT_VERBOSE, 1, NULL);	// Shut off verbose mode
	UUSetOption(UUOPT_DEBUG, 1, NULL);	// Shut off verbose mode

//	UUSetOption(UUOPT_VERBOSE, 0, NULL);	// Shut off verbose mode
	UUSetMsgCallback(NULL, UUMCapture);	// Set the message callback
//	UUSetBusyCallback(NULL, BusyHandler, -1);	// Set the callback loop--call every time
	}

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

if (last_message != NULL)		// Clear last message storage
	free(last_message);

if (info_buffer != NULL)		// Dump an Info buffer (why's it here?)
	free(info_buffer);

}



/**/
/**
*
* UUVBMessage gets a message (if any) from the UU DLL.
*
* It returns TRUE if a message was found.
*
* The message is cleared after it has been retrieved
*
**/

VBoolean UUEXPORT UUVBMessage(		// Returns TRUE if a message was returned
BSTR *str,
short *level)
{

if (last_message != NULL) {		// Got a message on hand
	SETSTR(str, last_message);	// Set the new string

	*level = (short) last_severity;

	free(last_message);			// Clear previous message
	last_message = NULL;
	return(VBTRUE);				// Flag it
	}

SETSTR(str, "No errors");
level = 0;

return(VBFALSE);				// No error located
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
BSTR *fname,					// Filename return
BSTR *status,					// State of this object translated to ASCII
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
		"BinHex Encoded"
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
BSTR *info)						// Return area
{
	int rc, len;

if (UUGlobalFileList == NULL)
	return(VBFALSE);				// No list in memory

if ((info_buffer = malloc(INFO_SZ)) == NULL)
	return(VBFALSE);			// Allocate storage for info

info_pointer = info_buffer;		// Point to the start of the buffer

if ((rc = UUInfoFile(item, NULL, InfoAcc)) == UURET_OK) {		// Everything worked
	len = info_pointer - info_buffer;	// Grab length
	info_pointer--;				// Point to last character...

	while (len > 0 && isspace(*info_pointer)) {		// Remove trailing spaces
		len--;
		info_pointer--;
		}

	SysFreeString(*info);			// Free the old string
	*info = SysAllocStringByteLen(info_buffer, len);
	}

free(info_buffer);				// Don't need accumulator any more

info_buffer = NULL;

return(rc);
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



/**/
/**
*
* Read the library version
*
**/

BSTR UUEXPORT UUVBLibVersion(void)
{
	int isto;
	char wrk[256];
	
UUGetOption(UUOPT_VERSION, &isto, wrk, sizeof(wrk)-1);

strcat(wrk, " " __TIMESTAMP__);

return(SysAllocStringByteLen(wrk, strlen(wrk)));	// Send back the version information
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
					0, partno++, (int) lines);
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




