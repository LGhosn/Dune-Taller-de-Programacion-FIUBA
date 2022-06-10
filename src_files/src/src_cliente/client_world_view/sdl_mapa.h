#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include <SDL2pp/SDL2pp.hh>
#include <string>
#include <vector>
#include "sdl_tile.h"
#include "sdl_tile_factory.h"

#define ARRIBA 'A'
#define IZQUIERDA 'I'
#define DERECHA 'D'
#define ABAJO 'B'

#define ANCHO_VENTANA 1024
#define LARGO_VENTANA 768

#define PADDING 100

#define PASO 6

class MapaSDL {
	SDL2pp::Renderer& renderer;
	TileFactorySDL tile_factory;
	std::vector<TileSDL>& tiles;
	int ancho, alto;
	int pos_x, pos_y;
	bool moviendose_h, moviendose_v;
	char direccion_h, direccion_v;
	float zoom;

	int limite_superior() const;
	int limite_inferior() const;
	int limite_izquierdo() const;
	int limite_derecho() const;

	void updateTiles();

public:
	explicit MapaSDL(SDL2pp::Renderer& renderer, std::string ruta_mapa, float zoom);

	void moverArriba();
	void moverIzquierda();
	void moverAbajo();
	void moverDerecha();
	void dejarDeMoverseHorizontalmente();
	void dejarDeMoverseVerticalmente();

	int obtener_offset_x() const;
	int obtener_offset_y() const;

	void update(float zoom);
	void render();
};

#endif
