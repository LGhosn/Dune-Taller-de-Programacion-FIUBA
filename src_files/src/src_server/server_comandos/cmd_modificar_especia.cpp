#include "cmd_modificar_especia.h"

CmdModificarEspeciaServer::CmdModificarEspeciaServer(uint16_t cantidad_especia):
                                            cantidad_especia(cantidad_especia) {}

void CmdModificarEspeciaServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoModificarEspecia(cantidad_especia);
}
