#include "sol_crear_edificio.h"

SoliCrearEdificioServer::SoliCrearEdificioServer(uint16_t id_jugador, uint16_t tipo, Coordenadas& coords) :
                            id_jugador(id_jugador),
                            tipo(tipo),
                            coords(coords) {}

bool SoliCrearEdificioServer::ejecutar(Game& game) const {
    game.crearEdificio(id_jugador, tipo, this->coords);
    return true;
}