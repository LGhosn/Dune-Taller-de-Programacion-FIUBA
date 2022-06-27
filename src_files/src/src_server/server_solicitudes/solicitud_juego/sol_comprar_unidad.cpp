#include "sol_comprar_unidad.h"

SolicitudComprarUnidad::SolicitudComprarUnidad(SolicitudComprarUnidadDTO& dto) :
                                                id_jugador(dto.id_jugador),
                                                tipo(dto.tipo) {}

bool SolicitudComprarUnidad::ejecutar(Game& game) const {
    game.comprarUnidad(id_jugador, tipo);
    return true;
}
