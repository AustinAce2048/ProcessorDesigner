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
include glew/build/cmake/CMakeFiles/glew_s.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glew/build/cmake/CMakeFiles/glew_s.dir/compiler_depend.make

# Include the progress variables for this target.
include glew/build/cmake/CMakeFiles/glew_s.dir/progress.make

# Include the compile flags for this target's objects.
include glew/build/cmake/CMakeFiles/glew_s.dir/flags.make

glew/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.obj: glew/build/cmake/CMakeFiles/glew_s.dir/flags.make
glew/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.obj: glew/build/cmake/CMakeFiles/glew_s.dir/includes_C.rsp
glew/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.obj: glew/src/glew.c
glew/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.obj: glew/build/cmake/CMakeFiles/glew_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glew/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.obj"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glew/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.obj -MF CMakeFiles\glew_s.dir\__\__\src\glew.c.obj.d -o CMakeFiles\glew_s.dir\__\__\src\glew.c.obj -c C:\Projects\ProcessorDesigner\glew\src\glew.c

glew/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew_s.dir/__/__/src/glew.c.i"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projects\ProcessorDesigner\glew\src\glew.c > CMakeFiles\glew_s.dir\__\__\src\glew.c.i

glew/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew_s.dir/__/__/src/glew.c.s"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projects\ProcessorDesigner\glew\src\glew.c -o CMakeFiles\glew_s.dir\__\__\src\glew.c.s

glew/build/cmake/CMakeFiles/glew_s.dir/__/glew.rc.obj: glew/build/cmake/CMakeFiles/glew_s.dir/flags.make
glew/build/cmake/CMakeFiles/glew_s.dir/__/glew.rc.obj: glew/build/glew.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object glew/build/cmake/CMakeFiles/glew_s.dir/__/glew.rc.obj"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && C:\msys64\mingw64\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Projects\ProcessorDesigner\glew\build\glew.rc CMakeFiles\glew_s.dir\__\glew.rc.obj

# Object files for target glew_s
glew_s_OBJECTS = \
"CMakeFiles/glew_s.dir/__/__/src/glew.c.obj" \
"CMakeFiles/glew_s.dir/__/glew.rc.obj"

# External object files for target glew_s
glew_s_EXTERNAL_OBJECTS =

lib/libglew32.a: glew/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.obj
lib/libglew32.a: glew/build/cmake/CMakeFiles/glew_s.dir/__/glew.rc.obj
lib/libglew32.a: glew/build/cmake/CMakeFiles/glew_s.dir/build.make
lib/libglew32.a: glew/build/cmake/CMakeFiles/glew_s.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library ..\..\..\lib\libglew32.a"
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && $(CMAKE_COMMAND) -P CMakeFiles\glew_s.dir\cmake_clean_target.cmake
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glew_s.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glew/build/cmake/CMakeFiles/glew_s.dir/build: lib/libglew32.a
.PHONY : glew/build/cmake/CMakeFiles/glew_s.dir/build

glew/build/cmake/CMakeFiles/glew_s.dir/clean:
	cd /d C:\Projects\ProcessorDesigner\glew\build\cmake && $(CMAKE_COMMAND) -P CMakeFiles\glew_s.dir\cmake_clean.cmake
.PHONY : glew/build/cmake/CMakeFiles/glew_s.dir/clean

glew/build/cmake/CMakeFiles/glew_s.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\ProcessorDesigner C:\Projects\ProcessorDesigner\glew\build\cmake C:\Projects\ProcessorDesigner C:\Projects\ProcessorDesigner\glew\build\cmake C:\Projects\ProcessorDesigner\glew\build\cmake\CMakeFiles\glew_s.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : glew/build/cmake/CMakeFiles/glew_s.dir/depend

