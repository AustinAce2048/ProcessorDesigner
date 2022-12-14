# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"C:\Program Files\CMake\bin\cmake-gui.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\CMake\bin\cmake.exe" --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	"C:\Program Files\CMake\bin\cmake.exe" -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	"C:\Program Files\CMake\bin\cmake.exe" -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	"C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	"C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	"C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	"C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Projects\ProcessorDesigner\CMakeFiles C:\Projects\ProcessorDesigner\\CMakeFiles\progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Projects\ProcessorDesigner\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ProcessorDesigner

# Build rule for target.
ProcessorDesigner: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ProcessorDesigner
.PHONY : ProcessorDesigner

# fast build rule for target.
ProcessorDesigner/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ProcessorDesigner.dir\build.make CMakeFiles/ProcessorDesigner.dir/build
.PHONY : ProcessorDesigner/fast

#=============================================================================
# Target rules for targets named IMGUI

# Build rule for target.
IMGUI: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 IMGUI
.PHONY : IMGUI

# fast build rule for target.
IMGUI/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/build
.PHONY : IMGUI/fast

#=============================================================================
# Target rules for targets named SOIL

# Build rule for target.
SOIL: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 SOIL
.PHONY : SOIL

# fast build rule for target.
SOIL/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/build
.PHONY : SOIL/fast

#=============================================================================
# Target rules for targets named uninstall

# Build rule for target.
uninstall: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 uninstall
.PHONY : uninstall

# fast build rule for target.
uninstall/fast:
	$(MAKE) $(MAKESILENT) -f glfw\CMakeFiles\uninstall.dir\build.make glfw/CMakeFiles/uninstall.dir/build
.PHONY : uninstall/fast

#=============================================================================
# Target rules for targets named glfw

# Build rule for target.
glfw: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 glfw
.PHONY : glfw

# fast build rule for target.
glfw/fast:
	$(MAKE) $(MAKESILENT) -f glfw\src\CMakeFiles\glfw.dir\build.make glfw/src/CMakeFiles/glfw.dir/build
.PHONY : glfw/fast

#=============================================================================
# Target rules for targets named update_mappings

# Build rule for target.
update_mappings: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 update_mappings
.PHONY : update_mappings

# fast build rule for target.
update_mappings/fast:
	$(MAKE) $(MAKESILENT) -f glfw\src\CMakeFiles\update_mappings.dir\build.make glfw/src/CMakeFiles/update_mappings.dir/build
.PHONY : update_mappings/fast

#=============================================================================
# Target rules for targets named glew

# Build rule for target.
glew: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 glew
.PHONY : glew

# fast build rule for target.
glew/fast:
	$(MAKE) $(MAKESILENT) -f glew\build\cmake\CMakeFiles\glew.dir\build.make glew/build/cmake/CMakeFiles/glew.dir/build
.PHONY : glew/fast

#=============================================================================
# Target rules for targets named glew_s

# Build rule for target.
glew_s: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 glew_s
.PHONY : glew_s

# fast build rule for target.
glew_s/fast:
	$(MAKE) $(MAKESILENT) -f glew\build\cmake\CMakeFiles\glew_s.dir\build.make glew/build/cmake/CMakeFiles/glew_s.dir/build
.PHONY : glew_s/fast

#=============================================================================
# Target rules for targets named glewinfo

# Build rule for target.
glewinfo: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 glewinfo
.PHONY : glewinfo

# fast build rule for target.
glewinfo/fast:
	$(MAKE) $(MAKESILENT) -f glew\build\cmake\CMakeFiles\glewinfo.dir\build.make glew/build/cmake/CMakeFiles/glewinfo.dir/build
.PHONY : glewinfo/fast

#=============================================================================
# Target rules for targets named visualinfo

# Build rule for target.
visualinfo: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 visualinfo
.PHONY : visualinfo

# fast build rule for target.
visualinfo/fast:
	$(MAKE) $(MAKESILENT) -f glew\build\cmake\CMakeFiles\visualinfo.dir\build.make glew/build/cmake/CMakeFiles/visualinfo.dir/build
.PHONY : visualinfo/fast

imgui/imgui.obj: imgui/imgui.cpp.obj
.PHONY : imgui/imgui.obj

# target to build an object file
imgui/imgui.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui.cpp.obj
.PHONY : imgui/imgui.cpp.obj

imgui/imgui.i: imgui/imgui.cpp.i
.PHONY : imgui/imgui.i

# target to preprocess a source file
imgui/imgui.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui.cpp.i
.PHONY : imgui/imgui.cpp.i

imgui/imgui.s: imgui/imgui.cpp.s
.PHONY : imgui/imgui.s

# target to generate assembly for a file
imgui/imgui.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui.cpp.s
.PHONY : imgui/imgui.cpp.s

imgui/imgui_demo.obj: imgui/imgui_demo.cpp.obj
.PHONY : imgui/imgui_demo.obj

# target to build an object file
imgui/imgui_demo.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_demo.cpp.obj
.PHONY : imgui/imgui_demo.cpp.obj

imgui/imgui_demo.i: imgui/imgui_demo.cpp.i
.PHONY : imgui/imgui_demo.i

# target to preprocess a source file
imgui/imgui_demo.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_demo.cpp.i
.PHONY : imgui/imgui_demo.cpp.i

imgui/imgui_demo.s: imgui/imgui_demo.cpp.s
.PHONY : imgui/imgui_demo.s

# target to generate assembly for a file
imgui/imgui_demo.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_demo.cpp.s
.PHONY : imgui/imgui_demo.cpp.s

imgui/imgui_draw.obj: imgui/imgui_draw.cpp.obj
.PHONY : imgui/imgui_draw.obj

# target to build an object file
imgui/imgui_draw.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_draw.cpp.obj
.PHONY : imgui/imgui_draw.cpp.obj

imgui/imgui_draw.i: imgui/imgui_draw.cpp.i
.PHONY : imgui/imgui_draw.i

# target to preprocess a source file
imgui/imgui_draw.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_draw.cpp.i
.PHONY : imgui/imgui_draw.cpp.i

imgui/imgui_draw.s: imgui/imgui_draw.cpp.s
.PHONY : imgui/imgui_draw.s

# target to generate assembly for a file
imgui/imgui_draw.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_draw.cpp.s
.PHONY : imgui/imgui_draw.cpp.s

imgui/imgui_impl_glfw.obj: imgui/imgui_impl_glfw.cpp.obj
.PHONY : imgui/imgui_impl_glfw.obj

# target to build an object file
imgui/imgui_impl_glfw.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_impl_glfw.cpp.obj
.PHONY : imgui/imgui_impl_glfw.cpp.obj

imgui/imgui_impl_glfw.i: imgui/imgui_impl_glfw.cpp.i
.PHONY : imgui/imgui_impl_glfw.i

# target to preprocess a source file
imgui/imgui_impl_glfw.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_impl_glfw.cpp.i
.PHONY : imgui/imgui_impl_glfw.cpp.i

imgui/imgui_impl_glfw.s: imgui/imgui_impl_glfw.cpp.s
.PHONY : imgui/imgui_impl_glfw.s

# target to generate assembly for a file
imgui/imgui_impl_glfw.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_impl_glfw.cpp.s
.PHONY : imgui/imgui_impl_glfw.cpp.s

imgui/imgui_impl_opengl3.obj: imgui/imgui_impl_opengl3.cpp.obj
.PHONY : imgui/imgui_impl_opengl3.obj

# target to build an object file
imgui/imgui_impl_opengl3.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_impl_opengl3.cpp.obj
.PHONY : imgui/imgui_impl_opengl3.cpp.obj

imgui/imgui_impl_opengl3.i: imgui/imgui_impl_opengl3.cpp.i
.PHONY : imgui/imgui_impl_opengl3.i

# target to preprocess a source file
imgui/imgui_impl_opengl3.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_impl_opengl3.cpp.i
.PHONY : imgui/imgui_impl_opengl3.cpp.i

imgui/imgui_impl_opengl3.s: imgui/imgui_impl_opengl3.cpp.s
.PHONY : imgui/imgui_impl_opengl3.s

# target to generate assembly for a file
imgui/imgui_impl_opengl3.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_impl_opengl3.cpp.s
.PHONY : imgui/imgui_impl_opengl3.cpp.s

imgui/imgui_tables.obj: imgui/imgui_tables.cpp.obj
.PHONY : imgui/imgui_tables.obj

# target to build an object file
imgui/imgui_tables.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_tables.cpp.obj
.PHONY : imgui/imgui_tables.cpp.obj

imgui/imgui_tables.i: imgui/imgui_tables.cpp.i
.PHONY : imgui/imgui_tables.i

# target to preprocess a source file
imgui/imgui_tables.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_tables.cpp.i
.PHONY : imgui/imgui_tables.cpp.i

imgui/imgui_tables.s: imgui/imgui_tables.cpp.s
.PHONY : imgui/imgui_tables.s

# target to generate assembly for a file
imgui/imgui_tables.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_tables.cpp.s
.PHONY : imgui/imgui_tables.cpp.s

imgui/imgui_widgets.obj: imgui/imgui_widgets.cpp.obj
.PHONY : imgui/imgui_widgets.obj

# target to build an object file
imgui/imgui_widgets.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_widgets.cpp.obj
.PHONY : imgui/imgui_widgets.cpp.obj

imgui/imgui_widgets.i: imgui/imgui_widgets.cpp.i
.PHONY : imgui/imgui_widgets.i

# target to preprocess a source file
imgui/imgui_widgets.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_widgets.cpp.i
.PHONY : imgui/imgui_widgets.cpp.i

imgui/imgui_widgets.s: imgui/imgui_widgets.cpp.s
.PHONY : imgui/imgui_widgets.s

# target to generate assembly for a file
imgui/imgui_widgets.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/imgui_widgets.cpp.s
.PHONY : imgui/imgui_widgets.cpp.s

imgui/misc/cpp/imgui_stdlib.obj: imgui/misc/cpp/imgui_stdlib.cpp.obj
.PHONY : imgui/misc/cpp/imgui_stdlib.obj

# target to build an object file
imgui/misc/cpp/imgui_stdlib.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/misc/cpp/imgui_stdlib.cpp.obj
.PHONY : imgui/misc/cpp/imgui_stdlib.cpp.obj

imgui/misc/cpp/imgui_stdlib.i: imgui/misc/cpp/imgui_stdlib.cpp.i
.PHONY : imgui/misc/cpp/imgui_stdlib.i

# target to preprocess a source file
imgui/misc/cpp/imgui_stdlib.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/misc/cpp/imgui_stdlib.cpp.i
.PHONY : imgui/misc/cpp/imgui_stdlib.cpp.i

imgui/misc/cpp/imgui_stdlib.s: imgui/misc/cpp/imgui_stdlib.cpp.s
.PHONY : imgui/misc/cpp/imgui_stdlib.s

# target to generate assembly for a file
imgui/misc/cpp/imgui_stdlib.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\IMGUI.dir\build.make CMakeFiles/IMGUI.dir/imgui/misc/cpp/imgui_stdlib.cpp.s
.PHONY : imgui/misc/cpp/imgui_stdlib.cpp.s

main.obj: main.cpp.obj
.PHONY : main.obj

# target to build an object file
main.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ProcessorDesigner.dir\build.make CMakeFiles/ProcessorDesigner.dir/main.cpp.obj
.PHONY : main.cpp.obj

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ProcessorDesigner.dir\build.make CMakeFiles/ProcessorDesigner.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ProcessorDesigner.dir\build.make CMakeFiles/ProcessorDesigner.dir/main.cpp.s
.PHONY : main.cpp.s

soil/src/image_dxt.obj: soil/src/image_dxt.c.obj
.PHONY : soil/src/image_dxt.obj

# target to build an object file
soil/src/image_dxt.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/image_dxt.c.obj
.PHONY : soil/src/image_dxt.c.obj

soil/src/image_dxt.i: soil/src/image_dxt.c.i
.PHONY : soil/src/image_dxt.i

# target to preprocess a source file
soil/src/image_dxt.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/image_dxt.c.i
.PHONY : soil/src/image_dxt.c.i

soil/src/image_dxt.s: soil/src/image_dxt.c.s
.PHONY : soil/src/image_dxt.s

# target to generate assembly for a file
soil/src/image_dxt.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/image_dxt.c.s
.PHONY : soil/src/image_dxt.c.s

soil/src/image_helper.obj: soil/src/image_helper.c.obj
.PHONY : soil/src/image_helper.obj

# target to build an object file
soil/src/image_helper.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/image_helper.c.obj
.PHONY : soil/src/image_helper.c.obj

soil/src/image_helper.i: soil/src/image_helper.c.i
.PHONY : soil/src/image_helper.i

# target to preprocess a source file
soil/src/image_helper.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/image_helper.c.i
.PHONY : soil/src/image_helper.c.i

soil/src/image_helper.s: soil/src/image_helper.c.s
.PHONY : soil/src/image_helper.s

# target to generate assembly for a file
soil/src/image_helper.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/image_helper.c.s
.PHONY : soil/src/image_helper.c.s

soil/src/soil.obj: soil/src/soil.c.obj
.PHONY : soil/src/soil.obj

# target to build an object file
soil/src/soil.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/soil.c.obj
.PHONY : soil/src/soil.c.obj

soil/src/soil.i: soil/src/soil.c.i
.PHONY : soil/src/soil.i

# target to preprocess a source file
soil/src/soil.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/soil.c.i
.PHONY : soil/src/soil.c.i

soil/src/soil.s: soil/src/soil.c.s
.PHONY : soil/src/soil.s

# target to generate assembly for a file
soil/src/soil.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/soil.c.s
.PHONY : soil/src/soil.c.s

soil/src/stb_image_aug.obj: soil/src/stb_image_aug.c.obj
.PHONY : soil/src/stb_image_aug.obj

# target to build an object file
soil/src/stb_image_aug.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/stb_image_aug.c.obj
.PHONY : soil/src/stb_image_aug.c.obj

soil/src/stb_image_aug.i: soil/src/stb_image_aug.c.i
.PHONY : soil/src/stb_image_aug.i

# target to preprocess a source file
soil/src/stb_image_aug.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/stb_image_aug.c.i
.PHONY : soil/src/stb_image_aug.c.i

soil/src/stb_image_aug.s: soil/src/stb_image_aug.c.s
.PHONY : soil/src/stb_image_aug.s

# target to generate assembly for a file
soil/src/stb_image_aug.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\SOIL.dir\build.make CMakeFiles/SOIL.dir/soil/src/stb_image_aug.c.s
.PHONY : soil/src/stb_image_aug.c.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... install
	@echo ... install/local
	@echo ... install/strip
	@echo ... list_install_components
	@echo ... rebuild_cache
	@echo ... uninstall
	@echo ... update_mappings
	@echo ... IMGUI
	@echo ... ProcessorDesigner
	@echo ... SOIL
	@echo ... glew
	@echo ... glew_s
	@echo ... glewinfo
	@echo ... glfw
	@echo ... visualinfo
	@echo ... imgui/imgui.obj
	@echo ... imgui/imgui.i
	@echo ... imgui/imgui.s
	@echo ... imgui/imgui_demo.obj
	@echo ... imgui/imgui_demo.i
	@echo ... imgui/imgui_demo.s
	@echo ... imgui/imgui_draw.obj
	@echo ... imgui/imgui_draw.i
	@echo ... imgui/imgui_draw.s
	@echo ... imgui/imgui_impl_glfw.obj
	@echo ... imgui/imgui_impl_glfw.i
	@echo ... imgui/imgui_impl_glfw.s
	@echo ... imgui/imgui_impl_opengl3.obj
	@echo ... imgui/imgui_impl_opengl3.i
	@echo ... imgui/imgui_impl_opengl3.s
	@echo ... imgui/imgui_tables.obj
	@echo ... imgui/imgui_tables.i
	@echo ... imgui/imgui_tables.s
	@echo ... imgui/imgui_widgets.obj
	@echo ... imgui/imgui_widgets.i
	@echo ... imgui/imgui_widgets.s
	@echo ... imgui/misc/cpp/imgui_stdlib.obj
	@echo ... imgui/misc/cpp/imgui_stdlib.i
	@echo ... imgui/misc/cpp/imgui_stdlib.s
	@echo ... main.obj
	@echo ... main.i
	@echo ... main.s
	@echo ... soil/src/image_dxt.obj
	@echo ... soil/src/image_dxt.i
	@echo ... soil/src/image_dxt.s
	@echo ... soil/src/image_helper.obj
	@echo ... soil/src/image_helper.i
	@echo ... soil/src/image_helper.s
	@echo ... soil/src/soil.obj
	@echo ... soil/src/soil.i
	@echo ... soil/src/soil.s
	@echo ... soil/src/stb_image_aug.obj
	@echo ... soil/src/stb_image_aug.i
	@echo ... soil/src/stb_image_aug.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

