#include "cmd_actualizar_puntaje.h"

CmdActualizarPuntajeServer::CmdActualizarPuntajeServer(uint8_t id_jugador, uint16_t nuevo_puntaje) :
                                                        id_jugador(id_jugador),
                                                        nuevo_puntaje(nuevo_puntaje) {}

void CmdActualizarPuntajeServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoActualizarPuntaje(id_jugador, nuevo_puntaje);
}
