#include "cmd_mover_unidad.h"

CmdMoverUnidadServer::CmdMoverUnidadServer(uint16_t id_jugador, char direccion) :
                                                  id_jugador(id_jugador),
                                                  direccion(direccion) {}

void CmdMoverUnidadServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarInstruccionMoverUnidad(id_jugador, direccion);
}
