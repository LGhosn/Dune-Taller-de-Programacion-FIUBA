#include "sdl_tile_factory.h"
#include "yaml-cpp/yaml.h"
#include <exception>

void TileFactorySDL::agregarTileDeRoca(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 7, 15);
}

void TileFactorySDL::agregarTileDeArena(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 8, 8);
}

void TileFactorySDL::agregarTileDePrecipicio(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 0, 7);
}

void TileFactorySDL::agregarTileDeCima(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 0, 9);
}

void TileFactorySDL::agregarTileDeDuna(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 3, 16);
}

void TileFactorySDL::agregarTileDeEspecia(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 3, 18);
}

void TileFactorySDL::agregarTile(uint8_t tipo_terreno, uint16_t tipo_textura, Coordenadas& coords) {
    switch (tipo_terreno) {
        case ROCA:
            agregarTileDeRoca(tipo_textura, coords);
            break;
        case ARENA:
            agregarTileDeArena(tipo_textura, coords);
            break;
        case PRECIPICIO:
            agregarTileDePrecipicio(tipo_textura, coords);
            break;
        case CIMA:
            agregarTileDeCima(tipo_textura, coords);
            break;
        case DUNA:
            agregarTileDeDuna(tipo_textura, coords);
            break;
        case ESPECIA:
            agregarTileDeEspecia(tipo_textura, coords);
            break;
        default:
            throw std::runtime_error("Tipo de terreno invalido.");
    }
}

TileFactorySDL::TileFactorySDL(SDL2pp::Renderer& renderer, std::string& ruta_mapa,
                                TexturasSDL& texturas) :
                                renderer(renderer),
                                textura_base(texturas.obtenerTilesBase()) {
    YAML::Node mapa_config = YAML::LoadFile(ruta_mapa);
    this->ancho = mapa_config["Ancho"].as<uint16_t>();
    this->alto = mapa_config["Alto"].as<uint16_t>();
    // this->ancho = 100;
    // this->alto = 100;
    this->tiles = std::vector<TileSDL>();
    for (uint32_t i = 0; i < alto; i++) {
		for (uint32_t j = 0; j < ancho; j++){
			Coordenadas coords(j, i);
            // TODO: implementar YAML
            uint8_t tipo_terreno = mapa_config["TiposTerrenos"][i][j].as<char>();
            uint16_t tipo_textura = mapa_config["TiposTexturas"][i][j].as<uint16_t>();
            // uint8_t tipo_terreno = 'A';
            // uint16_t tipo_textura = 0;
            agregarTile(tipo_terreno, tipo_textura, coords);
		}
	}
}
std::vector<TileSDL>& TileFactorySDL::obtenerTiles() {
    return this->tiles;
}

uint16_t TileFactorySDL::obtenerAlto() const {
    return this->alto;
}

uint16_t TileFactorySDL::obtenerAncho() const {
    return this->ancho;
}
