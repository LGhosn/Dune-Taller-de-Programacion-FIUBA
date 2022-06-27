#include "cmd_mover_unidad.h"

CmdMoverUnidadServer::CmdMoverUnidadServer(uint16_t id_jugador, uint16_t x, uint16_t y) :
                                                  id_jugador(id_jugador),
                                                  x(x),
                                                  y(y) {}

void CmdMoverUnidadServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarInstruccionMoverUnidad(id_jugador, x, y);
}
