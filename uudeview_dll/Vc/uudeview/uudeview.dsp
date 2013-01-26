# Microsoft Developer Studio Project File - Name="uudeview" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=uudeview - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "uudeview.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "uudeview.mak" CFG="uudeview - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "uudeview - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "uudeview - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "uudeview - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\..\Vc16\UUD16" /I "." /I "H:\My Documents\Utilities\Vc16\UUD16" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386

!ELSEIF  "$(CFG)" == "uudeview - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "C:\MSDEV\PROJ16\UUD16" /I "." /I "H:\My Documents\Utilities\Vc16\UUD16" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "HAVE_CONFIG_H" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386

!ENDIF 

# Begin Target

# Name "uudeview - Win32 Release"
# Name "uudeview - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Group "Uud16"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Vc16\UUD16\crc32.c
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\fptools.c
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uucheck.c
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uuencode.c
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uulib.c
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uunconc.c
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uuscan.c
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uustring.c
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uuutil.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\uudeview.def
# End Source File
# Begin Source File

SOURCE=.\uudw32.c
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\Uuvb.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE="C:\Program Files\Microsoft Visual Studio\Vc98\Include\Basetsd.h"
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\config.h
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\fptools.h
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\miken.h
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uudeview.h
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uuint.h
# End Source File
# Begin Source File

SOURCE=..\..\Vc16\Uud16\uustring.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\uudeview.rc
# End Source File
# End Group
# End Target
# End Project
