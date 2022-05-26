cmake_minimum_required(VERSION 3.14)

project(mapaSDL)

set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic -std=c++17 -ggdb")
add_subdirectory(../third_party/SDL2pp ./SDL2pp/build)

add_definitions(-DRESOURCE_PATH="${PROJECT_SOURCE_DIR}/../resources")

include_directories(${SDL2PP_INCLUDE_DIRS})

add_executable(mapa sdl_main.cpp sdl_mapa.cpp sdl_game_loop.cpp sdl_edificio.cpp)
target_link_libraries(mapa ${SDL2PP_LIBRARIES})
