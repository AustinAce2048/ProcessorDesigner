# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projects\ProcessorDesigner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projects\ProcessorDesigner

# Include any dependencies generated for this target.
include glew/build/cmake/CMakeFiles/glewinfo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glew/build/cmake/CMakeFiles/glewinfo.dir/compiler_depend.make

# Include the progress variables for this target.
include glew/build/cmake/CMakeFiles/glewinfo.dir/progress.make

# Include the compile flags for this target's objects.
include glew/build/cmake/CMakeFiles/glewinfo.dir/flags.make

glew/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.obj: glew/build/cmake/CMakeFiles/glewinfo.dir/flags.make
glew/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.obj: glew/build/cmake/CMakeFiles/glewinfo.dir/includes_C.rsp
glew/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.obj: glew/src/glewinfo.c
glew/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.obj: glew/build/cmake/CMakeFiles/glewinfo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glew/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.obj"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glew/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.obj -MF CMakeFiles\glewinfo.dir\__\__\src\glewinfo.c.obj.d -o CMakeFiles\glewinfo.dir\__\__\src\glewinfo.c.obj -c C:\Projects\ProcessorDesigner\glew\src\glewinfo.c

glew/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.i"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projects\ProcessorDesigner\glew\src\glewinfo.c > CMakeFiles\glewinfo.dir\__\__\src\glewinfo.c.i

glew/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.s"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projects\ProcessorDesigner\glew\src\glewinfo.c -o CMakeFiles\glewinfo.dir\__\__\src\glewinfo.c.s

glew/build/cmake/CMakeFiles/glewinfo.dir/__/glewinfo.rc.obj: glew/build/cmake/CMakeFiles/glewinfo.dir/flags.make
glew/build/cmake/CMakeFiles/glewinfo.dir/__/glewinfo.rc.obj: glew/build/glewinfo.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object glew/build/cmake/CMakeFiles/glewinfo.dir/__/glewinfo.rc.obj"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && C:\msys64\mingw64\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Projects\ProcessorDesigner\glew\build\glewinfo.rc CMakeFiles\glewinfo.dir\__\glewinfo.rc.obj

# Object files for target glewinfo
glewinfo_OBJECTS = \
"CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.obj" \
"CMakeFiles/glewinfo.dir/__/glewinfo.rc.obj"

# External object files for target glewinfo
glewinfo_EXTERNAL_OBJECTS =

bin/glewinfo.exe: glew/build/cmake/CMakeFiles/glewinfo.dir/__/__/src/glewinfo.c.obj
bin/glewinfo.exe: glew/build/cmake/CMakeFiles/glewinfo.dir/__/glewinfo.rc.obj
bin/glewinfo.exe: glew/build/cmake/CMakeFiles/glewinfo.dir/build.make
bin/glewinfo.exe: lib/libglew32.dll.a
bin/glewinfo.exe: glew/build/cmake/CMakeFiles/glewinfo.dir/linklibs.rsp
bin/glewinfo.exe: glew/build/cmake/CMakeFiles/glewinfo.dir/objects1.rsp
bin/glewinfo.exe: glew/build/cmake/CMakeFiles/glewinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ..\..\..\bin\glewinfo.exe"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glewinfo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glew/build/cmake/CMakeFiles/glewinfo.dir/build: bin/glewinfo.exe
.PHONY : glew/build/cmake/CMakeFiles/glewinfo.dir/build

glew/build/cmake/CMakeFiles/glewinfo.dir/clean:
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && $(CMAKE_COMMAND) -P CMakeFiles\glewinfo.dir\cmake_clean.cmake
.PHONY : glew/build/cmake/CMakeFiles/glewinfo.dir/clean

glew/build/cmake/CMakeFiles/glewinfo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\ProcessorDesigner C:\Projects\ProcessorDesigner\glew\build\cmake C:\Projects\ProcessorDesigner C:\Projects\ProcessorDesigner\glew\build\cmake C:\Projects\ProcessorDesigner\glew\build\cmake\CMakeFiles\glewinfo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : glew/build/cmake/CMakeFiles/glewinfo.dir/depend

