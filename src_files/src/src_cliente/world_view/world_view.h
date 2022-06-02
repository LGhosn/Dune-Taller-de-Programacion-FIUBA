#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include "sdl_mapa.h"

class WorldView {
	SDL2pp::Window window;
	SDL2pp::Renderer renderer;
	MapaSDL mapa;

public:
	WorldView();

	void moverMapaArriba();
	void moverMapaIzquierda();
	void moverMapaDerecha();
	void moverMapaAbajo();

	void update(float tiempo_transcurrido);
	void render(long frame);
};

#endif
