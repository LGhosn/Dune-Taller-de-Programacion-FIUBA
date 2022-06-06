#include "MovimientoDTO.h"

MovimientoDTO::MovimientoDTO(uint16_t& id_unidad, uint16_t& x, uint16_t& y) :
                            id_unidad(id_unidad), x(x), y(y) {}

uint16_t& MovimientoDTO::getUnidad() const {
    return this->id_unidad;
}

uint16_t& MovimientoDTO::getX() const {
    return this->x;
}

uint16_t& MovimientoDTO::getY() const {
    return this->y;
}