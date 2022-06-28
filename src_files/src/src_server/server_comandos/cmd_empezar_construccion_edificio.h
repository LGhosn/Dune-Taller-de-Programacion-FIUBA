#ifndef SERVER_CMD_EMPEZAR_CONSTRUCCION_EDIFICIO_H
#define SERVER_CMD_EMPEZAR_CONSTRUCCION_EDIFICIO_H

#include "server_comando.h"

class CmdEmpezarConstruccionEdificioServer : public ComandoServer {
    uint8_t tipo_edificio;
    uint16_t tiempo_construccion;
public:
    CmdEmpezarConstruccionEdificioServer(uint8_t tipo_edificio,
                                        uint16_t tiempo_construccion);

    virtual void enviarComando(ProtocoloServidor& protocolo) const override;

    ~CmdEmpezarConstruccionEdificioServer() = default;
};

#endif // SERVER_CMD_EMPEZAR_CONSTRUCCION_EDIFICIO_H
