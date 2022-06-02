cmake_minimum_required(VERSION 3.1)
project(sdl_cliente_main)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic -std=c++17 -pthread")


set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support
add_subdirectory(../src_libs/SDL2pp ./SDL2pp/build)
include_directories(${SDL2PP_INCLUDE_DIRS})

add_definitions(-DRESOURCE_PATH="${PROJECT_SOURCE_DIR}/../../assets")

add_executable(
    sdl_cliente_main
    sdl_client_main.cpp
    comandos/cmd_mover_mapa.cpp
    comandos/comando.cpp
    thread_renderer/hilo_renderer.cpp
    world_view/sdl_mapa.cpp
    world_view/world_view.cpp
    cola_bloqueante.cpp
    cola_no_bloqueante.cpp
)

target_link_libraries(
  sdl_cliente_main
  PRIVATE
  ${SDL2PP_LIBRARIES}
)
