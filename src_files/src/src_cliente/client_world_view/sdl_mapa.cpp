#include "sdl_mapa.h"
#include <functional>
#include <iostream>

	int MapaSDL::limite_superior() const {
		return - PADDING;
	}

	int MapaSDL::limite_inferior() const {
		return this->alto - LARGO_VENTANA + PADDING;
	}

	int MapaSDL::limite_izquierdo() const {
		return - PADDING;
	}

	int MapaSDL::limite_derecho() const {
		return this->ancho - ANCHO_VENTANA + PADDING;
	}

	void MapaSDL::updateTiles() {
		for (auto& tile : tiles) {
			tile.update(this->pos_x, this->pos_y);
		}
	}

MapaSDL::MapaSDL(SDL2pp::Renderer& renderer, std::string ruta_mapa) : renderer(renderer),
tile_factory(renderer, ruta_mapa), tiles(tile_factory.obtenerTiles()), ancho(tile_factory.obtenerAncho()),
alto(tile_factory.obtenerAlto()), pos_x(0), pos_y(0), moviendose_h(false), moviendose_v(false), direccion_h(IZQUIERDA),
direccion_v(ARRIBA) {}

void MapaSDL::moverArriba() {
	if (pos_y > this->limite_superior() && !this->moviendose_v) {
		this->direccion_v = ARRIBA;
		this->moviendose_v = true;
	}
}

void MapaSDL::moverIzquierda() {
	if (pos_x > this->limite_izquierdo() && !this->moviendose_h) {
		this->direccion_h = IZQUIERDA;
		this->moviendose_h = true;
	}
}

void MapaSDL::moverAbajo() {
	if (pos_y < this->limite_inferior() && !this->moviendose_v) {
		this->direccion_v = ABAJO;
		this->moviendose_v = true;
	}
}

void MapaSDL::moverDerecha() {
	if (pos_x < this->limite_derecho() && !this->moviendose_h) {
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
	return this->pos_x;
}

int MapaSDL::obtener_offset_y() const {
	return this->pos_y;
}

void MapaSDL::update() {
	if (this->moviendose_h) {
		switch(this->direccion_h) {
			case IZQUIERDA:
				if (this->pos_x > this->limite_izquierdo()) {
					this->pos_x -= PASO;
					this->updateTiles();
				} else {
					this->dejarDeMoverseHorizontalmente();
				}
				break;
			case DERECHA:
				if (this->pos_x < this->limite_derecho()) {
					this->pos_x += PASO;
					this->updateTiles();
				} else {
					this->dejarDeMoverseHorizontalmente();
				}
				break;
		}
	}

	if (this->moviendose_v) {
		switch(this->direccion_v) {
			case ARRIBA:
				if (this->pos_y > this->limite_superior()) {
					this->pos_y -= PASO;
					this->updateTiles();
				} else {
					this->dejarDeMoverseVerticalmente();
				}
				break;
			case ABAJO:
				if (this->pos_y < this->limite_inferior()) {
					this->pos_y += PASO;
					this->updateTiles();
				} else {
					this->dejarDeMoverseVerticalmente();
				}
				break;
		}
	}
}

void MapaSDL::render() {
	for (int i = 0; i < this->alto; i++) {
		for (int j = 0; j < this->ancho; j++) {
			this->tiles[i * ancho + j].render();
		}
	}
}
