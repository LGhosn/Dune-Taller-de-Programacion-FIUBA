#include "cmd_mover_unidad.h"

CmdMoverUnidadServer::CmdMoverUnidadServer(uint16_t id_jugador, char direccion, long tiempo) :
                                                  id_jugador(id_jugador),
                                                  direccion(direccion),
                                                  tiempo(tiempo){}

void CmdMoverUnidadServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarInstruccionMoverUnidad(id_jugador, direccion, tiempo);
}
