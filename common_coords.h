#ifndef COORDS_H
#define COORDS_H
#include <stdint.h>
#include <cstddef>

struct Coordenadas {
	uint16_t x;
	uint16_t y;

	Coordenadas(uint16_t x, uint16_t y);
	Coordenadas();

	bool operator==(const Coordenadas& otra) const;
	bool operator!=(const Coordenadas& otra) const;
	bool operator<(const Coordenadas& otra) const;

	Coordenadas operator+(const Coordenadas& otra) const;

	Coordenadas(const Coordenadas& otra);
    Coordenadas& operator=(const Coordenadas& otra);
};

struct HashCoordenadas {
	std::size_t operator() (const Coordenadas& pos) const noexcept;	
};

#endif
