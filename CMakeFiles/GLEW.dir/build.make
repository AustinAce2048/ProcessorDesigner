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
include CMakeFiles/GLEW.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GLEW.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GLEW.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GLEW.dir/flags.make

CMakeFiles/GLEW.dir/glew/src/glew.c.obj: CMakeFiles/GLEW.dir/flags.make
CMakeFiles/GLEW.dir/glew/src/glew.c.obj: CMakeFiles/GLEW.dir/includes_C.rsp
CMakeFiles/GLEW.dir/glew/src/glew.c.obj: glew/src/glew.c
CMakeFiles/GLEW.dir/glew/src/glew.c.obj: CMakeFiles/GLEW.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GLEW.dir/glew/src/glew.c.obj"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GLEW.dir/glew/src/glew.c.obj -MF CMakeFiles\GLEW.dir\glew\src\glew.c.obj.d -o CMakeFiles\GLEW.dir\glew\src\glew.c.obj -c C:\Projects\ProcessorDesigner\glew\src\glew.c

CMakeFiles/GLEW.dir/glew/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GLEW.dir/glew/src/glew.c.i"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projects\ProcessorDesigner\glew\src\glew.c > CMakeFiles\GLEW.dir\glew\src\glew.c.i

CMakeFiles/GLEW.dir/glew/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GLEW.dir/glew/src/glew.c.s"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projects\ProcessorDesigner\glew\src\glew.c -o CMakeFiles\GLEW.dir\glew\src\glew.c.s

CMakeFiles/GLEW.dir/glew/src/glewinfo.c.obj: CMakeFiles/GLEW.dir/flags.make
CMakeFiles/GLEW.dir/glew/src/glewinfo.c.obj: CMakeFiles/GLEW.dir/includes_C.rsp
CMakeFiles/GLEW.dir/glew/src/glewinfo.c.obj: glew/src/glewinfo.c
CMakeFiles/GLEW.dir/glew/src/glewinfo.c.obj: CMakeFiles/GLEW.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GLEW.dir/glew/src/glewinfo.c.obj"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GLEW.dir/glew/src/glewinfo.c.obj -MF CMakeFiles\GLEW.dir\glew\src\glewinfo.c.obj.d -o CMakeFiles\GLEW.dir\glew\src\glewinfo.c.obj -c C:\Projects\ProcessorDesigner\glew\src\glewinfo.c

CMakeFiles/GLEW.dir/glew/src/glewinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GLEW.dir/glew/src/glewinfo.c.i"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projects\ProcessorDesigner\glew\src\glewinfo.c > CMakeFiles\GLEW.dir\glew\src\glewinfo.c.i

CMakeFiles/GLEW.dir/glew/src/glewinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GLEW.dir/glew/src/glewinfo.c.s"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projects\ProcessorDesigner\glew\src\glewinfo.c -o CMakeFiles\GLEW.dir\glew\src\glewinfo.c.s

CMakeFiles/GLEW.dir/glew/src/visualinfo.c.obj: CMakeFiles/GLEW.dir/flags.make
CMakeFiles/GLEW.dir/glew/src/visualinfo.c.obj: CMakeFiles/GLEW.dir/includes_C.rsp
CMakeFiles/GLEW.dir/glew/src/visualinfo.c.obj: glew/src/visualinfo.c
CMakeFiles/GLEW.dir/glew/src/visualinfo.c.obj: CMakeFiles/GLEW.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/GLEW.dir/glew/src/visualinfo.c.obj"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GLEW.dir/glew/src/visualinfo.c.obj -MF CMakeFiles\GLEW.dir\glew\src\visualinfo.c.obj.d -o CMakeFiles\GLEW.dir\glew\src\visualinfo.c.obj -c C:\Projects\ProcessorDesigner\glew\src\visualinfo.c

CMakeFiles/GLEW.dir/glew/src/visualinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GLEW.dir/glew/src/visualinfo.c.i"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projects\ProcessorDesigner\glew\src\visualinfo.c > CMakeFiles\GLEW.dir\glew\src\visualinfo.c.i

CMakeFiles/GLEW.dir/glew/src/visualinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GLEW.dir/glew/src/visualinfo.c.s"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projects\ProcessorDesigner\glew\src\visualinfo.c -o CMakeFiles\GLEW.dir\glew\src\visualinfo.c.s

# Object files for target GLEW
GLEW_OBJECTS = \
"CMakeFiles/GLEW.dir/glew/src/glew.c.obj" \
"CMakeFiles/GLEW.dir/glew/src/glewinfo.c.obj" \
"CMakeFiles/GLEW.dir/glew/src/visualinfo.c.obj"

# External object files for target GLEW
GLEW_EXTERNAL_OBJECTS =

libGLEW.a: CMakeFiles/GLEW.dir/glew/src/glew.c.obj
libGLEW.a: CMakeFiles/GLEW.dir/glew/src/glewinfo.c.obj
libGLEW.a: CMakeFiles/GLEW.dir/glew/src/visualinfo.c.obj
libGLEW.a: CMakeFiles/GLEW.dir/build.make
libGLEW.a: CMakeFiles/GLEW.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projects\ProcessorDesigner\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libGLEW.a"
	$(CMAKE_COMMAND) -P CMakeFiles\GLEW.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GLEW.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GLEW.dir/build: libGLEW.a
.PHONY : CMakeFiles/GLEW.dir/build

CMakeFiles/GLEW.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GLEW.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GLEW.dir/clean

CMakeFiles/GLEW.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\ProcessorDesigner C:\Projects\ProcessorDesigner C:\Projects\ProcessorDesigner C:\Projects\ProcessorDesigner C:\Projects\ProcessorDesigner\CMakeFiles\GLEW.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GLEW.dir/depend

