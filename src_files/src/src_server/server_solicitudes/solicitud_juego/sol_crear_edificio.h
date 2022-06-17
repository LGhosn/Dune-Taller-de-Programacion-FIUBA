#ifndef SOLI_CREAR_EDIFICIO_H
#define SOLI_CREAR_EDIFICIO_H

#include "server_solicitud.h"
#include "../../../src_common/common_coords.h"
#include "../../server_DTO/dto_sol_crear_edificio.h"

class SoliCrearEdificioServer : public SolicitudServer {
    uint8_t id_jugador;
    uint8_t tipo;
    Coordenadas coords;
public:
    SoliCrearEdificioServer(SolicitudCrearEdificioDTO &dto);

    virtual bool ejecutar(Game& game) const override;

    virtual ~SoliCrearEdificioServer() = default;
};

#endif
