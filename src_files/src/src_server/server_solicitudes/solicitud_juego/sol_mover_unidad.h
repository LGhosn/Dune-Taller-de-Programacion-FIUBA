#ifndef SOL_MOVER_UNIDAD_H
#define SOL_MOVER_UNIDAD_H

#include "server_solicitud.h"
#include "../../../src_common/common_coords.h"
#include "../../server_DTO/dto_sol_mover_unidad.h"

class SolicitudMoverUnidad : public SolicitudServer {
private:
    uint16_t id_jugador;
    uint16_t tipo_unidad;
    Coordenadas& origen;
    Coordenadas& destino;

public:
    SolicitudMoverUnidad(SolicitudMoverUnidadDTO& dto);
    virtual bool ejecutar(Game& game) const override;
    virtual ~SolicitudMoverUnidad() = default;
};

#endif // SOL_MOVER_UNIDAD_H
