# Microsoft Developer Studio Project File - Name="uud32acx" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=uud32acx - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "uud32acx.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "uud32acx.mak" CFG="uud32acx - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "uud32acx - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "uud32acx - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "uud32acx - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "uud32acx - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /YX"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\Release
TargetPath=.\Release\uud32acx.ocx
InputPath=.\Release\uud32acx.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\Debug
TargetPath=.\Debug\uud32acx.ocx
InputPath=.\Debug\uud32acx.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\DebugU
TargetPath=.\DebugU\uud32acx.ocx
InputPath=.\DebugU\uud32acx.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseU"
# PROP BASE Intermediate_Dir "ReleaseU"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseU"
# PROP Intermediate_Dir "ReleaseU"
# PROP Target_Ext "ocx"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\ReleaseU
TargetPath=.\ReleaseU\uud32acx.ocx
InputPath=.\ReleaseU\uud32acx.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "uud32acx - Win32 Release"
# Name "uud32acx - Win32 Debug"
# Name "uud32acx - Win32 Unicode Debug"
# Name "uud32acx - Win32 Unicode Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Frank"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\fptools.cpp

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# ADD CPP /YX""

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# ADD CPP /YX"uudcpp.h"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uucheck.cpp

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# ADD CPP /YX""

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# ADD CPP /YX"uudcpp.h"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uudcore.cpp

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# ADD CPP /YX""

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# ADD CPP /YX"uudcpp.h"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uuencode.cpp

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# ADD CPP /YX""

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# ADD CPP /YX"uudcpp.h"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uulib.cpp

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# ADD CPP /YX""

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# ADD CPP /YX

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uunconc.cpp

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# ADD CPP /YX""

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# ADD CPP /YX"uudcpp.h"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uuscan.cpp

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# ADD CPP /YX""

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# ADD CPP /YX"uudcpp.h"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uustring.cpp

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# ADD CPP /YX""

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# ADD CPP /YX"uudcpp.h"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\uuutil.cpp

!IF  "$(CFG)" == "uud32acx - Win32 Release"

# ADD CPP /YX""

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Debug"

# ADD CPP /YX"uudcpp.h"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "uud32acx - Win32 Unicode Release"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\mapdfile.cpp
# End Source File
# Begin Source File

SOURCE=.\methods.cpp
# End Source File
# Begin Source File

SOURCE=.\props.cpp
# End Source File
# Begin Source File

SOURCE=.\uud32acx.cpp
# End Source File
# Begin Source File

SOURCE=.\uud32acx.def
# End Source File
# Begin Source File

SOURCE=.\uud32acx.odl
# End Source File
# Begin Source File

SOURCE=.\uud32acx.rc
# End Source File
# Begin Source File

SOURCE=.\Uud32acxCtl.cpp
# End Source File
# Begin Source File

SOURCE=.\Uud32acxPpg.cpp
# End Source File
# Begin Source File

SOURCE=.\xfile.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\crc32.h
# End Source File
# Begin Source File

SOURCE=.\mapdfile.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\uud32acx.h
# End Source File
# Begin Source File

SOURCE=.\Uud32acxCtl.h
# End Source File
# Begin Source File

SOURCE=.\Uud32acxPpg.h
# End Source File
# Begin Source File

SOURCE=.\uudcore.h
# End Source File
# Begin Source File

SOURCE=.\uudcpp.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\uud32acx.ico
# End Source File
# Begin Source File

SOURCE=.\Hlp\uud32acx.rtf
# End Source File
# Begin Source File

SOURCE=.\Uud32acxCtl.bmp
# End Source File
# Begin Source File

SOURCE=.\uudbutn.bmp
# End Source File
# Begin Source File

SOURCE=.\uudeview.ico
# End Source File
# End Group
# End Target
# End Project
