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
CMAKE_SOURCE_DIR = /home/sruizs/Escritorio/DuneMapEditor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sruizs/Escritorio/DuneMapEditor/build

# Include any dependencies generated for this target.
include CMakeFiles/editor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/editor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/editor.dir/flags.make

CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.o: CMakeFiles/editor.dir/flags.make
CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.o: editor_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sruizs/Escritorio/DuneMapEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.o -c /home/sruizs/Escritorio/DuneMapEditor/build/editor_autogen/mocs_compilation.cpp

CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sruizs/Escritorio/DuneMapEditor/build/editor_autogen/mocs_compilation.cpp > CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.i

CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sruizs/Escritorio/DuneMapEditor/build/editor_autogen/mocs_compilation.cpp -o CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.s

CMakeFiles/editor.dir/DuneMapEditor.cpp.o: CMakeFiles/editor.dir/flags.make
CMakeFiles/editor.dir/DuneMapEditor.cpp.o: ../DuneMapEditor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sruizs/Escritorio/DuneMapEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/editor.dir/DuneMapEditor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/editor.dir/DuneMapEditor.cpp.o -c /home/sruizs/Escritorio/DuneMapEditor/DuneMapEditor.cpp

CMakeFiles/editor.dir/DuneMapEditor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/editor.dir/DuneMapEditor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sruizs/Escritorio/DuneMapEditor/DuneMapEditor.cpp > CMakeFiles/editor.dir/DuneMapEditor.cpp.i

CMakeFiles/editor.dir/DuneMapEditor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/editor.dir/DuneMapEditor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sruizs/Escritorio/DuneMapEditor/DuneMapEditor.cpp -o CMakeFiles/editor.dir/DuneMapEditor.cpp.s

CMakeFiles/editor.dir/main_editor.cpp.o: CMakeFiles/editor.dir/flags.make
CMakeFiles/editor.dir/main_editor.cpp.o: ../main_editor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sruizs/Escritorio/DuneMapEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/editor.dir/main_editor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/editor.dir/main_editor.cpp.o -c /home/sruizs/Escritorio/DuneMapEditor/main_editor.cpp

CMakeFiles/editor.dir/main_editor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/editor.dir/main_editor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sruizs/Escritorio/DuneMapEditor/main_editor.cpp > CMakeFiles/editor.dir/main_editor.cpp.i

CMakeFiles/editor.dir/main_editor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/editor.dir/main_editor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sruizs/Escritorio/DuneMapEditor/main_editor.cpp -o CMakeFiles/editor.dir/main_editor.cpp.s

# Object files for target editor
editor_OBJECTS = \
"CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/editor.dir/DuneMapEditor.cpp.o" \
"CMakeFiles/editor.dir/main_editor.cpp.o"

# External object files for target editor
editor_EXTERNAL_OBJECTS =

editor: CMakeFiles/editor.dir/editor_autogen/mocs_compilation.cpp.o
editor: CMakeFiles/editor.dir/DuneMapEditor.cpp.o
editor: CMakeFiles/editor.dir/main_editor.cpp.o
editor: CMakeFiles/editor.dir/build.make
editor: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
editor: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
editor: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
editor: CMakeFiles/editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sruizs/Escritorio/DuneMapEditor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable editor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/editor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/editor.dir/build: editor

.PHONY : CMakeFiles/editor.dir/build

CMakeFiles/editor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/editor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/editor.dir/clean

CMakeFiles/editor.dir/depend:
	cd /home/sruizs/Escritorio/DuneMapEditor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sruizs/Escritorio/DuneMapEditor /home/sruizs/Escritorio/DuneMapEditor /home/sruizs/Escritorio/DuneMapEditor/build /home/sruizs/Escritorio/DuneMapEditor/build /home/sruizs/Escritorio/DuneMapEditor/build/CMakeFiles/editor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/editor.dir/depend

