# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EX2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EX2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EX2.dir/flags.make

CMakeFiles/EX2.dir/main.cpp.o: CMakeFiles/EX2.dir/flags.make
CMakeFiles/EX2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EX2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EX2.dir/main.cpp.o -c /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/main.cpp

CMakeFiles/EX2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EX2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/main.cpp > CMakeFiles/EX2.dir/main.cpp.i

CMakeFiles/EX2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EX2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/main.cpp -o CMakeFiles/EX2.dir/main.cpp.s

# Object files for target EX2
EX2_OBJECTS = \
"CMakeFiles/EX2.dir/main.cpp.o"

# External object files for target EX2
EX2_EXTERNAL_OBJECTS =

EX2: CMakeFiles/EX2.dir/main.cpp.o
EX2: CMakeFiles/EX2.dir/build.make
EX2: CMakeFiles/EX2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable EX2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EX2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EX2.dir/build: EX2

.PHONY : CMakeFiles/EX2.dir/build

CMakeFiles/EX2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EX2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EX2.dir/clean

CMakeFiles/EX2.dir/depend:
	cd /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2 /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2 /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/cmake-build-debug /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/cmake-build-debug /Users/ewo/Desktop/предметы/alghoritms/lab1/EX2/cmake-build-debug/CMakeFiles/EX2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EX2.dir/depend

