#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include "sdl_mapa.h"

class WorldView {
	SDL2pp::Window window;
	SDL2pp::Renderer renderer;
	MapaSDL mapa;
	long frame_anterior;

public:
	WorldView();

	void moverMapaArriba();
	void moverMapaIzquierda();
	void moverMapaDerecha();
	void moverMapaAbajo();
	void dejarDeMoverMapaHorizontalmente();
	void dejarDeMoverMapaVerticalmente();

	void update(long frame_actual);
	void render();
};

#endif
