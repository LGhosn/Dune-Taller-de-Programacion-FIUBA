# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sruizs/Escritorio/MenuDune

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sruizs/Escritorio/MenuDune/build

# Utility rule file for client_autogen.

# Include the progress variables for this target.
include CMakeFiles/client_autogen.dir/progress.make

CMakeFiles/client_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sruizs/Escritorio/MenuDune/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target client"
	/usr/bin/cmake -E cmake_autogen /home/sruizs/Escritorio/MenuDune/build/CMakeFiles/client_autogen.dir/AutogenInfo.json ""

client_autogen: CMakeFiles/client_autogen
client_autogen: CMakeFiles/client_autogen.dir/build.make

.PHONY : client_autogen

# Rule to build all files generated by this target.
CMakeFiles/client_autogen.dir/build: client_autogen

.PHONY : CMakeFiles/client_autogen.dir/build

CMakeFiles/client_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client_autogen.dir/clean

CMakeFiles/client_autogen.dir/depend:
	cd /home/sruizs/Escritorio/MenuDune/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sruizs/Escritorio/MenuDune /home/sruizs/Escritorio/MenuDune /home/sruizs/Escritorio/MenuDune/build /home/sruizs/Escritorio/MenuDune/build /home/sruizs/Escritorio/MenuDune/build/CMakeFiles/client_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client_autogen.dir/depend

