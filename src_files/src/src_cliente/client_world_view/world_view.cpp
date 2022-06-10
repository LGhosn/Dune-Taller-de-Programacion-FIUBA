#include "world_view.h"
#include <functional>

#define RUTA_MAPA_1 RESOURCE_PATH "/maps/mapa1.yaml"

WorldView::WorldView() : 
window("Dune 2000", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_VENTANA, LARGO_VENTANA, 0),
renderer(window, -1, SDL_RENDERER_ACCELERATED), zoom(ZOOM_INICIAL), mapa(renderer, RUTA_MAPA_1, zoom),
frame_anterior(0) {}

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

void WorldView::dejarDeMoverMapaHorizontalmente() {
	this->mapa.dejarDeMoverseHorizontalmente();
}

void WorldView::dejarDeMoverMapaVerticalmente() {
	this->mapa.dejarDeMoverseVerticalmente();
}

void WorldView::zoomIn() {
	if (this->zoom < ZOOM_MAXIMO) {
		this->zoom += ZOOM_PASO;
	}
}

void WorldView::zoomOut() {
	if (this->zoom > ZOOM_MINIMO) {
		this->zoom -= ZOOM_PASO;
	}
}

void WorldView::salir() {

}

// void WorldView::crearEdificio(uint16_t id, uint8_t id_jugador,
// const Coordenadas& coords, uint8_t tipo) {
// 	this->edificios.emplace_back(this->renderer, id, id_jugador, coords, tipo);
// }


void WorldView::update(long frame_actual) {
	long frames_transcurridos = frame_actual - this->frame_anterior;
	for (int i = 0; i < frames_transcurridos; i++) {
		this->mapa.update(this->zoom);
	}
	this->frame_anterior = frame_actual;
}

void WorldView::render() {
	this->renderer.Clear();
	this->mapa.render();
	this->renderer.Present();
}
