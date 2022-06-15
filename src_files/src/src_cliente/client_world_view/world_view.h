#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include "sdl_mapa/sdl_mapa.h"
#include "sdl_edificio/sdl_edificio.h"
#include "sdl_edificio/sdl_edificio_factory.h"
#include "../../src_common/common_coords.h"
#include <list>

#define ZOOM_INICIAL 1.0f
#define ZOOM_MAXIMO 4.0f
#define ZOOM_MINIMO 1.0f
#define ZOOM_PASO 0.1f

class WorldView {
	SDL2pp::Window window;
	SDL2pp::Renderer renderer;
	float zoom;
	MapaSDL mapa;
	std::unordered_map<Coordenadas, EdificioSDL*, HashCoordenadas> edificios;
	EdificioFactorySDL edificio_factory;
	long frame_anterior = 0;

public:
	WorldView();

	void moverMapaArriba();
	void moverMapaIzquierda();
	void moverMapaDerecha();
	void moverMapaAbajo();
	void dejarDeMoverMapaHorizontalmente();
	void dejarDeMoverMapaVerticalmente();
	void zoomIn();
	void zoomOut();

	void crearEdificio(uint16_t id_edificio, uint8_t id_jugador, uint8_t casa,
						const Coordenadas& coords, uint8_t tipo);

	void click_en_mapa(int pos_x, int pos_y);

	void salir();

	// void crearEdificio(uint16_t id, uint8_t id_jugador, const Coordenadas& coords, uint8_t tipo);

	void update(long frame_actual);
	void render();

	~WorldView();
};

#endif
