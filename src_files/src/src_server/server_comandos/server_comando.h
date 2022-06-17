#ifndef SERVER_COMANDO_H
#define SERVER_COMANDO_H

#include "../server_protocolo/server_protocolo.h"

class ComandoServer {
public:
    virtual void enviarComando(ProtocoloServidor& protocolo) const = 0;

    virtual ~ComandoServer() = default;
};

#endif
