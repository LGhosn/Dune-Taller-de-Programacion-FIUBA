#ifndef COORDS_H
#define COORDS_H
#include <stdint.h>

struct Coordenadas {
	uint16_t x;
	uint16_t y;

	Coordenadas(uint16_t x, uint16_t y);
	Coordenadas();

	bool operator==(const Coordenadas& otra) const;

	Coordenadas(const Coordenadas& otra);
    Coordenadas& operator=(const Coordenadas& otra);
};

#endif
