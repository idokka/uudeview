/* config.h  Generated automatically from configure.in by autoheader.  */

// Windows 16 Version by MikeN

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
// #undef size_t

//
// MikeN Additions
//             
#define VERSION "0.5"
#define PATCH "15"

#if defined(_WIN32) || defined(WIN32)
#undef WIN32
#define WIN32 1
#define WIN16 0
#else
#define WIN32 0
#define WIN16 1
#endif

#define SKIP 0				// Used to zap out code

#define MIKEN 1				// This is Mike's build

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if you can safely include both <sys/time.h> and <time.h>.  */
#undef TIME_WITH_SYS_TIME

/*
 * If your system is kinda special
 */
#undef SYSTEM_DOS
#undef SYSTEM_QUICKWIN
#undef SYSTEM_WINDLL
#undef SYSTEM_OS2

/*
 * If your system has stdin/stdout/stderr
 */
#undef HAVE_STDIO

/*
 * how to declare functions that are exported from the UU library
 */
#if WIN32
#if defined(_AFXDLL)
#define UUEXPORT
#else
#define UUEXPORT _stdcall
#endif
#else
#define UUEXPORT _export _far _pascal
#endif

/*
 * how to declare functions that are exported from the fptools library
 */
#define TOOLEXPORT

/*
 * define if your compiler supports function prototypes
 */
#define PROTOTYPES 1
  
/*
 * Replacement functions.
 * #define strerror _FP_strerror
 * #define tempnam  _FP_tempnam
 * if you don't have these functions
 */
#undef strerror
#undef tempnam

/* 
 * your mailing program. full path and the necessary parameters.
 * the recepient address is added to the command line (with a leading
 * space) without any further options
 */
#undef PROG_MAILER

/* 
 * define if the mailer needs to have the subject set on the command
 * line with -s "Subject". Preferredly, we send the subject as a header.
 */
#undef MAILER_NEEDS_SUBJECT

/* 
 * define if posting is enabled. Do not edit.
 */
#undef HAVE_NEWS

/*
 * your local news posting program. full path and parameters, so that
 * the article and all its headers are read from stdin
 */
#undef PROG_INEWS

/* Define if you have the gettimeofday function.  */
#undef HAVE_GETTIMEOFDAY

/* Define if you have the popen function.  */
#undef HAVE_POPEN

/* Define if you have the <errno.h> header file.  */
#define HAVE_ERRNO_H 1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <io.h> header file.  */
#define HAVE_IO_H 1

/* Define if you have the <malloc.h> header file.  */
#define HAVE_MALLOC_H 1

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <stdarg.h> header file.  */
#define HAVE_STDARG_H 1

/* Define if you have the <sys/time.h> header file.  */
#undef HAVE_SYS_TIME_H

/* Define if you have the <unistd.h> header file.  */
#undef HAVE_UNISTD_H

/* Define if you have the <varargs.h> header file.  */
#define HAVE_VARARGS_H 1
