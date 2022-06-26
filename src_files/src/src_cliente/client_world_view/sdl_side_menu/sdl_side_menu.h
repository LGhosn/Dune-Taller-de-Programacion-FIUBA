#ifndef SDL_SIDE_MENU_H
#define SDL_SIDE_MENU_H

#include <SDL2pp/SDL2pp.hh>
#include "../sdl_texturas.h"
#include "sdl_tienda/sdl_tienda.h"
#include "sdl_especia.h"
#include "../../client_solicitudes/cliente_solicitud.h"
#include "../sdl_color/sdl_color.h"

class SideMenuSDL {
    YAML::Node& constantes;
    SDL2pp::Renderer& renderer;
    ColorSDL& color;
    uint8_t casa;
    TiendaSDL tienda;
    EspeciaSDL especia;
    SDL2pp::Texture& logo_casa;
    SDL2pp::Rect origen_logo_casa;
    SDL2pp::Rect destino_logo_casa;
    SDL2pp::Rect side_menu_rect;

public:
    SideMenuSDL(SDL2pp::Renderer& renderer, uint8_t casa, TexturasSDL& texturas,
                uint8_t id_jugador, YAML::Node& constantes, ColorSDL& color);

    SolicitudCliente* click_en_menu(int pos_x, int pos_y);
    SolicitudCliente* clickEnMapa(Coordenadas& coords);

    void modificarEspecia(uint16_t cantidad_especia);

    bool tieneBotonSeleccionado() const;

    void update(long frame_actual);

    void render();
};

#endif
