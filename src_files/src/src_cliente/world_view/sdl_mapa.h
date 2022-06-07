#ifndef SDL_MAPA_H
#define SDL_MAPA_H

#include <SDL2pp/SDL2pp.hh>
#include <string>
#include <list>
#include "sdl_tile.h"

#define ARRIBA 'A'
#define IZQUIERDA 'I'
#define DERECHA 'D'
#define ABAJO 'B'

#define ANCHO_VENTANA 1024
#define LARGO_VENTANA 768

#define PADDING 200

#define PASO 6

class MapaSDL {
	SDL2pp::Renderer& renderer;
	std::list<TileSDL> tiles;
	int largo_mapa;
	int ancho_mapa;
	int pos_x, pos_y;
	bool moviendose_h, moviendose_v;
	char direccion_h, direccion_v;

	int limite_superior() const;
	int limite_inferior() const;
	int limite_izquierdo() const;
	int limite_derecho() const;

	void updateTiles();

public:
	explicit MapaSDL(SDL2pp::Renderer& renderer, std::string ruta_mapa);

	void moverArriba();
	void moverIzquierda();
	void moverAbajo();
	void moverDerecha();
	void dejarDeMoverseHorizontalmente();
	void dejarDeMoverseVerticalmente();

	int obtener_offset_x() const;
	int obtener_offset_y() const;

	void update();
	void render();
};

#endif
