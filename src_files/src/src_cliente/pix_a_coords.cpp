#include "pix_a_coords.h"

PixACoords::PixACoords(uint16_t x, uint16_t y) : x(x / LARGO_TILE), y(y / LARGO_TILE) {}

uint16_t PixACoords::get_x() {
    return this->x;
}

uint16_t PixACoords::get_y() {
    return this->y;
}
