#include "sdl_side_menu.h"

SideMenuSDL::SideMenuSDL(SDL2pp::Renderer& renderer, uint8_t casa, TexturasSDL& texturas) :
                            renderer(renderer),
                            casa(casa),
                            tienda(renderer, casa, texturas),
                            logo_casa(texturas.obtenerLogoCasa(casa)),
                            origen_logo_casa(0,0,logo_casa.GetWidth(),logo_casa.GetWidth()),
                            destino_logo_casa(ANCHO_VISTA_MAPA + PADDING_TIENDA,
                                                PADDING_TIENDA,
                                                ANCHO_MENU - 2 * PADDING_TIENDA,
                                                ANCHO_MENU - 2 * PADDING_TIENDA),
                            side_menu_rect(ANCHO_VISTA_MAPA,
                                            0,
                                            ANCHO_MENU,
                                            LARGO_VISTA_MAPA) {}

SolicitudCliente* SideMenuSDL::click_en_menu(int pos_x, int pos_y) {
    if (tienda.contiene(pos_x, pos_y)) {
        return tienda.click(pos_x, pos_y);
    }
    return nullptr;
}

SolicitudCliente* SideMenuSDL::clickEnMapa(Coordenadas& coords) {
    return tienda.clickEnMapa(coords);
}

bool SideMenuSDL::tieneBotonSeleccionado() const {
    return tienda.tieneBotonSeleccionado();
}

void SideMenuSDL::update(long frame_actual) {
    tienda.update(frame_actual);
}

void SideMenuSDL::render() {
    renderer.SetDrawColor(78, 15, 0);
    renderer.FillRect(side_menu_rect);
    renderer.Copy(logo_casa, origen_logo_casa, destino_logo_casa);
    tienda.render();
}
