# Microsoft Developer Studio Project File - Name="UudATL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=UudATL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "UudATL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "UudATL.mak" CFG="UudATL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "UudATL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "UudATL - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "UudATL - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "UudATL - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "UudATL - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "UudATL - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "UudATL - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\UudATL.dll
InputPath=.\Debug\UudATL.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugU"
# PROP BASE Intermediate_Dir "DebugU"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugU"
# PROP Intermediate_Dir "DebugU"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\DebugU
TargetPath=.\DebugU\UudATL.dll
InputPath=.\DebugU\UudATL.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinSize"
# PROP BASE Intermediate_Dir "ReleaseMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinSize"
# PROP Intermediate_Dir "ReleaseMinSize"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\UudATL.dll
InputPath=.\ReleaseMinSize\UudATL.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinDependency"
# PROP BASE Intermediate_Dir "ReleaseMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinDependency"
# PROP Intermediate_Dir "ReleaseMinDependency"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Z<none>
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"" /subsystem:windows /dll /machine:I386
# SUBTRACT LINK32 /debug
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\UudATL.dll
InputPath=.\ReleaseMinDependency\UudATL.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUMinSize"
# PROP BASE Intermediate_Dir "ReleaseUMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUMinSize"
# PROP Intermediate_Dir "ReleaseUMinSize"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\UudATL.dll
InputPath=.\ReleaseUMinSize\UudATL.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUMinDependency"
# PROP BASE Intermediate_Dir "ReleaseUMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUMinDependency"
# PROP Intermediate_Dir "ReleaseUMinDependency"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# Begin Custom Build - Performing registration
OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\UudATL.dll
InputPath=.\ReleaseUMinDependency\UudATL.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "UudATL - Win32 Debug"
# Name "UudATL - Win32 Unicode Debug"
# Name "UudATL - Win32 Release MinSize"
# Name "UudATL - Win32 Release MinDependency"
# Name "UudATL - Win32 Unicode Release MinSize"
# Name "UudATL - Win32 Unicode Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Frank"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\uud32acx\fptools.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\mapdfile.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\uucheck.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\uudcore.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\uuencode.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\uulib.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\uunconc.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\uuscan.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\uustring.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\uuutil.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\MString.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\UudATL.cpp
# End Source File
# Begin Source File

SOURCE=.\UudATL.def
# End Source File
# Begin Source File

SOURCE=.\UudATL.idl
# ADD MTL /tlb ".\UudATL.tlb" /h "UudATL.h" /iid "UudATL_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\UudATL.rc
# End Source File
# Begin Source File

SOURCE=.\UudEng.cpp
# End Source File
# Begin Source File

SOURCE=.\UUEngine.cpp

!IF  "$(CFG)" == "UudATL - Win32 Debug"

# ADD CPP /Yu

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Debug"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Release MinDependency"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinSize"

!ELSEIF  "$(CFG)" == "UudATL - Win32 Unicode Release MinDependency"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\MString.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\UudATLCP.h
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uudcore.h
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uudcpp.h
# End Source File
# Begin Source File

SOURCE=.\UudEng.h
# End Source File
# Begin Source File

SOURCE=.\UUEngine.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\UUEngine.rgs
# End Source File
# End Group
# End Target
# End Project
