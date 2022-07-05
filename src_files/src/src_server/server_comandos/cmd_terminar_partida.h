#ifndef SERVER_CMD_TERMINAR_PARTIDA_H
#define SERVER_CMD_TERMINAR_PARTIDA_H

#include "server_comando.h"

class CmdTerminarPartidaServer : public ComandoServer {
    uint8_t id_ganador;
public:
    CmdTerminarPartidaServer(uint8_t id_ganador);

    void enviarComando(ProtocoloServidor& protocolo) const;

    ~CmdTerminarPartidaServer() = default;
};

#endif // SERVER_CMD_TERMINAR_PARTIDA_H
