#include "cmd_empezar_partida.h"

CmdEmpezarPartida::CmdEmpezarPartida(InfoPartidaDTO& info_partida) :
                                    info_partida(info_partida) {}

void CmdEmpezarPartida::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComienzoDePartida(info_partida);
}
