#ifndef DTO_CMD_ENEMIGO_DESPLIEGA_UNIDAD_H
#define DTO_CMD_ENEMIGO_DESPLIEGA_UNIDAD_H

#include <cstdint>
#include "../../src_common/common_coords.h"

struct CmdEnemigoDespliegaUnidadDTO {
    uint8_t id_unidad;
    uint8_t id_jugador;
    uint8_t tipo_unidad;
    uint16_t tiempo_entrenamiento;
    Coordenadas coords_spawn;
    CmdEnemigoDespliegaUnidadDTO(uint8_t id_unidad, uint8_t id_jugador, uint8_t tipo_unidad, uint16_t tiempo_entrenamiento, uint16_t x, uint16_t y) :
                            id_unidad(id_unidad),
                            id_jugador(id_jugador),
                            tipo_unidad(tipo_unidad),
                            tiempo_entrenamiento(tiempo_entrenamiento),
                            coords_spawn(Coordenadas(x,y)) {};
};

#endif // DTO_CMD_ENEMIGO_DESPLIEGA_UNIDAD_H
