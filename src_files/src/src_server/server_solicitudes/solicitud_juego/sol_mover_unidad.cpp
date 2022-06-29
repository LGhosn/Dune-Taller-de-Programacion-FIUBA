#include "sol_mover_unidad.h"

SolicitudMoverUnidad::SolicitudMoverUnidad(SolicitudMoverUnidadDTO& dto) :
                                                 id_unidad(dto.id_unidad),
                                                 destino(dto.destino){}

bool SolicitudMoverUnidad::ejecutar(Game& game) const {
    // game.moverUnidad(id_unidad, destino);
    return true;
}
