cmake_minimum_required(VERSION 3.0)
project(tests_mapa)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(mapa_tests
    pruebas_mapa.cpp
    ../../src_server/server_game/server_mapa/server_mapa.cpp
    ../../src_server/server_game/server_mapa/server_camino.cpp
    ../../src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp
    ../../src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp
    ../../src_common/common_coords.cpp
)

target_link_libraries(
  mapa_tests
  PRIVATE
  yaml-cpp
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(mapa_tests)
