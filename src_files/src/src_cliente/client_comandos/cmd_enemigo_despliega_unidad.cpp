#include "cmd_enemigo_despliega_unidad.h"

CmdEnemigoDespliegaUnidadCliente::CmdEnemigoDespliegaUnidadCliente(CmdEnemigoDespliegaUnidadDTO& dto) :
                                                                 id_jugador(dto.id_jugador),
                                                                 id_unidad(dto.id_unidad),
                                                                 tipo_unidad(dto.tipo_unidad),
                                                                 tiempo_entrenamiento(dto.tiempo_entrenamiento),
                                                                 coords_spawn(dto.coords_spawn) {}

bool CmdEnemigoDespliegaUnidadCliente::ejecutar(WorldView& worldView) const {
    worldView.empezarAparicionDeUnidad(id_unidad, id_jugador, tipo_unidad, false, tiempo_entrenamiento, (Coordenadas&) coords_spawn);
    return true;
}
