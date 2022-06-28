#ifndef SERVER_SOL_COMPRAR_EDIFICIO_DTO_H
#define SERVER_SOL_COMPRAR_EDIFICIO_DTO_H

#include <cstdint>

struct SolComprarEdificioDTO {
    uint8_t id_jugador;
    uint8_t tipo;

    SolComprarEdificioDTO(uint8_t id_jugador, uint8_t tipo) :
                            id_jugador(id_jugador), tipo(tipo) {};
};

#endif // SERVER_SOL_COMPRAR_EDIFICIO_DTO_H
