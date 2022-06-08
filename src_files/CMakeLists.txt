cmake_minimum_required(VERSION 3.00)
project(Dune2000)
find_package(Qt5Widgets)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")

SET(SDL2PP_WITH_IMAGE YES)
SET(SDL2PP_WITH_TTF YES)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/src_libs/yaml_cpp)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/src_libs/SDL2pp)

# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})
message("Headers generados: ${UIS_HEADERS}")

message("Agregando '${PROJECT_SOURCE_DIR}/src/src_libs' como directorio de includes")
include_directories(${PROJECT_SOURCE_DIR}/src/src_libs)
include_directories(${SDL2PP_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS}
        ${SDL2TTF_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/src_libs
        ${PROJECT_SOURCE_DIR}/src/src_menu
        ${PROJECT_SOURCE_DIR}/src/src_form_creacion
        ${PROJECT_SOURCE_DIR}/src/src_form_union
        ${PROJECT_SOURCE_DIR}/src/src_cliente
        ${PROJECT_SOURCE_DIR}/src/src_server
        ${PROJECT_SOURCE_DIR}/src/src_common
        )

        # Agrego la libreria SDL2pp habilitando manejo de imagenes y de letras

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

qt5_wrap_ui(UIS_HEADERS
        src/src_menu/MenuUi.ui
        src/src_form_creacion/FormCreacion.ui
        src/src_form_union/FormUnion.ui
        )
# Habilito el automoc para poder hacer autoconnect de señales
set(CMAKE_AUTOMOC on)
# Habilito autorcc para manejar automaticamente los QResources
set(CMAKE_AUTORCC ON)

add_executable(client
        src/src_menu/MenuDune.cpp
        src/src_form_creacion/FormCreacion.cpp
        src/src_form_union/FormUnion.cpp
        src/src_cliente/client_client.cpp
        src/src_cliente/client_protocolo.cpp
        src/src_common/common_resolver.cpp
        src/src_common/common_socket.cpp
        src/src_common/common_socket_error.cpp
        src/src_common/common_serializador.cpp
        src/main_client.cpp
        assets/resources.qrc
        ${UIS_HEADERS})

add_executable(server
        src/src_server/server_server.cpp
        src/src_server/server_protocolo.cpp
        src/src_server/server_partida.cpp
        src/src_server/server_lobby.cpp
        src/src_server/server_handler.cpp
        src/src_server/server_aceptador.cpp
        # src/src_server/server_partida_empezada.cpp
        src/src_common/common_resolver.cpp
        src/src_common/common_socket.cpp
        src/src_common/common_socket_error.cpp
        src/src_common/common_serializador.cpp
        src/main_server.cpp
        )

add_executable(camino_tests
        src/src_testing/pruebas_camino/pruebas_camino.cpp
        src/src_server/server_camino.cpp
        src/src_server/server_camino_no_encontrado_exception.cpp
        src/src_server/server_fuera_de_rango_exception.cpp
        src/src_common/common_coords.cpp
        )

add_executable(
        pruebas_mapa
        src/src_testing/pruebas_mapa/pruebas.cpp
        src/src_server/server_mapa.h
        src/src_server/server_mapa.cpp
        src/src_server/server_camino.cpp
        src/src_server/server_camino_no_encontrado_exception.cpp
        src/src_server/server_fuera_de_rango_exception.cpp
        src/src_common/common_coords.h
        src/src_common/common_coords.cpp
)

add_executable(
        serializador_tests
        src/src_testing/pruebas_serializador/pruebas_serializador.cpp
        src/src_common/common_serializador.h
        src/src_common/common_serializador.cpp
)


target_link_libraries(client Qt5::Widgets Qt5::Core)
target_link_libraries(server pthread)
target_link_libraries(camino_tests gtest_main)
target_link_libraries(pruebas_mapa PRIVATE yaml-cpp gtest_main)
target_link_libraries(serializador_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(camino_tests pruebas_mapa serializador_tests)
