#ifndef SERVER_CMD_MODIFICAR_ENERGIA_H
#define SERVER_CMD_MODIFICAR_ENERGIA_H

#include "server_comando.h"

class CmdModificarEnergiaServer : public ComandoServer {
    int16_t cantidad_energia;
    uint16_t tope_energia;
public:
    CmdModificarEnergiaServer(int16_t cantidad_energia, uint16_t tope_energia);

    virtual void enviarComando(ProtocoloServidor& protocolo) const;

    ~CmdModificarEnergiaServer() = default;
};

#endif // SERVER_CMD_MODIFICAR_ENERGIA_H
