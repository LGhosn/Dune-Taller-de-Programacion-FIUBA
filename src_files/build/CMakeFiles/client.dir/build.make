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
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

ui_MenuUi.h: ../src/src_menu/MenuUi.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_MenuUi.h"
	/usr/lib/qt5/bin/uic -o "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/ui_MenuUi.h" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_menu/MenuUi.ui"

ui_FormCreacion.h: ../src/src_form_creacion/FormCreacion.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Generating ui_FormCreacion.h"
	/usr/lib/qt5/bin/uic -o "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/ui_FormCreacion.h" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_form_creacion/FormCreacion.ui"

ui_FormUnion.h: ../src/src_form_union/FormUnion.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Generating ui_FormUnion.h"
	/usr/lib/qt5/bin/uic -o "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/ui_FormUnion.h" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_form_union/FormUnion.ui"

client_autogen/GBFAFXFCVO/qrc_resources.cpp: ../assets/resources.qrc
client_autogen/GBFAFXFCVO/qrc_resources.cpp: CMakeFiles/client_autogen.dir/AutoRcc_resources_GBFAFXFCVO_Info.json
client_autogen/GBFAFXFCVO/qrc_resources.cpp: ../assets/OrdosIcon.png
client_autogen/GBFAFXFCVO/qrc_resources.cpp: ../assets/HarkonnenIcon.png
client_autogen/GBFAFXFCVO/qrc_resources.cpp: ../assets/AtreidesIcon.png
client_autogen/GBFAFXFCVO/qrc_resources.cpp: ../assets/logo.jpg
client_autogen/GBFAFXFCVO/qrc_resources.cpp: ../assets/mute.png
client_autogen/GBFAFXFCVO/qrc_resources.cpp: ../assets/dune_space_wars.jpg
client_autogen/GBFAFXFCVO/qrc_resources.cpp: /usr/lib/qt5/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Automatic RCC for assets/resources.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/sruizs/Escritorio/FIUBA/TALLER\ DE\ PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles/client_autogen.dir/AutoRcc_resources_GBFAFXFCVO_Info.json 

CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.o: client_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/client_autogen/mocs_compilation.cpp"

CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/client_autogen/mocs_compilation.cpp" > CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.i

CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/client_autogen/mocs_compilation.cpp" -o CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.s

CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.o: ../src/src_menu/MenuDune.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_menu/MenuDune.cpp"

CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_menu/MenuDune.cpp" > CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.i

CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_menu/MenuDune.cpp" -o CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.s

CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.o: ../src/src_form_creacion/FormCreacion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_form_creacion/FormCreacion.cpp"

CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_form_creacion/FormCreacion.cpp" > CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.i

CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_form_creacion/FormCreacion.cpp" -o CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.s

CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.o: ../src/src_form_union/FormUnion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_form_union/FormUnion.cpp"

CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_form_union/FormUnion.cpp" > CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.i

CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_form_union/FormUnion.cpp" -o CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.s

CMakeFiles/client.dir/src/src_cliente/client_client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/src_cliente/client_client.cpp.o: ../src/src_cliente/client_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/client.dir/src/src_cliente/client_client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/src_cliente/client_client.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_cliente/client_client.cpp"

CMakeFiles/client.dir/src/src_cliente/client_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/src_cliente/client_client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_cliente/client_client.cpp" > CMakeFiles/client.dir/src/src_cliente/client_client.cpp.i

CMakeFiles/client.dir/src/src_cliente/client_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/src_cliente/client_client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_cliente/client_client.cpp" -o CMakeFiles/client.dir/src/src_cliente/client_client.cpp.s

CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.o: ../src/src_cliente/client_protocolo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_cliente/client_protocolo.cpp"

CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_cliente/client_protocolo.cpp" > CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.i

CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_cliente/client_protocolo.cpp" -o CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.s

CMakeFiles/client.dir/src/src_common/common_resolver.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/src_common/common_resolver.cpp.o: ../src/src_common/common_resolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/client.dir/src/src_common/common_resolver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/src_common/common_resolver.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_resolver.cpp"

CMakeFiles/client.dir/src/src_common/common_resolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/src_common/common_resolver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_resolver.cpp" > CMakeFiles/client.dir/src/src_common/common_resolver.cpp.i

CMakeFiles/client.dir/src/src_common/common_resolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/src_common/common_resolver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_resolver.cpp" -o CMakeFiles/client.dir/src/src_common/common_resolver.cpp.s

CMakeFiles/client.dir/src/src_common/common_socket.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/src_common/common_socket.cpp.o: ../src/src_common/common_socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/client.dir/src/src_common/common_socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/src_common/common_socket.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket.cpp"

CMakeFiles/client.dir/src/src_common/common_socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/src_common/common_socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket.cpp" > CMakeFiles/client.dir/src/src_common/common_socket.cpp.i

CMakeFiles/client.dir/src/src_common/common_socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/src_common/common_socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket.cpp" -o CMakeFiles/client.dir/src/src_common/common_socket.cpp.s

CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.o: ../src/src_common/common_socket_error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket_error.cpp"

CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket_error.cpp" > CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.i

CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket_error.cpp" -o CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.s

CMakeFiles/client.dir/src/src_common/common_serializador.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/src_common/common_serializador.cpp.o: ../src/src_common/common_serializador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/client.dir/src/src_common/common_serializador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/src_common/common_serializador.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_serializador.cpp"

CMakeFiles/client.dir/src/src_common/common_serializador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/src_common/common_serializador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_serializador.cpp" > CMakeFiles/client.dir/src/src_common/common_serializador.cpp.i

CMakeFiles/client.dir/src/src_common/common_serializador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/src_common/common_serializador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_serializador.cpp" -o CMakeFiles/client.dir/src/src_common/common_serializador.cpp.s

CMakeFiles/client.dir/src/main_client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/main_client.cpp.o: ../src/main_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/client.dir/src/main_client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/main_client.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/main_client.cpp"

CMakeFiles/client.dir/src/main_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/main_client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/main_client.cpp" > CMakeFiles/client.dir/src/main_client.cpp.i

CMakeFiles/client.dir/src/main_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/main_client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/src/main_client.cpp" -o CMakeFiles/client.dir/src/main_client.cpp.s

CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.o: client_autogen/GBFAFXFCVO/qrc_resources.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.o -c "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/client_autogen/GBFAFXFCVO/qrc_resources.cpp"

CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/client_autogen/GBFAFXFCVO/qrc_resources.cpp" > CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.i

CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/client_autogen/GBFAFXFCVO/qrc_resources.cpp" -o CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.o" \
"CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.o" \
"CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.o" \
"CMakeFiles/client.dir/src/src_cliente/client_client.cpp.o" \
"CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.o" \
"CMakeFiles/client.dir/src/src_common/common_resolver.cpp.o" \
"CMakeFiles/client.dir/src/src_common/common_socket.cpp.o" \
"CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.o" \
"CMakeFiles/client.dir/src/src_common/common_serializador.cpp.o" \
"CMakeFiles/client.dir/src/main_client.cpp.o" \
"CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/client_autogen/mocs_compilation.cpp.o
client: CMakeFiles/client.dir/src/src_menu/MenuDune.cpp.o
client: CMakeFiles/client.dir/src/src_form_creacion/FormCreacion.cpp.o
client: CMakeFiles/client.dir/src/src_form_union/FormUnion.cpp.o
client: CMakeFiles/client.dir/src/src_cliente/client_client.cpp.o
client: CMakeFiles/client.dir/src/src_cliente/client_protocolo.cpp.o
client: CMakeFiles/client.dir/src/src_common/common_resolver.cpp.o
client: CMakeFiles/client.dir/src/src_common/common_socket.cpp.o
client: CMakeFiles/client.dir/src/src_common/common_socket_error.cpp.o
client: CMakeFiles/client.dir/src/src_common/common_serializador.cpp.o
client: CMakeFiles/client.dir/src/main_client.cpp.o
client: CMakeFiles/client.dir/client_autogen/GBFAFXFCVO/qrc_resources.cpp.o
client: CMakeFiles/client.dir/build.make
client: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
client: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
client: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend: ui_MenuUi.h
CMakeFiles/client.dir/depend: ui_FormCreacion.h
CMakeFiles/client.dir/depend: ui_FormUnion.h
CMakeFiles/client.dir/depend: client_autogen/GBFAFXFCVO/qrc_resources.cpp
	cd "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build" "/home/sruizs/Escritorio/FIUBA/TALLER DE PROGRAMACION/DUNE/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles/client.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend
