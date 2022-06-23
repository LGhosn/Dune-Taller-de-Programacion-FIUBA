#ifndef SDL_TILE_FACTORY_H
#define SDL_TILE_FACTORY_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "sdl_tile.h"
#include "../sdl_texturas.h"
#include <vector>

class TileFactorySDL {
    YAML::Node& constantes;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura_base;
    uint32_t ancho, alto;
    std::vector<TileSDL> tiles;

    // Constantes
    const uint8_t roca;
    const uint8_t arena;
    const uint8_t precipicio;
    const uint8_t cima;
    const uint8_t duna;
    const uint8_t especia;

    void agregarTileDeRoca(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDeArena(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDePrecipicio(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDeCima(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDeDuna(uint16_t tipo_textura, Coordenadas& coords);
    void agregarTileDeEspecia(uint16_t tipo_textura, Coordenadas& coords);

    void agregarTile(uint8_t tipo_terreno, uint16_t tipo_textura, Coordenadas& coords);

public:
    TileFactorySDL(SDL2pp::Renderer& renderer, std::string& nombre_mapa, TexturasSDL& texturas,
                    YAML::Node& constantes);

    std::vector<TileSDL>& obtenerTiles();

    uint16_t obtenerAlto() const;
    uint16_t obtenerAncho() const;
};

#endif
