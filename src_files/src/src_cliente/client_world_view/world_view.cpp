#include "world_view.h"
#include "../client_solicitudes/client_sol_crear_edificio.h"
#include <functional>

#define RUTA_MAPA_1 RESOURCE_PATH "/maps/mapa1.yaml"

void WorldView::deseleccionarEdificios() {
	for (auto edificio : edificios_seleccionados) {
		edificio->deseleccionar();
	}
	edificios_seleccionados.clear();
}

void WorldView::seleccionarEdificio(EdificioSDL* edificio) {
	deseleccionarEdificios();
	edificio->seleccionar();
	edificios_seleccionados.push_back(edificio);
}

void WorldView::renderUI() {
	for (auto edificio : edificios_seleccionados) {
		edificio->renderUI();
	}
	this->side_menu.render();
}

WorldView::WorldView(ColaBloqueante<SolicitudCliente>& cola_solicitudes, uint8_t id_jugador) :
					window("Dune 2000", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							ANCHO_VISTA_MAPA + ANCHO_MENU, LARGO_VISTA_MAPA, 0),
					renderer(window, -1, SDL_RENDERER_ACCELERATED),
					texturas(renderer),
					cola_solicitudes(cola_solicitudes),
					zoom(ZOOM_INICIAL),
					mapa(renderer, RUTA_MAPA_1, texturas),
					side_menu(renderer, 0, texturas),			// FIXME: hardcoded
					edificio_factory(renderer, texturas),
					id_jugador(id_jugador) {
	renderer.SetDrawBlendMode(SDL_BLENDMODE_BLEND);
}

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

void WorldView::crearEdificio(uint16_t id_edificio, uint8_t id_jugador,
							const Coordenadas& coords, uint8_t tipo, uint8_t casa) {
	EdificioSDL* edificio = edificio_factory.crearEdificio
												(id_edificio, id_jugador, casa, tipo, coords);
	Coordenadas dimensiones = edificio->obtenerDimensiones();
	for (int i = 0; i < dimensiones.x; i++) {
		for (int j = 0; j < dimensiones.y; j++) {
			Coordenadas coord_actual(coords.x + i, coords.y + j);
			edificios.insert(std::make_pair(coord_actual, edificio));
		}
	}
}

void WorldView::click_en_mapa(int pos_x, int pos_y) {
	Coordenadas coords = mapa.obtenerCoords(pos_x, pos_y);
	if (edificios.find(coords) != edificios.end()) {
		seleccionarEdificio(edificios.at(coords));
	} else {
		SolicitudCrearEdificio* solicitud = new SolicitudCrearEdificio(id_jugador, coords, 0);
		cola_solicitudes.push(solicitud);
		deseleccionarEdificios();
	}
}

void WorldView::salir() {

}

void WorldView::update(long frame_actual) {
	long frames_transcurridos = frame_actual - this->frame_anterior;
	for (int i = 0; i < frames_transcurridos; i++) {
		this->mapa.update(this->zoom);
	}
	for (auto& edificio : this->edificios)
		edificio.second->update(mapa.obtener_offset_x(), mapa.obtener_offset_y(),
								frame_actual, zoom);
	this->frame_anterior = frame_actual;
}

void WorldView::render() {
	this->renderer.Clear();
	// this->renderer.SetScale(this->zoom, this->zoom);
	this->mapa.render();
	for (auto& edificio : this->edificios)
		edificio.second->render();
	this->renderUI();
	this->renderer.Present();
}

WorldView::~WorldView() {
	for (auto& edificio : this->edificios)
		delete edificio.second;
}
