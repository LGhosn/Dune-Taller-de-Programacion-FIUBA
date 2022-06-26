#include "cmd_modificar_especia.h"

CmdModificarEspeciaServer::CmdModificarEspeciaServer(uint16_t cantidad_especia):
                                                cantidad_especia(cantidad_especia) {}

bool CmdModificarEspeciaServer::ejecutar(WorldView& worldView) const {
    worldView.modificarEspecia(cantidad_especia);
    return true;
}
