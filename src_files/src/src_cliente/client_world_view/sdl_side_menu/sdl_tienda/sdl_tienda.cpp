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
}

 bool TiendaSDL::contiene(int pos_x, int pos_y) const {
    for (auto& boton : botones_edificios) {
        if (boton.contiene(pos_x, pos_y)) {
            return true;
        }
    }
    return false;
 }

 bool TiendaSDL::tieneBotonSeleccionado() const {
    for (auto& boton : botones_edificios) {
        if (boton.estaSeleccionado()) {
            return true;
        }
    }
    return false;
 }

 SolicitudCliente* TiendaSDL::click(int pos_x, int pos_y) {
    for (auto& boton : botones_edificios) {
        if (boton.contiene(pos_x, pos_y)) {
            return boton.click();
        }
    }
    return nullptr;
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

void TiendaSDL::update(long frame_actual) {
    for (auto& boton : botones_edificios) {
        boton.update(frame_actual);
    }
}

void TiendaSDL::render() {
    renderer.SetDrawColor(color.obtenerOscuro());
    renderer.FillRect(tienda_rect);
    for(auto& boton : botones_edificios) {
        boton.render();
    }
}
