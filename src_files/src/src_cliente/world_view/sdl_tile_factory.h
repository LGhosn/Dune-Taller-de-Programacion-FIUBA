#ifndef SDL_TILE_FACTORY_H
#define SDL_TILE_FACTORY_H

#include <SDL2pp/SDL2pp.hh>
#include "sdl_tile.h"

#define TEX_BASE_PATH "/terrain/d2k_BLOXBASE.bmp"

#define ROCA 'R'
#define ARENA 'A'
#define PRECIPICIO 'P'
#define CIMA 'C'
#define DUNA 'D'
#define ESPECIA 'E'

class TileFactorySDL {
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura_base;

    TileSDL crearTileDeRoca(uint16_t tipo_textura, Coordenadas& coords);
    TileSDL crearTileDeArena(uint16_t tipo_textura, Coordenadas& coords);
    TileSDL crearTileDePrecipicio(uint16_t tipo_textura, Coordenadas& coords);
    TileSDL crearTileDeCima(uint16_t tipo_textura, Coordenadas& coords);
    TileSDL crearTileDeDuna(uint16_t tipo_textura, Coordenadas& coords);
    TileSDL crearTileDeEspecia(uint16_t tipo_textura, Coordenadas& coords);

public:
    TileFactorySDL(SDL2pp::Renderer& renderer);

    TileSDL crearTile(uint8_t tipo_terreno, uint16_t tipo_textura, Coordenadas& coords);
};

#endif
