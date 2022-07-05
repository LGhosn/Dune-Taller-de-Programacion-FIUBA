#ifndef SERVER_SOL_ATACAR_EDIFICIO_H
#define SERVER_SOL_ATACAR_EDIFICIO_H

#include "server_solicitud.h"
#include "../../server_DTO/dto_sol_atacar_unidad.h"

class SolicitudAtacarEdificioServer : public SolicitudServer {
    uint8_t id_jugador_atacante;
    uint8_t id_unidad_atacante;
    uint8_t id_edificio_a_atacar;
public:
    SolicitudAtacarEdificioServer(SolicitudAtacarEdificioDTO &dto);

    virtual bool ejecutar(Game& game) const override;

    virtual ~SolicitudAtacarEdificioServer() = default;
};

#endif // SERVER_SOL_ATACAR_EDIFICIO_H
