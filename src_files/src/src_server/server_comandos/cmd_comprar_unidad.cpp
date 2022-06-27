#include "cmd_comprar_unidad.h"

CmdComprarUnidadServer::CmdComprarUnidadServer(uint16_t id_jugador, uint8_t tipo_unidad) :
                                                 id_jugador(id_jugador),
                                                 tipo_unidad(tipo_unidad) {}

void CmdComprarUnidadServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoComprarUnidad(id_jugador, tipo_unidad);
}
