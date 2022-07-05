#include "cmd_terminar_partida.h"

CmdTerminarPartidaServer::CmdTerminarPartidaServer(uint8_t id_ganador):
                                        id_ganador(id_ganador) {}

void CmdTerminarPartidaServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoTerminarPartida(id_ganador);
}
