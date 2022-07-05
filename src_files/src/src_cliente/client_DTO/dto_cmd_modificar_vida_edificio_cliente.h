#ifndef CLIENT_DTO_CMD_MODIFICAR_VIDA_EDIFICIO_H
#define CLIENT_DTO_CMD_MODIFICAR_VIDA_EDIFICIO_H

#include <cstdint>

struct CmdModificarVidaEdificioClienteDTO {
    uint8_t id_edificio;
    uint8_t unidad_atacante;
    uint16_t vida;

    CmdModificarVidaEdificioClienteDTO(uint8_t id_edificio, uint8_t unidad_atacante,
                                        uint16_t vida):
                                        id_edificio(id_edificio),
                                        unidad_atacante(unidad_atacante),
                                        vida(vida) {}
};

#endif // CLIENT_DTO_CMD_MODIFICAR_VIDA_EDIFICIO_H
