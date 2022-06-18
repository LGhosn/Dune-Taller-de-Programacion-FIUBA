#include "sdl_side_menu.h"

SideMenuSDL::SideMenuSDL(SDL2pp::Renderer& renderer, uint8_t casa, TexturasSDL& texturas) :
                            renderer(renderer),
                            casa(casa),
                            logo_casa(texturas.obtenerLogoCasa(casa)),
                            origen_logo_casa(0,0,logo_casa.GetWidth(),logo_casa.GetWidth()),
                            destino_logo_casa(ANCHO_VISTA_MAPA + PADDING_TIENDA,
                                                PADDING_TIENDA,
                                                ANCHO_MENU - 2 * PADDING_TIENDA,
                                                ANCHO_MENU - 2 * PADDING_TIENDA),
                            side_menu_rect(ANCHO_VISTA_MAPA,
                                            0,
                                            ANCHO_MENU,
                                            LARGO_VISTA_MAPA),
                            tienda_rect(ANCHO_VISTA_MAPA + PADDING_TIENDA,
                                        POS_TIENDA,
                                        ANCHO_MENU - 2 * PADDING_TIENDA,
                                        LARGO_VISTA_MAPA - POS_TIENDA - 2 * PADDING_TIENDA) {}

void SideMenuSDL::render() {
    renderer.SetDrawColor(78, 15, 0);
    renderer.FillRect(side_menu_rect);
    renderer.SetDrawColor(26, 1, 17);
    renderer.FillRect(tienda_rect);
    renderer.Copy(logo_casa, origen_logo_casa, destino_logo_casa);
}
