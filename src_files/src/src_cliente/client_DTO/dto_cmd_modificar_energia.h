#ifndef CLIENTE_CMD_MODIFICAR_ENERGIA_DTO_H
#define CLIENTE_CMD_MODIFICAR_ENERGIA_DTO_H

#include <cstdint>

struct CmdModificarEnergiaDTO {
    int16_t cantidad_energia;
    uint16_t tope_energia;
    CmdModificarEnergiaDTO(int16_t cantidad_energia, uint16_t tope_energia):
                            cantidad_energia(cantidad_energia),
                            tope_energia(tope_energia) {};
};

#endif // CLIENTE_CMD_MODIFICAR_ENERGIA_DTO_H
