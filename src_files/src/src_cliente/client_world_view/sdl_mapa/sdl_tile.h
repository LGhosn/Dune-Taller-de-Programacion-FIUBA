#ifndef SDL_TILE_H
#define SDL_TILE_H

#include <SDL2pp/SDL2pp.hh>
#include "../../../src_common/common_coords.h"

#define LARGO_TILE 32
#define PADDING 100

class TileSDL {
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    uint32_t pos_movil_x, pos_movil_y;
    Coordenadas coords;
    int pos_tex_x, pos_tex_y;

public:
    TileSDL(SDL2pp::Renderer& renderer, SDL2pp::Texture& textura, Coordenadas& coords,
    int pos_tex_x, int pos_tex_y);

    void update(uint32_t offset_x, uint32_t offset_y);

    void render();
};

#endif
