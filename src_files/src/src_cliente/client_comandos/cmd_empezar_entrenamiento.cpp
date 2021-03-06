#include "cmd_empezar_entrenamiento.h"

CmdEmpezarEntrenamientoCliente::CmdEmpezarEntrenamientoCliente(CmdEmpezarEntrenamientoClienteDTO& dto):
                                                    dto(dto) {}

bool CmdEmpezarEntrenamientoCliente::ejecutar(WorldView& worldView) const {
    worldView.empezarEntrenamiento(dto.id_unidad, dto.tipo, dto.tiempo_construccion,
                                    (Coordenadas& )dto.coords_spawn, dto.vida);
    return true;
}
