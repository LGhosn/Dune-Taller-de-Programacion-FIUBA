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
    TexturasSDL& texturas;
    uint32_t ancho, alto;
    std::vector<TileSDL> tiles;

    void agregarTile(uint8_t tipo_terreno, uint16_t tipo_textura, Coordenadas& coords);

public:
    TileFactorySDL(SDL2pp::Renderer& renderer, std::string& nombre_mapa, TexturasSDL& texturas,
                    YAML::Node& constantes);

    std::vector<TileSDL>& obtenerTiles();

    uint16_t obtenerAlto() const;
    uint16_t obtenerAncho() const;
};

#endif
