#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include <string>
#include <vector>
#include "sdl_tile.h"
#include "sdl_tile_factory.h"
#include "../sdl_texturas.h"

#define ARRIBA 'A'
#define IZQUIERDA 'I'
#define DERECHA 'D'
#define ABAJO 'B'

#define PADDING 100

#define VELOCIDAD 10

class MapaSDL {
	SDL2pp::Renderer& renderer;
	TileFactorySDL tile_factory;
	std::vector<TileSDL>& tiles;
	int ancho, alto;
	int eje_movil_x = 0;
	int eje_movil_y = 0;
	bool moviendose_h = false;
	bool moviendose_v = false;
	char direccion_h = 0;
	char direccion_v = 0;
	float zoom;

	// Constantes
	const uint8_t arriba;
	const uint8_t izquierda;
	const uint8_t derecha;
	const uint8_t abajo;
	const int32_t velocidad_camara;
	const uint32_t ancho_tile;
	const uint32_t largo_tile;
	const uint32_t ancho_vista_mapa;
	const uint32_t largo_vista_mapa;

	int limite_superior() const;
	int limite_inferior() const;
	int limite_izquierdo() const;
	int limite_derecho() const;

	/*
	 * Ajusta la posicion del eje movil en caso de que se haya ido de los
	 * limites permitidos.
	*/
	void ajustarPosicion();

	void updateTiles();

	/*
	 * Determina la posicion del eje movil en base a la coordenadas donde
	 * deberia empezar la camara del cliente.
	*/
	void determinarPosicionInicial(Coordenadas& coords_iniciales);

public:
	explicit MapaSDL(SDL2pp::Renderer& renderer, std::string& nombre_mapa,
					TexturasSDL& texturas, YAML::Node& constantes,
					Coordenadas& coords_iniciales, float zoom_inicial);

	void moverArriba();
	void moverIzquierda();
	void moverAbajo();
	void moverDerecha();
	void dejarDeMoverseHorizontalmente();
	void dejarDeMoverseVerticalmente();

	int obtener_offset_x() const;
	int obtener_offset_y() const;
	Coordenadas obtenerCoords(int pos_movil_x, int pos_movil_y) const;

	void update(float zoom);
	void render();
};

#endif
