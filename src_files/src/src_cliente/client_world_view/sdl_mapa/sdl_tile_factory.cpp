#include "sdl_tile_factory.h"
#include "yaml-cpp/yaml.h"
#include <exception>

void TileFactorySDL::agregarTile(uint8_t tipo_terreno, uint16_t tipo_textura, Coordenadas& coords) {
    tiles.emplace_back(renderer, texturas.obtenerTexTile(tipo_terreno, tipo_textura),
                        coords, constantes);
}

TileFactorySDL::TileFactorySDL(SDL2pp::Renderer& renderer, std::string& nombre_mapa,
                                TexturasSDL& texturas,YAML::Node& constantes) :
                                constantes(constantes),
                                renderer(renderer),
                                texturas(texturas) {
    std::stringstream ruta_mapa;
    ruta_mapa << RESOURCE_PATH << "/maps/" << nombre_mapa << ".yaml";
    YAML::Node mapa_config = YAML::LoadFile(ruta_mapa.str());
    this->ancho = mapa_config["Ancho"].as<uint16_t>();
    this->alto = mapa_config["Alto"].as<uint16_t>();
    this->tiles = std::vector<TileSDL>();
    for (uint32_t i = 0; i < alto; i++) {
		for (uint32_t j = 0; j < ancho; j++){
			Coordenadas coords(j, i);
            uint8_t tipo_terreno = mapa_config["TiposTerrenos"][i][j].as<uint16_t>();
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
