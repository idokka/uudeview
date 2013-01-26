# Microsoft Visual C++ generated build script - Do not modify

PROJ = UUD16
DEBUG = 0
PROGTYPE = 1
CALLER = E:\VB\VBPRG\UUDEVIEW\UUDEVIEW.EXE
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = C:\MSDEV\VC\PROJ16\UUD16\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC = FPTOOLS.C   
FIRSTCPP =             
RC = rc
CFLAGS_D_WDLL = /nologo /G2 /W3 /Zi /ALw /Gx- /Od /D "_DEBUG" /D "HAVE_CONFIG_H" /D "MSPRINTF" /FR /GD /Fd"MAKEFILE.PDB"
CFLAGS_R_WDLL = /nologo /W3 /ALw /Gx- /O1 /D "NDEBUG" /D "HAVE_CONFIG_H" /D "MSPRINTF" /FR /GD 
LFLAGS_D_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE /CO /MAP:FULL
LFLAGS_R_WDLL = /NOLOGO /NOD /NOE /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE /MAP:FULL
LIBS_D_WDLL = oldnames libw ldllcew vbapi commdlg.lib olecli.lib olesvr.lib shell.lib 
LIBS_R_WDLL = oldnames libw ldllcew vbapi commdlg.lib olecli.lib olesvr.lib shell.lib 
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
DEFFILE = MAKEFILE.DEF
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WDLL)
LFLAGS = $(LFLAGS_D_WDLL)
LIBS = $(LIBS_D_WDLL)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WDLL)
LFLAGS = $(LFLAGS_R_WDLL)
LIBS = $(LIBS_R_WDLL)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = FPTOOLS.SBR \
		UUCHECK.SBR \
		UUENCODE.SBR \
		UULIB.SBR \
		UUNCONC.SBR \
		UUUTIL.SBR \
		UUVB.SBR \
		UUSCAN.SBR \
		UUSTRING.SBR \
		UUDW.SBR


FPTOOLS_DEP = c:\msdev\vc\proj16\uud16\config.h


UUCHECK_DEP = c:\msdev\vc\proj16\uud16\config.h


UUENCODE_DEP = c:\msdev\vc\proj16\uud16\config.h


UULIB_DEP = c:\msdev\vc\proj16\uud16\config.h


UUNCONC_DEP = c:\msdev\vc\proj16\uud16\config.h


UUUTIL_DEP = c:\msdev\vc\proj16\uud16\config.h


UUVB_DEP = c:\msdev\vc\proj16\uud16\vbapi.h \
	c:\msdev\vc\proj16\uud16\config.h \
	c:\msdev\vc\proj16\uud16\uudeview.h \
	c:\msdev\vc\proj16\uud16\uuint.h \
	c:\msdev\vc\proj16\uud16\miken.h


UUSCAN_DEP = c:\msdev\vc\proj16\uud16\config.h


UUSTRING_DEP = c:\msdev\vc\proj16\uud16\config.h


UUD16_RCDEP = 

UUDW_DEP = c:\msdev\vc\proj16\uud16\vbapi.h \
	c:\msdev\vc\proj16\uud16\config.h \
	c:\msdev\vc\proj16\uud16\uudeview.h \
	c:\msdev\vc\proj16\uud16\miken.h


all:	$(PROJ).DLL $(PROJ).BSC

FPTOOLS.OBJ:	FPTOOLS.C $(FPTOOLS_DEP)
	$(CC) $(CFLAGS) $(CCREATEPCHFLAG) /c FPTOOLS.C

UUCHECK.OBJ:	UUCHECK.C $(UUCHECK_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c UUCHECK.C

UUENCODE.OBJ:	UUENCODE.C $(UUENCODE_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c UUENCODE.C

UULIB.OBJ:	UULIB.C $(UULIB_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c UULIB.C

UUNCONC.OBJ:	UUNCONC.C $(UUNCONC_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c UUNCONC.C

UUUTIL.OBJ:	UUUTIL.C $(UUUTIL_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c UUUTIL.C

UUVB.OBJ:	UUVB.C $(UUVB_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c UUVB.C

UUSCAN.OBJ:	UUSCAN.C $(UUSCAN_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c UUSCAN.C

UUSTRING.OBJ:	UUSTRING.C $(UUSTRING_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c UUSTRING.C

UUD16.RES:	UUD16.RC $(UUD16_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r UUD16.RC

UUDW.OBJ:	UUDW.C $(UUDW_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c UUDW.C


$(PROJ).DLL::	UUD16.RES

$(PROJ).DLL::	FPTOOLS.OBJ UUCHECK.OBJ UUENCODE.OBJ UULIB.OBJ UUNCONC.OBJ UUUTIL.OBJ \
	UUVB.OBJ UUSCAN.OBJ UUSTRING.OBJ UUDW.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
FPTOOLS.OBJ +
UUCHECK.OBJ +
UUENCODE.OBJ +
UULIB.OBJ +
UUNCONC.OBJ +
UUUTIL.OBJ +
UUVB.OBJ +
UUSCAN.OBJ +
UUSTRING.OBJ +
UUDW.OBJ +
$(OBJS_EXT)
$(PROJ).DLL
$(MAPFILE)
h:\msvc\lib\+
h:\msvc\mfc\lib\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) UUD16.RES $@
	@copy $(PROJ).CRF MSVC.BND
	implib /nowep $(PROJ).LIB $(PROJ).DLL

$(PROJ).DLL::	UUD16.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) UUD16.RES $@

run: $(PROJ).DLL
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
