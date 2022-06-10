#ifndef SDL_TILE_H
#define SDL_TILE_H

#include <SDL2pp/SDL2pp.hh>
#include "../../src_common/common_coords.h"

#define LARGO_TILE 16
#define PADDING 100

class TileSDL {
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    float zoom;
    uint32_t pos_x, pos_y;
    Coordenadas coords;
    char pos_tex_x, pos_tex_y;

public:
    TileSDL(SDL2pp::Renderer& renderer, SDL2pp::Texture& textura, Coordenadas& coords,
    char pos_tex_x, char pos_tex_y, float zoom_inicial);

    void update(uint32_t offset_x, uint32_t offset_y, float zoom);

    void render();
};

#endif
