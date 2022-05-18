cmake_minimum_required(VERSION 3.22)
project(Dune_Taller_de_Programacion_FIUBA)
find_package(Qt5Widgets)
set(CMAKE_CXX_STANDARD 14)

add_executable(programa
        ejemplo.cpp)

target_link_libraries(programa Qt5::Widgets)