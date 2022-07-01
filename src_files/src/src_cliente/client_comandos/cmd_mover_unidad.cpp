#include "cmd_mover_unidad.h"

CmdMoverUnidadCliente::CmdMoverUnidadCliente(CmdMoverUnidadClienteDTO& dto) :
                                                   id_unidad(dto.id_unidad),
                                                   direccion(dto.direccion),
                                                   tiempo(dto.tiempo){}

bool CmdMoverUnidadCliente::ejecutar(WorldView& worldView) const {
    worldView.moverUnidad(id_unidad, direccion, tiempo);
    return true;
}
