#ifndef SOL_CREAR_EDIFICIO_H
#define SOL_CREAR_EDIFICIO_H

#include "server_solicitud.h"
#include "../../src_common/common_coords.h"

class SoliCrearEdificioServer : SolicitudServer {
    uint16_t id_jugador;
    uint16_t tipo;
    Coordenadas coords;
public:
    SoliCrearEdificioServer(uint16_t id_jugador, uint16_t tipo, Coordenadas& coords);

    virtual bool ejecutar(Game& game) const override;

    virtual ~SoliCrearEdificioServer() = default;
};

#endif
