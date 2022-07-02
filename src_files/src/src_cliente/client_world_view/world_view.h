#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include "yaml-cpp/yaml.h"
#include "sdl_mapa/sdl_mapa.h"
#include "sdl_sonidos/sdl_mixer.h"
#include "sdl_sonidos/sdl_sonidos.h"
#include "sdl_color/sdl_colores.h"
#include "sdl_texturas.h"
#include "sdl_unidad/sdl_unidad.h"
#include "sdl_edificio/sdl_edificio.h"
#include "sdl_unidad/sdl_unidad_factory.h"
#include "sdl_edificio/sdl_edificio_factory.h"
#include "sdl_side_menu/sdl_side_menu.h"
#include "../client_solicitudes/cliente_solicitud.h"
#include "../../src_common/common_coords.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include <list>
#include <SDL2pp/SDLMixer.hh>

class WorldView {
	YAML::Node& constantes;
	ColoresSDL colores;
	uint8_t casa;

	// Constantes
	const uint32_t ancho_ventana;
	const uint32_t largo_ventana;
	const uint32_t ancho_menu;
	const float zoom_inicial;
	const float zoom_minimo;
	const float zoom_maximo;
	const float velocidad_zoom;

	SDL2pp::SDL biblioteca_sdl;
	SDL2pp::SDLMixer biblioteca_sdl_mixer;
	SDL2pp::Window window;
	SDL2pp::Renderer renderer;
	MixerSDL mixer;
	TexturasSDL texturas;
	ColaBloqueante<SolicitudCliente>& cola_solicitudes;
	float zoom;
	MapaSDL mapa;
	SideMenuSDL side_menu;
	std::unordered_map<Coordenadas, std::shared_ptr<EdificioSDL>, HashCoordenadas> edificios;
	std::vector<std::shared_ptr<EdificioSDL>> edificios_seleccionados;
    std::vector<std::shared_ptr<UnidadSDL>> unidades_seleccionadas;
    std::map<uint8_t, std::shared_ptr<UnidadSDL>> unidades;
	EdificioFactorySDL edificio_factory;
	UnidadFactorySDL unidad_factory;
	long frame_anterior = 0;
	uint8_t id_jugador;
	InfoPartidaDTO info_partida;

	void deseleccionarEdificios();
	void seleccionarEdificio(std::shared_ptr<EdificioSDL> edificio);
    void seleccionarUnidad(std::shared_ptr<UnidadSDL> edificio);
    void deseleccionarUnidades();

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

	void empezarConstruccionEdificio(uint8_t tipo, uint16_t tiempo_construccion);
	void construccionInvalida();

	void empezarEntrenamiento(uint8_t id_unidad, uint8_t tipo, uint16_t tiempo_construccion, Coordenadas& coords_spawn);

	void empezarAparicionDeUnidad(uint8_t id_jugador,uint8_t id_unidad,uint8_t tipo_unidad,long tiempo_entrenamiento,Coordenadas& coords_spawn);

	void crearEdificio(uint16_t id_edificio, uint8_t id_jugador,
						const Coordenadas& coords, uint8_t tipo, uint8_t casa);

    void moverUnidad(uint8_t id_unidad, char direccion, long tiempo_movimiento);

	void click(uint32_t pos_x, uint32_t pos_y);

	void modificarEspecia(uint16_t cantidad_especia);

	void modificarEnergia(int16_t cantidad_energia);

	void actualizarTiendaEdificios(const std::vector<bool>& edificios_comprables);
	void actualizarTiendaUnidades(const std::vector<bool>& unidades_comprables);

	void salir();

	// void crearEdificio(uint16_t id, uint8_t id_jugador, const Coordenadas& coords, uint8_t tipo);

	void update(long frame_actual);
	void render();
};

#endif
