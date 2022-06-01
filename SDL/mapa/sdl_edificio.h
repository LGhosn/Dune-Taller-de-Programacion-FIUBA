#ifndef SDL_EDIFICIO_H
#define SDL_EDIFICIO_H

#include "sdl_mapa.h"

class EdificioSDL {
	MapaSDL& mapa;
	SDL2pp::Texture& textura;
	const int pos_x;
	const int pos_y;
	const uint8_t ancho;
	const uint8_t largo;

public:
	EdificioSDL(MapaSDL& mapa, SDL2pp::Texture& textura, int pos_x, int pos_y, uint8_t ancho, uint8_t largo);

	void update();

	void render(SDL2pp::Renderer& renderer);
};

#endif
