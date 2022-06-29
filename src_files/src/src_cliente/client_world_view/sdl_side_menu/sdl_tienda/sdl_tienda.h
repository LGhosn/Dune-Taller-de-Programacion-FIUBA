#ifndef SDL_TIENDA_H
#define SDL_TIENDA_H

#include "sdl_boton_edificio.h"
#include "sdl_boton_unidad.h"
#include "sdl_boton_paginas.h"
#include "../../sdl_color/sdl_color.h"
#include "../../../client_solicitudes/cliente_solicitud.h"
#include <vector>

class TiendaSDL {
    SDL2pp::Renderer& renderer;
    ColorSDL& color;
    uint8_t casa;
    std::vector<BotonEdificioSDL> botones_edificios;
    std::vector<BotonUnidadSDL> botones_infanteria;
    std::vector<BotonUnidadSDL> botones_vehiculos;
    std::vector<BotonPaginasSDL> botones_paginas;
    uint8_t botones_a_mostrar = 0;
    // 0 = Edificios, 1 = Infanteria, 2 = Vehiculos

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

    void cargarBotonesEdificios(TexturasSDL& texturas, YAML::Node& constantes,
                                uint8_t id_jugador);
    void cargarBotonesUnidades(TexturasSDL& texturas, YAML::Node& constantes,
                                uint8_t id_jugador);
    void cargarBotonesPaginas(TexturasSDL& texturas, YAML::Node& constantes);

public:
    TiendaSDL(SDL2pp::Renderer& renderer, uint8_t casa, TexturasSDL& texturas,
                uint8_t id_jugador, YAML::Node& constantes, ColorSDL& color);

    void empezarConstruccionEdificio(uint8_t tipo, uint16_t tiempo_construccion);

    void empezarEntrenamiento(uint8_t tipo, uint16_t tiempo_construccion);

    void actualizarEdificios(const std::vector<bool>& edificios_comprables);

    /*
     * Le informa al boton del tipo de edificio que fue creado acerca de la construccion del
     * nuevo edificio.
    */
    void edificioCreado(uint8_t tipo);

    SolicitudCliente* click(int pos_x, int pos_y);
    SolicitudCliente* clickEnMapa(Coordenadas& coords);

    void update(long frames_transcurridos);
    void render();
};

#endif
