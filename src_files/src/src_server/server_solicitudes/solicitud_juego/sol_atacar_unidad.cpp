#include "sol_atacar_unidad.h"


SolicitudAtacarUnidadServer::SolicitudAtacarUnidadServer(SolicitudAtacarUnidadDTO& dto):
                                                    id_jugador_atacante(dto.id_jugador_atacante),
                                                    id_unidad_atacante(dto.id_unidad_atacante),
                                                    id_unidad_a_atacar(dto.id_unidad_a_atacar){}

bool SolicitudAtacarUnidadServer::ejecutar(Game& game) const {
    game.atacarUnidad(id_jugador_atacante, id_unidad_atacante, id_unidad_a_atacar);
    return true;
}
