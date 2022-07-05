#ifndef SOL_ATACAR_EDIFICIO_DTO_H
#define SOL_ATACAR_EDIFICIO_DTO_H

#include "../../src_common/common_coords.h"

struct SolicitudAtacarEdificioDTO {
    uint8_t id_jugador_atacante;
    uint8_t id_unidad_atacante;
    uint8_t id_edificio_a_atacar;

    SolicitudAtacarEdificioDTO(uint8_t id_jugador_atacante, uint8_t id_unidad_atacante, uint8_t id_edificio_a_atacar) :
                                id_jugador_atacante(id_jugador_atacante),
                                id_unidad_atacante(id_unidad_atacante),
                                id_edificio_a_atacar(id_edificio_a_atacar) {};
};

#endif // SOL_ATACAR_EDIFICIO_DTO_H
