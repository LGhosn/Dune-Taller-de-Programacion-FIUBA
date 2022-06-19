cmake_minimum_required(VERSION 3.00)
project(DuneMapEditor)
find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic -std=c++17")

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

add_executable(editor
        DuneMapEditor.cpp
        main_editor.cpp
        ${UIS_HEADERS})

target_link_libraries(editor Qt5::Widgets Qt5::Core)