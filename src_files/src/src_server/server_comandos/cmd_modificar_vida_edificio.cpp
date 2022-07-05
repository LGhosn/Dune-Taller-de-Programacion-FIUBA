#include "cmd_modificar_vida_edificio.h"

CmdModificarVidaEdificioServer::CmdModificarVidaEdificioServer(uint8_t id_edificio,
                                uint8_t unidad_atacante, uint16_t vida):
                                id_edificio(id_edificio),
                                unidad_atacante(unidad_atacante),
                                vida(vida) {}

void CmdModificarVidaEdificioServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoModificarVidaEdificio(id_edificio, unidad_atacante, vida);
}
