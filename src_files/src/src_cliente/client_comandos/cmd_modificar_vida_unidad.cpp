#include "cmd_modificar_vida_unidad.h"

CmdModificarVidaUnidadCliente::CmdModificarVidaUnidadCliente(CmdModificarVidaUnidadClienteDTO& dto) :
                                                            id_unidad(dto.id_unidad),
                                                            nueva_cant_vida(dto.nueva_cant_vida) {}

bool CmdModificarVidaUnidadCliente::ejecutar(WorldView& worldView) const {
    worldView.modificarVidaUnidad(id_unidad, nueva_cant_vida);
    return true;
}
