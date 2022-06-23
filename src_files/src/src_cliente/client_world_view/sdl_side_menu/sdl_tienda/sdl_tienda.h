#ifndef SDL_TIENDA_H
#define SDL_TIENDA_H

#include "sdl_boton_tienda.h"
#include "../../../client_solicitudes/cliente_solicitud.h"
#include <list>

#define ANCHO_MENU 300
#define ANCHO_VISTA_MAPA 924
#define LARGO_VISTA_MAPA 768

#define POS_TIENDA 300
#define PADDING_TIENDA 10
#define ANCHO_TIENDA ANCHO_MENU - 2 * PADDING_TIENDA
#define LARGO_TIENDA LARGO_VISTA_MAPA - POS_TIENDA - 2 * PADDING_TIENDA
#define PADDING_BOTONES 16

#define LARGO_BOTON 92 
#define ANCHO_BOTON LARGO_BOTON * RATIO_ANCHO_LARGO_BOTON
#define POS_INICIAL_BOTONES_TIENDA_X ANCHO_VISTA_MAPA + PADDING_TIENDA + PADDING_BOTONES
#define POS_INICIAL_BOTONES_TIENDA_Y POS_TIENDA + PADDING_TIENDA

class TiendaSDL {
    SDL2pp::Renderer& renderer;
    uint8_t casa;
    std::list<BotonTiendaSDL> botones_edificios;
    std::list<BotonTiendaSDL> botones_unidades;

    // Constantes
    const uint32_t ancho_menu;
    const uint32_t ancho_ventana;
    const uint32_t largo_ventana;
    const uint32_t pos_y;
    const uint32_t padding;
    const uint32_t ancho;
    const uint32_t largo;
    const uint32_t padding_botones;
    const uint32_t largo_boton;
    const float relacion_ancho_largo_boton;
    const uint32_t ancho_boton;
    const uint32_t pos_inicial_botones_x;
    const uint32_t pos_inicial_botones_y;

     SDL2pp::Rect tienda_rect;


public:
    TiendaSDL(SDL2pp::Renderer& renderer, uint8_t casa, TexturasSDL& texturas,
                uint8_t id_jugador, YAML::Node& constantes);

    bool contiene(int pos_x, int pos_y) const;

    bool tieneBotonSeleccionado() const;

    SolicitudCliente* click(int pos_x, int pos_y);
    SolicitudCliente* clickEnMapa(Coordenadas& coords);

    void update(long frame_actual);
    void render();
};

#endif
