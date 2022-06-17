#include "sol_crear_edificio.h"

SoliCrearEdificioServer::SoliCrearEdificioServer(SolicitudCrearEdificioDTO& dto) :
                                                id_jugador(dto.id_jugador),
                                                tipo(dto.tipo),
                                                coords(dto.coords) {}

bool SoliCrearEdificioServer::ejecutar(Game& game) const {
    game.crearEdificio(id_jugador, tipo, coords);
    return true;
}
