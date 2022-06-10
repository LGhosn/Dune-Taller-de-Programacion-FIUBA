cmake_minimum_required(VERSION 3.1)
project(sdl_cliente_main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic -std=c++17 -ggdb -O0 -pthread")


set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support
add_subdirectory(../src_libs/SDL2pp ./SDL2pp/build)
include_directories(${SDL2PP_INCLUDE_DIRS})

add_definitions(-DRESOURCE_PATH="${PROJECT_SOURCE_DIR}/../../assets")

add_executable(
    sdl_cliente_main
    sdl_client_main.cpp
    pix_a_coords.cpp
    client_comandos/cmd_mover_mapa.cpp
    client_solicitudes/sol_mover_unidad.cpp
    client_comandos/client_comando.cpp
        client_thread_renderer/client_hilo_renderer.cpp
        client_world_view/sdl_tile_factory.cpp
        client_world_view/sdl_tile.cpp
        client_world_view/sdl_mapa.cpp
        client_world_view/sdl_mapa.h
        client_world_view/world_view.cpp
        ../src_common/common_colas/cola_bloqueante.cpp
        ../src_common/common_colas/cola_no_bloqueante.cpp
        client_thread_sdl/client_hilo_sdl.h
        client_thread_sdl/client_hilo_sdl.cpp
        client_thread_sdl/client_sdl_evento.h
        client_thread_sdl/client_sdl_evento.cpp
    ../src_common/common_coords.cpp
    client_protocolo.cpp
    ../src_common/common_serializador.cpp
    ../src_common/common_socket.cpp
    ../src_common/common_resolver.cpp
    ../src_common/common_socket_error.cpp
)

target_link_libraries(
  sdl_cliente_main
  ${SDL2PP_LIBRARIES}
)
