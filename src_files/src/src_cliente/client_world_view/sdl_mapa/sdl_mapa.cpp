#include "sdl_mapa.h"
#include <functional>
#include <iostream>

int MapaSDL::limite_superior() const {
	return 0;
}

int MapaSDL::limite_inferior() const {
	return (this->alto * largo_tile) * zoom - largo_vista_mapa;
}

int MapaSDL::limite_izquierdo() const {
	return 0;
}

int MapaSDL::limite_derecho() const {
	return (this->ancho * ancho_tile) * zoom - ancho_vista_mapa;
}

void MapaSDL::ajustarPosicion() {
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
}

void MapaSDL::updateTiles() {
	for (auto& tile : tiles) {
		tile.update(this->eje_movil_x, this->eje_movil_y, zoom);
	}
}

void MapaSDL::determinarPosicionInicial(Coordenadas& coords_iniciales) {
	this->eje_movil_x = coords_iniciales.x * ancho_tile - ancho_vista_mapa / 2;
	this->eje_movil_y = coords_iniciales.y * largo_tile - largo_vista_mapa / 2;
	ajustarPosicion();
}

MapaSDL::MapaSDL(SDL2pp::Renderer& renderer, std::string& nombre_mapa, TexturasSDL& texturas,
				YAML::Node& constantes, Coordenadas& coords_iniciales, float zoom_inicial) :
				renderer(renderer),
				tile_factory(renderer, nombre_mapa, texturas, constantes),
				tiles(tile_factory.obtenerTiles()),
				ancho(tile_factory.obtenerAncho()),
				alto(tile_factory.obtenerAlto()),
				zoom(zoom_inicial),
				arriba(constantes["WorldView"]["Mapa"]["Direcciones"]["Arriba"].as<uint8_t>()),
				izquierda(constantes["WorldView"]["Mapa"]["Direcciones"]["Izquierda"].as<uint8_t>()),
				derecha(constantes["WorldView"]["Mapa"]["Direcciones"]["Derecha"].as<uint8_t>()),
				abajo(constantes["WorldView"]["Mapa"]["Direcciones"]["Abajo"].as<uint8_t>()),
				velocidad_camara(constantes["WorldView"]["Mapa"]["Velocidad"].as<int32_t>()),
				ancho_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Ancho"].as<uint32_t>()),
				largo_tile(constantes["WorldView"]["Mapa"]["Tiles"]["Largo"].as<uint32_t>()),
				ancho_vista_mapa(constantes["WorldView"]["Mapa"]["Ancho"].as<uint32_t>()),
				largo_vista_mapa(constantes["WorldView"]["Ventana"]["Alto"].as<uint32_t>()) {
	determinarPosicionInicial(coords_iniciales);
}

void MapaSDL::moverArriba() {
	if (eje_movil_y > this->limite_superior()) {
		this->direccion_v = arriba;
		this->moviendose_v = true;
	}
}

void MapaSDL::moverIzquierda() {
	if (eje_movil_x > this->limite_izquierdo()) {
		this->direccion_h = izquierda;
		this->moviendose_h = true;
	}
}

void MapaSDL::moverAbajo() {
	if (eje_movil_y < this->limite_inferior()) {
		this->direccion_v = abajo;
		this->moviendose_v = true;
	}
}

void MapaSDL::moverDerecha() {
	if (eje_movil_x < this->limite_derecho()) {
		this->direccion_h = derecha;
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

Coordenadas MapaSDL::obtenerCoords(int pos_movil_x, int pos_movil_y) const {
	uint16_t coord_x = (pos_movil_x + this->eje_movil_x) / (ancho_tile * zoom);
	uint16_t coord_y = (pos_movil_y + this->eje_movil_y) / (largo_tile * zoom);
	return Coordenadas(coord_x, coord_y);
}

void MapaSDL::update(float zoom) {
	this->zoom = zoom;
	if (moviendose_h) {
		if (direccion_h == izquierda) {
			if (this->eje_movil_x > this->limite_izquierdo() + velocidad_camara) {
				this->eje_movil_x -= velocidad_camara;
			} else {
				this->dejarDeMoverseHorizontalmente();
			}
		} else if (direccion_h == derecha) {
			if (this->eje_movil_x < this->limite_derecho() - velocidad_camara) {
				this->eje_movil_x += velocidad_camara;
			} else {
				this->dejarDeMoverseHorizontalmente();
			}
		}
	}
	if (moviendose_v) {
		if (direccion_v == arriba) {
			if (this->eje_movil_y > this->limite_superior() + velocidad_camara) {
				this->eje_movil_y -= velocidad_camara;
			} else {
				this->dejarDeMoverseVerticalmente();
			}
		} else if (direccion_v == abajo) {
			if (this->eje_movil_y < this->limite_inferior() - velocidad_camara) {
				this->eje_movil_y += velocidad_camara;
			} else {
				this->dejarDeMoverseVerticalmente();
			}
		}
	}
	this->ajustarPosicion();
	this->updateTiles();
}

void MapaSDL::render() {
	for (unsigned long i = 0; i < tiles.size(); i++)
		tiles[i].render();
}
