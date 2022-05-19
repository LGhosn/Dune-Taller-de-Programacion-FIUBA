#include "common_coords.h"

Coordenadas::Coordenadas(uint16_t x, uint16_t y) : x(x), y(y) {}

Coordenadas::Coordenadas() : x(0), y(0) {}

bool Coordenadas::operator==(const Coordenadas& otra) const {
	return (this->x == otra.x && this->y == otra.y);
}

Coordenadas::Coordenadas(const Coordenadas& otra) {
	this->x = otra.x;
	this->y = otra.y;
}

Coordenadas& Coordenadas::operator=(const Coordenadas& otra) {
	if (this == &otra)
		return *this;
	this->x = otra.x;
	this->y = otra.y;
	return *this;
}
