#ifndef SDL_TILE_FACTORY_H
#define SDL_TILE_FACTORY_H

#include <SDL2pp/SDL2pp.hh>
#include "sdl_tile.h"
#include <vector>

#define TEX_BASE_PATH "/terrain/d2k_BLOXBASE.bmp"

#define ROCA 'R'
#define ARENA 'A'
#define PRECIPICIO 'P'
#define CIMA 'C'
#define DUNA 'D'
#define ESPECIA 'E'

class TileFactorySDL {
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture textura_base;
    uint32_t ancho, alto;
    std::vector<TileSDL> tiles;

    void agregarTileDeRoca(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDeArena(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDePrecipicio(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDeCima(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDeDuna(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDeEspecia(uint16_t tipo_textura, Coordenadas& coords);

    void agregarTile(uint8_t tipo_terreno, uint16_t tipo_textura, Coordenadas& coords);

public:
    TileFactorySDL(SDL2pp::Renderer& renderer, std::string& nombre_mapa);

    std::vector<TileSDL>& obtenerTiles();

    uint16_t obtenerAlto() const;
    uint16_t obtenerAncho() const;
};

#endif
