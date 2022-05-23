cmake_minimum_required(VERSION 3.1)
project(MapaTests)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(third_party/yaml_cpp)

add_executable(
    pruebas_mapa
    pruebas.cpp
    ../server_mapa.h
    ../server_mapa.cpp
    ../common_coords.h
    ../common_coords.cpp
    ../server_camino.cpp
    ../server_camino_no_encontrado_exception.cpp 
    ../server_fuera_de_rango_exception.cpp
)

target_link_libraries(
    pruebas_mapa
    PRIVATE
    yaml-cpp
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(pruebas_mapa)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
