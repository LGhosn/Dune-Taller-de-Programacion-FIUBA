cmake_minimum_required(VERSION 3.00)
project(MenuDune)
find_package(Qt5Widgets)

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/src_menu
        ${PROJECT_SOURCE_DIR}/src/src_form_creacion
        ${PROJECT_SOURCE_DIR}/src/src_form_union
        ${PROJECT_SOURCE_DIR}/src/src_cliente
        ${PROJECT_SOURCE_DIR}/src/src_server
        ${PROJECT_SOURCE_DIR}/src/src_common
        )

qt5_wrap_ui(UIS_HEADERS
        src/src_menu/MenuUi.ui
        src/src_form_creacion/FormCreacion.ui
        src/src_form_union/FormUnion.ui
        )
# Habilito el automoc para poder hacer autoconnect de señales
set(CMAKE_AUTOMOC on)
# Habilito autorcc para manejar automaticamente los QResources
set(CMAKE_AUTORCC ON)
# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})
message("Headers generados: ${UIS_HEADERS}")

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
        src/src_common/common_resolver.cpp
        src/src_common/common_socket.cpp
        src/src_common/common_socket_error.cpp
        src/src_common/common_serializador.cpp
        src/main_server.cpp
        )

target_link_libraries(client Qt5::Widgets Qt5::Core)
target_link_libraries(server pthread)