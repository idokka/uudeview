# Microsoft Developer Studio Project File - Name="Uud32" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Uud32 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Uud32.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Uud32.mak" CFG="Uud32 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Uud32 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Uud32 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Uud32 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../uud32acx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Uud32 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../uud32acx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"oleaut32" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Uud32 - Win32 Release"
# Name "Uud32 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Frank"

# PROP Default_Filter "*.cpp"
# Begin Source File

SOURCE=..\uud32acx\fptools.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\uud32acx\mapdfile.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uucheck.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uudcore.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uuencode.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uulib.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uunconc.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uuscan.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uustring.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uuutil.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Group "Acx"

# PROP Default_Filter "*.cpp"
# Begin Source File

SOURCE=..\uud32acx\methods.cpp

!IF  "$(CFG)" == "Uud32 - Win32 Release"

!ELSEIF  "$(CFG)" == "Uud32 - Win32 Debug"

# ADD CPP /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\props.cpp

!IF  "$(CFG)" == "Uud32 - Win32 Release"

!ELSEIF  "$(CFG)" == "Uud32 - Win32 Debug"

# ADD CPP /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\Uud32acxCtl.cpp

!IF  "$(CFG)" == "Uud32 - Win32 Release"

!ELSEIF  "$(CFG)" == "Uud32 - Win32 Debug"

# ADD CPP /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\uud32acx\xfile.cpp

!IF  "$(CFG)" == "Uud32 - Win32 Release"

!ELSEIF  "$(CFG)" == "Uud32 - Win32 Debug"

# ADD CPP /Yu

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\AboutBox.cpp
# End Source File
# Begin Source File

SOURCE=.\DebugDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\DecodeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DecodeOn.cpp
# End Source File
# Begin Source File

SOURCE=.\DecodeOptions.cpp
# End Source File
# Begin Source File

SOURCE=.\EncodeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Engine.cpp
# End Source File
# Begin Source File

SOURCE=.\FileName.cpp
# End Source File
# Begin Source File

SOURCE=.\InfoDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\LaunchDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\MikeNButton.cpp
# End Source File
# Begin Source File

SOURCE=.\MikeNListCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\MikeNPopupMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\MyListBox.cpp
# End Source File
# Begin Source File

SOURCE=.\RegIni.cpp
# End Source File
# Begin Source File

SOURCE=.\RenOutFile.cpp
# End Source File
# Begin Source File

SOURCE=.\SizeDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Uud32.cpp
# End Source File
# Begin Source File

SOURCE=.\Uud32.rc
# End Source File
# Begin Source File

SOURCE=.\Uud32Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UUDCommand.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AboutBox.h
# End Source File
# Begin Source File

SOURCE=.\DebugDialog.h
# End Source File
# Begin Source File

SOURCE=.\DecodeDlg.h
# End Source File
# Begin Source File

SOURCE=.\DecodeOptions.h
# End Source File
# Begin Source File

SOURCE=.\EncodeDlg.h
# End Source File
# Begin Source File

SOURCE=.\Engine.h
# End Source File
# Begin Source File

SOURCE=.\FileName.h
# End Source File
# Begin Source File

SOURCE=.\InfoDialog.h
# End Source File
# Begin Source File

SOURCE=.\LaunchDialog.h
# End Source File
# Begin Source File

SOURCE=..\uud32acx\mapdfile.h
# End Source File
# Begin Source File

SOURCE=.\MikeNButton.h
# End Source File
# Begin Source File

SOURCE=.\MikeNListCtrl.h
# End Source File
# Begin Source File

SOURCE=.\MikeNPopupMenu.h
# End Source File
# Begin Source File

SOURCE=.\MyListBox.h
# End Source File
# Begin Source File

SOURCE=.\RegIni.h
# End Source File
# Begin Source File

SOURCE=.\RenOutFile.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SizeDialog.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Uud32.h
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uud32acx.h
# End Source File
# Begin Source File

SOURCE=..\uud32acx\Uud32acxCtl.h
# End Source File
# Begin Source File

SOURCE=.\Uud32Dlg.h
# End Source File
# Begin Source File

SOURCE=.\UUDCommand.h
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uudcore.h
# End Source File
# Begin Source File

SOURCE=..\uud32acx\uudcpp.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\About.bmp
# End Source File
# Begin Source File

SOURCE=.\Help.cur
# End Source File
# Begin Source File

SOURCE=.\info.ico
# End Source File
# Begin Source File

SOURCE=.\PClip.BMP
# End Source File
# Begin Source File

SOURCE=.\pclip1.bmp
# End Source File
# Begin Source File

SOURCE=.\qmark.ico
# End Source File
# Begin Source File

SOURCE=.\res\Uud32.ico
# End Source File
# Begin Source File

SOURCE=.\res\Uud32.rc2
# End Source File
# Begin Source File

SOURCE=.\uudeb.ico
# End Source File
# Begin Source File

SOURCE=.\uudeview.ico
# End Source File
# End Group
# End Target
# End Project
# Section Uud32 : {6FC838A4-A54A-11D0-8988-444553540000}
# 	2:5:Class:CUud32acx
# 	2:10:HeaderFile:uud32acx.h
# 	2:8:ImplFile:uud32acx.cpp
# End Section
# Section Uud32 : {6FC838A6-A54A-11D0-8988-444553540000}
# 	2:21:DefaultSinkHeaderFile:uud32acx.h
# 	2:16:DefaultSinkClass:CUud32acx
# End Section
