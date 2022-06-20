#include "sdl_mapa.h"
#include <functional>
#include <iostream>

	int MapaSDL::limite_superior() const {
		return 0;
	}

	int MapaSDL::limite_inferior() const {
		return (this->alto * LARGO_TILE) * zoom - LARGO_VISTA_MAPA;
	}

	int MapaSDL::limite_izquierdo() const {
		return 0;
	}

	int MapaSDL::limite_derecho() const {
		return (this->ancho * LARGO_TILE) * zoom - ANCHO_VISTA_MAPA;
	}

	void MapaSDL::updateTiles() {
		for (auto& tile : tiles) {
			tile.update(this->eje_movil_x, this->eje_movil_y, zoom);
		}
	}

MapaSDL::MapaSDL(SDL2pp::Renderer& renderer, std::string ruta_mapa, TexturasSDL& texturas,
				YAML::Node& constantes) :
				constantes(constantes),
				renderer(renderer),
				tile_factory(renderer, ruta_mapa, texturas, constantes),
				tiles(tile_factory.obtenerTiles()),
				ancho(tile_factory.obtenerAncho()),
				alto(tile_factory.obtenerAlto()) {}

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
	uint16_t coord_x = (pos_movil_x+ this->eje_movil_x) / (LARGO_TILE * zoom);
	uint16_t coord_y = (pos_movil_y + this->eje_movil_y) / (LARGO_TILE * zoom);
	return Coordenadas(coord_x, coord_y);
}

void MapaSDL::update(float zoom) {
	this->zoom = zoom;
	if (this->moviendose_h) {
		switch(this->direccion_h) {
			case IZQUIERDA:
				if (this->eje_movil_x > this->limite_izquierdo() + VELOCIDAD) {
					this->eje_movil_x -= VELOCIDAD;
				} else {
					this->dejarDeMoverseHorizontalmente();
				}
				break;
			case DERECHA:
				if (this->eje_movil_x < this->limite_derecho() - VELOCIDAD) {
					this->eje_movil_x += VELOCIDAD;
				} else {
					this->dejarDeMoverseHorizontalmente();
				}
				break;
		}
	}
	if (this->moviendose_v) {
		switch(this->direccion_v) {
			case ARRIBA:
				if (this->eje_movil_y > this->limite_superior() + VELOCIDAD) {
					this->eje_movil_y -= VELOCIDAD;
				} else {
					this->dejarDeMoverseVerticalmente();
				}
				break;
			case ABAJO:
				if (this->eje_movil_y < this->limite_inferior() - VELOCIDAD) {
					this->eje_movil_y += VELOCIDAD;
				} else {
					this->dejarDeMoverseVerticalmente();
				}
				break;
		}
	}
	if (this->eje_movil_x < this->limite_izquierdo()) {
		this->eje_movil_x = this->limite_izquierdo();
	} else if (this->eje_movil_x > this->limite_derecho()) {
		this->eje_movil_x = this->limite_derecho();
	}
	if (this->eje_movil_y < this->limite_superior()) {
		this->eje_movil_y = this->limite_superior();
	} else if (this->eje_movil_y > this->limite_inferior()) {
		this->eje_movil_y = this->limite_inferior();
	}
	this->updateTiles();
}

void MapaSDL::render() {
	for (unsigned long i = 0; i < tiles.size(); i++)
		tiles[i].render();
}
