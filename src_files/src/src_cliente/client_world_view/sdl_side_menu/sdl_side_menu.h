#ifndef SDL_SIDE_MENU_H
#define SDL_SIDE_MENU_H

#include <SDL2pp/SDL2pp.hh>
#include "../sdl_texturas.h"

#define ANCHO_MENU 300
#define ANCHO_VISTA_MAPA 924
#define LARGO_VISTA_MAPA 768

#define PADDING_TIENDA 10
#define POS_TIENDA 300

class SideMenuSDL {
    SDL2pp::Renderer& renderer;
    uint8_t casa;
    SDL2pp::Texture& logo_casa;
    SDL2pp::Rect origen_logo_casa;
    SDL2pp::Rect destino_logo_casa;
    SDL2pp::Rect side_menu_rect;
    SDL2pp::Rect tienda_rect;

public:
    SideMenuSDL(SDL2pp::Renderer& renderer, uint8_t casa, TexturasSDL& texturas);

    void render();
};

#endif
