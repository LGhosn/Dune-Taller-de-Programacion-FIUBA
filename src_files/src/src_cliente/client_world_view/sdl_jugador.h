#ifndef SDL_JUGADOR_H
#define SDL_JUGADOR_H

#include <stdint.h>

class JugadorSDL {
    uint16_t id;
    uint8_t color;
public:
    JugadorSDL(uint16_t id, uint8_t color);
};

#endif
