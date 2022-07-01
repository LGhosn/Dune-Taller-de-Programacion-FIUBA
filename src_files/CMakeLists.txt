cmake_minimum_required(VERSION 3.00)
project(Dune2000)
find_package(Qt5Widgets)
find_package(yaml-cpp REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -ggdb -O0 -pedantic -std=c++17")

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")



set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support
add_subdirectory(src/src_libs/SDL2pp)

add_definitions(-DRESOURCE_PATH="${PROJECT_SOURCE_DIR}/assets")

include_directories(${SDL2PP_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/src_menu
        ${PROJECT_SOURCE_DIR}/src/src_form_creacion
        ${PROJECT_SOURCE_DIR}/src/src_form_union
        ${PROJECT_SOURCE_DIR}/src/src_cliente
        ${PROJECT_SOURCE_DIR}/src/src_server
        ${PROJECT_SOURCE_DIR}/src/src_common
        # ${PROJECT_SOURCE_DIR}/src/src_editor
        )

qt5_wrap_ui(UIS_HEADERS
        src/src_menu/MenuUi.ui
        src/src_form_creacion/FormCreacion.ui
        src/src_form_union/FormUnion.ui
        src/src_editor/DuneEditorDeMapasUi.ui
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
        src/main_client.cpp
        src/src_cliente/pix_a_coords.cpp
        src/src_cliente/client_client.cpp
        src/src_cliente/client_protocolo.cpp
        src/src_cliente/client_serializador.cpp
        src/src_cliente/client_thread_reciever/client_hilo_reciever.cpp
        src/src_cliente/client_thread_sender/client_hilo_sender.cpp
        src/src_cliente/client_renderer/client_renderer.cpp
        src/src_cliente/client_thread_sender/client_hilo_sender.cpp
        src/src_cliente/client_solicitudes/sol_crear_partida.cpp
        src/src_cliente/client_solicitudes/sol_unirse_a_partida.cpp
        src/src_cliente/client_DTO/dto_cmd_crear_edificio.h
        src/src_cliente/client_comandos/cmd_mover_mapa.cpp
        src/src_cliente/client_comandos/cmd_zoom.cpp
        src/src_cliente/client_comandos/cmd_salir.cpp
        src/src_cliente/client_comandos/cmd_click_en_mapa.cpp
        src/src_cliente/client_comandos/cmd_crear_edificio.cpp
        src/src_cliente/client_comandos/cmd_actualizar_tienda_edificios.cpp
        src/src_cliente/client_comandos/cmd_modificar_especia.cpp
        src/src_cliente/client_comandos/cmd_modificar_energia.cpp
        src/src_cliente/client_comandos/cmd_empezar_construccion_edificio.cpp
        src/src_cliente/client_comandos/cmd_empezar_entrenamiento.cpp
        src/src_cliente/client_comandos/cmd_construccion_invalida.cpp
        src/src_cliente/client_comandos/cmd_mover_unidad.cpp
        src/src_cliente/client_solicitudes/sol_mover_unidad.cpp
        src/src_cliente/client_solicitudes/sol_comprar_edificio.cpp
        src/src_cliente/client_solicitudes/sol_comprar_unidad.cpp
        src/src_cliente/client_comandos/client_comando.cpp
        src/src_cliente/client_world_view/sdl_mapa/sdl_tile_factory.cpp
        src/src_cliente/client_world_view/sdl_mapa/sdl_tile.cpp
        src/src_cliente/client_world_view/sdl_mapa/sdl_mapa.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_edificio.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_edificio_factory.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_centro.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_cuartel.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_fabrica_ligera.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_fabrica_pesada.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_palacio.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_refineria.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_silo.cpp
        src/src_cliente/client_world_view/sdl_edificio/sdl_trampa.cpp
        src/src_cliente/client_world_view/sdl_side_menu/sdl_side_menu.cpp
        src/src_cliente/client_world_view/sdl_side_menu/sdl_tienda/sdl_tienda.cpp
        src/src_cliente/client_world_view/sdl_side_menu/sdl_tienda/sdl_boton_edificio.cpp
        src/src_cliente/client_world_view/sdl_side_menu/sdl_tienda/sdl_boton_unidad.cpp
        src/src_cliente/client_world_view/sdl_side_menu/sdl_tienda/sdl_boton_paginas.cpp
        src/src_cliente/client_world_view/sdl_side_menu/sdl_especia.cpp
        src/src_cliente/client_world_view/sdl_side_menu/sdl_energia.cpp
        src/src_cliente/client_world_view/sdl_sonidos/sdl_sonidos.cpp
        src/src_cliente/client_world_view/sdl_sonidos/sdl_mixer.cpp
        src/src_cliente/client_world_view/world_view.cpp
        src/src_cliente/client_world_view/sdl_color/sdl_color.cpp
        src/src_cliente/client_world_view/sdl_color/sdl_colores.cpp
        src/src_cliente/client_world_view/sdl_texturas.cpp
        src/src_common/common_DTO/Status.cpp
        src/src_common/common_colas/cola_bloqueante.cpp
        src/src_common/common_colas/cola_no_bloqueante.cpp
        src/src_cliente/client_thread_sdl/client_hilo_sdl.cpp
        src/src_cliente/client_thread_sdl/client_sdl_evento.cpp
        src/src_common/common_coords.cpp
        src/src_menu/MenuDune.cpp
        src/src_form_creacion/FormCreacion.cpp
        src/src_form_union/FormUnion.cpp
        src/src_common/common_resolver.cpp
        src/src_common/common_socket.cpp
        src/src_common/common_socket_error.cpp
        src/src_common/common_serializador.cpp
        assets/resources.qrc
        src/src_cliente/client_solicitudes/client_sol_crear_edificio.cpp
        ${UIS_HEADERS})

add_executable(server
        src/src_server/server_server.cpp
        src/src_server/server_comandos/cmd_crear_edificio.cpp
        src/src_server/server_comandos/cmd_empezar_partida.cpp
        src/src_server/server_comandos/cmd_modificar_especia.cpp
        src/src_server/server_comandos/cmd_comprar_unidad.cpp
        src/src_server/server_comandos/cmd_mover_unidad.cpp
        src/src_server/server_comandos/cmd_empezar_entrenamiento.cpp
        src/src_server/server_comandos/cmd_modificar_energia.cpp
        src/src_server/server_comandos/cmd_construccion_invalida.cpp
        src/src_server/server_solicitudes/solicitud_juego/sol_crear_edificio.cpp
        src/src_server/server_solicitudes/solicitud_juego/sol_comprar_unidad.cpp
        src/src_server/server_solicitudes/solicitud_juego/sol_mover_unidad.cpp
        src/src_server/server_comandos/cmd_actualizar_tienda_edificios.cpp
        src/src_server/server_comandos/cmd_actualizar_tienda_unidades.cpp
        src/src_server/server_comandos/cmd_empezar_construccion_edificio.cpp
        src/src_server/server_solicitudes/solicitud_juego/sol_crear_edificio.cpp
        src/src_server/server_solicitudes/solicitud_juego/sol_comprar_edificio.cpp
        src/src_server/server_protocolo/server_protocolo.cpp
        src/src_server/server_protocolo/server_serializador.cpp
        src/src_server/server_DTO/partida_DTO.h
        src/src_server/server_DTO/MovimientoDTO.cpp
        src/src_server/server_lobby.cpp
        src/src_server/server_thread_sender/server_hilo_sender.cpp
        src/src_server/server_thread_reciever/server_hilo_reciever.cpp
        src/src_server/server_thread_gameloop/server_hilo_gameloop.cpp
        src/src_server/server_game/game.cpp
        src/src_server/server_game/server_mapa/entidades/edificios/edificios_mapa.cpp
        src/src_server/server_game/server_mapa/entidades/terrenos/terrenos_mapa.cpp
        src/src_server/server_game/server_mapa/entidades/unidades/unidades_mapa.cpp
        src/src_server/server_game/server_mapa/server_mapa.cpp
        src/src_server/server_game/server_mapa/server_camino.cpp
        src/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp
        src/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp
        src/src_server/server_game/server_jugador/jugador.cpp
        src/src_server/server_game/server_jugador/especia_acumulada.cpp
        src/src_server/server_game/server_jugador/energia_acumulada.cpp
        src/src_server/server_game/server_unidades/unidades.cpp
        src/src_server/server_game/server_unidades/cosechadora.cpp
        src/src_server/server_game/server_unidades/desviador.cpp
        src/src_server/server_game/server_unidades/devastador.cpp
        src/src_server/server_game/server_unidades/fremen.cpp
        src/src_server/server_game/server_unidades/infanteriaLigera.cpp
        src/src_server/server_game/server_unidades/infanteriaPesada.cpp
        src/src_server/server_game/server_unidades/raider.cpp
        src/src_server/server_game/server_unidades/sardaukar.cpp
        src/src_server/server_game/server_unidades/tanque.cpp
        src/src_server/server_game/server_unidades/tanqueSonico.cpp
        src/src_server/server_game/server_unidades/trike.cpp
        src/src_server/server_aceptador.cpp
        src/src_server/server_handler_cliente/server_handler_cliente.cpp
        src/src_server/server_partida/server_partida.cpp
        src/src_common/common_DTO/Status.cpp
        src/src_common/common_resolver.cpp
        src/src_common/common_socket.cpp
        src/src_common/common_socket_error.cpp
        src/src_common/common_serializador.cpp
        src/src_common/common_coords.cpp
        src/main_server.cpp
        )


add_executable(DuneEditorDeMapas
        src/src_editor/DuneEditorDeMapas.cpp
        src/src_editor/SelectorDeModoDeEdicion.cpp
        src/src_editor/ClickableLabel.cpp
        src/main_editor.cpp
        ${UIS_HEADERS})

# add_subdirectory(src/src_testing/pruebas_camino)
#add_subdirectory(src/src_testing/pruebas_mapa)
add_subdirectory(src/src_testing/pruebas_serializador)


target_link_libraries(client Qt5::Widgets Qt5::Core ${SDL2PP_LIBRARIES} pthread yaml-cpp)
target_link_libraries(server pthread yaml-cpp)

target_link_libraries(DuneEditorDeMapas Qt5::Widgets Qt5::Core yaml-cpp)
