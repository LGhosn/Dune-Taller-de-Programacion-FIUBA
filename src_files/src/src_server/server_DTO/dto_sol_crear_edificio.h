#ifndef DTO_SOL_CREAR_EDIFICIO_H
#define DTO_SOL_CREAR_EDIFICIO_H

#include "../../src_common/common_coords.h"

struct SolicitudCrearEdificioDTO {
    uint8_t id_jugador;
    uint8_t tipo;
    Coordenadas coords;

    SolicitudCrearEdificioDTO(uint8_t id_jugador, uint8_t tipo, Coordenadas& coords) :
                                id_jugador(id_jugador),
                                tipo(tipo),
                                coords(coords) {};
};

#endif
