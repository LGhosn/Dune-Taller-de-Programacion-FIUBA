#ifndef SERVER_COMANDO_MODIFICAR_ESPECIA_H
#define SERVER_COMANDO_MODIFICAR_ESPECIA_H

#include "server_comando.h"

class CmdModificarEspeciaServer : public ComandoServer {
    uint16_t cantidad_especia;
public:
    CmdModificarEspeciaServer(uint16_t cantidad_especia);

    virtual void enviarComando(ProtocoloServidor& protocolo) const override;

    ~CmdModificarEspeciaServer() = default;
};

#endif // SERVER_COMANDO_MODIFICAR_ESPECIA_H
