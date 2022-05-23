cmake_minimum_required(VERSION 3.14)

project(tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic -std=c++17 -ggdb")

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(camino_tests camino_tests.cpp server_camino.cpp common_coords.cpp server_camino_no_encontrado_exception.cpp server_fuera_de_rango_exception.cpp)

target_link_libraries(
  camino_tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(camino_tests)