#ifndef CLIENTE_CMD_MOVER_UNIDAD_DTO_H
#define CLIENTE_CMD_MOVER_UNIDAD_DTO_H

#include <cstdint>

struct CmdMoverUnidadClienteDTO {
    uint8_t direccion;
    uint8_t id_unidad;
    uint16_t tiempo;
    CmdMoverUnidadClienteDTO(uint8_t direccion, uint8_t id_unidad, uint16_t tiempo) :
                            direccion(direccion),
                            id_unidad(id_unidad),
                            tiempo(tiempo) {};
};

#endif // CLIENTE_CMD_MOVER_UNIDAD_DTO_H
