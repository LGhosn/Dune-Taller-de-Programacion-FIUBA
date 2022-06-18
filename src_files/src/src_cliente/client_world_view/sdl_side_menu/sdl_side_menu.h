#ifndef SDL_SIDE_MENU_H
#define SDL_SIDE_MENU_H

#include <SDL2pp/SDL2pp.hh>

#define ANCHO_MENU 300
#define ANCHO_VISTA_MAPA 924
#define LARGO_VISTA_MAPA 768
// 26 1 17

class SideMenuSDL {
    SDL2pp::Renderer& renderer;
    uint8_t casa;
public:
    SideMenuSDL(SDL2pp::Renderer& renderer, uint8_t casa);

    void render();
};

#endif
