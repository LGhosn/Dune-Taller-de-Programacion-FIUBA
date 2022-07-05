#ifndef SERVER_CMD_MODIFICAR_VIDA_EDIFICIO_H
#define SERVER_CMD_MODIFICAR_VIDA_EDIFICIO_H

#include "server_comando.h"

class CmdModificarVidaEdificioServer : public ComandoServer {
    uint8_t id_edificio;
    uint8_t unidad_atacante;
    uint16_t vida;
public:
    CmdModificarVidaEdificioServer(uint8_t id_edificio, uint8_t unidad_atacante,
                                    uint16_t vida);

    virtual void enviarComando(ProtocoloServidor& protocolo) const;

    ~CmdModificarVidaEdificioServer() = default;
};

#endif // SERVER_CMD_MODIFICAR_VIDA_EDIFICIO_H
