#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include "sdl_mapa.h"
// #include "sdl_edificio.h"
#include <list>

#define ZOOM_INICIAL 3.5f

class WorldView {
	SDL2pp::Window window;
	SDL2pp::Renderer renderer;
	float zoom;
	MapaSDL mapa;
	// std::list<EdificioSDL> edificios;
	long frame_anterior;

public:
	WorldView();

	void moverMapaArriba();
	void moverMapaIzquierda();
	void moverMapaDerecha();
	void moverMapaAbajo();
	void dejarDeMoverMapaHorizontalmente();
	void dejarDeMoverMapaVerticalmente();

	void salir();

	// void crearEdificio(uint16_t id, uint8_t id_jugador, const Coordenadas& coords, uint8_t tipo);

	void update(long frame_actual);
	void render();
};

#endif
