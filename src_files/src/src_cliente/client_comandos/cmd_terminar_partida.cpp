#include "cmd_terminar_partida.h"

CmdTerminarPartidaCliente::CmdTerminarPartidaCliente(uint8_t id_ganador):
                                                id_ganador(id_ganador) {}

bool CmdTerminarPartidaCliente::ejecutar(WorldView& worldView) const {
    worldView.terminarPartida(id_ganador);
    return false;
}
