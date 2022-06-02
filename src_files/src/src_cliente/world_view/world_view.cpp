#include "world_view.h"
#include <functional>

WorldView::WorldView() : 
window("Dune 2000", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_VENTANA, LARGO_VENTANA, 0),
renderer(window, -1, SDL_RENDERER_ACCELERATED), mapa(renderer) {}

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
	this->mapa.update();
}

void WorldView::render(long frame) {
	this->renderer.Clear();
	this->mapa.render(frame);
	this->renderer.Present();
}
