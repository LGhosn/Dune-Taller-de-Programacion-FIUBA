#include "world_view.h"
#include <functional>

#define RUTA_MAPA_1 RESOURCE_PATH "/maps/mapa1.yaml"

WorldView::WorldView() : 
window("Dune 2000", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO_VENTANA, LARGO_VENTANA, 0),
renderer(window, -1, SDL_RENDERER_ACCELERATED), zoom(ZOOM_INICIAL), mapa(renderer, RUTA_MAPA_1),
edificio_factory(renderer) {}

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

void WorldView::crearEdificio(uint16_t id_edificio, uint8_t id_jugador, uint8_t casa,
							const Coordenadas& coords, uint8_t tipo) {
	EdificioSDL* edificio = edificio_factory.crearEdificio
												(id_edificio, id_jugador, casa, tipo, coords); 
	edificios.insert(std::make_pair(coords, edificio));
}

// . . . .
// . . . .
// . . . .
// . . . .

void WorldView::click_en_mapa(int pos_x, int pos_y) {
	Coordenadas coords = mapa.obtenerCoords(pos_x, pos_y);
	this->crearEdificio(1, 1, 0, coords, 0);	// temporal
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
	for (auto& edificio : this->edificios)
		edificio.second->update(mapa.obtener_offset_x(), mapa.obtener_offset_y(), frame_actual);
	this->frame_anterior = frame_actual;
}

void WorldView::render() {
	this->renderer.Clear();
	this->renderer.SetScale(this->zoom, this->zoom);
	this->mapa.render();
	for (auto& edificio : this->edificios)
		edificio.second->render();
	this->renderer.Present();
}

WorldView::~WorldView() {
	for (auto& edificio : this->edificios)
		delete edificio.second;
}
