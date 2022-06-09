#include "sdl_edificio.h"

EdificioSDL::EdificioSDL(uint16_t id, JugadorSDL jugador, SDL2pp::Renderer& renderer, SDL2pp::Texture& textura,
Coordenadas& coords, uint16_t alto, uint16_t ancho, int pos_textura_x, int pos_textura_y) :
id(id), jugador(jugador), renderer(renderer), textura(textura), coords(coords), alto(alto), ancho(ancho),
pos_textura_x(pos_textura_x), pos_textura_y(pos_textura_y) {}


