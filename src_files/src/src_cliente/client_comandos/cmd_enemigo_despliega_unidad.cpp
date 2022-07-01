#include "cmd_enemigo_despliega_unidad.h"

CmdEnemigoDespliegaUnidadCliente::CmdEnemigoDespliegaUnidadCliente(CmdEnemigoDespliegaUnidadDTO& dto) :
                                                                 id_jugador(dto.id_jugador),
                                                                 id_unidad(dto.id_unidad),
                                                                 tipo_unidad(dto.tipo_unidad),
                                                                 tiempo_entrenamiento(dto.tiempo_entrenamiento),
                                                                 coords_spawn(dto.coords_spawn) {}

bool CmdEnemigoDespliegaUnidadCliente::ejecutar(WorldView& wordView) const {
    // wordView.despliegaUnidadEnemiga(id_jugador, id_unidad, tipo_unidad, tiempo_entrenamiento, coords_spawn);
    return true;
}
