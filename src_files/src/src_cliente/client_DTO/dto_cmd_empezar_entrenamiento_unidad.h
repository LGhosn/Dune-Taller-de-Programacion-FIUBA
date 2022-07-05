#ifndef CLIENTE_DTO_CMD_EMPEZAR_ENTRENAMIENTO_UNIDAD_H
#define CLIENTE_DTO_CMD_EMPEZAR_ENTRENAMIENTO_UNIDAD_H

#include <cstdint>
#include "../../src_common/common_coords.h"
struct CmdEmpezarEntrenamientoClienteDTO {
    uint8_t id_unidad;
    uint8_t tipo;
    uint16_t tiempo_construccion;
    Coordenadas coords_spawn;
    uint16_t vida;

    CmdEmpezarEntrenamientoClienteDTO(uint8_t id_unidad, uint8_t tipo, uint16_t tiempo_construccion,
                                    uint16_t x, uint16_t y, uint16_t vida) :
                                        id_unidad(id_unidad),
                                        tipo(tipo),
                                        tiempo_construccion(tiempo_construccion),
                                        coords_spawn(Coordenadas(x,y)),
                                        vida(vida) {};
};

#endif // CLIENTE_DTO_CMD_EMPEZAR_ENTRENAMIENTO_UNIDAD_H
