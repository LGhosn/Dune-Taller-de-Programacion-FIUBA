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
include examples/CMakeFiles/ttf.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/ttf.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/ttf.dir/flags.make

examples/CMakeFiles/ttf.dir/ttf.cc.o: examples/CMakeFiles/ttf.dir/flags.make
examples/CMakeFiles/ttf.dir/ttf.cc.o: examples/ttf.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/ttf.dir/ttf.cc.o"
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ttf.dir/ttf.cc.o -c "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples/ttf.cc"

examples/CMakeFiles/ttf.dir/ttf.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ttf.dir/ttf.cc.i"
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples/ttf.cc" > CMakeFiles/ttf.dir/ttf.cc.i

examples/CMakeFiles/ttf.dir/ttf.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ttf.dir/ttf.cc.s"
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples/ttf.cc" -o CMakeFiles/ttf.dir/ttf.cc.s

# Object files for target ttf
ttf_OBJECTS = \
"CMakeFiles/ttf.dir/ttf.cc.o"

# External object files for target ttf
ttf_EXTERNAL_OBJECTS =

examples/ttf: examples/CMakeFiles/ttf.dir/ttf.cc.o
examples/ttf: examples/CMakeFiles/ttf.dir/build.make
examples/ttf: /usr/lib/x86_64-linux-gnu/libSDL2main.a
examples/ttf: libSDL2pp.so.8.3.0
examples/ttf: /usr/lib/x86_64-linux-gnu/libSDL2.so
examples/ttf: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
examples/ttf: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
examples/ttf: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
examples/ttf: examples/CMakeFiles/ttf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ttf"
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ttf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/ttf.dir/build: examples/ttf

.PHONY : examples/CMakeFiles/ttf.dir/build

examples/CMakeFiles/ttf.dir/clean:
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples" && $(CMAKE_COMMAND) -P CMakeFiles/ttf.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/ttf.dir/clean

examples/CMakeFiles/ttf.dir/depend:
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples" "/home/joaquin/Documents/Facultad/Taller/TP Final/SDL2PP/libSDL2pp-0.16.2/examples/CMakeFiles/ttf.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : examples/CMakeFiles/ttf.dir/depend

