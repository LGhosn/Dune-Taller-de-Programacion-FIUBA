#include "cmd_modificar_energia.h"

CmdModificarEnergiaServer::CmdModificarEnergiaServer(int16_t cantidad_energia) :
                                                    cantidad_energia(cantidad_energia) {}

void CmdModificarEnergiaServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoModificarEnergia(cantidad_energia);
}
