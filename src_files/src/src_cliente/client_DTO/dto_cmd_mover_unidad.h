#ifndef CLIENTE_CMD_MOVER_UNIDAD_DTO_H
#define CLIENTE_CMD_MOVER_UNIDAD_DTO_H

#include <cstdint>

struct CmdMoverUnidadClienteDTO {
    char direccion;
    uint8_t id_unidad;
    long tiempo;
    CmdMoverUnidadClienteDTO(char direccion, uint8_t id_unidad, long tiempo) :
                            direccion(direccion),
                            id_unidad(id_unidad),
                            tiempo(tiempo) {};
};

#endif // CLIENTE_CMD_MOVER_UNIDAD_DTO_H
