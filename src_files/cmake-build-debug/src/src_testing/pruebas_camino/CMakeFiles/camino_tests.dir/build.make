# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/193/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/193/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug"

# Include any dependencies generated for this target.
include src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/progress.make

# Include the compile flags for this target's objects.
include src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/flags.make

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/flags.make
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o: src/src_testing/pruebas_camino/camino_tests_autogen/mocs_compilation.cpp
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o -MF CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino/camino_tests_autogen/mocs_compilation.cpp"

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.i"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino/camino_tests_autogen/mocs_compilation.cpp" > CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.i

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.s"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino/camino_tests_autogen/mocs_compilation.cpp" -o CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.s

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/pruebas_camino.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/flags.make
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/pruebas_camino.cpp.o: ../src/src_testing/pruebas_camino/pruebas_camino.cpp
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/pruebas_camino.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/pruebas_camino.cpp.o"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/pruebas_camino.cpp.o -MF CMakeFiles/camino_tests.dir/pruebas_camino.cpp.o.d -o CMakeFiles/camino_tests.dir/pruebas_camino.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_camino/pruebas_camino.cpp"

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/pruebas_camino.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/pruebas_camino.cpp.i"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_camino/pruebas_camino.cpp" > CMakeFiles/camino_tests.dir/pruebas_camino.cpp.i

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/pruebas_camino.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/pruebas_camino.cpp.s"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_camino/pruebas_camino.cpp" -o CMakeFiles/camino_tests.dir/pruebas_camino.cpp.s

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/flags.make
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.o: ../src/src_server/server_game/server_mapa/server_camino.cpp
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.o"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.o -MF CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.o.d -o CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_game/server_mapa/server_camino.cpp"

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.i"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_game/server_mapa/server_camino.cpp" > CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.i

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.s"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_game/server_mapa/server_camino.cpp" -o CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.s

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/flags.make
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.o: ../src/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.o"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.o -MF CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.o.d -o CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp"

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.i"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp" > CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.i

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.s"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp" -o CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.s

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/flags.make
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.o: ../src/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.o"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.o -MF CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.o.d -o CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp"

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.i"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp" > CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.i

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.s"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp" -o CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.s

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/flags.make
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.o: ../src/src_common/common_coords.cpp
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.o: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.o"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.o -MF CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.o.d -o CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_coords.cpp"

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.i"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_coords.cpp" > CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.i

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.s"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_coords.cpp" -o CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.s

# Object files for target camino_tests
camino_tests_OBJECTS = \
"CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/camino_tests.dir/pruebas_camino.cpp.o" \
"CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.o" \
"CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.o" \
"CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.o" \
"CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.o"

# External object files for target camino_tests
camino_tests_EXTERNAL_OBJECTS =

src/src_testing/pruebas_camino/camino_tests: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o
src/src_testing/pruebas_camino/camino_tests: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/pruebas_camino.cpp.o
src/src_testing/pruebas_camino/camino_tests: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino.cpp.o
src/src_testing/pruebas_camino/camino_tests: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp.o
src/src_testing/pruebas_camino/camino_tests: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp.o
src/src_testing/pruebas_camino/camino_tests: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/__/__/src_common/common_coords.cpp.o
src/src_testing/pruebas_camino/camino_tests: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/build.make
src/src_testing/pruebas_camino/camino_tests: lib/libgtest_maind.a
src/src_testing/pruebas_camino/camino_tests: lib/libgtestd.a
src/src_testing/pruebas_camino/camino_tests: src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable camino_tests"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/camino_tests.dir/link.txt --verbose=$(VERBOSE)
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && /snap/clion/193/bin/cmake/linux/bin/cmake -D TEST_TARGET=camino_tests -D "TEST_EXECUTABLE=/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino/camino_tests" -D TEST_EXECUTOR= -D "TEST_WORKING_DIR=/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=camino_tests_TESTS -D "CTEST_FILE=/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino/camino_tests[1]_tests.cmake" -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /snap/clion/193/bin/cmake/linux/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/build: src/src_testing/pruebas_camino/camino_tests
.PHONY : src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/build

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/clean:
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" && $(CMAKE_COMMAND) -P CMakeFiles/camino_tests.dir/cmake_clean.cmake
.PHONY : src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/clean

src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/depend:
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_camino" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/src_testing/pruebas_camino/CMakeFiles/camino_tests.dir/depend

