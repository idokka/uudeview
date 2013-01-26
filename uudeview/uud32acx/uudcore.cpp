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

//
// ------------------------- UUCHECK.C ------------------------------------------
//

//
// UUD32 C++ Wrapper Function implementation
//
#include "uudcore.h"
#pragma hdrstop


//
// Setup
//

UUDWrap::UUDWrap()
{

ResetVars();

uulibversion = strdup(VERSION "pl" PATCH);

}



//
// UnSetup
//

UUDWrap::~UUDWrap()
{

UUCleanUp();

free(uulibversion);

}


//
// ResetVars puts everything back to zero
//
void UUDWrap::ResetVars(void)
{

UUGlobalFileList = NULL;

uu_FileCallback = NULL;

uu_MsgCBArg  = NULL;
uu_BusyCBArg = NULL;
uu_FileCBArg = NULL;
uu_FFCBArg   = NULL;

/*
 * Global variables
 */

uu_fast_scanning = 0;		/* assumes at most 1 part per file			*/
uu_bracket_policy = 0;		/* gives part numbers in [] higher priority */
uu_verbose = 1;				/* enables/disables messages&notes			*/
uu_desperate = 0;			/* desperate mode							*/
uu_ignreply = 0;			/* ignore replies							*/
uu_debug = 0;				/* debugging mode (print __FILE__/__LINE__) */
uu_errno = 0;				/* the errno that caused this UURET_IOERR	*/
uu_dumbness = 0;			/* switch off the program's intelligence	*/
uu_overwrite = 0;			/* whether it's ok to overwrite ex. files	*/
uu_ignmode = 0;				/* ignore the original file mode			*/
uu_handletext = 0;			/* do we want text/plain messages			*/
uu_usepreamble = 0;			/* do we want Mime preambles/epilogues		*/
uu_tinyb64 = 0;				/* detect short B64 outside of MIME			*/
uu_headercount = 0;
uu_remove_input = 0;
uu_more_mime = 0;
uu_strict_filename = 0;		/* Require strict filename processing */

hlcount.restart = 3;					/* restarting after a MIME body				*/
hlcount.afterdata = 2;							/* after useful data in freestyle mode		*/
hlcount.afternl =   1;								/* after useful data and an empty line		*/

progress.action	  = 0;
progress.curfile[0] = '\0';

ftodel = NULL;

uusavepath  = NULL;
uuencodeext = NULL;

mssdepth = 0;
memset(&localenv, 0, sizeof (headers));
memset(&sstate,	 0, sizeof (scanstate));

nofnum	= 0;
mimseqno = 0;
lastvalid = 0;
lastenc	= 0;
uuyctr	= 0;

uu_last_usecs = 0;

lastpart = 0;

//
// Static substitutes
dl_leftover = 0;
DP_bhflag = 0;
SCD_p3 = NULL;
UUb_rpc = 0;

UUInitConc();

}
