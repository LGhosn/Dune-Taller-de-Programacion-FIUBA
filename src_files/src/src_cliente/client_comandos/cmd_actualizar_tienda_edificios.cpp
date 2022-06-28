#include "cmd_actualizar_tienda_edificios.h"


CmdActualizarTiendaEdificiosCliente::CmdActualizarTiendaEdificiosCliente(
                                        std::vector<bool> edificios_comprables):
                                        edificios_comprables(edificios_comprables) {}

bool CmdActualizarTiendaEdificiosCliente::ejecutar(WorldView& worldView) const {
    worldView.actualizarTiendaEdificios(edificios_comprables);
    return true;
}
