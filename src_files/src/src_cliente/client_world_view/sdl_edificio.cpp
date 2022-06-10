#include "sdl_edificio.h"

EdificioSDL::EdificioSDL(uint16_t id, JugadorSDL jugador, SDL2pp::Renderer& renderer, SDL2pp::Texture& textura,
Coordenadas& coords, uint16_t alto, uint16_t ancho, int pos_textura_x, int pos_textura_y) :
id(id), jugador(jugador), renderer(renderer), textura(textura), coords(coords), alto(alto), ancho(ancho),
pos_textura_x(pos_textura_x), pos_textura_y(pos_textura_y), pos_x(0), pos_y(0), iter_anterior(0) {}

void EdificioSDL::update(long iter_actual, uint32_t offset_x, uint32_t offset_y) {
    this->pos_x = LARGO_TILE * this->coords.x - offset_x;
    this->pos_y = LARGO_TILE * this->coords.y - offset_y;
}

void EdificioSDL::render() {
    this->renderer.Copy(this->textura,
    SDL2pp::Rect(
        this->pos_textura_x,
        this->pos_textura_y,
        LARGO_TILE * this->ancho, LARGO_TILE * this->alto
    ), SDL2pp::Rect(
        this->pos_x,
        this->pos_y,
        LARGO_TILE * this->ancho,
        LARGO_TILE * this->alto)
    );
}
