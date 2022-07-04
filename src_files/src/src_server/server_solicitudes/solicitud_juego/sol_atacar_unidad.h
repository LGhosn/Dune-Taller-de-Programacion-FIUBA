#ifndef SERVER_SOL_ATACAR_UNIDAD_H
#define SERVER_SOL_ATACAR_UNIDAD_H

#include "server_solicitud.h"
#include "../../server_DTO/dto_sol_atacar_unidad.h"

class SolicitudAtacarUnidadServer : public SolicitudServer {
    uint8_t id_jugador_atacante;
    uint8_t id_unidad_atacante;
    uint8_t id_unidad_a_atacar;
    const Coordenadas coords_a_atacar;
public:
    SolicitudAtacarUnidadServer(SolicitudAtacarUnidadDTO &dto);

    virtual bool ejecutar(Game& game) const override;

    virtual ~SolicitudAtacarUnidadServer() = default;
};

#endif // SERVER_SOL_ATACAR_UNIDAD_H
