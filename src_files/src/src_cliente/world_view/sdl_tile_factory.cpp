#include "sdl_tile_factory.h"
#include <exception>

TileSDL TileFactorySDL::crearTileDeRoca(uint16_t tipo_textura, Coordenadas &coords) {
    return TileSDL(renderer, textura_base, coords, 7, 15);
}

TileSDL TileFactorySDL::crearTileDeArena(uint16_t tipo_textura, Coordenadas &coords) {
    return TileSDL(renderer, textura_base, coords, 0, 0);
}

TileSDL TileFactorySDL::crearTileDePrecipicio(uint16_t tipo_textura, Coordenadas &coords) {
    return TileSDL(renderer, textura_base, coords, 0, 7);
}

TileSDL TileFactorySDL::crearTileDeCima(uint16_t tipo_textura, Coordenadas &coords) {
    return TileSDL(renderer, textura_base, coords, 0, 9);
}

TileSDL TileFactorySDL::crearTileDeDuna(uint16_t tipo_textura, Coordenadas &coords) {
    return TileSDL(renderer, textura_base, coords, 3, 16);
}

TileSDL TileFactorySDL::crearTileDeEspecia(uint16_t tipo_textura, Coordenadas &coords) {
    return TileSDL(renderer, textura_base, coords, 3, 18);
}

TileSDL TileFactorySDL::crearTile(uint8_t tipo_terreno, uint16_t tipo_textura, Coordenadas& coords) {
    switch (tipo_terreno) {
        case ROCA:
            return crearTileDeRoca(tipo_textura, coords);
        case ARENA:
            return crearTileDeRoca(tipo_textura, coords);
        case PRECIPICIO:
            return crearTileDePrecipicio(tipo_textura, coords);
        case CIMA:
            return crearTileDeCima(tipo_textura, coords);
        case DUNA:
            return crearTileDeDuna(tipo_textura, coords);
        case ESPECIA:
            return crearTileDeEspecia(tipo_textura, coords);
        default:
            throw std::runtime_error("Tipo de terreno invalido.");
    }
}
