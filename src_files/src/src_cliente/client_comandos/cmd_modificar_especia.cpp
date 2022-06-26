#include "cmd_modificar_especia.h"

CmdModificarEspeciaServer::CmdModificarEspeciaServer(uint8_t cantidad_especia):
                                                cantidad_especia(cantidad_especia) {}

virtual bool CmdModificarEspeciaServer::ejecutar(WorldView& worldView) const {
    worldView.modificarEspecia(cantidad_especia);
}
