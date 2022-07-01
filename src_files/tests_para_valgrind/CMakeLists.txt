cmake_minimum_required(VERSION 3.00)
project(TestsParaValgrind)

find_package(Qt5 CONFIG REQUIRED COMPONENTS Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -ggdb -O0 -pedantic -std=c++17")

set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support
add_subdirectory(../src/src_libs/SDL2pp ./SDL2pp/build)

add_definitions(-DRESOURCE_PATH="${PROJECT_SOURCE_DIR}/../assets")

include_directories(${SDL2PP_INCLUDE_DIRS})

set(CMAKE_AUTOMOC on)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${PROJECT_BINARY_DIR})

add_executable(sdl_test
    sdl_main.ui
    sdl_main.cpp
    resources.qrc)
add_executable(qt_test ${UIS_HEADERS})

target_link_libraries(sdl_test ${SDL2PP_LIBRARIES})
target_link_libraries(qt_test Qt5::Widgets Qt5::Core)
