#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include "sdl_mapa.h"

class WorldView {
	MapaSDL mapa;

public:
	WorldView(SDL2pp::Texture& mapa_textura);

	void moverMapaArriba();
	void moverMapaIzquierda();
	void moverMapaDerecha();
	void moverMapaAbajo();

	void update(float tiempo_transcurrido);
	void render(SDL2pp::Renderer& renderer, long frame);
};

#endif
