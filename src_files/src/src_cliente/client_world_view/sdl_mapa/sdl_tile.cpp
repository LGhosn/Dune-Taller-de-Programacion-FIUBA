#include "sdl_tile.h"

TileSDL::TileSDL(SDL2pp::Renderer& renderer, SDL2pp::Texture& textura, Coordenadas& coords,
int pos_tex_x, int pos_tex_y) : renderer(renderer), textura(textura), pos_movil_x(coords.x * LARGO_TILE + PADDING),
pos_movil_y(coords.y * LARGO_TILE + PADDING),
coords(coords), pos_tex_x(pos_tex_x), pos_tex_y(pos_tex_y) {}

void TileSDL::update(uint32_t origen_movil_x, uint32_t origen_movil_y) {
    pos_movil_x = LARGO_TILE * coords.x - origen_movil_x;
    pos_movil_y =LARGO_TILE * coords.y - origen_movil_y;
}

void TileSDL::render() {
    renderer.Copy(textura,
        SDL2pp::Rect(
            pos_tex_x,
            pos_tex_y,
            LARGO_TILE,
            LARGO_TILE
        ),
        SDL2pp::Rect(
            pos_movil_x,
            pos_movil_y,
            LARGO_TILE,
            LARGO_TILE)
    );
}
