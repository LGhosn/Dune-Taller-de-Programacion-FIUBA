#include "cmd_modificar_vida_unidad.h"

CmdModificarVidaUnidadServer::CmdModificarVidaUnidadServer(uint8_t id_jugador, uint16_t vida):
                                                            id_jugador(id_jugador),
                                                            vida(vida) {}

void CmdModificarVidaUnidadServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoModificarVidaUnidad(id_jugador, vida);
}
