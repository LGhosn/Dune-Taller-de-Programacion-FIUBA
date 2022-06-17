#include "sdl_centro.h"

void CentroSDL::actualizarFrameBrazo(long frame_actual) {
    long cant_frames = (frame_actual - frame_anterior) / RATE_BRAZO;
    if (cant_frames > 0) {
        frame_actual_brazo = (frame_actual_brazo + cant_frames) % CANT_FRAMES_BRAZO;
        pos_en_tex_brazo_x = frame_actual_brazo * ANCHO_TEX_BRAZO; 
        frame_anterior = frame_actual;
    }
}

void CentroSDL::setearPosicionBrazo() {
    pos_actual_brazo_y = pos_actual_y + OFFSET_BRAZO_Y;
    switch (frame_actual_brazo) {
        case 0:
            pos_actual_brazo_x = pos_actual_x + OFFSET_BRAZO_X - 1;
            break;
        case 3:
            pos_actual_brazo_x = pos_actual_x + OFFSET_BRAZO_X - 2;
            break;
        case 4:
            pos_actual_brazo_x = pos_actual_x + OFFSET_BRAZO_X - 2;
            break;
        default:
            pos_actual_brazo_x = pos_actual_x + OFFSET_BRAZO_X;
            break;
    }
}

CentroSDL::CentroSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                    SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                    uint16_t ancho, uint8_t casa):
    EdificioSDL(id, id_jugador, renderer, textura, coords, alto, ancho, casa) {
    pos_en_tex_x = 0;
    switch (casa) {
        case HARKONNEN: {
            pos_en_tex_y = 0;
            break;
        } case ATREIDES: {
            pos_en_tex_y = ALTO_TEX_EDIFICIO + ALTO_TEX_BRAZO + 1;
            break;
        } case ORDOS: {
            pos_en_tex_y = 2*(ALTO_TEX_EDIFICIO + ALTO_TEX_BRAZO) + 1;
            break;
        }
    }
    pos_en_tex_brazo_x = 0;
    pos_en_tex_brazo_y = pos_en_tex_y + ALTO_TEX_EDIFICIO;
}

void CentroSDL::cambiarHP(uint16_t hp_edificio) {
    if (hp_edificio < LIMITE_HP_DEBILITAR)
        pos_en_tex_x = ANCHO_TEX_EDIFICIO;
}

void CentroSDL::update(uint32_t offset_x, uint32_t offset_y, long frame_actual) {
    pos_actual_x = coords.x * LARGO_TILE - offset_x;
    pos_actual_y = coords.y * LARGO_TILE - offset_y;
    actualizarFrameBrazo(frame_actual);
    setearPosicionBrazo();
    tam_actual_x = LARGO_TILE * ancho;
    tam_actual_y = LARGO_TILE * alto;
    tam_actual_brazo_x = ANCHO_TEX_BRAZO;
    tam_actual_brazo_y = ALTO_TEX_BRAZO;
}

void CentroSDL::render() {
    renderer.Copy(textura,
                  SDL2pp::Rect(
                    pos_en_tex_x,
                    pos_en_tex_y,
                    ANCHO_TEX_EDIFICIO,
                    ALTO_TEX_EDIFICIO
                  ),
                  SDL2pp::Rect(
                    pos_actual_x,
                    pos_actual_y + PADDING_EDIFICIO_Y,
                    tam_actual_x,
                    tam_actual_y - 2 * PADDING_EDIFICIO_Y
                  )
                );

    renderer.Copy(textura,
                    SDL2pp::Rect(
                        pos_en_tex_brazo_x,
                        pos_en_tex_brazo_y,
                        ANCHO_TEX_BRAZO,
                        ALTO_TEX_BRAZO
                    ),
                    SDL2pp::Rect(
                        pos_actual_brazo_x,
                        pos_actual_brazo_y,
                        tam_actual_brazo_x,
                        tam_actual_brazo_y
                    )
                );
}
