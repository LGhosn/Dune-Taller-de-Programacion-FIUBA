#ifndef CLIENT_SDL_COLORES_H
#define CLIENT_SDL_COLORES_H

#include "sdl_color.h"
#include <vector>

class ColoresSDL {
    std::vector<ColorSDL> colores;

    uint8_t obtenerIdColor(uint8_t id_jugador);
public:
    ColoresSDL();

    ColorSDL& obtenerColor(uint8_t id_jugador);
};

#endif
