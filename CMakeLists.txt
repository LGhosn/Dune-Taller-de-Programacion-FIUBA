cmake_minimum_required(VERSION 3.00)
project(Dune2000)
find_package(Qt5Widgets)
find_package(yaml-cpp REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -ggdb -O0 -pedantic -std=c++17")

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")



set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support
add_subdirectory(src_files/src/src_libs/SDL2pp)

add_definitions(-DRESOURCE_PATH="${PROJECT_SOURCE_DIR}/src_files/assets")

include_directories(${SDL2PP_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/src_files/src
        ${PROJECT_SOURCE_DIR}/src_files/src/src_menu
        ${PROJECT_SOURCE_DIR}/src_files/src/src_form_creacion
        ${PROJECT_SOURCE_DIR}/src_files/src/src_form_union
        ${PROJECT_SOURCE_DIR}/src_files/src/src_cliente
        ${PROJECT_SOURCE_DIR}/src_files/src/src_server
        ${PROJECT_SOURCE_DIR}/src_files/src/src_common
        # ${PROJECT_SOURCE_DIR}/src/src_editor
        )

qt5_wrap_ui(UIS_HEADERS
        src_files/src/src_menu/MenuUi.ui
        src_files/src/src_form_creacion/FormCreacion.ui
        src_files/src/src_form_union/FormUnion.ui
        src_files/src/src_editor/DuneEditorDeMapasUi.ui
        )
# Habilito el automoc para poder hacer autoconnect de señales
set(CMAKE_AUTOMOC on)
# Habilito autorcc para manejar automaticamente los QResources
set(CMAKE_AUTORCC ON)
# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})
message("Headers generados: ${UIS_HEADERS}")

add_executable(ClientDune2000
        src_files/src/main_client.cpp
        src_files/src/src_cliente/pix_a_coords.cpp
        src_files/src/src_cliente/client_client.cpp
        src_files/src/src_cliente/client_comandos/cmd_modificar_vida_unidad.cpp
        src_files/src/src_cliente/client_DTO/dto_cmd_modificar_vida_unidad_cliente.h
        src_files/src/src_cliente/client_protocolo.cpp
        src_files/src/src_cliente/client_serializador.cpp
        src_files/src/src_cliente/client_thread_reciever/client_hilo_reciever.cpp
        src_files/src/src_cliente/client_thread_sender/client_hilo_sender.cpp
        src_files/src/src_cliente/client_renderer/client_renderer.cpp
        src_files/src/src_cliente/client_thread_sender/client_hilo_sender.cpp
        src_files/src/src_cliente/client_solicitudes/sol_crear_partida.cpp
        src_files/src/src_cliente/client_solicitudes/sol_unirse_a_partida.cpp
        src_files/src/src_cliente/client_solicitudes/sol_atacar_unidad.cpp
        src_files/src/src_cliente/client_DTO/dto_cmd_crear_edificio.h
        src_files/src/src_cliente/client_comandos/cmd_mover_mapa.cpp
        src_files/src/src_cliente/client_comandos/cmd_zoom.cpp
        src_files/src/src_cliente/client_comandos/cmd_salir.cpp
        src_files/src/src_cliente/client_comandos/cmd_click_en_mapa.cpp
        src_files/src/src_cliente/client_comandos/cmd_click_der_en_mapa.cpp
        src_files/src/src_cliente/client_comandos/cmd_crear_edificio.cpp
        src_files/src/src_cliente/client_comandos/cmd_actualizar_tienda_edificios.cpp
        src_files/src/src_cliente/client_comandos/cmd_actualizar_tienda_unidades.cpp
        src_files/src/src_cliente/client_comandos/cmd_modificar_especia.cpp
        src_files/src/src_cliente/client_comandos/cmd_modificar_energia.cpp
        src_files/src/src_cliente/client_comandos/cmd_empezar_construccion_edificio.cpp
        src_files/src/src_cliente/client_comandos/cmd_empezar_entrenamiento.cpp
        src_files/src/src_cliente/client_comandos/cmd_construccion_invalida.cpp
        src_files/src/src_cliente/client_comandos/cmd_mover_unidad.cpp
        src_files/src/src_cliente/client_comandos/cmd_enemigo_despliega_unidad.cpp
        src_files/src/src_cliente/client_comandos/cmd_actualizar_puntaje.cpp
        src_files/src/src_cliente/client_comandos/cmd_marcador.cpp
        src_files/src/src_cliente/client_solicitudes/sol_mover_unidad.cpp
        src_files/src/src_cliente/client_solicitudes/sol_comprar_edificio.cpp
        src_files/src/src_cliente/client_solicitudes/sol_comprar_unidad.cpp
        src_files/src/src_cliente/client_comandos/client_comando.cpp
        src_files/src/src_cliente/client_world_view/sdl_mapa/sdl_tile_factory.cpp
        src_files/src/src_cliente/client_world_view/sdl_mapa/sdl_tile.cpp
        src_files/src/src_cliente/client_world_view/sdl_mapa/sdl_mapa.cpp
        src_files/src/src_cliente/client_world_view/sdl_unidad/sdl_vehiculo/sdl_vehiculo.cpp
        src_files/src/src_cliente/client_world_view/sdl_unidad/sdl_infanteria/sdl_infanteria.cpp
        src_files/src/src_cliente/client_world_view/sdl_unidad/sdl_unidad.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_edificio.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_edificio_factory.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_centro.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_cuartel.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_fabrica_ligera.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_fabrica_pesada.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_palacio.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_refineria.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_silo.cpp
        src_files/src/src_cliente/client_world_view/sdl_edificio/sdl_trampa.cpp
        src_files/src/src_cliente/client_world_view/sdl_side_menu/sdl_side_menu.cpp
        src_files/src/src_cliente/client_world_view/sdl_side_menu/sdl_tienda/sdl_tienda.cpp
        src_files/src/src_cliente/client_world_view/sdl_side_menu/sdl_tienda/sdl_boton_edificio.cpp
        src_files/src/src_cliente/client_world_view/sdl_side_menu/sdl_tienda/sdl_boton_unidad.cpp
        src_files/src/src_cliente/client_world_view/sdl_side_menu/sdl_tienda/sdl_boton_paginas.cpp
        src_files/src/src_cliente/client_world_view/sdl_side_menu/sdl_especia.cpp
        src_files/src/src_cliente/client_world_view/sdl_side_menu/sdl_energia.cpp
        src_files/src/src_cliente/client_world_view/sdl_marcador/sdl_marcador.cpp
        src_files/src/src_cliente/client_world_view/sdl_sonidos/sdl_sonidos.cpp
        src_files/src/src_cliente/client_world_view/sdl_sonidos/sdl_mixer.cpp
        src_files/src/src_cliente/client_world_view/world_view.cpp
        src_files/src/src_cliente/client_world_view/sdl_color/sdl_color.cpp
        src_files/src/src_cliente/client_world_view/sdl_color/sdl_colores.cpp
        src_files/src/src_cliente/client_world_view/sdl_texturas.cpp
        src_files/src/src_common/common_DTO/Status.cpp
        src_files/src/src_common/common_colas/cola_bloqueante.cpp
        src_files/src/src_common/common_colas/cola_no_bloqueante.cpp
        src_files/src/src_cliente/client_thread_sdl/client_hilo_sdl.cpp
        src_files/src/src_cliente/client_thread_sdl/client_sdl_evento.cpp
        src_files/src/src_common/common_coords.cpp
        src_files/src/src_menu/MenuDune.cpp
        src_files/src/src_form_creacion/FormCreacion.cpp
        src_files/src/src_form_union/FormUnion.cpp
        src_files/src/src_common/common_resolver.cpp
        src_files/src/src_common/common_socket.cpp
        src_files/src/src_common/common_socket_error.cpp
        src_files/src/src_common/common_serializador.cpp
        src_files/assets/resources.qrc
        src_files/src/src_cliente/client_solicitudes/client_sol_crear_edificio.cpp
        ${UIS_HEADERS})

add_executable(ServerDune2000
        src_files/src/src_server/server_server.cpp
        src_files/src/src_server/server_comandos/cmd_crear_edificio.cpp
        src_files/src/src_server/server_comandos/cmd_empezar_partida.cpp
        src_files/src/src_server/server_comandos/cmd_modificar_especia.cpp
        src_files/src/src_server/server_comandos/cmd_mover_unidad.cpp
        src_files/src/src_server/server_comandos/cmd_empezar_entrenamiento.cpp
        src_files/src/src_server/server_comandos/cmd_modificar_energia.cpp
        src_files/src/src_server/server_comandos/cmd_enemigo_despliega_unidad.cpp
        src_files/src/src_server/server_comandos/cmd_construccion_invalida.cpp
        src_files/src/src_server/server_comandos/cmd_actualizar_puntaje.cpp
        src_files/src/src_server/server_solicitudes/solicitud_juego/sol_crear_edificio.cpp
        src_files/src/src_server/server_solicitudes/solicitud_juego/sol_comprar_unidad.cpp
        src_files/src/src_server/server_solicitudes/solicitud_juego/sol_mover_unidad.cpp
        src_files/src/src_server/server_solicitudes/solicitud_juego/sol_atacar_unidad.cpp
        src_files/src/src_server/server_comandos/cmd_actualizar_tienda_edificios.cpp
        src_files/src/src_server/server_comandos/cmd_actualizar_tienda_unidades.cpp
        src_files/src/src_server/server_comandos/cmd_empezar_construccion_edificio.cpp
        src_files/src/src_server/server_solicitudes/solicitud_juego/sol_crear_edificio.cpp
        src_files/src/src_server/server_solicitudes/solicitud_juego/sol_comprar_edificio.cpp
        src_files/src/src_server/server_protocolo/server_protocolo.cpp
        src_files/src/src_server/server_protocolo/server_serializador.cpp
        src_files/src/src_server/server_DTO/partida_DTO.h
        src_files/src/src_server/server_DTO/MovimientoDTO.cpp
        src_files/src/src_server/server_lobby.cpp
        src_files/src/src_server/server_thread_sender/server_hilo_sender.cpp
        src_files/src/src_server/server_thread_reciever/server_hilo_reciever.cpp
        src_files/src/src_server/server_thread_gameloop/server_hilo_gameloop.cpp
        src_files/src/src_server/server_game/game.cpp
        src_files/src/src_server/server_game/server_gusano.cpp
        src_files/src/src_server/server_game/server_mapa/entidades/edificios/edificios_mapa.cpp
        src_files/src/src_server/server_game/server_mapa/entidades/terrenos/terrenos_mapa.cpp
        src_files/src/src_server/server_game/server_mapa/entidades/unidades/unidades_mapa.cpp
        src_files/src/src_server/server_game/server_mapa/server_mapa.cpp
        src_files/src/src_server/server_game/server_mapa/server_camino.cpp
        src_files/src/src_server/server_game/server_mapa/server_fuera_de_rango_exception.cpp
        src_files/src/src_server/server_game/server_mapa/server_camino_no_encontrado_exception.cpp
        src_files/src/src_server/server_game/server_jugador/jugador.cpp
        src_files/src/src_server/server_game/server_jugador/especia_acumulada.cpp
        src_files/src/src_server/server_game/server_jugador/energia_acumulada.cpp
        src_files/src/src_server/server_game/server_jugador/validador_unidades.cpp
        src_files/src/src_server/server_game/server_unidades/unidades.cpp
        src_files/src/src_server/server_game/server_unidades/cosechadora.cpp
        src_files/src/src_server/server_game/server_unidades/desviador.cpp
        src_files/src/src_server/server_game/server_unidades/devastador.cpp
        src_files/src/src_server/server_game/server_unidades/fremen.cpp
        src_files/src/src_server/server_game/server_unidades/infanteriaLigera.cpp
        src_files/src/src_server/server_game/server_unidades/infanteriaPesada.cpp
        src_files/src/src_server/server_game/server_unidades/raider.cpp
        src_files/src/src_server/server_game/server_unidades/sardaukar.cpp
        src_files/src/src_server/server_game/server_unidades/tanque.cpp
        src_files/src/src_server/server_game/server_unidades/tanqueSonico.cpp
        src_files/src/src_server/server_game/server_unidades/trike.cpp
        src_files/src/src_server/server_game/server_unidades/server_armas/arma.cpp
        src_files/src/src_server/server_game/server_unidades/server_armas/Canion.cpp
        src_files/src/src_server/server_game/server_unidades/server_armas/Canion22mm.cpp
        src_files/src/src_server/server_game/server_unidades/server_armas/CanionDePlasma.cpp
        src_files/src/src_server/server_game/server_unidades/server_armas/LanzaMisiles.cpp
        src_files/src/src_server/server_game/server_unidades/server_armas/OndasDeSonido.cpp
        src_files/src/src_server/server_game/server_unidades/server_armas/Rifle.cpp
        src_files/src/src_server/server_aceptador.cpp
        src_files/src/src_server/server_handler_cliente/server_handler_cliente.cpp
        src_files/src/src_server/server_partida/server_partida.cpp
        src_files/src/src_common/common_DTO/Status.cpp
        src_files/src/src_common/common_resolver.cpp
        src_files/src/src_common/common_socket.cpp
        src_files/src/src_common/common_socket_error.cpp
        src_files/src/src_common/common_serializador.cpp
        src_files/src/src_common/common_coords.cpp
        src_files/src/main_server.cpp
        )


add_executable(DuneEditorDeMapas
        src_files/src/src_editor/DuneEditorDeMapas.cpp
        src_files/src/src_editor/SelectorDeModoDeEdicion.cpp
        src_files/src/src_editor/ClickableLabel.cpp
        src_files/src/main_editor.cpp
        ${UIS_HEADERS})

# add_subdirectory(src_files/src/src_testing/pruebas_camino)
#add_subdirectory(src_files/src/src_testing/pruebas_mapa)
add_subdirectory(src_files/src/src_testing/pruebas_serializador)


target_link_libraries(ClientDune2000 Qt5::Widgets Qt5::Core ${SDL2PP_LIBRARIES} pthread yaml-cpp)
target_link_libraries(ServerDune2000 pthread yaml-cpp)

target_link_libraries(DuneEditorDeMapas Qt5::Widgets Qt5::Core yaml-cpp)
