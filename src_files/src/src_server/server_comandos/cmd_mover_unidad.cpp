#include "cmd_mover_unidad.h"

CmdMoverUnidadServer::CmdMoverUnidadServer(uint8_t id_unidad, uint8_t direccion, uint16_t tiempo) :
                                                  id_unidad(id_unidad),
                                                  direccion(direccion),
                                                  tiempo(tiempo){}

void CmdMoverUnidadServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoMoverUnidad(id_unidad, direccion, tiempo);
}
