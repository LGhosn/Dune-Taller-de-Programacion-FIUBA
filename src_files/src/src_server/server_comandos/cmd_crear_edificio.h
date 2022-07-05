#ifndef CMD_CREAR_EDIFICIO_H
#define CMD_CREAR_EDIFICIO_H

#include "server_comando.h"
#include "../../src_common/common_coords.h"

class CmdCrearEdificioServer : public ComandoServer {
    uint8_t id_jugador;
    uint8_t id_edificio;
    uint8_t tipo;
    Coordenadas coords;
    uint8_t casa;
    uint16_t vida;

public:
    CmdCrearEdificioServer(uint8_t id_jugador, uint8_t id_edificio, uint8_t tipo,
                            Coordenadas& coords, uint8_t casa, uint16_t vida);

    virtual void enviarComando(ProtocoloServidor& protocolo) const override;

    virtual ~CmdCrearEdificioServer() = default;
};

#endif
