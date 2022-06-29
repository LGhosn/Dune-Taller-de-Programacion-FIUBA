#include "sdl_tienda.h"

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

void TiendaSDL::empezarConstruccionEdificio(uint8_t tipo, uint16_t tiempo_construccion) {
    botones_edificios[tipo - 1].empezarConstruccion(tiempo_construccion);
}

void TiendaSDL::empezarEntrenamiento(uint8_t tipo, uint16_t tiempo_construccion) {
    
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
    SolicitudCliente* solicitud = nullptr;
    for (auto& boton : botones_edificios) {
        solicitud = boton.click(pos_x, pos_y);
        if (solicitud)
            break;
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
}

void TiendaSDL::render() {
    renderer.SetDrawColor(color.obtenerOscuro());
    renderer.FillRect(tienda_rect);
    for(auto& boton : botones_edificios) {
        boton.render();
    }
    for (auto& boton : botones_paginas) {
        boton.render();
    }
}
