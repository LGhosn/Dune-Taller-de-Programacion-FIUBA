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
CMAKE_SOURCE_DIR = "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2"

# Include any dependencies generated for this target.
include tests/CMakeFiles/SDL2pp_Point_hh_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/SDL2pp_Point_hh_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/SDL2pp_Point_hh_test.dir/flags.make

tests/CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.o: tests/CMakeFiles/SDL2pp_Point_hh_test.dir/flags.make
tests/CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.o: tests/SDL2pp_Point_hh_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.o"
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.o -c "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests/SDL2pp_Point_hh_test.cc"

tests/CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.i"
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests/SDL2pp_Point_hh_test.cc" > CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.i

tests/CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.s"
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests/SDL2pp_Point_hh_test.cc" -o CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.s

# Object files for target SDL2pp_Point_hh_test
SDL2pp_Point_hh_test_OBJECTS = \
"CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.o"

# External object files for target SDL2pp_Point_hh_test
SDL2pp_Point_hh_test_EXTERNAL_OBJECTS =

tests/SDL2pp_Point_hh_test: tests/CMakeFiles/SDL2pp_Point_hh_test.dir/SDL2pp_Point_hh_test.cc.o
tests/SDL2pp_Point_hh_test: tests/CMakeFiles/SDL2pp_Point_hh_test.dir/build.make
tests/SDL2pp_Point_hh_test: /usr/lib/x86_64-linux-gnu/libSDL2main.a
tests/SDL2pp_Point_hh_test: libSDL2pp.so.8.3.0
tests/SDL2pp_Point_hh_test: /usr/lib/x86_64-linux-gnu/libSDL2.so
tests/SDL2pp_Point_hh_test: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
tests/SDL2pp_Point_hh_test: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
tests/SDL2pp_Point_hh_test: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
tests/SDL2pp_Point_hh_test: tests/CMakeFiles/SDL2pp_Point_hh_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SDL2pp_Point_hh_test"
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2pp_Point_hh_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/SDL2pp_Point_hh_test.dir/build: tests/SDL2pp_Point_hh_test

.PHONY : tests/CMakeFiles/SDL2pp_Point_hh_test.dir/build

tests/CMakeFiles/SDL2pp_Point_hh_test.dir/clean:
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests" && $(CMAKE_COMMAND) -P CMakeFiles/SDL2pp_Point_hh_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/SDL2pp_Point_hh_test.dir/clean

tests/CMakeFiles/SDL2pp_Point_hh_test.dir/depend:
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/tests/CMakeFiles/SDL2pp_Point_hh_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/SDL2pp_Point_hh_test.dir/depend

