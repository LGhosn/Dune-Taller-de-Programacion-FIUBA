#ifndef SDL_EDIFICIO_H
#define SDL_EDIFICIO_H

#include <SDL2pp/SDL2pp.hh>
#include "../../src_common/common_coords.h"
#include "sdl_jugador.h"

#define LARGO_TILE 16

class EdificioSDL {
    uint16_t id;
    JugadorSDL jugador;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    Coordenadas coords;
    uint16_t alto, ancho;
    int pos_textura_x, pos_textura_y;
    int pos_x, pos_y;
    long iter_anterior;

public:
    EdificioSDL(uint16_t id, JugadorSDL jugador, SDL2pp::Renderer& renderer, SDL2pp::Texture& textura,
    Coordenadas& coords, uint16_t alto, uint16_t ancho, int pos_textura_x, int pos_textura_y);
    
    void debilitar();
    
    void update(long iter_actual, uint32_t offset_x, uint32_t offset_y);

    void render();
};

#endif
