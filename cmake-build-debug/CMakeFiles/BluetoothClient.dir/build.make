# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\BluetoothClient.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\BluetoothClient.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\BluetoothClient.dir\flags.make

CMakeFiles\BluetoothClient.dir\src\dllmain.cpp.obj: CMakeFiles\BluetoothClient.dir\flags.make
CMakeFiles\BluetoothClient.dir\src\dllmain.cpp.obj: ..\src\dllmain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BluetoothClient.dir/src/dllmain.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\BluetoothClient.dir\src\dllmain.cpp.obj /FdCMakeFiles\BluetoothClient.dir\ /FS -c C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\dllmain.cpp
<<

CMakeFiles\BluetoothClient.dir\src\dllmain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothClient.dir/src/dllmain.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\BluetoothClient.dir\src\dllmain.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\dllmain.cpp
<<

CMakeFiles\BluetoothClient.dir\src\dllmain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothClient.dir/src/dllmain.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\BluetoothClient.dir\src\dllmain.cpp.s /c C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\dllmain.cpp
<<

CMakeFiles\BluetoothClient.dir\src\exports.cpp.obj: CMakeFiles\BluetoothClient.dir\flags.make
CMakeFiles\BluetoothClient.dir\src\exports.cpp.obj: ..\src\exports.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BluetoothClient.dir/src/exports.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\BluetoothClient.dir\src\exports.cpp.obj /FdCMakeFiles\BluetoothClient.dir\ /FS -c C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\exports.cpp
<<

CMakeFiles\BluetoothClient.dir\src\exports.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothClient.dir/src/exports.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\BluetoothClient.dir\src\exports.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\exports.cpp
<<

CMakeFiles\BluetoothClient.dir\src\exports.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothClient.dir/src/exports.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\BluetoothClient.dir\src\exports.cpp.s /c C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\exports.cpp
<<

CMakeFiles\BluetoothClient.dir\src\Component.cpp.obj: CMakeFiles\BluetoothClient.dir\flags.make
CMakeFiles\BluetoothClient.dir\src\Component.cpp.obj: ..\src\Component.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BluetoothClient.dir/src/Component.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\BluetoothClient.dir\src\Component.cpp.obj /FdCMakeFiles\BluetoothClient.dir\ /FS -c C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\Component.cpp
<<

CMakeFiles\BluetoothClient.dir\src\Component.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothClient.dir/src/Component.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\BluetoothClient.dir\src\Component.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\Component.cpp
<<

CMakeFiles\BluetoothClient.dir\src\Component.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothClient.dir/src/Component.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\BluetoothClient.dir\src\Component.cpp.s /c C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\Component.cpp
<<

CMakeFiles\BluetoothClient.dir\src\BluetoothClient.cpp.obj: CMakeFiles\BluetoothClient.dir\flags.make
CMakeFiles\BluetoothClient.dir\src\BluetoothClient.cpp.obj: ..\src\BluetoothClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/BluetoothClient.dir/src/BluetoothClient.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\BluetoothClient.dir\src\BluetoothClient.cpp.obj /FdCMakeFiles\BluetoothClient.dir\ /FS -c C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\BluetoothClient.cpp
<<

CMakeFiles\BluetoothClient.dir\src\BluetoothClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BluetoothClient.dir/src/BluetoothClient.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\BluetoothClient.dir\src\BluetoothClient.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\BluetoothClient.cpp
<<

CMakeFiles\BluetoothClient.dir\src\BluetoothClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BluetoothClient.dir/src/BluetoothClient.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\BluetoothClient.dir\src\BluetoothClient.cpp.s /c C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\src\BluetoothClient.cpp
<<

# Object files for target BluetoothClient
BluetoothClient_OBJECTS = \
"CMakeFiles\BluetoothClient.dir\src\dllmain.cpp.obj" \
"CMakeFiles\BluetoothClient.dir\src\exports.cpp.obj" \
"CMakeFiles\BluetoothClient.dir\src\Component.cpp.obj" \
"CMakeFiles\BluetoothClient.dir\src\BluetoothClient.cpp.obj"

# External object files for target BluetoothClient
BluetoothClient_EXTERNAL_OBJECTS =

BluetoothClient.dll: CMakeFiles\BluetoothClient.dir\src\dllmain.cpp.obj
BluetoothClient.dll: CMakeFiles\BluetoothClient.dir\src\exports.cpp.obj
BluetoothClient.dll: CMakeFiles\BluetoothClient.dir\src\Component.cpp.obj
BluetoothClient.dll: CMakeFiles\BluetoothClient.dir\src\BluetoothClient.cpp.obj
BluetoothClient.dll: CMakeFiles\BluetoothClient.dir\build.make
BluetoothClient.dll: ..\src\addin.def
BluetoothClient.dll: CMakeFiles\BluetoothClient.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library BluetoothClient.dll"
	"E:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E vs_link_dll --intdir=CMakeFiles\BluetoothClient.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\BluetoothClient.dir\objects1.rsp @<<
 /out:BluetoothClient.dll /implib:BluetoothClient.lib /pdb:C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug\BluetoothClient.pdb /dll /version:0.0 /machine:X86 /debug /INCREMENTAL /DEF:..\src\addin.def  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib  
<<

# Rule to build all files generated by this target.
CMakeFiles\BluetoothClient.dir\build: BluetoothClient.dll

.PHONY : CMakeFiles\BluetoothClient.dir\build

CMakeFiles\BluetoothClient.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BluetoothClient.dir\cmake_clean.cmake
.PHONY : CMakeFiles\BluetoothClient.dir\clean

CMakeFiles\BluetoothClient.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug C:\Users\akpaev.e.ENTERPRISE\Desktop\BluetoothClient\cmake-build-debug\CMakeFiles\BluetoothClient.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\BluetoothClient.dir\depend

