#include "cmd_actualizar_tienda_unidades.h"

CmdActualizarTiendaUnidadesServer::CmdActualizarTiendaUnidadesServer(
                                std::vector<bool> unidades_comprables) :
                                unidades_comprables(unidades_comprables) {}

void CmdActualizarTiendaUnidadesServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoActualizarTiendaUnidades(unidades_comprables);
}
