#ifndef SOL_MOVER_UNIDAD_SERVER_H
#define SOL_MOVER_UNIDAD_SERVER_H

#include "server_solicitud.h"
#include "../../../src_common/common_coords.h"
#include "../../server_DTO/dto_sol_mover_unidad.h"

class SolicitudMoverUnidad : public SolicitudServer {
private:
    uint8_t id_jugador;
    uint8_t id_unidad;
    const Coordenadas destino;

public:
    SolicitudMoverUnidad(SolicitudMoverUnidadDTO& dto);
    virtual bool ejecutar(Game& game) const override;
    virtual ~SolicitudMoverUnidad() = default;
};

#endif // SOL_MOVER_UNIDAD_H
