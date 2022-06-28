cmake_minimum_required(VERSION 3.00)
project(DuneEditorDeMapas)
find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic -std=c++17")

add_executable(DuneEditorDeMapas
        DuneEditorDeMapas.cpp
        ../main_editor.cpp
        ${UIS_HEADERS})

target_link_libraries(DuneEditorDeMapas Qt5::Widgets Qt5::Core)
