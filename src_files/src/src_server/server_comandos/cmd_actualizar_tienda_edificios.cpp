#include "cmd_actualizar_tienda_edificios.h"

CmdActualizarTiendaEdificiosServer::CmdActualizarTiendaEdificiosServer(
                                std::vector<bool> edificios_comprables) :
                                edificios_comprables(edificios_comprables) {}

void CmdActualizarTiendaEdificiosServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoActualizarTiendaEdificios(edificios_comprables);
}
