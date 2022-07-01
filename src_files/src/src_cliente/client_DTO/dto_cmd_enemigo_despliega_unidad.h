#ifndef DTO_CMD_ENEMIGO_DESPLIEGA_UNIDAD_H
#define DTO_CMD_ENEMIGO_DESPLIEGA_UNIDAD_H

#include <cstdint>
#include "../../src_common/common_coords.h"

struct CmdEnemigoDespliegaUnidadDTO {
    uint8_t id_unidad;
    uint8_t id_jugador;
    uint8_t tipo_unidad;
    long tiempo_entrenamiento;
    Coordenadas coords_spawn;
    CmdEnemigoDespliegaUnidadDTO(uint8_t id_unidad, uint8_t id_jugador, uint8_t tipo_unidad, long tiempo_entrenamiento, uint16_t x, uint16_t y) :
                             tipo_unidad(tipo_unidad),
                             tiempo_entrenamiento(tiempo_entrenamiento),
                             coords_spawn(Coordenadas(x,y)) {};
};

#endif // DTO_CMD_ENEMIGO_DESPLIEGA_UNIDAD_H
