#include "sdl_side_menu.h"

SideMenuSDL::SideMenuSDL(SDL2pp::Renderer& renderer, uint8_t casa) :
                            renderer(renderer),
                            casa(casa) {}

void SideMenuSDL::render() {
    renderer.SetDrawColor(26, 1, 17);
    renderer.FillRect(
        ANCHO_VISTA_MAPA, 0,
        ANCHO_VISTA_MAPA + ANCHO_MENU, LARGO_VISTA_MAPA
    );
}
