#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include "sdl_mapa/sdl_mapa.h"
#include "sdl_edificio/sdl_edificio.h"
#include "sdl_edificio/sdl_edificio_factory.h"
#include "../client_solicitudes/cliente_solicitud.h"
#include "../../src_common/common_coords.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include <list>

#define ZOOM_INICIAL 3.0f
#define ZOOM_MAXIMO 4.0f
#define ZOOM_MINIMO 2.0f
#define ZOOM_PASO 0.1f

class WorldView {
	SDL2pp::Window window;
	SDL2pp::Renderer renderer;
	ColaBloqueante<SolicitudCliente>& cola_solicitudes;
	float zoom;
	MapaSDL mapa;
	std::unordered_map<Coordenadas, EdificioSDL*, HashCoordenadas> edificios;
	std::vector<EdificioSDL*> edificios_seleccionados;
	EdificioFactorySDL edificio_factory;
	long frame_anterior = 0;
	uint8_t id_jugador;

	void deseleccionarEdificios();
	void seleccionarEdificio(EdificioSDL* edificio);

public:
	WorldView(ColaBloqueante<SolicitudCliente>& cola_solicitudes, uint8_t id_jugador, std::string& nombre_mapa);

	void moverMapaArriba();
	void moverMapaIzquierda();
	void moverMapaDerecha();
	void moverMapaAbajo();
	void dejarDeMoverMapaHorizontalmente();
	void dejarDeMoverMapaVerticalmente();
	void zoomIn();
	void zoomOut();

	void crearEdificio(uint16_t id_edificio, uint8_t id_jugador,
						const Coordenadas& coords, uint8_t tipo, uint8_t casa);

	void click_en_mapa(int pos_x, int pos_y);

	void salir();

	// void crearEdificio(uint16_t id, uint8_t id_jugador, const Coordenadas& coords, uint8_t tipo);

	void update(long frame_actual);
	void render();

	~WorldView();
};

#endif
