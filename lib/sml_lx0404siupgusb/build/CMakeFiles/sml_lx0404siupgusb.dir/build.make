# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\msys64\ucrt64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\ucrt64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb\build

# Include any dependencies generated for this target.
include CMakeFiles/sml_lx0404siupgusb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sml_lx0404siupgusb.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sml_lx0404siupgusb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sml_lx0404siupgusb.dir/flags.make

CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.obj: CMakeFiles/sml_lx0404siupgusb.dir/flags.make
CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.obj: CMakeFiles/sml_lx0404siupgusb.dir/includes_C.rsp
CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.obj: C:/Users/mukai/rainbow/lib/sml_lx0404siupgusb/src/sml_lx0404siupgusb.c
CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.obj: CMakeFiles/sml_lx0404siupgusb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.obj"
	C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.obj -MF CMakeFiles\sml_lx0404siupgusb.dir\src\sml_lx0404siupgusb.c.obj.d -o CMakeFiles\sml_lx0404siupgusb.dir\src\sml_lx0404siupgusb.c.obj -c C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb\src\sml_lx0404siupgusb.c

CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.i"
	C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb\src\sml_lx0404siupgusb.c > CMakeFiles\sml_lx0404siupgusb.dir\src\sml_lx0404siupgusb.c.i

CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.s"
	C:\msys64\ucrt64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb\src\sml_lx0404siupgusb.c -o CMakeFiles\sml_lx0404siupgusb.dir\src\sml_lx0404siupgusb.c.s

# Object files for target sml_lx0404siupgusb
sml_lx0404siupgusb_OBJECTS = \
"CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.obj"

# External object files for target sml_lx0404siupgusb
sml_lx0404siupgusb_EXTERNAL_OBJECTS =

libsml_lx0404siupgusb.a: CMakeFiles/sml_lx0404siupgusb.dir/src/sml_lx0404siupgusb.c.obj
libsml_lx0404siupgusb.a: CMakeFiles/sml_lx0404siupgusb.dir/build.make
libsml_lx0404siupgusb.a: CMakeFiles/sml_lx0404siupgusb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libsml_lx0404siupgusb.a"
	$(CMAKE_COMMAND) -P CMakeFiles\sml_lx0404siupgusb.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sml_lx0404siupgusb.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sml_lx0404siupgusb.dir/build: libsml_lx0404siupgusb.a
.PHONY : CMakeFiles/sml_lx0404siupgusb.dir/build

CMakeFiles/sml_lx0404siupgusb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sml_lx0404siupgusb.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sml_lx0404siupgusb.dir/clean

CMakeFiles/sml_lx0404siupgusb.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb\build C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb\build C:\Users\mukai\rainbow\lib\sml_lx0404siupgusb\build\CMakeFiles\sml_lx0404siupgusb.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sml_lx0404siupgusb.dir/depend
