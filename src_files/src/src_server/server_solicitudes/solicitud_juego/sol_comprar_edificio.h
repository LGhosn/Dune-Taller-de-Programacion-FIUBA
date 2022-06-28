#ifndef SERVER_SOL_COMPRAR_EDIFICIO_H
#define SERVER_SOL_COMPRAR_EDIFICIO_H

#include "server_solicitud.h"

class SolComprarEdificioServer : public SolicitudServer {
    uint8_t id_jugador;
    uint8_t tipo;
public:
    SolComprarEdificioServer(uint8_t id_jugador, uint8_t tipo);

    virtual bool ejecutar(Game& game) const override;

    ~SolComprarEdificioServer() = default;
};

#endif // SERVER_SOL_COMPRAR_EDIFICIO_H
