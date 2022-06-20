#ifndef SDL_TILE_H
#define SDL_TILE_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_coords.h"

#define LARGO_TILE 32
#define PADDING 100

#define ANCHO_VISTA_MAPA 924
#define LARGO_VISTA_MAPA 768

class TileSDL {
    YAML::Node& constantes;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    SDL2pp::Rect origen;
    SDL2pp::Rect destino;
    Coordenadas coords;

public:
    TileSDL(SDL2pp::Renderer& renderer, SDL2pp::Texture& textura, Coordenadas& coords,
    int pos_tex_x, int pos_tex_y, YAML::Node& constantes);

    void update(uint32_t offset_x, uint32_t offset_y, float zoom);

    void render();
};

#endif
