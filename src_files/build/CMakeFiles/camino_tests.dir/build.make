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
CMAKE_SOURCE_DIR = "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build"

# Include any dependencies generated for this target.
include CMakeFiles/camino_tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/camino_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/camino_tests.dir/flags.make

CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o: CMakeFiles/camino_tests.dir/flags.make
CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o: camino_tests_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests_autogen/mocs_compilation.cpp"

CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests_autogen/mocs_compilation.cpp" > CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.i

CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests_autogen/mocs_compilation.cpp" -o CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.s

CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.o: CMakeFiles/camino_tests.dir/flags.make
CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.o: ../src/src_testing/pruebas_camino/pruebas_camino.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_camino/pruebas_camino.cpp"

CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_camino/pruebas_camino.cpp" > CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.i

CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_camino/pruebas_camino.cpp" -o CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.s

CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.o: CMakeFiles/camino_tests.dir/flags.make
CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.o: ../src/src_server/server_camino.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_camino.cpp"

CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_camino.cpp" > CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.i

CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_camino.cpp" -o CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.s

CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.o: CMakeFiles/camino_tests.dir/flags.make
CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.o: ../src/src_server/server_camino_no_encontrado_exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_camino_no_encontrado_exception.cpp"

CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_camino_no_encontrado_exception.cpp" > CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.i

CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_camino_no_encontrado_exception.cpp" -o CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.s

CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.o: CMakeFiles/camino_tests.dir/flags.make
CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.o: ../src/src_server/server_fuera_de_rango_exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_fuera_de_rango_exception.cpp"

CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_fuera_de_rango_exception.cpp" > CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.i

CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_fuera_de_rango_exception.cpp" -o CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.s

CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.o: CMakeFiles/camino_tests.dir/flags.make
CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.o: ../src/src_common/common_coords.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_coords.cpp"

CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_coords.cpp" > CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.i

CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_coords.cpp" -o CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.s

# Object files for target camino_tests
camino_tests_OBJECTS = \
"CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.o" \
"CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.o" \
"CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.o" \
"CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.o" \
"CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.o"

# External object files for target camino_tests
camino_tests_EXTERNAL_OBJECTS =

camino_tests: CMakeFiles/camino_tests.dir/camino_tests_autogen/mocs_compilation.cpp.o
camino_tests: CMakeFiles/camino_tests.dir/src/src_testing/pruebas_camino/pruebas_camino.cpp.o
camino_tests: CMakeFiles/camino_tests.dir/src/src_server/server_camino.cpp.o
camino_tests: CMakeFiles/camino_tests.dir/src/src_server/server_camino_no_encontrado_exception.cpp.o
camino_tests: CMakeFiles/camino_tests.dir/src/src_server/server_fuera_de_rango_exception.cpp.o
camino_tests: CMakeFiles/camino_tests.dir/src/src_common/common_coords.cpp.o
camino_tests: CMakeFiles/camino_tests.dir/build.make
camino_tests: lib/libgtest_main.a
camino_tests: lib/libgtest.a
camino_tests: CMakeFiles/camino_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable camino_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/camino_tests.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=camino_tests -D "TEST_EXECUTABLE=/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests" -D TEST_EXECUTOR= -D "TEST_WORKING_DIR=/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build" -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=camino_tests_TESTS -D "CTEST_FILE=/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/camino_tests[1]_tests.cmake" -D TEST_DISCOVERY_TIMEOUT=5 -P /usr/share/cmake-3.16/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/camino_tests.dir/build: camino_tests

.PHONY : CMakeFiles/camino_tests.dir/build

CMakeFiles/camino_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/camino_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/camino_tests.dir/clean

CMakeFiles/camino_tests.dir/depend:
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles/camino_tests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/camino_tests.dir/depend

