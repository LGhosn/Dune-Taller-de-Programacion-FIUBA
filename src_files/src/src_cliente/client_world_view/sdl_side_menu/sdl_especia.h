#ifndef SDL_ESPECIA_H
#define SDL_ESPECIA_H

#include <SDL2pp/SDL2pp.hh>
#include "../../sdl_texturas.h"

class EspeciaSDL {
    uint16_t cantidad_especia;
    SDL2pp::Font& fuente;
    SDL2pp::Rect destino;
public:
    EspeciaSDL(TexturasSDL& texturas);

    void modificarEspecia(uint16_t cantidad_especia);

    void render();
};

#endif // SDL_ESPECIA_H
