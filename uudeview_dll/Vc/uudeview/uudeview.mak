# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=uudeview - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to uudeview - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "uudeview - Win32 Release" && "$(CFG)" !=\
 "uudeview - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "uudeview.mak" CFG="uudeview - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "uudeview - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "uudeview - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "uudeview - Win32 Debug"
RSC=rc.exe
MTL=mktyplib.exe
CPP=cl.exe

!IF  "$(CFG)" == "uudeview - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\uudeview.dll" ".\UDist\uudeview.dll"

CLEAN : 
	-@erase "$(INTDIR)\fptools.obj"
	-@erase "$(INTDIR)\uucheck.obj"
	-@erase "$(INTDIR)\uudeview.res"
	-@erase "$(INTDIR)\uudw32.obj"
	-@erase "$(INTDIR)\uuencode.obj"
	-@erase "$(INTDIR)\uulib.obj"
	-@erase "$(INTDIR)\uunconc.obj"
	-@erase "$(INTDIR)\uuscan.obj"
	-@erase "$(INTDIR)\uustring.obj"
	-@erase "$(INTDIR)\uuutil.obj"
	-@erase "$(INTDIR)\Uuvb.obj"
	-@erase "$(OUTDIR)\uudeview.dll"
	-@erase "$(OUTDIR)\uudeview.exp"
	-@erase "$(OUTDIR)\uudeview.lib"
	-@erase ".\UDist\uudeview.dll"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "C:\MSDEV\PROJ16\UUD16" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /YX /c
CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "." /I "C:\MSDEV\PROJ16\UUD16" /D "NDEBUG"\
 /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /Fp"$(INTDIR)/uudeview.pch" /YX\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/uudeview.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/uudeview.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)/uudeview.pdb" /machine:I386 /def:".\uudeview.def"\
 /out:"$(OUTDIR)/uudeview.dll" /implib:"$(OUTDIR)/uudeview.lib" 
DEF_FILE= \
	".\uudeview.def"
LINK32_OBJS= \
	"$(INTDIR)\fptools.obj" \
	"$(INTDIR)\uucheck.obj" \
	"$(INTDIR)\uudeview.res" \
	"$(INTDIR)\uudw32.obj" \
	"$(INTDIR)\uuencode.obj" \
	"$(INTDIR)\uulib.obj" \
	"$(INTDIR)\uunconc.obj" \
	"$(INTDIR)\uuscan.obj" \
	"$(INTDIR)\uustring.obj" \
	"$(INTDIR)\uuutil.obj" \
	"$(INTDIR)\Uuvb.obj"

"$(OUTDIR)\uudeview.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build - Updating Distribution Dir
InputPath=.\Release\uudeview.dll
SOURCE=$(InputPath)

"C:\MSDEV\projects\uudeview\UDist\uudeview.dll" : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
   "G:\Program Files\Norton Navigator\SYMAPCPY.EXE"\
        "C:\MSDEV\projects\uudeview\Release\uudeview.dll"\
        "C:\MSDEV\projects\uudeview\Release\uudeview.lib"\
        /TO="C:\MSDEV\projects\uudeview\UDist" /QM /NOWARN

# End Custom Build

!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\uudeview.dll" "$(OUTDIR)\uudeview.bsc"

CLEAN : 
	-@erase "$(INTDIR)\fptools.obj"
	-@erase "$(INTDIR)\fptools.sbr"
	-@erase "$(INTDIR)\uucheck.obj"
	-@erase "$(INTDIR)\uucheck.sbr"
	-@erase "$(INTDIR)\uudeview.res"
	-@erase "$(INTDIR)\uudw32.obj"
	-@erase "$(INTDIR)\uudw32.sbr"
	-@erase "$(INTDIR)\uuencode.obj"
	-@erase "$(INTDIR)\uuencode.sbr"
	-@erase "$(INTDIR)\uulib.obj"
	-@erase "$(INTDIR)\uulib.sbr"
	-@erase "$(INTDIR)\uunconc.obj"
	-@erase "$(INTDIR)\uunconc.sbr"
	-@erase "$(INTDIR)\uuscan.obj"
	-@erase "$(INTDIR)\uuscan.sbr"
	-@erase "$(INTDIR)\uustring.obj"
	-@erase "$(INTDIR)\uustring.sbr"
	-@erase "$(INTDIR)\uuutil.obj"
	-@erase "$(INTDIR)\uuutil.sbr"
	-@erase "$(INTDIR)\Uuvb.obj"
	-@erase "$(INTDIR)\Uuvb.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\uudeview.bsc"
	-@erase "$(OUTDIR)\uudeview.dll"
	-@erase "$(OUTDIR)\uudeview.exp"
	-@erase "$(OUTDIR)\uudeview.ilk"
	-@erase "$(OUTDIR)\uudeview.lib"
	-@erase "$(OUTDIR)\uudeview.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "." /I "C:\MSDEV\PROJ16\UUD16" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /FR /YX /c
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /Zi /Od /I "." /I "C:\MSDEV\PROJ16\UUD16" /D\
 "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /FR"$(INTDIR)/"\
 /Fp"$(INTDIR)/uudeview.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/uudeview.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/uudeview.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\fptools.sbr" \
	"$(INTDIR)\uucheck.sbr" \
	"$(INTDIR)\uudw32.sbr" \
	"$(INTDIR)\uuencode.sbr" \
	"$(INTDIR)\uulib.sbr" \
	"$(INTDIR)\uunconc.sbr" \
	"$(INTDIR)\uuscan.sbr" \
	"$(INTDIR)\uustring.sbr" \
	"$(INTDIR)\uuutil.sbr" \
	"$(INTDIR)\Uuvb.sbr"

"$(OUTDIR)\uudeview.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)/uudeview.pdb" /debug /machine:I386 /def:".\uudeview.def"\
 /out:"$(OUTDIR)/uudeview.dll" /implib:"$(OUTDIR)/uudeview.lib" 
DEF_FILE= \
	".\uudeview.def"
LINK32_OBJS= \
	"$(INTDIR)\fptools.obj" \
	"$(INTDIR)\uucheck.obj" \
	"$(INTDIR)\uudeview.res" \
	"$(INTDIR)\uudw32.obj" \
	"$(INTDIR)\uuencode.obj" \
	"$(INTDIR)\uulib.obj" \
	"$(INTDIR)\uunconc.obj" \
	"$(INTDIR)\uuscan.obj" \
	"$(INTDIR)\uustring.obj" \
	"$(INTDIR)\uuutil.obj" \
	"$(INTDIR)\Uuvb.obj"

"$(OUTDIR)\uudeview.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "uudeview - Win32 Release"
# Name "uudeview - Win32 Debug"

!IF  "$(CFG)" == "uudeview - Win32 Release"

!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\uudeview.def

!IF  "$(CFG)" == "uudeview - Win32 Release"

!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\uudeview.rc

"$(INTDIR)\uudeview.res" : $(SOURCE) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=\Msdev\Proj16\Uud16\uuutil.c
DEP_CPP_UUUTI=\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\fptools.h"\
	"\MSDEV\PROJ16\UUD16\uudeview.h"\
	"\MSDEV\PROJ16\UUD16\uuint.h"\
	"\MSDEV\PROJ16\UUD16\uustring.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\uuutil.obj" : $(SOURCE) $(DEP_CPP_UUUTI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\uuutil.obj" : $(SOURCE) $(DEP_CPP_UUUTI) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\uuutil.sbr" : $(SOURCE) $(DEP_CPP_UUUTI) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Msdev\Proj16\Uud16\uucheck.c
DEP_CPP_UUCHE=\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\fptools.h"\
	"\MSDEV\PROJ16\UUD16\uudeview.h"\
	"\MSDEV\PROJ16\UUD16\uuint.h"\
	"\MSDEV\PROJ16\UUD16\uustring.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\uucheck.obj" : $(SOURCE) $(DEP_CPP_UUCHE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\uucheck.obj" : $(SOURCE) $(DEP_CPP_UUCHE) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\uucheck.sbr" : $(SOURCE) $(DEP_CPP_UUCHE) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Msdev\Proj16\Uud16\uuencode.c
DEP_CPP_UUENC=\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\fptools.h"\
	"\MSDEV\PROJ16\UUD16\uudeview.h"\
	"\MSDEV\PROJ16\UUD16\uuint.h"\
	"\MSDEV\PROJ16\UUD16\uustring.h"\
	{$(INCLUDE)}"\sys\Stat.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\uuencode.obj" : $(SOURCE) $(DEP_CPP_UUENC) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\uuencode.obj" : $(SOURCE) $(DEP_CPP_UUENC) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\uuencode.sbr" : $(SOURCE) $(DEP_CPP_UUENC) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Msdev\Proj16\Uud16\uulib.c
DEP_CPP_UULIB=\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\fptools.h"\
	"\MSDEV\PROJ16\UUD16\uudeview.h"\
	"\MSDEV\PROJ16\UUD16\uuint.h"\
	"\MSDEV\PROJ16\UUD16\uustring.h"\
	{$(INCLUDE)}"\sys\Stat.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\uulib.obj" : $(SOURCE) $(DEP_CPP_UULIB) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\uulib.obj" : $(SOURCE) $(DEP_CPP_UULIB) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\uulib.sbr" : $(SOURCE) $(DEP_CPP_UULIB) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Msdev\Proj16\Uud16\uunconc.c
DEP_CPP_UUNCO=\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\fptools.h"\
	"\MSDEV\PROJ16\UUD16\uudeview.h"\
	"\MSDEV\PROJ16\UUD16\uuint.h"\
	"\MSDEV\PROJ16\UUD16\uustring.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\uunconc.obj" : $(SOURCE) $(DEP_CPP_UUNCO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\uunconc.obj" : $(SOURCE) $(DEP_CPP_UUNCO) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\uunconc.sbr" : $(SOURCE) $(DEP_CPP_UUNCO) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Msdev\Proj16\Uud16\uuscan.c
DEP_CPP_UUSCA=\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\fptools.h"\
	"\MSDEV\PROJ16\UUD16\uudeview.h"\
	"\MSDEV\PROJ16\UUD16\uuint.h"\
	"\MSDEV\PROJ16\UUD16\uustring.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\uuscan.obj" : $(SOURCE) $(DEP_CPP_UUSCA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\uuscan.obj" : $(SOURCE) $(DEP_CPP_UUSCA) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\uuscan.sbr" : $(SOURCE) $(DEP_CPP_UUSCA) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Msdev\Proj16\Uud16\uustring.c
DEP_CPP_UUSTR=\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\uudeview.h"\
	"\MSDEV\PROJ16\UUD16\uuint.h"\
	"\MSDEV\PROJ16\UUD16\uustring.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\uustring.obj" : $(SOURCE) $(DEP_CPP_UUSTR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\uustring.obj" : $(SOURCE) $(DEP_CPP_UUSTR) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\uustring.sbr" : $(SOURCE) $(DEP_CPP_UUSTR) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Msdev\Proj16\Uud16\fptools.c
DEP_CPP_FPTOO=\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\fptools.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\fptools.obj" : $(SOURCE) $(DEP_CPP_FPTOO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\fptools.obj" : $(SOURCE) $(DEP_CPP_FPTOO) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\fptools.sbr" : $(SOURCE) $(DEP_CPP_FPTOO) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\uudw32.c
DEP_CPP_UUDW3=\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\miken.h"\
	"\MSDEV\PROJ16\UUD16\uudeview.h"\
	"\MSDEV\PROJ16\UUD16\uuint.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\uudw32.obj" : $(SOURCE) $(DEP_CPP_UUDW3) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


"$(INTDIR)\uudw32.obj" : $(SOURCE) $(DEP_CPP_UUDW3) "$(INTDIR)"

"$(INTDIR)\uudw32.sbr" : $(SOURCE) $(DEP_CPP_UUDW3) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Msdev\Proj16\Uud16\Uuvb.c
DEP_CPP_UUVB_=\
	"..\..\Proj16\Uud16\vbapi.h"\
	"\MSDEV\PROJ16\UUD16\config.h"\
	"\MSDEV\PROJ16\UUD16\miken.h"\
	"\MSDEV\PROJ16\UUD16\uudeview.h"\
	"\MSDEV\PROJ16\UUD16\uuint.h"\
	

!IF  "$(CFG)" == "uudeview - Win32 Release"


"$(INTDIR)\Uuvb.obj" : $(SOURCE) $(DEP_CPP_UUVB_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"


BuildCmds= \
	$(CPP) $(CPP_PROJ) $(SOURCE) \
	

"$(INTDIR)\Uuvb.obj" : $(SOURCE) $(DEP_CPP_UUVB_) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Uuvb.sbr" : $(SOURCE) $(DEP_CPP_UUVB_) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
