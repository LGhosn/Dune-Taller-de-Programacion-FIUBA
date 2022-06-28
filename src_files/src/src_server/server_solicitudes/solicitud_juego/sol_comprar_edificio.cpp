#include "sol_comprar_edificio.h"


SolComprarEdificioServer::SolComprarEdificioServer(uint8_t id_jugador, uint8_t tipo):
                                                    id_jugador(id_jugador), tipo(tipo) {}

bool SolComprarEdificioServer::ejecutar(Game& game) const {
    game.comprarEdificio(id_jugador, tipo);
    return true;
}
