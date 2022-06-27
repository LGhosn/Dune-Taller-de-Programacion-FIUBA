#ifndef DTO_SOL_COMPRAR_UNIDAD_H
#define DTO_SOL_COMPRAR_UNIDAD_H

#include "../../src_common/common_coords.h"

struct SolicitudComprarUnidadDTO {
    uint8_t id_jugador;
    uint8_t tipo;

    SolicitudComprarUnidadDTO(uint8_t id_jugador, uint8_t tipo) :
                                id_jugador(id_jugador),
                                tipo(tipo) {};
};

#endif
