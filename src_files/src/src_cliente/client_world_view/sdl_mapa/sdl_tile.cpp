#include "sdl_tile.h"

TileSDL::TileSDL(SDL2pp::Renderer& renderer, SDL2pp::Texture& textura, Coordenadas& coords,
                YAML::Node& constantes) :
                renderer(renderer),
                textura(textura),
                origen(0, 0, textura.GetWidth(), textura.GetHeight()),
                coords(coords),
                ancho_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Ancho"].as<uint8_t>()),
                largo_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Largo"].as<uint8_t>()) {}

void TileSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, float zoom) {
    destino.SetX(coords.x * ancho_tile * zoom - origen_movil_x);
    destino.SetY(largo_tile * coords.y * zoom - origen_movil_y);
    destino.SetW(ancho_tile * zoom + 1);
    destino.SetH(largo_tile * zoom + 1);
}

void TileSDL::render() {
    renderer.Copy(textura, origen, destino);
}
