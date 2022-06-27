#include "sol_mover_unidad.h"

SolicitudMoverUnidad::SolicitudMoverUnidad(SolicitudMoverUnidadDTO& dto) :
                                                 id_jugador(dto.id_jugador),
                                                 tipo_unidad(dto.tipo_unidad),
                                                 origen(dto.origen),
                                                 destino(dto.destino){}

bool SolicitudMoverUnidad::ejecutar(Game& game) const {
    game.moverUnidad(id_jugador, tipo_unidad, origen, destino);
    return true;
}
