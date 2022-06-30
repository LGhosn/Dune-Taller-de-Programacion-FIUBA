#include "sdl_tienda.h"

void TiendaSDL::cargarBotonesEdificios(TexturasSDL& texturas, YAML::Node& constantes,
                                        uint8_t id_jugador) {
    botones_edificios.emplace_back(renderer, texturas, 1, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y,
                            ancho_boton,
                            largo_boton),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 2, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y + largo_boton + padding_botones,
                            ancho_boton,
                            largo_boton),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 3, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y + 2 * (largo_boton + padding_botones),
                            ancho_boton,
                            largo_boton),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 4, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y + 3 * (largo_boton + padding_botones),
                            ancho_boton,
                            largo_boton),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 5, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x + ancho_boton + padding_botones,
                            pos_inicial_botones_y,
                            ancho_boton,
                            largo_boton),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 6, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x + ancho_boton + padding_botones,
                            pos_inicial_botones_y + largo_boton + padding_botones,
                            ancho_boton,
                            largo_boton),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 7, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x + ancho_boton + padding_botones,
                            pos_inicial_botones_y + 2 * (largo_boton + padding_botones),
                            ancho_boton,
                            largo_boton),
                        constantes);
}

void TiendaSDL::cargarBotonesUnidades(TexturasSDL& texturas, YAML::Node& constantes,
                                        uint8_t id_jugador) {
    botones_infanteria.emplace_back(renderer, texturas, 0, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y,
                            ancho_boton,
                            largo_boton),
                        constantes);
    botones_infanteria.emplace_back(renderer, texturas, 1, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y + largo_boton + padding_botones,
                            ancho_boton,
                            largo_boton),
                        constantes);
    botones_infanteria.emplace_back(renderer, texturas, 2, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x + ancho_boton + padding_botones,
                            pos_inicial_botones_y,
                            ancho_boton,
                            largo_boton),
                        constantes);
    botones_infanteria.emplace_back(renderer, texturas, 3, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x + ancho_boton + padding_botones,
                            pos_inicial_botones_y + largo_boton + padding_botones,
                            ancho_boton,
                            largo_boton),
                        constantes);
    
    botones_vehiculos.emplace_back(renderer, texturas, 4, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y,
                            ancho_boton,
                            largo_boton
                        ), constantes);

    botones_vehiculos.emplace_back(renderer, texturas, 5, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y + largo_boton + padding_botones,
                            ancho_boton,
                            largo_boton
                        ), constantes);
    
    botones_vehiculos.emplace_back(renderer, texturas, 6, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y + 2 * (largo_boton + padding_botones),
                            ancho_boton,
                            largo_boton
                        ), constantes);
    botones_vehiculos.emplace_back(renderer, texturas, 7, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x,
                            pos_inicial_botones_y + 3 * (largo_boton + padding_botones),
                            ancho_boton,
                            largo_boton
                        ), constantes);
    botones_vehiculos.emplace_back(renderer, texturas, 8, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x + ancho_boton + padding_botones,
                            pos_inicial_botones_y,
                            ancho_boton,
                            largo_boton
                        ), constantes);
    botones_vehiculos.emplace_back(renderer, texturas, 9, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x + ancho_boton + padding_botones,
                            pos_inicial_botones_y + largo_boton + padding_botones,
                            ancho_boton,
                            largo_boton
                        ), constantes);
    botones_vehiculos.emplace_back(renderer, texturas, 10, casa, id_jugador,
                        SDL2pp::Rect(
                            pos_inicial_botones_x + ancho_boton + padding_botones,
                            pos_inicial_botones_y + 2 * (largo_boton + padding_botones),
                            ancho_boton,
                            largo_boton
                        ), constantes);
}

void TiendaSDL::cargarBotonesPaginas(TexturasSDL& texturas, YAML::Node& constantes) {
    uint32_t largo_boton_pagina =
        constantes["WorldView"]["SideMenu"]["Tienda"]["BotonesPagina"]["Alto"].as<uint32_t>();
    
    uint32_t padding_boton_pagina =
        constantes["WorldView"]["SideMenu"]["Tienda"]["BotonesPagina"]["Padding"].as<uint32_t>();

    botones_paginas.emplace_back(renderer, SDL2pp::Rect(
        pos_inicial_botones_x + ancho_boton + padding_botones,
        pos_inicial_botones_y + 3 * (largo_boton + padding_botones),
        ancho_boton,
        largo_boton_pagina
    ), texturas.obtenerTextoEdificios(), constantes);

    botones_paginas.emplace_back(renderer, SDL2pp::Rect(
        pos_inicial_botones_x + ancho_boton + padding_botones,
        pos_inicial_botones_y + 3 * (largo_boton + padding_botones) +
                                largo_boton_pagina + padding_boton_pagina,
        ancho_boton,
        largo_boton_pagina
    ), texturas.obtenerTextoInfanteria(), constantes);

    botones_paginas.emplace_back(renderer, SDL2pp::Rect(
        pos_inicial_botones_x + ancho_boton + padding_botones,
        pos_inicial_botones_y + 3 * (largo_boton + padding_botones) +
                                2 * (largo_boton_pagina + padding_boton_pagina),
        ancho_boton,
        largo_boton_pagina
    ), texturas.obtenerTextoVehiculos(), constantes);
}

TiendaSDL::TiendaSDL(SDL2pp::Renderer& renderer, uint8_t casa, TexturasSDL& texturas,
                        uint8_t id_jugador, YAML::Node& constantes, ColorSDL& color):
                    renderer(renderer),
                    color(color),
                    casa(casa),
                    ancho_menu(constantes["WorldView"]["SideMenu"]["Ancho"].as<uint32_t>()),
                    ancho_ventana(constantes["WorldView"]["Ventana"]["Ancho"].as<uint32_t>()),
                    largo_ventana(constantes["WorldView"]["Ventana"]["Alto"].as<uint32_t>()),
                    pos_y(constantes["WorldView"]["SideMenu"]["Tienda"]["OffsetY"].as<uint32_t>()),
                    padding(constantes["WorldView"]["SideMenu"]["Tienda"]["Padding"].as<uint32_t>()),
                    ancho(ancho_menu - 2 * padding),
                    largo(largo_ventana - pos_y - 2 * padding),
                    padding_botones(constantes["WorldView"]["SideMenu"]["Tienda"]["Botones"]["Padding"].as<uint32_t>()),
                    largo_boton(constantes["WorldView"]["SideMenu"]["Tienda"]["Botones"]["Alto"].as<uint32_t>()),
                    relacion_ancho_largo_boton(constantes["WorldView"]["SideMenu"]["Tienda"]["Botones"]["RelacionAnchoLargo"].as<float>()),
                    ancho_boton(largo_boton * relacion_ancho_largo_boton),
                    pos_inicial_botones_x(ancho_ventana - ancho + padding + padding_botones),
                    pos_inicial_botones_y(pos_y + padding),
                    tienda_rect(ancho_ventana - ancho + padding,
                                    pos_y,
                                    ancho,
                                    largo) {
    cargarBotonesEdificios(texturas, constantes, id_jugador);
    cargarBotonesUnidades(texturas, constantes, id_jugador);
    cargarBotonesPaginas(texturas, constantes);
}

void TiendaSDL::empezarConstruccionEdificio(uint8_t tipo, uint16_t tiempo_construccion) {
    botones_edificios[tipo - 1].empezarConstruccion(tiempo_construccion);
}

void TiendaSDL::empezarEntrenamientoInfanteria(uint8_t tipo, uint16_t tiempo_entrenamiento, Coordenadas& coords_spawn) {
    botones_infanteria[tipo - 1].empezarEntrenamiento(tiempo_entrenamiento);
}

void TiendaSDL::empezarEntrenamientoVehiculo(uint8_t tipo, uint16_t tiempo_entrenamiento, Coordenadas& coords_spawn) {
    botones_vehiculos[tipo - 1].empezarEntrenamiento(tiempo_entrenamiento);
}

void TiendaSDL::actualizarEdificios(const std::vector<bool>& edificios_comprables) {
    for (uint8_t i = 0; i < edificios_comprables.size(); i++) {
        if (edificios_comprables[i + 1]) {
            botones_edificios[i].habilitar();
        } else {
            botones_edificios[i].deshabilitar();
        }
    }
}

void TiendaSDL::edificioCreado(uint8_t tipo) {
    botones_edificios[tipo - 1].edificioCreado();
}

SolicitudCliente* TiendaSDL::click(int pos_x, int pos_y) {
    if (botones_paginas[0].contiene(pos_x, pos_y)) {
        botones_a_mostrar = 0;
        botones_paginas[0].seleccionar();
        botones_paginas[1].deseleccionar();
        botones_paginas[2].deseleccionar();
        return nullptr;
    } else if (botones_paginas[1].contiene(pos_x, pos_y)) {
        botones_a_mostrar = 1;
        botones_paginas[0].deseleccionar();
        botones_paginas[1].seleccionar();
        botones_paginas[2].deseleccionar();
        return nullptr;
    } else if (botones_paginas[2].contiene(pos_x, pos_y)) {
        botones_a_mostrar = 2;
        botones_paginas[0].deseleccionar();
        botones_paginas[1].deseleccionar();
        botones_paginas[2].seleccionar();
        return nullptr;
    }
    SolicitudCliente* solicitud = nullptr;
    if (botones_a_mostrar == 0) {
        for (auto& boton : botones_edificios) {
            solicitud = boton.click(pos_x, pos_y);
            if (solicitud)
                break;
        }
    } else if (botones_a_mostrar == 1) {
        for (auto& boton : botones_infanteria) {
            solicitud = boton.click(pos_x, pos_y);
            if (solicitud)
                break;
        }
    } else if (botones_a_mostrar == 2) {
        for (auto& boton : botones_vehiculos) {
            solicitud = boton.click(pos_x, pos_y);
            if (solicitud)
                break;
        }
    }
    return solicitud;
}

SolicitudCliente* TiendaSDL::clickEnMapa(Coordenadas& coords) {
    SolicitudCliente* solicitud = nullptr;
    for (auto& boton : botones_edificios) {
        solicitud = boton.clickEnMapa(coords);
        if (solicitud)
            break;
        }
    return solicitud;
}

void TiendaSDL::update(long frames_transcurridos) {
    for (auto& boton : botones_edificios) {
        boton.update(frames_transcurridos);
    }
    for (auto& boton : botones_infanteria) {
        boton.update(frames_transcurridos);
    }
    for (auto& boton : botones_vehiculos) {
        boton.update(frames_transcurridos);
    }
}

void TiendaSDL::render() {
    renderer.SetDrawColor(color.obtenerOscuro());
    renderer.FillRect(tienda_rect);
    if (botones_a_mostrar == 0) {
        for(auto& boton : botones_edificios)
            boton.render();
    } else if (botones_a_mostrar == 1) {
        for(auto& boton : botones_infanteria)
            boton.render();
    } else if (botones_a_mostrar == 2) {
        for (auto& boton : botones_vehiculos)
            boton.render();
    }
    for (auto& boton : botones_paginas) {
        boton.render();
    }
}
