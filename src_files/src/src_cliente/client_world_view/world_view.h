#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include "yaml-cpp/yaml.h"
#include "sdl_mapa/sdl_mapa.h"
#include "sdl_texturas.h"
#include "sdl_edificio/sdl_edificio.h"
#include "sdl_edificio/sdl_edificio_factory.h"
#include "sdl_side_menu/sdl_side_menu.h"
#include "../client_solicitudes/cliente_solicitud.h"
#include "../../src_common/common_coords.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include <list>

#define ZOOM_INICIAL 3.0f
#define ZOOM_MAXIMO 4.0f
#define ZOOM_MINIMO 2.0f
#define ZOOM_PASO 0.1f

class WorldView {
	YAML::Node& constantes;

	// Constantes
	const uint32_t ancho_ventana;
	const uint32_t largo_ventana;
	const uint32_t ancho_menu;
	const float zoom_inicial;
	const float zoom_minimo;
	const float zoom_maximo;
	const float velocidad_zoom;

	SDL2pp::Window window;
	SDL2pp::Renderer renderer;
	TexturasSDL texturas;
	ColaBloqueante<SolicitudCliente>& cola_solicitudes;
	float zoom;
	MapaSDL mapa;
	SideMenuSDL side_menu;
	std::unordered_map<Coordenadas, EdificioSDL*, HashCoordenadas> edificios;
	std::vector<EdificioSDL*> edificios_seleccionados;
	EdificioFactorySDL edificio_factory;
	long frame_anterior = 0;
	uint8_t id_jugador;
	InfoPartidaDTO info_partida;

	void deseleccionarEdificios();
	void seleccionarEdificio(EdificioSDL* edificio);

	void renderUI();

public:
	WorldView(ColaBloqueante<SolicitudCliente>& cola_solicitudes, uint8_t id_jugador,
				InfoPartidaDTO& info_partida, YAML::Node& constantes);

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

	void click_en_mapa(uint32_t pos_x, uint32_t pos_y);

	void salir();

	// void crearEdificio(uint16_t id, uint8_t id_jugador, const Coordenadas& coords, uint8_t tipo);

	void update(long frame_actual);
	void render();

	~WorldView();
};

#endif
