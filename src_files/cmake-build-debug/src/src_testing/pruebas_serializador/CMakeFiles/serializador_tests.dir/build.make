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
include src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/progress.make

# Include the compile flags for this target's objects.
include src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/flags.make

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.o: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/flags.make
src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.o: src/src_testing/pruebas_serializador/serializador_tests_autogen/mocs_compilation.cpp
src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.o: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.o"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.o -MF CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador/serializador_tests_autogen/mocs_compilation.cpp"

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.i"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador/serializador_tests_autogen/mocs_compilation.cpp" > CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.i

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.s"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador/serializador_tests_autogen/mocs_compilation.cpp" -o CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.s

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.o: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/flags.make
src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.o: ../src/src_testing/pruebas_serializador/pruebas_serializador.cpp
src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.o: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.o"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.o -MF CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.o.d -o CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_serializador/pruebas_serializador.cpp"

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.i"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_serializador/pruebas_serializador.cpp" > CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.i

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.s"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_serializador/pruebas_serializador.cpp" -o CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.s

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.o: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/flags.make
src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.o: ../src/src_common/common_serializador.cpp
src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.o: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.o"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.o -MF CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.o.d -o CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_serializador.cpp"

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.i"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_serializador.cpp" > CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.i

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.s"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_serializador.cpp" -o CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.s

# Object files for target serializador_tests
serializador_tests_OBJECTS = \
"CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.o" \
"CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.o"

# External object files for target serializador_tests
serializador_tests_EXTERNAL_OBJECTS =

src/src_testing/pruebas_serializador/serializador_tests: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/serializador_tests_autogen/mocs_compilation.cpp.o
src/src_testing/pruebas_serializador/serializador_tests: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/pruebas_serializador.cpp.o
src/src_testing/pruebas_serializador/serializador_tests: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/__/__/src_common/common_serializador.cpp.o
src/src_testing/pruebas_serializador/serializador_tests: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/build.make
src/src_testing/pruebas_serializador/serializador_tests: lib/libgtest_maind.a
src/src_testing/pruebas_serializador/serializador_tests: lib/libgtestd.a
src/src_testing/pruebas_serializador/serializador_tests: src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable serializador_tests"
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serializador_tests.dir/link.txt --verbose=$(VERBOSE)
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && /snap/clion/193/bin/cmake/linux/bin/cmake -D TEST_TARGET=serializador_tests -D "TEST_EXECUTABLE=/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador/serializador_tests" -D TEST_EXECUTOR= -D "TEST_WORKING_DIR=/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=serializador_tests_TESTS -D "CTEST_FILE=/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador/serializador_tests[1]_tests.cmake" -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /snap/clion/193/bin/cmake/linux/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/build: src/src_testing/pruebas_serializador/serializador_tests
.PHONY : src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/build

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/clean:
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" && $(CMAKE_COMMAND) -P CMakeFiles/serializador_tests.dir/cmake_clean.cmake
.PHONY : src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/clean

src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/depend:
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_testing/pruebas_serializador" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/TP FINAL/Dune-Taller-de-Programacion-FIUBA/src_files/cmake-build-debug/src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/src_testing/pruebas_serializador/CMakeFiles/serializador_tests.dir/depend

