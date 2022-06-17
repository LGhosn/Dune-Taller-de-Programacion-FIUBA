#include "sdl_mapa.h"
#include <functional>
#include <iostream>

	int MapaSDL::limite_superior() const {
		return PASO;
	}

	int MapaSDL::limite_inferior() const {
		return (this->alto * LARGO_TILE) * zoom - LARGO_VENTANA / zoom;
	}

	int MapaSDL::limite_izquierdo() const {
		return PASO;
	}

	int MapaSDL::limite_derecho() const {
		return (this->ancho * LARGO_TILE) * zoom  - ANCHO_VENTANA / zoom;
	}

	void MapaSDL::updateTiles() {
		for (auto& tile : tiles) {
			tile.update(this->eje_movil_x, this->eje_movil_y);
		}
	}

MapaSDL::MapaSDL(SDL2pp::Renderer& renderer, std::string ruta_mapa) : renderer(renderer),
tile_factory(renderer, ruta_mapa), tiles(tile_factory.obtenerTiles()), ancho(tile_factory.obtenerAncho()),
alto(tile_factory.obtenerAlto()), moviendose_h(false), moviendose_v(false), direccion_h(IZQUIERDA),
direccion_v(ARRIBA) {}
void MapaSDL::moverArriba() {
	if (eje_movil_y > this->limite_superior()) {
		this->direccion_v = ARRIBA;
		this->moviendose_v = true;
	}
}

void MapaSDL::moverIzquierda() {
	if (eje_movil_x > this->limite_izquierdo()) {
		this->direccion_h = IZQUIERDA;
		this->moviendose_h = true;
	}
}

void MapaSDL::moverAbajo() {
	if (eje_movil_y < this->limite_inferior()) {
		this->direccion_v = ABAJO;
		this->moviendose_v = true;
	}
}

void MapaSDL::moverDerecha() {
	if (eje_movil_x < this->limite_derecho()) {
		this->direccion_h = DERECHA;
		this->moviendose_h = true;
	}
}

void MapaSDL::dejarDeMoverseHorizontalmente() {
	this->moviendose_h = false;
}

void MapaSDL::dejarDeMoverseVerticalmente() {
	this->moviendose_v = false;
}

int MapaSDL::obtener_offset_x() const {
	return this->eje_movil_x;
}

int MapaSDL::obtener_offset_y() const {
	return this->eje_movil_y;
}

// . . . . . . . . . . .
// . . . . . . . . . . .
// . . . . . . . . . . .
// . . . x . . . . . x x
// . . . . . . o . . . .
// . . . . . . . . . . .
// . . . . . . . . . . .
// . . . x . . . . . x .
// . . . x . . . . . . x
// . . . . . . . . . . .
// . . . . . . . . . . .

Coordenadas MapaSDL::obtenerCoords(int pos_movil_x, int pos_movil_y) const {
	uint16_t coord_x = (pos_movil_x / zoom + this->eje_movil_x) / LARGO_TILE;
	uint16_t coord_y = (pos_movil_y / zoom + this->eje_movil_y) / LARGO_TILE;
	return Coordenadas(coord_x, coord_y);
}

void MapaSDL::update(float zoom) {
	this->zoom = zoom;
	if (this->moviendose_h) {
		switch(this->direccion_h) {
			case IZQUIERDA:
				if (this->eje_movil_x > this->limite_izquierdo()) {
					this->eje_movil_x -= PASO;
				} else {
					this->dejarDeMoverseHorizontalmente();
				}
				break;
			case DERECHA:
				if (this->eje_movil_x < this->limite_derecho()) {
					this->eje_movil_x += PASO;
				} else {
					this->dejarDeMoverseHorizontalmente();
				}
				break;
		}
	}
	if (this->moviendose_v) {
		switch(this->direccion_v) {
			case ARRIBA:
				if (this->eje_movil_y > this->limite_superior()) {
					this->eje_movil_y -= PASO;
				} else {
					this->dejarDeMoverseVerticalmente();
				}
				break;
			case ABAJO:
				if (this->eje_movil_y < this->limite_inferior()) {
					this->eje_movil_y += PASO;
				} else {
					this->dejarDeMoverseVerticalmente();
				}
				break;
		}
	}
	this->updateTiles();
}

void MapaSDL::render() {
	for (unsigned long i = 0; i < tiles.size(); i++)
		tiles[i].render();
}
