#include "world_view.h"
#include <functional>

WorldView::WorldView(SDL2pp::Texture& mapa_textura) : mapa(mapa_textura) {}

void WorldView::moverMapaArriba() {
	this->mapa.moverArriba();
}

void WorldView::moverMapaIzquierda() {
	this->mapa.moverIzquierda();
}

void WorldView::moverMapaDerecha() {
	this->mapa.moverDerecha();
}

void WorldView::moverMapaAbajo() {
	this->mapa.moverAbajo();
}

void WorldView::update(float tiempo_transcurrido) {
	this->mapa.update(tiempo_transcurrido);
}

void WorldView::render(SDL2pp::Renderer& renderer) {
	this->mapa.render(renderer);
}
