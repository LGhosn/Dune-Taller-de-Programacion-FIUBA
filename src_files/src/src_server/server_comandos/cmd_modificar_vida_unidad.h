#ifndef SERVER_CMD_MODIFICAR_VIDA_UNIDAD_H
#define SERVER_CMD_MODIFICAR_VIDA_UNIDAD_H

#include "server_comando.h"

class CmdModificarVidaUnidadServer : public ComandoServer {
    uint8_t id_jugador;
    uint16_t vida;
public:
    CmdModificarVidaUnidadServer(uint8_t id_jugador, uint16_t vida);

    virtual void enviarComando(ProtocoloServidor& protocolo) const;

    ~CmdModificarVidaUnidadServer() = default;
};

#endif // SERVER_CMD_MODIFICAR_VIDA_UNIDAD_H
