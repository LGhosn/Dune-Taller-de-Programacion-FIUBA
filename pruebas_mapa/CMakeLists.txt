cmake_minimum_required(VERSION 3.1)
project(MapaTests)

include(GoogleTest)

enable_testing()

find_package(GTest REQUIRED)

add_subdirectory(third_party/yaml_cpp)

add_executable(
    pruebas_mapa
    pruebas.cpp
    ../server_mapa.h
    ../server_mapa.cpp
    ../common_coords.h
    ../common_coords.cpp
)

target_link_libraries(
    pruebas_mapa
    PRIVATE
    yaml-cpp
    GTest::GTest
    GTest::Main
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
