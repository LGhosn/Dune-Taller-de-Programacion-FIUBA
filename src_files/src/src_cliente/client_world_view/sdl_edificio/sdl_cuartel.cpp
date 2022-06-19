#include "sdl_cuartel.h"

CuartelSDL::CuartelSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                       SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                       uint16_t ancho, uint8_t casa) :
                    EdificioSDL(id, id_jugador, renderer, textura, coords, alto, ancho, casa) {
    origen.SetX(0);
    origen.SetH(ALTO_TEX_EDIFICIO_CUARTEL);
    switch (casa) {
        case HARKONNEN: {
            origen.SetY(0);
            origen.SetW(ANCHO_TEX_EDIFICIO_ATREIDES);
            break;
        } case ATREIDES: {
            origen.SetY(ALTO_TEX_EDIFICIO_CUARTEL);
            origen.SetW(ANCHO_TEX_EDIFICIO_OTROS);
            break;
        } case ORDOS: {
            origen.SetY(2 * ALTO_TEX_EDIFICIO_CUARTEL);
            origen.SetW(ANCHO_TEX_EDIFICIO_OTROS);
            break;
        }
    }
}   

void CuartelSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < LIMITE_HP_DEBILITAR)
        origen.SetX(origen.GetW());
}

void CuartelSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual, float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * LARGO_TILE * zoom - origen_movil_x);
    destino.SetY((coords.y * LARGO_TILE + PADDING_CUARTEL_Y) * zoom - origen_movil_y);
    destino.SetW(LARGO_TILE * ancho * zoom);
    destino.SetH((LARGO_TILE * alto - 2 * PADDING_CUARTEL_Y) * zoom);
    setearPosicionUI(origen_movil_x, origen_movil_y);
}

void CuartelSDL::render() {
    renderer.Copy(textura, origen, destino);
}
