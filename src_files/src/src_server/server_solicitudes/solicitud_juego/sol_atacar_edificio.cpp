#include "sol_atacar_edificio.h"

SolicitudAtacarEdificioServer::SolicitudAtacarEdificioServer(SolicitudAtacarEdificioDTO& dto):
                                                    id_jugador_atacante(dto.id_jugador_atacante),
                                                    id_unidad_atacante(dto.id_unidad_atacante),
                                                    id_edificio_a_atacar(dto.id_edificio_a_atacar) {}

bool SolicitudAtacarEdificioServer::ejecutar(Game& game) const {
    game.atacarEdificio(id_jugador_atacante, id_unidad_atacante, id_edificio_a_atacar);
    return true;
}
