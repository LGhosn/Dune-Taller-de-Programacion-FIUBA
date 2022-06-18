#include "sdl_tile.h"

TileSDL::TileSDL(SDL2pp::Renderer& renderer, SDL2pp::Texture& textura, Coordenadas& coords,
                int pos_tex_x, int pos_tex_y) :
                renderer(renderer),
                textura(textura),
                origen(pos_tex_x, pos_tex_y, LARGO_TILE, LARGO_TILE),
                coords(coords) {}

void TileSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y, float zoom) {
    destino.SetX(coords.x * LARGO_TILE * zoom - origen_movil_x);
    destino.SetY(LARGO_TILE * coords.y * zoom - origen_movil_y);
    destino.SetW(LARGO_TILE * zoom + 1);
    destino.SetH(LARGO_TILE * zoom + 1);
}

void TileSDL::render() {
    renderer.Copy(textura, origen, destino);
}
