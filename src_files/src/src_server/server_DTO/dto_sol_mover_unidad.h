#ifndef DTO_SOL_MOVER_UNIDAD_H
#define DTO_SOL_MOVER_UNIDAD_H

#include "../../src_common/common_coords.h"

struct SolicitudMoverUnidadDTO {
    uint16_t id_jugador;
    uint8_t tipo_unidad;
    Coordenadas& origen;
    Coordenadas& destino;

    SolicitudMoverUnidadDTO(uint16_t id_jugador, uint8_t tipo_unidad, Coordenadas& origen, Coordenadas& destino) :
                                 id_jugador(id_jugador),
                                 tipo_unidad(tipo_unidad),
                                 origen(origen),
                                 destino(destino) {};
};

#endif
