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
CMAKE_SOURCE_DIR = "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build"

# Utility rule file for camino_tests_autogen.

# Include the progress variables for this target.
include src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/progress.make

src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target camino_tests"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build/src/src_testing/pruebas_camino" && /usr/bin/cmake -E cmake_autogen "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build/src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/AutogenInfo.json" ""

camino_tests_autogen: src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen
camino_tests_autogen: src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/build.make

.PHONY : camino_tests_autogen

# Rule to build all files generated by this target.
src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/build: camino_tests_autogen

.PHONY : src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/build

src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/clean:
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build/src/src_testing/pruebas_camino" && $(CMAKE_COMMAND) -P CMakeFiles/camino_tests_autogen.dir/cmake_clean.cmake
.PHONY : src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/clean

src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/depend:
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_camino" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build/src/src_testing/pruebas_camino" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/build/src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/src_testing/pruebas_camino/CMakeFiles/camino_tests_autogen.dir/depend

