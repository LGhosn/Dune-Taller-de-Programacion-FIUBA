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
CMAKE_SOURCE_DIR = /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.o: server_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/server_autogen/mocs_compilation.cpp

CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/server_autogen/mocs_compilation.cpp > CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.i

CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/server_autogen/mocs_compilation.cpp -o CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.s

CMakeFiles/server.dir/src/src_server/server_server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_server/server_server.cpp.o: ../src/src_server/server_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server.dir/src/src_server/server_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_server/server_server.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_server.cpp

CMakeFiles/server.dir/src/src_server/server_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_server/server_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_server.cpp > CMakeFiles/server.dir/src/src_server/server_server.cpp.i

CMakeFiles/server.dir/src/src_server/server_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_server/server_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_server.cpp -o CMakeFiles/server.dir/src/src_server/server_server.cpp.s

CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.o: ../src/src_server/server_protocolo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_protocolo.cpp

CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_protocolo.cpp > CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.i

CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_protocolo.cpp -o CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.s

CMakeFiles/server.dir/src/src_server/server_partida.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_server/server_partida.cpp.o: ../src/src_server/server_partida.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server.dir/src/src_server/server_partida.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_server/server_partida.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_partida.cpp

CMakeFiles/server.dir/src/src_server/server_partida.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_server/server_partida.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_partida.cpp > CMakeFiles/server.dir/src/src_server/server_partida.cpp.i

CMakeFiles/server.dir/src/src_server/server_partida.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_server/server_partida.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_partida.cpp -o CMakeFiles/server.dir/src/src_server/server_partida.cpp.s

CMakeFiles/server.dir/src/src_server/server_lobby.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_server/server_lobby.cpp.o: ../src/src_server/server_lobby.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/server.dir/src/src_server/server_lobby.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_server/server_lobby.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_lobby.cpp

CMakeFiles/server.dir/src/src_server/server_lobby.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_server/server_lobby.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_lobby.cpp > CMakeFiles/server.dir/src/src_server/server_lobby.cpp.i

CMakeFiles/server.dir/src/src_server/server_lobby.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_server/server_lobby.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_lobby.cpp -o CMakeFiles/server.dir/src/src_server/server_lobby.cpp.s

CMakeFiles/server.dir/src/src_server/server_handler.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_server/server_handler.cpp.o: ../src/src_server/server_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/server.dir/src/src_server/server_handler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_server/server_handler.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_handler.cpp

CMakeFiles/server.dir/src/src_server/server_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_server/server_handler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_handler.cpp > CMakeFiles/server.dir/src/src_server/server_handler.cpp.i

CMakeFiles/server.dir/src/src_server/server_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_server/server_handler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_handler.cpp -o CMakeFiles/server.dir/src/src_server/server_handler.cpp.s

CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.o: ../src/src_server/server_aceptador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_aceptador.cpp

CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_aceptador.cpp > CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.i

CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_server/server_aceptador.cpp -o CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.s

CMakeFiles/server.dir/src/src_common/common_resolver.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_common/common_resolver.cpp.o: ../src/src_common/common_resolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/server.dir/src/src_common/common_resolver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_common/common_resolver.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_resolver.cpp

CMakeFiles/server.dir/src/src_common/common_resolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_common/common_resolver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_resolver.cpp > CMakeFiles/server.dir/src/src_common/common_resolver.cpp.i

CMakeFiles/server.dir/src/src_common/common_resolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_common/common_resolver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_resolver.cpp -o CMakeFiles/server.dir/src/src_common/common_resolver.cpp.s

CMakeFiles/server.dir/src/src_common/common_socket.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_common/common_socket.cpp.o: ../src/src_common/common_socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/server.dir/src/src_common/common_socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_common/common_socket.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket.cpp

CMakeFiles/server.dir/src/src_common/common_socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_common/common_socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket.cpp > CMakeFiles/server.dir/src/src_common/common_socket.cpp.i

CMakeFiles/server.dir/src/src_common/common_socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_common/common_socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket.cpp -o CMakeFiles/server.dir/src/src_common/common_socket.cpp.s

CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.o: ../src/src_common/common_socket_error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket_error.cpp

CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket_error.cpp > CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.i

CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_socket_error.cpp -o CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.s

CMakeFiles/server.dir/src/src_common/common_serializador.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/src_common/common_serializador.cpp.o: ../src/src_common/common_serializador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/server.dir/src/src_common/common_serializador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/src_common/common_serializador.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_serializador.cpp

CMakeFiles/server.dir/src/src_common/common_serializador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/src_common/common_serializador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_serializador.cpp > CMakeFiles/server.dir/src/src_common/common_serializador.cpp.i

CMakeFiles/server.dir/src/src_common/common_serializador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/src_common/common_serializador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/src_common/common_serializador.cpp -o CMakeFiles/server.dir/src/src_common/common_serializador.cpp.s

CMakeFiles/server.dir/src/main_server.cpp.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/main_server.cpp.o: ../src/main_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/server.dir/src/main_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/src/main_server.cpp.o -c /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/main_server.cpp

CMakeFiles/server.dir/src/main_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/src/main_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/main_server.cpp > CMakeFiles/server.dir/src/main_server.cpp.i

CMakeFiles/server.dir/src/main_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/src/main_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/src/main_server.cpp -o CMakeFiles/server.dir/src/main_server.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/server.dir/src/src_server/server_server.cpp.o" \
"CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.o" \
"CMakeFiles/server.dir/src/src_server/server_partida.cpp.o" \
"CMakeFiles/server.dir/src/src_server/server_lobby.cpp.o" \
"CMakeFiles/server.dir/src/src_server/server_handler.cpp.o" \
"CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.o" \
"CMakeFiles/server.dir/src/src_common/common_resolver.cpp.o" \
"CMakeFiles/server.dir/src/src_common/common_socket.cpp.o" \
"CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.o" \
"CMakeFiles/server.dir/src/src_common/common_serializador.cpp.o" \
"CMakeFiles/server.dir/src/main_server.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/server_autogen/mocs_compilation.cpp.o
server: CMakeFiles/server.dir/src/src_server/server_server.cpp.o
server: CMakeFiles/server.dir/src/src_server/server_protocolo.cpp.o
server: CMakeFiles/server.dir/src/src_server/server_partida.cpp.o
server: CMakeFiles/server.dir/src/src_server/server_lobby.cpp.o
server: CMakeFiles/server.dir/src/src_server/server_handler.cpp.o
server: CMakeFiles/server.dir/src/src_server/server_aceptador.cpp.o
server: CMakeFiles/server.dir/src/src_common/common_resolver.cpp.o
server: CMakeFiles/server.dir/src/src_common/common_socket.cpp.o
server: CMakeFiles/server.dir/src/src_common/common_socket_error.cpp.o
server: CMakeFiles/server.dir/src/src_common/common_serializador.cpp.o
server: CMakeFiles/server.dir/src/main_server.cpp.o
server: CMakeFiles/server.dir/build.make
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build /home/lautaro/Dune-Taller-de-Programacion-FIUBA/src_files/build/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

