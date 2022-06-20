#include "sdl_tienda.h"

TiendaSDL::TiendaSDL(SDL2pp::Renderer& renderer, uint8_t casa, TexturasSDL& texturas,
                        uint8_t id_jugador, YAML::Node& constantes):
                    constantes(constantes),
                    renderer(renderer),
                    casa(casa),
                    tienda_rect(ANCHO_VISTA_MAPA + PADDING_TIENDA,
                                        POS_TIENDA,
                                        ANCHO_TIENDA,
                                        LARGO_TIENDA) {
    botones_edificios.emplace_back(renderer, texturas, 1, casa, id_jugador,
                        SDL2pp::Rect(
                            POS_INICIAL_BOTONES_TIENDA_X,
                            POS_INICIAL_BOTONES_TIENDA_Y,
                            ANCHO_BOTON,
                            LARGO_BOTON),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 2, casa, id_jugador,
                        SDL2pp::Rect(
                            POS_INICIAL_BOTONES_TIENDA_X,
                            POS_INICIAL_BOTONES_TIENDA_Y + LARGO_BOTON + PADDING_BOTONES,
                            ANCHO_BOTON,
                            LARGO_BOTON),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 3, casa, id_jugador,
                        SDL2pp::Rect(
                            POS_INICIAL_BOTONES_TIENDA_X,
                            POS_INICIAL_BOTONES_TIENDA_Y + 2 * (LARGO_BOTON + PADDING_BOTONES),
                            ANCHO_BOTON,
                            LARGO_BOTON),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 4, casa, id_jugador,
                        SDL2pp::Rect(
                            POS_INICIAL_BOTONES_TIENDA_X,
                            POS_INICIAL_BOTONES_TIENDA_Y + 3 * (LARGO_BOTON + PADDING_BOTONES),
                            ANCHO_BOTON,
                            LARGO_BOTON),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 5, casa, id_jugador,
                        SDL2pp::Rect(
                            POS_INICIAL_BOTONES_TIENDA_X + ANCHO_BOTON + PADDING_BOTONES,
                            POS_INICIAL_BOTONES_TIENDA_Y,
                            ANCHO_BOTON,
                            LARGO_BOTON),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 6, casa, id_jugador,
                        SDL2pp::Rect(
                            POS_INICIAL_BOTONES_TIENDA_X + ANCHO_BOTON + PADDING_BOTONES,
                            POS_INICIAL_BOTONES_TIENDA_Y + LARGO_BOTON + PADDING_BOTONES,
                            ANCHO_BOTON,
                            LARGO_BOTON),
                        constantes);
    botones_edificios.emplace_back(renderer, texturas, 7, casa, id_jugador,
                        SDL2pp::Rect(
                            POS_INICIAL_BOTONES_TIENDA_X + ANCHO_BOTON + PADDING_BOTONES,
                            POS_INICIAL_BOTONES_TIENDA_Y + 2 * (LARGO_BOTON + PADDING_BOTONES),
                            ANCHO_BOTON,
                            LARGO_BOTON),
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
    renderer.SetDrawColor(26, 1, 17);
    renderer.FillRect(tienda_rect);
    for(auto& boton : botones_edificios) {
        boton.render();
    }
}
