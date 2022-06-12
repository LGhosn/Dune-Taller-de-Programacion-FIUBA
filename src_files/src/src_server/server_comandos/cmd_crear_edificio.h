#ifndef CMD_CREAR_EDIFICIO_H
#define CMD_CREAR_EDIFICIO_H

#include "server_comando.h"
#include "../../src_common/common_coords.h"

class CmdCrearEdificioServer : public ComandoServer {
    uint8_t id_jugador;
    uint8_t id_edificio;
    uint8_t tipo;
    Coordenadas coords;

public:
    CmdCrearEdificioServer(uint8_t id_jugador, uint8_t id_edificio, uint8_t tipo, Coordenadas& coords);

    virtual void enviarComando(ProtocoloServidor& protocolo) const override;

    virtual ~CmdCrearEdificioServer() = default;
};

#endif
