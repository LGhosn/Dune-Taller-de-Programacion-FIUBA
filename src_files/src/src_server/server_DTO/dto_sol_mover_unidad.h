#ifndef DTO_SOL_MOVER_UNIDAD_H
#define DTO_SOL_MOVER_UNIDAD_H

#include "../../src_common/common_coords.h"

struct SolicitudMoverUnidadDTO {
    uint8_t id_unidad;
    const Coordenadas& destino;

    SolicitudMoverUnidadDTO(uint8_t id_unidad, const Coordenadas& destino) :
                                 id_unidad(id_unidad),
                                 destino(destino) {};
};

#endif
