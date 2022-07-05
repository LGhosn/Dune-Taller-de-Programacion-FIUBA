#ifndef CLIENTE_CMD_MODIFICAR_VIDA_UNIDAD_DTO_H
#define CLIENTE_CMD_MODIFICAR_VIDA_UNIDAD_DTO_H

#include <cstdint>

struct CmdModificarVidaUnidadClienteDTO {
    uint16_t nueva_cant_vida;
    uint8_t id_unidad;
    CmdModificarVidaUnidadClienteDTO(uint16_t nueva_cant_vida, uint8_t id_unidad):
                            nueva_cant_vida(nueva_cant_vida),
                            id_unidad(id_unidad) {};
};

#endif // CLIENTE_CMD_MODIFICAR_VIDA_UNIDAD_DTO_H
