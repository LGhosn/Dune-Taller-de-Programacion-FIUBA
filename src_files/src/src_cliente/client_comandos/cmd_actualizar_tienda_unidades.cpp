#include "cmd_actualizar_tienda_unidades.h"


CmdActualizarTiendaUnidadesCliente::CmdActualizarTiendaUnidadesCliente(
                                        std::vector<bool> unidades_comprables):
                                        unidades_comprables(unidades_comprables) {}

bool CmdActualizarTiendaUnidadesCliente::ejecutar(WorldView& worldView) const {
    worldView.actualizarTiendaUnidades(unidades_comprables);
    return true;
}
