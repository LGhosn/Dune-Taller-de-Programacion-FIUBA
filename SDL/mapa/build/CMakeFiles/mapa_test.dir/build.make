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
CMAKE_SOURCE_DIR = "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/build"

# Include any dependencies generated for this target.
include CMakeFiles/mapa_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mapa_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mapa_test.dir/flags.make

CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.o: CMakeFiles/mapa_test.dir/flags.make
CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.o: ../sdl_mapa_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.o -c "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/sdl_mapa_main.cpp"

CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/sdl_mapa_main.cpp" > CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.i

CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/sdl_mapa_main.cpp" -o CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.s

# Object files for target mapa_test
mapa_test_OBJECTS = \
"CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.o"

# External object files for target mapa_test
mapa_test_EXTERNAL_OBJECTS =

mapa_test: CMakeFiles/mapa_test.dir/sdl_mapa_main.cpp.o
mapa_test: CMakeFiles/mapa_test.dir/build.make
mapa_test: /usr/lib/x86_64-linux-gnu/libSDL2main.a
mapa_test: SDL2pp/build/libSDL2pp.a
mapa_test: /usr/lib/x86_64-linux-gnu/libSDL2.so
mapa_test: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
mapa_test: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
mapa_test: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
mapa_test: CMakeFiles/mapa_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mapa_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mapa_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mapa_test.dir/build: mapa_test

.PHONY : CMakeFiles/mapa_test.dir/build

CMakeFiles/mapa_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mapa_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mapa_test.dir/clean

CMakeFiles/mapa_test.dir/depend:
	cd "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa" "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa" "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/build" "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/build" "/home/joaquin/Documents/Facultad/Taller/TP Final/Dune-Taller-de-Programacion-FIUBA/SDL/mapa/build/CMakeFiles/mapa_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mapa_test.dir/depend

