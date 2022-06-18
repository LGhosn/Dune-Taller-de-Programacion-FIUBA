#include "sdl_centro.h"

void CentroSDL::actualizarFrameBrazo(long frame_actual) {
    long cant_frames = (frame_actual - frame_anterior) / RATE_BRAZO;
    if (cant_frames > 0) {
        frame_actual_brazo = (frame_actual_brazo + cant_frames) % CANT_FRAMES_BRAZO;
        origen_brazo.SetX(frame_actual_brazo * ANCHO_TEX_BRAZO); 
        frame_anterior = frame_actual;
    }
}

void CentroSDL::setearPosicionBrazo() {
    destino_brazo.SetY(destino.GetY() + OFFSET_BRAZO_Y * zoom);
    switch (frame_actual_brazo) {
        case 0:
            destino_brazo.SetX(destino.GetX() + (OFFSET_BRAZO_X - 1) * zoom);
            break;
        case 3:
            destino_brazo.SetX(destino.GetX() + (OFFSET_BRAZO_X - 2) * zoom);
            break;
        case 4:
            destino_brazo.SetX(destino.GetX() + (OFFSET_BRAZO_X - 2) * zoom);
            break;
        default:
            destino_brazo.SetX(destino.GetX() + OFFSET_BRAZO_X * zoom);
            break;
    }
}

CentroSDL::CentroSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                    SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                    uint16_t ancho, uint8_t casa):
    EdificioSDL(id, id_jugador, renderer, textura, coords, alto, ancho, casa) {
    origen.SetX(0);
    switch (casa) {
        case HARKONNEN: {
            origen.SetY(0);
            break;
        } case ATREIDES: {
            origen.SetY(ALTO_TEX_EDIFICIO + ALTO_TEX_BRAZO + 1);
            break;
        } case ORDOS: {
            origen.SetY(2*(ALTO_TEX_EDIFICIO + ALTO_TEX_BRAZO) + 1);
            break;
        }
    }
    origen.SetW(ANCHO_TEX_EDIFICIO);
    origen.SetH(ALTO_TEX_EDIFICIO);
    origen_brazo.SetX(0);
    origen_brazo.SetY(origen.GetY() + ALTO_TEX_EDIFICIO);
    origen_brazo.SetW(ANCHO_TEX_BRAZO);
    origen_brazo.SetH(ALTO_TEX_BRAZO);
}

void CentroSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < LIMITE_HP_DEBILITAR)
        origen.SetX(ANCHO_TEX_EDIFICIO);
}

void CentroSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual,
                        float zoom) {
    this->zoom = zoom;
    destino.SetX(coords.x * LARGO_TILE * zoom - origen_movil_x);
    destino.SetY((coords.y * LARGO_TILE + PADDING_EDIFICIO_Y) * zoom - origen_movil_y);
    actualizarFrameBrazo(frame_actual);
    setearPosicionBrazo();
    destino.SetW(LARGO_TILE * ancho * zoom);
    destino.SetH((LARGO_TILE * alto - 2 * PADDING_EDIFICIO_Y) * zoom);
    destino_brazo.SetW(ANCHO_TEX_BRAZO * zoom);
    destino_brazo.SetH(ALTO_TEX_BRAZO * zoom);
}

void CentroSDL::render() {
    renderer.Copy(textura, origen, destino);
    renderer.Copy(textura, origen_brazo, destino_brazo);
}
