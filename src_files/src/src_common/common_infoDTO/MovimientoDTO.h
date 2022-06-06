#ifndef COMMON_MOVIMIENTODTO_H
#define COMMON_MOVIMIENTODTO_H

#include "infoDTO.h"
#include <cstdint>

class MovimientoDTO: public InfoDTO {
private:
    uint16_t& id_unidad;
    uint16_t& x;
    uint16_t& y;
public:
    MovimientoDTO(uint16_t& id_unidad, uint16_t& x, uint16_t& y);
    uint16_t& getUnidad() const;
    uint16_t& getX() const;
    uint16_t& getY() const;
};


#endif //COMMON_MOVIMIENTODTO_H
