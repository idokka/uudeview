/**
*
* UUDW contains functions needed by UUDeview for Windows,
*  but probably not much use to anyone else
*
**/
#include "windows.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "io.h"

#include "vbapi.h"

#include "config.h"

#include "uudeview.h"

#include "miken.h"

extern uuprogress progress;		// The global progress structure


//
// Context Menu data structure
//
typedef struct cmenu_stuct {
	char *menuitem;				// Text of the menu item (NULL = Separator)
	long mask;					// Disable if this bit set
	int	mid;					// Menu ID to use
	} CM_S;


/**/
/**
*
* UUDecodeOptionMenu shows a popup menu that allows the user to set the
*  decoding options
*
* Menus:
*		0		Decode Output
*		1		Decode Input
*
**/

VBoolean UUEXPORT UUDecodeContextMenu(		// Returns FALSE for error or TRUE for OK
short menusel,						// Which menu to show
HWND owner,							// Form's window handle
HDC ohdc,							// Form's device context
HWND listbox,						// List box's window handle
short x,							// Origin point for menu
short y,
long flags)							// Word used to disable certain options
{
	int i, omapmode;
	HMENU mh;
	CM_S *cmsp;
	POINT pt;
	static CM_S menu_init[] ={
		"&Info",				(1 << 0),		101,
		"&Remove",				(1 << 1),		102,
		"R&ename",				(1 << 2),		103,
		NULL,						   0,		  0,
		"Select &None",				   0,		104,
		"Select &All",				   0,		105,
		"In&vert Selection", 		   0,		106,
		NULL,						   0,		  0,
//		"&Decode Selected",		(1 << 3),		107,
		"Decode && &Launch...", (1 << 4),		108,
		NULL,						   0,		  0,
		"&Help",					   0,		199  
		};
	static CM_S dci_menu[] ={
		"&Remove",				(1 << 1),		201,
		NULL,						   0,		  0,
		"Select &None",				   0,		202,
		"Select &All",				   0,		203,
		"In&vert Selection", 		   0,		204,
		NULL,						   0,		  0,
		"&Launch...", 			(1 << 2),		205,
		NULL,						   0,		  0,
		"&Help",					   0,		299  
		};

if ((mh = CreatePopupMenu()) == NULL)
	return(VBFALSE);					// Couldn't create menu
	
switch (menusel) {
	case 0:					// Decode output
		cmsp = menu_init;
		i = sizeof(menu_init) / sizeof(CM_S);
		break;
		
	case 1:
		cmsp = dci_menu;
		i = sizeof(dci_menu) / sizeof(CM_S);
		break;
		
	}

for (; i > 0; i--, cmsp++)
	if (cmsp->menuitem == NULL) {		// This is a separator
		if (AppendMenu(mh, MF_SEPARATOR, 0, NULL) == FALSE) {
			DestroyMenu(mh);
			return(VBFALSE);
			}
		}
	else {
		if (AppendMenu(mh,				// Normal menu item
			 (flags & cmsp->mask) ? (MF_STRING | MF_GRAYED) : MF_STRING,
			 cmsp->mid, cmsp->menuitem) == FALSE) {	// Couldn't add menu item
			DestroyMenu(mh);
			return(VBFALSE);
			}
		}
		
pt.x = x;							// Start with original coordinates
pt.y = y;

omapmode = GetMapMode(listbox);
SetMapMode(ohdc, MM_TWIPS);			// We're coming from twips

LPtoDP(ohdc, &pt, 1);

SetMapMode(ohdc, omapmode);			// Restore old mapping mode

pt.y = -pt.y;

ClientToScreen(listbox, &pt);

i = TrackPopupMenu(mh, TPM_LEFTALIGN | TPM_LEFTBUTTON, 
				   pt.x, pt.y, 0, owner, NULL);	// Pop up the menu

DestroyMenu(mh);					// Delete the menu we created

return((i) ? VBTRUE : VBFALSE);		// TPM sends back C true
}



/**/
/**
*
* SETSTR does the equivalent of a SysReallocStr except it accepts
*  a C-style string.
*
* I could do this with a macro, but since this was a port from 32-bit, I want
*  the type checking.
*
**/

void SETSTR(
HLSTR dest,						// Destination
char *source)				// Source
{

if (source == NULL) 
	VBSetHlstr(&dest, "(NULL)", 6); 	// Guard against NULL pointers (shouldn't happen)
else
	VBSetHlstr(&dest, source, strlen(source));

}



/**/
/**
*
* SETSTRL does the equivalent of a SysReallocStr except it accepts
*  a C-style string, this time with a length
*
**/

void SETSTRL(
HLSTR dest,						// Destination
char *source,				// Source
unsigned int len)				// Length
{

if (source == NULL) 
	VBSetHlstr(&dest, "(NULL)", 6); 	// Guard against NULL pointers (shouldn't happen)
else
	VBSetHlstr(&dest, source, len);

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

VBSTRP UUEXPORT UUVBFileFilter(		// Returns filtered string
LPSTR inp)
{
	boolean extflag = FALSE;		// Got one extension
	LPSTR src, wp;
	char c, wrk[14];
	int len;
	static char *exc = "<>:\"|";	// Things not to allow in filenames

len = strlen(inp);		// Read original string length

if (len == 0)
	return(inp);					// Might as well just send it back
	
wp = wrk;

src = inp;

len = 8;							// Max before extension

while (len > 0) {                   // Copy the 8...
	c = *src++;						// Read one source byte
	if (c == EOS || c == '.')		// Stop
		break;
	if (c > ' ' && strchr(exc, c) == NULL) {	// OK to copy
		*wp++ = tolower(c);	// Force lower Case
		len--;
		}
	}
	
if ((src = strrchr(inp, '.')) != NULL) {	// Got an extension
	*wp++ = '.';					// Add the dot
	src++;
	
	len = 3;						// Max AFTER extension
	
	while (len > 0) {               // Copy the 3...
		c = *src++;					// Read one source byte
		if (c == EOS)				// Stop
			break;
		if (c > ' ' && strchr(exc, c) == NULL) {	// OK to copy
			*wp++ = tolower(c);		// Force Lower Case
			len--;
			}
		}
	}

*wp = EOS;							// Just end it

for (wp=wrk; *wp == '.'; wp++)
	;								// Remove any leading dots

return(MAKEVBSTR(wp, strlen(wp)));	// Send back the fixed file name
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

return(_access(filename, 0) == 0);
                
}



/**/
/**
*
* UUVBProgressName returns the current file being worked on...
*
**/

HLSTR UUEXPORT UUVBProgressName(void)
{

return(VBCreateHlstr(progress.curfile, strlen(progress.curfile)));	// Send back the current file name

}



/**/
/**
*
* UUVBSaveClipboard writes the current clipboard contents to a temp file.
*
* If the temp name is empty, creates a new temporary file.
*
* Returns 0 for error (no useful data on clipboard, etc.) or the new
*  size of the clipboard file.
*
* Empties the clipboard after a successful operation.
*
**/

long UUEXPORT UUVBSaveClipboard(
HWND owner,								// Owner window handle
VBSTRP clipfile)							// Clipboard file
{
	FILE *cf;
	LPSTR cfn;
	HANDLE cdata;
	DWORD csize;
	size_t bsize;  
	long rc;
	char createf;
	char _huge *cp, _huge *eob;
	char wrk[256];

if (!IsClipboardFormatAvailable(CF_TEXT))
	return(0);								// No text on clipboard
	
cfn = VBDerefHlstrLen(clipfile, &bsize);	// Grab the current clipboard filename

if (bsize >= sizeof(wrk))
	return(0);							// Path name is too long

if (bsize == 0) {		// Need to create a new clipboard filename
	if (GetTempFileName(0, "uud", 0, wrk) == 0)
		return(0);						// Couldn't create temp name??
	SETSTR(clipfile, wrk);				// Set the caller's clipboard file name
	createf = TRUE;
	}
else {									// Existing clipboard string
	memcpy(wrk, cfn, bsize);				// Copy the path name       
	wrk[bsize] = EOS;					// Terminate string
	createf = FALSE; 
	}
	
if ((cf = fopen(wrk, (createf) ? "wb" : "ab")) == NULL)
	return(0);							// Couldn't create/append temp
	
if (OpenClipboard(owner) == FALSE) {
	fclose(cf);
	return(0);							// Couldn't grab clipboard
	}
	
if ((cdata = GetClipboardData(CF_TEXT)) == NULL ||	// Couldn't get handle
	 (cp = GlobalLock(cdata)) == NULL) {	// Couldn't lock it
	CloseClipboard();					// Let go of clipboard 
	fclose(cf);
	return(0);
	}
	
csize = GlobalSize(cdata);				// Read the size of the clipboard

while (csize > 0) {
	bsize = (csize > 8192) ? 8192 : (int) csize;	// Size of this block
	if ((eob = memchr(cp, 0, bsize)) != NULL) {
		csize = eob - cp;		// Found the end of the buffer...
		bsize = (int) csize;
		}
	if (fwrite(cp, 1, bsize, cf) != bsize) {	// Error writing
		rc = 0;
		goto emex;
		}
	csize -= bsize;
	cp += bsize;
	}
	
rc = ftell(cf);							// OK---we'll return the new file size

emex:

fclose(cf);
GlobalUnlock(cdata);

if (rc != 0)
	EmptyClipboard();					// Operation was OK, clear clipboard
	
CloseClipboard();

return(rc);
}



/**/
/**
*
* UUVBClipFile fills the Clipboard from a file
*
* It returns True if everything worked.
*
**/

VBoolean UUEXPORT UUVBClipFile(
HWND owner,							// New owner of clipboard
const char *tfile)					// Text file to put on clipboard
{
	HGLOBAL mh = NULL;
	char _huge *mp = NULL;
	char wrk[1024];
	FILE *inf = NULL;
	long fsize;
	unsigned int block;
	VBoolean rc = VBFALSE;
	
if ((inf = fopen(tfile, "rb")) == NULL)
	return(VBFALSE);				// Couldn't get the source file
	
if ((fsize = _filelength(_fileno(inf))) <= 0 ||	// Couldn't open clipboard
   (mh = GlobalAlloc(GMEM_MOVEABLE, fsize + 10)) == NULL ||		// Couldn't allocate memory
   (mp = GlobalLock(mh)) == NULL) 	// No lock
	goto emex;
	
while (fsize > 0) {
	block = (fsize > sizeof(wrk)) ? sizeof(wrk) : (unsigned int) fsize;
	if (fread(wrk, sizeof(char), block, inf) != block)
		goto emex;					// Couldn't read the block
	_fmemcpy(mp, wrk, block);		// Copy it
	mp += block;					// Point to next memory dest
	fsize -= block;
	}
	
*mp = EOS;							// The last char is always a null

GlobalUnlock(mh);
mp = NULL;							// Unlock the block so we can put it on the clipboard

if (OpenClipboard(owner) == 0)
	goto emex;						// Couldn't prep the clipboard
	
if (EmptyClipboard() == 0 ||		// Couldn't empty it
   SetClipboardData(CF_TEXT, mh) == NULL) {		// Couldn't set the new data
	CloseClipboard();
	goto emex;
	}
	
CloseClipboard();

rc = VBTRUE;						// OK!

emex:

if (mp != NULL)
	GlobalUnlock(mh);				// Have to unlock

if (!rc && mh != NULL)
	GlobalFree(mh);					// Error---free the memory
	
fclose(inf);

return(rc);
}
