#ifndef SOL_ATACAR_UNIDAD_DTO_H
#define SOL_ATACAR_UNIDAD_DTO_H

#include "../../src_common/common_coords.h"

struct SolicitudAtacarUnidadDTO {
    uint8_t id_jugador_atacante;
    uint8_t id_unidad_atacante;
    uint8_t id_unidad_a_atacar;

    SolicitudAtacarUnidadDTO(uint8_t id_jugador_atacante, uint8_t id_unidad_atacante, uint8_t id_unidad_a_atacar) :
                                id_jugador_atacante(id_jugador_atacante),
                                id_unidad_atacante(id_unidad_atacante),
                                id_unidad_a_atacar(id_unidad_a_atacar) {};
};

#endif // SOL_ATACAR_UNIDAD_DTO_H
