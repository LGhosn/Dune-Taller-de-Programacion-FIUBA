#include "pix_a_coords.h"

#define ANCHO_COORD 8
#define ALTO_COORD 8


PixACoords::PixACoords(uint16_t x, uint16_t y) : x(x / ANCHO_COORD), y(y / ALTO_COORD) {}

uint16_t PixACoords::get_x() {
    return this->x;
}

uint16_t PixACoords::get_y() {
    return this->y;
}
