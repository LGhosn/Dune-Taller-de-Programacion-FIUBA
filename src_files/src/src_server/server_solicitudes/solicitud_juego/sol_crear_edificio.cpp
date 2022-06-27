#include "sol_crear_edificio.h"

SolicitudCrearEdificioServer::SolicitudCrearEdificioServer(SolicitudCrearEdificioDTO& dto) :
                                                id_jugador(dto.id_jugador),
                                                tipo(dto.tipo),
                                                coords(dto.coords) {}

bool SolicitudCrearEdificioServer::ejecutar(Game& game) const {
    game.crearEdificio(id_jugador, tipo, coords);
    return true;
}
