#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include <SDL2pp/SDL2pp.hh>
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
	char direccion_h, direccion_v;
	float zoom;

	int limite_superior() const;
	int limite_inferior() const;
	int limite_izquierdo() const;
	int limite_derecho() const;

	void updateTiles();

public:
	explicit MapaSDL(SDL2pp::Renderer& renderer, std::string ruta_mapa, TexturasSDL& texturas);

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
