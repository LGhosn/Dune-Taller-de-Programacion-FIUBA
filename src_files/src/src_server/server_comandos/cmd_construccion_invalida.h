#ifndef CLIENT_CMD_CONSTRUCCION_INVALIDA_H
#define CLIENT_CMD_CONSTRUCCION_INVALIDA_H

#include "server_comando.h"

class CmdConstruccionInvalidaServer : public ComandoServer {
public:
    CmdConstruccionInvalidaServer() = default;

    virtual void enviarComando(ProtocoloServidor& protocolo) const;

    ~CmdConstruccionInvalidaServer() = default;
};

#endif // CLIENT_CMD_CONSTRUCCION_INVALIDA_H
