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
// UUDeview C++ Wrapper Header File
//

//
// MikeN Additions
//             
#define VERSION "0.5"
#define PATCH "16"

#define SKIP 0

#define INFO_BUFFER_SZ 16384		// Info accumulator buffer size

#define STDC_HEADERS 1

#define BUSY_MSECS				333			// Interval to call Busy callback


/*
 * Message Types
 */

#define UUMSG_MESSAGE	(0)	/* just a message, nothing important */
#define UUMSG_NOTE	(1)	/* something that should be noticed */
#define UUMSG_WARNING	(2)	/* important msg, processing continues */
#define UUMSG_ERROR	(3)	/* processing has been terminated */
#define UUMSG_FATAL	(4)	/* decoder cannot process further requests */
#define UUMSG_PANIC	(5)	/* recovery impossible, app must terminate */

/*
 * Return Values
 */

#define UURET_OK	(0)	/* everything went fine */
#define UURET_IOERR	(1)	/* I/O Error - examine errno */
#define UURET_NOMEM	(2)	/* not enough memory */
#define UURET_ILLVAL	(3)	/* illegal value for operation */
#define UURET_NODATA	(4)	/* decoder didn't find any data */
#define UURET_NOEND	(5)	/* encoded data wasn't ended properly */
#define UURET_UNSUP	(6)	/* unsupported function (encoding) */
#define UURET_EXISTS	(7)	/* file exists (decoding) */
#define UURET_CONT	(8)	/* continue -- special from ScanPart */
#define UURET_CANCEL	(9)	/* operation canceled */

/*
 * File states, may be OR'ed
 */

#define UUFILE_READ	(0)	/* Read in, but not further processed */
#define UUFILE_MISPART	(1)	/* Missing Part(s) detected */
#define UUFILE_NOBEGIN	(2)	/* No 'begin' found */
#define UUFILE_NOEND	(4)	/* No 'end' found */
#define UUFILE_NODATA	(8)	/* File does not contain valid uudata */
#define UUFILE_OK	(16)	/* All Parts found, ready to decode */
#define UUFILE_ERROR	(32)	/* Error while decoding */
#define UUFILE_DECODED	(64)	/* Successfully decoded */
#define UUFILE_TMPFILE	(128)	/* Temporary decoded file exists */
#define UUFILE_GENFN	(256)	// Generated filename

/*
 * Encoding Types
 */

#define UU_ENCODED	(1)	/* UUencoded data   */
#define B64ENCODED	(2)	/* Mime-Base64 data */
#define XX_ENCODED	(3)	/* XXencoded data   */
#define BH_ENCODED	(4)	/* Binhex encoded   */
#define PT_ENCODED	(5)	/* Plain-Text encoded (MIME) */
#define QP_ENCODED	(6)	/* Quoted-Printable (MIME)   */
#define YENC_ENCODED	(7)	/* yEnc encoded */

/*
 * Option indices for GetOption / SetOption
 */

#define UUOPT_VERSION	(0)	/* version number MAJOR.MINORplPATCH (ro) */
#define UUOPT_FAST	(1)	/* assumes only one part per file */
#define UUOPT_DUMBNESS	(2)	/* switch off the program's intelligence */
#define UUOPT_BRACKPOL	(3)	/* give numbers in [] higher precendence */
#define UUOPT_VERBOSE	(4)	/* generate informative messages */
#define UUOPT_DESPERATE	(5)	/* try to decode incomplete files */
#define UUOPT_IGNREPLY	(6)	/* ignore RE:plies (off by default) */
#define UUOPT_OVERWRITE	(7)	/* whether it's OK to overwrite ex. files */
#define UUOPT_SAVEPATH	(8)	/* prefix to save-files on disk */
#define UUOPT_IGNMODE	(9)	/* ignore the original file mode */
#define UUOPT_DEBUG	(10)	/* print messages with FILE/LINE info */
#define UUOPT_ERRNO	(14)	/* get last error code for UURET_IOERR (ro) */
#define UUOPT_PROGRESS	(15)	/* retrieve progress information */
#define UUOPT_USETEXT	(16)	/* handle text messages */
#define UUOPT_PREAMB	(17)	/* handle Mime preambles/epilogues */
#define UUOPT_TINYB64	(18)	/* detect short B64 outside of Mime */
#define UUOPT_ENCEXT	(19)	/* extension for single-part encoded files */
#define UUOPT_REMOVE    (20)    /* remove input files after decoding */
#define UUOPT_MOREMIME  (21)    /* strict MIME adherence */
#define UUOPT_STRICTFN  (22)	/* strict filename adherence */

/*
 * Code for the "action" in the progress structure
 */

#define UUACT_IDLE	(0)	/* we don't do anything */
#define UUACT_SCANNING	(1)	/* scanning an input file */
#define UUACT_DECODING	(2)	/* decoding into a temp file */
#define UUACT_COPYING	(3)	/* copying temp to target */
#define UUACT_ENCODING	(4)	/* encoding a file */
#define UUACT_NEWSTEP	(9) /* we are starting a new step */

 /*
 * Information from the headers of a message. Each instance must
 * have its very own copy of the strings. If `mimevers' is NULL,
 * then this message does not comply to the MIME standard.
 */

typedef struct _headers {
  char *from;			/* From:										  */
  char *subject;		/* Subject:										  */
  char *rcpt;			/* To:											  */
  char *date;			/* Date:										  */
  char *mimevers;		/* MIME-Version:								  */
  char *ctype;			/* Content-Type:								  */
  char *ctenc;			/* Content-Transfer-Encoding:					  */
  char *fname;			/* Potential Filename from Content-Type Parameter */
  char *boundary;		/* MIME-Boundary from Content-Type Parameter	  */
  char *mimeid;			/* MIME-Id for Message/Partial					  */
  int partno;			/* part number for Message/Partial				  */
  int numparts;			/* number of parts for Message/Partial			  */
} headers;

/*
 * Scanner state
 */

typedef struct _scanstate {
  int isfolder;			/* if we think this is a valid email folder		  */
  int ismime;			/* if we are within a valid MIME message		  */
  int mimestate;		/* state of MIME scanner						  */
  int mimeenc;			/* encoding of this MIME file					  */
  char *source;			/* source filename								  */
  headers envelope;		/* mail envelope headers						  */
} scanstate;

/*
 * Structure that holds the information for a single file / part of
 * a file. If a subject line is encountered, it is copied to subject;
 * if a begin is found, the mode and name of the file is extracted.
 * flags are set if 'begin' or 'end' is detected and 'uudet' if valid
 * uuencoded data is found. If the file contains a 'From:' line with
 * a '@' in it (indicating an origin email address), it is preserved
 * in 'origin'.
 **/

typedef struct _fileread {
  char *subject;		/* Whole subject line */
  char *filename;		/* Only filled in if begin detected */
  char *origin;			/* Whole 'From:' line */
  char *mimeid;			/* the ID for Mime-encoded files */
  char *mimetype;		/* Content-Type */
  short mode;			/* Mode of File (from 'begin') */
  int	begin;			/* begin detected */
  int	end;			/* end detected */
  int	flags;			/* associated flags */

  short uudet;			/* valid encoded data. value indicates encoding */
  short partno;			/* Mime-files have a part number within */
  short maxpno;			/* ... plus the total number of parts	*/

  char *sfname;			/* Associated source file */
  long startpos;		/* ftell() position where data starts */
  long length;			/* length of data */

  bool genfn;			// Generated Filename flag (added by MikeN)
} fileread;

/*
 * Structure for holding one part of a file, with some more information
 * about it. The UUPreProcessPart() function takes one a fileread structure
 * and produces this uufile structure.
 * Linked List, ordered by partno.
 **/

typedef struct _uufile {
  char	   *filename;
  char	   *subfname;
  char	   *mimeid;
  char	   *mimetype;
  short		partno;
  fileread *data;
  struct _uufile *NEXT;
} uufile;

/*
 * Structure for holding the list of files that have been found
 * uufile items are inserted into this list with UUInsertPartToList
 * After inserting a bunch of files, UUCheckGlobalList must be called
 * to update the states.
 */

typedef struct _uulist {
  short    state;		/* Status as described by the macros above */
  short    mode;		/* file mode as found on begin line        */

  int      begin;		/* part number where begin was detected    */
  int      end;			/* part number where end was detected      */

  short    uudet;		/* Encoding type (see macros above)        */
  int      flags;		/* flags, especially for single-part files */

  long     size;		/* approximate size of resulting file      */
  char    *filename;		/* malloc'ed file name                     */
  char    *subfname;		/* malloc'ed ID from subject line          */
  char    *mimeid;		/* malloc'ed MIME-ID, if available         */
  char    *mimetype;		/* malloc'ed Content-Type, if available    */

  char    *binfile;		/* name of temp file, if already decoded   */

  struct _uufile *thisfile;	/* linked list of this file's parts        */

  int     *haveparts;		/* the parts we have (max. 256 are listed) */
  int     *misparts;		/* list of missing parts (max. 256)        */

  struct _uulist *NEXT;		/* next item of the list                   */
  struct _uulist *PREV;		/* previous item of the list               */
} uulist;

/*
 * The "progress" structure which is passed to the Busy Callback
 */

typedef struct {
  int  action;			/* see UUACT_* definitions above           */
  char curfile[256];		/* the file we are working on, incl. path  */
  int  partno;			/* part we're currently decoding           */
  int  numparts;		/* total number of parts of this file      */
  long fsize;			/* size of the current file                */
  int  percent;			/* % of _current part_                     */
  long foffset;			/* file offset -- internal use only        */
  long totsize;			/* file total size -- internal use only    */
} uuprogress;


/*
 * How many lines of headers do we need to believe another mail
 * header is approaching? Use more restrictive values for MIME
 * mails, less restrictive for Freestyle
 */

typedef struct {
  int restart;			/* restarting after a MIME body (not subpart) */
  int afterdata;		/* after we had useful data in freestyle mode */
  int afternl;			/* after an empty line in freestyle mode	  */
} headercount;


/*
 * Linked list of files we want to delete after decoding
 */

typedef struct _itbd {
  char *fname;
  struct _itbd *NEXT;
} itbd;


// UUVBEncode control constants
#define UUVBE_NONE		0		// No MIME headers (use standard headers)
#define UUVBE_SIMPLE	1		// Simple MIME (no addressing)
#define UUVBE_MAIL		2		// MIME E-mail format
#define UUVBE_NEWS		3		// MIME News format

typedef unsigned long crc32_t;
#define Z_NULL  0

crc32_t crc32(crc32_t crc, const unsigned char *buf, unsigned int len);

//
// The UUDeview Wrapper Class
//
  
class UUDWrap {
	private:
		//
		// UULib
		//
		int uu_fast_scanning;		/* assumes at most 1 part per file			*/
		int uu_bracket_policy;		/* gives part numbers in [] higher priority */
		int uu_verbose;				/* enables/disables messages&notes			*/
		int uu_desperate;			/* desperate mode							*/
		int uu_ignreply;			/* ignore replies							*/
		int uu_debug;				/* debugging mode (print __FILE__/__LINE__) */
		int uu_errno;				/* the errno that caused this UURET_IOERR	*/
		int uu_dumbness;			/* switch off the program's intelligence	*/
		int uu_overwrite;			/* whether it's ok to overwrite ex. files	*/
		int uu_ignmode;				/* ignore the original file mode			*/
		int uu_handletext;			/* do we want text/plain messages			*/
		int uu_usepreamble;			/* do we want Mime preambles/epilogues		*/
		int uu_tinyb64;				/* detect short B64 outside of MIME			*/
		int uu_headercount;
		int uu_remove_input;
		int uu_more_mime;
		int uu_strict_filename;

		int (*uu_FileCallback)(void *, char *, char *, int);

		void *uu_MsgCBArg;
		void *uu_BusyCBArg;
		void *uu_FileCBArg;
		void *uu_FFCBArg;

		char uugen_fnbuffer[1024];	 /* generic filename buffer */
		char uugen_inbuffer[1024];	 /* generic input data buffer */
		char uucheck_lastname[256];	 /* from uucheck.c */
		char uucheck_tempname[256];
		char uuestr_itemp[256];	 /* from uuencode.c:UUEncodeStream() */
		char uuestr_otemp[256];
		char uulib_msgstring[1024];	 /* from uulib.c:UUMessage() */
		char uuncdl_fulline[256];	 /* from uunconc.c:UUDecodeLine() */
		char uuncdp_oline[512];	 /* from uunconc.c:UUDecodePart() */
		char uunconc_save[3*256];	 /* from uunconc.c:decoding buffer */
		char uuscan_shlline[1024];	 /* from uuscan.c:ScanHeaderLine() */
		char uuscan_pvvalue[256];	 /* from uuscan.c:ParseValue() */
		char uuscan_phtext[256];	 /* from uuscan.c:ParseHeader() */
		char uuscan_sdline[256];	 /* from uuscan.c:ScanData() */
		char uuscan_sdbhds1[256];
		char uuscan_sdbhds2[256];
		char uuscan_spline[256];	 /* from uuscan.c:ScanPart() */
		char uuutil_bhwtmp[256];	 /* from uuutil.c:UUbhwrite() */

		/*
		 * version string
		 */

		char *uulibversion;

		/*
		 * prefix to the files on disk, usually a path name to save files to
		 */

		char *uusavepath;

		/*
		 * extension to use when encoding single-part files
		 */

		char *uuencodeext;

		/*
		 * time values for BusyCallback. msecs is MILLIsecs here
		 */

//		long uu_busy_msecs;	/* call callback function each msecs */
//		long uu_last_secs;	/* secs	 of last call to callback */
		unsigned long uu_last_usecs;	/* usecs of last call to callback */

		/*
		 * progress information
		 */

		uuprogress progress;

		itbd *ftodel;			// Files to delete

		/*
		 * for the busy poll
		 */

		unsigned long uuyctr;

		//
		// UUCheck
		//

		/*
		 * State of Scanner function and PreProcessPart
		 */

		int lastvalid, lastenc, nofnum;
		int	lastpart;

		char *UUGetFileName (char *subject, char *ptonum, char *ptonend);
		int UUGetPartNo (char *subject, char **where, char **whend);
		uufile * UUPreProcessPart (fileread *data, int *ret);
		int UUInsertPartToList (uufile *data);
		uulist * UUCheckGlobalList (void);

		//
		// UUEncode
		//
		int UUEncodeStream (FILE *outfile, FILE *infile, int encoding, 
							 long linperfile, crc32_t *crc, crc32_t *pcrc);

		FILE *EncPart_theifile;

		int PP_numparts, PP_themode;
		char PP_mimeid[64];
		FILE *PP_theifile;

		//
		// UUnconc
		//
		size_t UUDecodeLine (char *s, char *d, int method);
		int dl_leftover;

		char *save[3];

		int DP_bhflag;

		short UUxlat[256];	/* from uunconc.c:toplevel */
		short UUxlen[64];
		short B64xlat[256];
		short XXxlat[256];
		short BHxlat[256];

		/*
		 * Return information for QuickDecode
		 */

		int uulboundary;

		int UUQuickDecode (FILE *datain, FILE *dataout, char *boundary, long maxpos);
		int UUDecodePart (FILE *datain, FILE *dataout, int *state,
 			  long maxpos, int method, int flags,
 			  char *boundary);
		int UUDecodePT (FILE *datain, FILE *dataout, int *state,
 			long maxpos, int method, int flags,
 			char *boundary);
		int UUDecodeQP (FILE *datain, FILE *dataout, int *state,
 			long maxpos, int method, int flags,
 			char *boundary);
		int UURepairData (FILE *datei, char *line, int encoding, int *bhflag);
		int UUValidData (char *ptr, int encoding, int *bhflag);
		int UUNetscapeCollapse (char *string);
		int UUBrokenByNetscape (char *string);
		void UUInitConc (void);

		//
		// UUScan
		//
		int mimseqno;

		int mssdepth;
		scanstate multistack[5];

		char *SCD_ptr, *SCD_p2, *SCD_p3, *SCD_bhdsp, SCD_bhl;

		/*
		 * The state and the local envelope
		 */
		headers	  localenv;
		scanstate sstate;
		headercount hlcount;

		char *ScanHeaderLine (FILE *datei, char *initial);
		int UUScanHeader (FILE *datei, headers *envelope);
		char *ParseValue (char *attribute, int looseValue = 0);
		headers *ParseHeader (headers *theheaders, char *line);
		int IsKnownHeader (char *line);
		int ScanData (FILE *datei, char *fname, int *errcode,
 		  char *boundary, int ismime, int checkheaders,
 		  fileread *result);
		fileread * ScanPart (FILE *datei, char *fname, int *errcode);

		//
		// UUUtil
		//

		void UUkillfread (fileread *data);
		void UUkillfile (uufile *data);
		void UUkillheaders (headers *data);
		int UUSMPKnownExt (char *filename);
		int UUbhdecomp (char *in, char *out, char *last, int *rpc,
 			size_t inc, size_t max, size_t *opc);
		size_t UUbhwrite (char *ptr, size_t sel, size_t nel, FILE *file);
		uulist *UU_smparts_r (uulist *addit, int pass);
		int UUSmerge (int pass);

		int UUb_rpc;
		char UUb_lc;

		//
		// FP Tools
		//
		char *strtok_optr;

	protected:
		/*
		 * The Global List of Files
		 */

		uulist *UUGlobalFileList;

		int UUMessage(char *file, int line, int level, char *format, ...);
		int UUBusyPoll (void);
		virtual void MessageHandler(char *message, int level) { };
		virtual int BusyCallback(uuprogress *) { return(0); };
		static void _FP_free (void *ptr);
		static char * _FP_strdup (char *string);
		static char * _FP_strncpy (char *dest, char *src, int length);
		static void * _FP_memdup (void *ptr, int len);
		static int _FP_stricmp (char *str1, char *str2);
		static int _FP_strnicmp (char *str1, char *str2, int count);
		static char * _FP_strstr (char *str1, char *str2);
		static char * _FP_strpbrk (char *str, char *accept);
		static char * _FP_strtok (char *str1, char *str2);
		static char * _FP_stristr (char *str1, char *str2);
		static char * _FP_strrstr (char *ptr, char *str);
		static char * _FP_strirstr (char *ptr, char *str);
		static char * _FP_stoupper (char *input);
		static char * _FP_stolower (char *input);
		static int _FP_strmatch (char *string, char *pattern);
		static char * _FP_strrchr (char *string, int tc);
		static char * _FP_cutdir (char *filename);
		static char * _FP_fgets (char *buf, int n, FILE *stream);
		static char * _FP_strerror (int errcode);
//		static char * _FP_tempnam (char *dir, char *pfx);
		char *uustring (int codeno);

		void UUkilllist (uulist *data);
		int OwriteOK(void) const { return(uu_overwrite); }	// Return "Overwrite OK" flag

	public:
		//
		// My additional functions
		//
		// Called by UUInfoFile
		virtual int UUInfoHandler(void *opaque, 
			char *uugen_inbuffer) { return(1); }	// Just stop if no handler

		//
		// Function called to delete input files that had data when 
		//  uu_remove_input is set.
		//
		// This behavior is so dangerous that the default implementation does nothing
		//
		// Return True to continue the removal loop
		//

			
		UUDWrap();
		~UUDWrap();
		void ResetVars(void);
		virtual char *UUFNameFilter(char *fname) { return(fname); };
		int UUGetOption (int option, int *ivalue, char *cvalue, int clength);
		int UUSetOption (int option, int ivalue, char *cvalue);
		uulist * UUGetFileListItem (int item);
		char * UUstrerror (int code);
		int UUDecode (uulist *data);
		int UULoadFile (char *filename, char *fileid, int delflag);
		int UUDecodeFile (uulist *thefile, char *destname);
		int UURenameFile (uulist *thefile, char *newname);
		int UURemoveTemp (uulist *thefile);
		int UUCleanUp (void);
		int UUInfoFile (uulist *thefile, void *opaque);
		int UUE_PrepPartial (FILE *outfile, FILE *infile,
 				 char *infname, int encoding,
 				 char *outfname, int filemode,
 				 int partno, long linperfile, long filesize,
 				 char *destination, char *from, char *subject,
 				 int isemail);
		int UUE_PrepSingle (FILE *outfile, FILE *infile,
 				char *infname, int encoding,
 				char *outfname, int filemode,
 				char *destination, char *from,
 				char *subject, int isemail);
		int UUE_PrepSingleExt (FILE *outfile, FILE *infile,
			   char *infname, int encoding,
			   char *outfname, int filemode,
			   char *destination, char *from,
			   char *subject, char *replyto,
			   int isemail);		   
		int UUE_PrepPartialExt (FILE *outfile, FILE *infile,
				char *infname, int encoding,
				char *outfname, int filemode,
				int partno, long linperfile, long filesize,
				char *destination,
				char *from, char *subject, char *replyto,
				int isemail);
		int UUEncodeToFile (FILE *infile, char *infname, int encoding,
 				char *outfname, char *diskname, long linperfile);
		int UUEncodeToStream (FILE *outfile, FILE *infile,
 				  char *infname, int encoding,
 				  char *outfname, int filemode);
		int UUEncodePartial (FILE *outfile, FILE *infile,
 				 char *infname, int encoding,
 				 char *outfname, char *mimetype,
 				 int filemode, int partno, long linperfile,
				 crc32_t *crcptr);
		int UUEncodeMulti (FILE *outfile, FILE *infile, char *infname, 
				int encoding,
 				char *outfname, char *mimetype, int filemode);

		 /*
		 * decode to a temporary file. this is well handled by uudecode()
		 */
		int UUDecodeToTemp (uulist *thefile) { return UUDecode (thefile); }


		virtual char *tempnam(const char *dir, const char *prefix) const 	// Create a temporary filename
		{	return(::_tempnam(dir, prefix)); }

};
