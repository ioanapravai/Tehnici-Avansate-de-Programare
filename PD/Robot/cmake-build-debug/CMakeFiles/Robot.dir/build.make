# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\ANUL2\TAP\PD\Robot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\ANUL2\TAP\PD\Robot\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Robot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Robot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Robot.dir/flags.make

CMakeFiles/Robot.dir/main.cpp.obj: CMakeFiles/Robot.dir/flags.make
CMakeFiles/Robot.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\ANUL2\TAP\PD\Robot\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Robot.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Robot.dir\main.cpp.obj -c C:\ANUL2\TAP\PD\Robot\main.cpp

CMakeFiles/Robot.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Robot.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\ANUL2\TAP\PD\Robot\main.cpp > CMakeFiles\Robot.dir\main.cpp.i

CMakeFiles/Robot.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Robot.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\ANUL2\TAP\PD\Robot\main.cpp -o CMakeFiles\Robot.dir\main.cpp.s

# Object files for target Robot
Robot_OBJECTS = \
"CMakeFiles/Robot.dir/main.cpp.obj"

# External object files for target Robot
Robot_EXTERNAL_OBJECTS =

Robot.exe: CMakeFiles/Robot.dir/main.cpp.obj
Robot.exe: CMakeFiles/Robot.dir/build.make
Robot.exe: CMakeFiles/Robot.dir/linklibs.rsp
Robot.exe: CMakeFiles/Robot.dir/objects1.rsp
Robot.exe: CMakeFiles/Robot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\ANUL2\TAP\PD\Robot\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Robot.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Robot.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Robot.dir/build: Robot.exe

.PHONY : CMakeFiles/Robot.dir/build

CMakeFiles/Robot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Robot.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Robot.dir/clean

CMakeFiles/Robot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\ANUL2\TAP\PD\Robot C:\ANUL2\TAP\PD\Robot C:\ANUL2\TAP\PD\Robot\cmake-build-debug C:\ANUL2\TAP\PD\Robot\cmake-build-debug C:\ANUL2\TAP\PD\Robot\cmake-build-debug\CMakeFiles\Robot.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Robot.dir/depend

