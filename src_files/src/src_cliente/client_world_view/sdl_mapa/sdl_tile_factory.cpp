#include "sdl_tile_factory.h"
#include "yaml-cpp/yaml.h"
#include <exception>

void TileFactorySDL::agregarTileDeRoca(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 96, 216, constantes);
}

void TileFactorySDL::agregarTileDeArena(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 8, 8, constantes);
}

void TileFactorySDL::agregarTileDePrecipicio(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 0, 7, constantes);
}

void TileFactorySDL::agregarTileDeCima(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 0, 9, constantes);
}

void TileFactorySDL::agregarTileDeDuna(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 3, 16, constantes);
}

void TileFactorySDL::agregarTileDeEspecia(uint16_t tipo_textura, Coordenadas &coords) {
    tiles.emplace_back(renderer, textura_base, coords, 3, 18, constantes);
}

void TileFactorySDL::agregarTile(uint8_t tipo_terreno, uint16_t tipo_textura, Coordenadas& coords) {
    if (tipo_terreno == roca) {
        agregarTileDeRoca(tipo_textura, coords);
    } else if (tipo_terreno == arena) {
        agregarTileDeArena(tipo_textura, coords);
    } else if (tipo_terreno == precipicio) {
        agregarTileDePrecipicio(tipo_textura, coords);
    } else if (tipo_terreno == cima) {
        agregarTileDeCima(tipo_textura, coords);
    } else if (tipo_terreno == duna) {
        agregarTileDeDuna(tipo_textura, coords);
    } else if (tipo_terreno == especia) {
        agregarTileDeEspecia(tipo_textura, coords);
    } else {
        throw std::runtime_error("Tipo de terreno invalido");
    }
}

TileFactorySDL::TileFactorySDL(SDL2pp::Renderer& renderer, std::string& nombre_mapa,
                                TexturasSDL& texturas,YAML::Node& constantes) :
                                constantes(constantes),
                                renderer(renderer),
                                textura_base(texturas.obtenerTilesBase()),
                                roca(constantes["WorldView"]["Mapa"]["Tiles"]["Tipos"]["Roca"].as<uint8_t>()),
                                arena(constantes["WorldView"]["Mapa"]["Tiles"]["Tipos"]["Arena"].as<uint8_t>()),
                                precipicio(constantes["WorldView"]["Mapa"]["Tiles"]["Tipos"]["Precipicio"].as<uint8_t>()),
                                cima(constantes["WorldView"]["Mapa"]["Tiles"]["Tipos"]["Cima"].as<uint8_t>()),
                                duna(constantes["WorldView"]["Mapa"]["Tiles"]["Tipos"]["Duna"].as<uint8_t>()),
                                especia(constantes["WorldView"]["Mapa"]["Tiles"]["Tipos"]["Especia"].as<uint8_t>()) {
    std::stringstream ruta_mapa;
    ruta_mapa << RESOURCE_PATH << "/maps/" << nombre_mapa << ".yaml";
    YAML::Node mapa_config = YAML::LoadFile(ruta_mapa.str());
    this->ancho = mapa_config["Ancho"].as<uint16_t>();
    this->alto = mapa_config["Alto"].as<uint16_t>();
    this->tiles = std::vector<TileSDL>();
    for (uint32_t i = 0; i < alto; i++) {
		for (uint32_t j = 0; j < ancho; j++){
			Coordenadas coords(j, i);
            uint8_t tipo_terreno = mapa_config["TiposTerrenos"][i][j].as<char>();
            uint16_t tipo_textura = mapa_config["TiposTexturas"][i][j].as<uint16_t>();
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
