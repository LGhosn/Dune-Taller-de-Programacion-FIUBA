#include "sdl_tile.h"

TileSDL::TileSDL(SDL2pp::Renderer& renderer, SDL2pp::Texture& textura, Coordenadas& coords,
char pos_tex_x, char pos_tex_y) : renderer(renderer), textura(textura),
pos_x(coords.x * LARGO_TILE), pos_y(coords.y * LARGO_TILE),
coords(coords), pos_tex_x(pos_tex_x), pos_tex_y(pos_tex_y) {}

void TileSDL::update(uint32_t offset_x, uint32_t offset_y) {
    pos_x = LARGO_TILE * coords.x - offset_x;
    pos_y = LARGO_TILE * coords.y - offset_y;
}

void TileSDL::render() {
    renderer.Copy(textura,
        SDL2pp::Rect(
            LARGO_TILE * pos_tex_x,
            LARGO_TILE * pos_tex_y,
            LARGO_TILE, LARGO_TILE
        ), SDL2pp::Rect(pos_x, pos_y, LARGO_TILE, LARGO_TILE)
    );
}
