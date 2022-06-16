#include "cmd_crear_edificio.h"

CmdCrearEdificioServer::CmdCrearEdificioServer(uint8_t id_jugador, uint8_t id_edificio, uint8_t tipo,
                                                const Coordenadas& coords, uint8_t casa):
                                                id_jugador(id_jugador),
                                                id_edificio(id_edificio),
                                                tipo(tipo),
                                                coords(coords),
                                                casa(casa) {}

void CmdCrearEdificioServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoCrearEdificio(id_jugador, id_edificio, tipo, this->coords, casa);
}
