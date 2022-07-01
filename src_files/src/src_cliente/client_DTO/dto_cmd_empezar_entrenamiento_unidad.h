#ifndef CLIENTE_DTO_CMD_EMPEZAR_ENTRENAMIENTO_UNIDAD_H
#define CLIENTE_DTO_CMD_EMPEZAR_ENTRENAMIENTO_UNIDAD_H

#include <cstdint>
#include "../../src_common/common_coords.h"
struct CmdEmpezarEntrenamientoClienteDTO {
    uint8_t tipo;
    uint16_t tiempo_construccion;
    Coordenadas coords_spawn;

    CmdEmpezarEntrenamientoClienteDTO(uint8_t tipo, uint16_t tiempo_construccion, uint16_t x, uint16_t y) :
                                        tipo(tipo),
                                        tiempo_construccion(tiempo_construccion),
                                        coords_spawn(Coordenadas(x,y)) {};
};

#endif // CLIENTE_DTO_CMD_EMPEZAR_ENTRENAMIENTO_UNIDAD_H
