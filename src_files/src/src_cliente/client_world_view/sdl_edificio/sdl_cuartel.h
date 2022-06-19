#ifndef SDL_CUARTEL_H
#define SDL_CUARTEL_H

#include "sdl_edificio.h"

#define ANCHO_TEX_EDIFICIO_ATREIDES 73
#define ANCHO_TEX_EDIFICIO_OTROS 64
#define ALTO_TEX_EDIFICIO_CUARTEL 76

#define PADDING_CUARTEL_Y 10

#define HARKONNEN 0 
#define ATREIDES 1
#define ORDOS 2

#define LIMITE_HP_DEBILITAR 1000

class CuartelSDL : public EdificioSDL {
public:
    CuartelSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                uint16_t ancho, uint8_t casa);

    void cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t offset_x, uint32_t offset_y, long frame_actual, float zoom) override;

    void render() override;

};

#endif // SDL_CUARTEL_H
