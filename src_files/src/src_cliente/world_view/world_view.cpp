#include "world_view.h"
#include <functional>

WorldView::WorldView() : 
window("Dune 2000", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_VENTANA, LARGO_VENTANA, 0),
renderer(window, -1, SDL_RENDERER_ACCELERATED), mapa(renderer), frame_anterior(0) {}

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

void WorldView::update(long frame_actual) {
	long frames_transcurridos = frame_actual - this->frame_anterior;
	for (int i = 0; i < frames_transcurridos; i++) {
		this->mapa.update();
	}
	this->frame_anterior = frame_actual;
}

void WorldView::render() {
	this->renderer.Clear();
	this->mapa.render();
	this->renderer.Present();
}
