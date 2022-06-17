#ifndef DTO_CMD_CREAR_EDIFICIO_H
#define DTO_CMD_CREAR_EDIFICIO_H

#include "../../src_common/common_coords.h"

struct ComandoCrearEdificioDTO {
    uint8_t id_edificio;
    uint8_t id_jugador;
    Coordenadas coords;
    uint8_t tipo;
    uint8_t casa;

    ComandoCrearEdificioDTO(uint8_t id_edificio, uint8_t id_jugador, const Coordenadas& coords,
                            uint8_t tipo, uint8_t casa) :
                            id_edificio(id_edificio),
                            id_jugador(id_jugador),
                            coords(coords),
                            tipo(tipo),
                            casa(casa) {};    
};


#endif
