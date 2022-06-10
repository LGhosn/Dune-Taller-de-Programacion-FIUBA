cmake_minimum_required(VERSION 3.1)
project(server_main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic -std=c++17 -pthread")

add_definitions(-DRESOURCE_PATH="${PROJECT_SOURCE_DIR}/../../assets")

add_executable(
  server_main
  server_comandos/server_comando.cpp
  server_game/game.cpp
  server_gameloop/server_gameloop.cpp
  server_solicitudes/server_solicitud.cpp
  server_thread_reciever/server_hilo_reciever.cpp
  server_thread_sender/server_hilo_sender.cpp
  server_aceptador.cpp
  server_handler.cpp
  server_jugador.cpp
  server_lobby.cpp
  server_main.cpp
  server_partida_empezada.cpp
  server_partida.cpp
  server_protocolo.cpp
  server_server.cpp

  ../src_common/common_coords.cpp
  ../src_common/common_resolver.cpp
  ../src_common/common_socket.cpp
  ../src_common/common_socket_error.cpp
  ../src_common/common_infoDTO/MovimientoDTO.cpp
  ../src_common/common_infoDTO/infoDTO.h
  ../src_common/common_DTOs.h
  ../src_common/common_colas/cola_bloqueante.cpp
  ../src_common/common_colas/cola_no_bloqueante.cpp
)
