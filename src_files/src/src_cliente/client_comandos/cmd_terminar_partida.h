#ifndef CLIENT_CMD_TERMINAR_PARTIDA_H
#define CLIENT_CMD_TERMINAR_PARTIDA_H

#include "client_comando.h"

class CmdTerminarPartidaCliente : public ComandoCliente {
    uint8_t id_ganador;
public:
    CmdTerminarPartidaCliente(uint8_t id_ganador);

    virtual bool ejecutar(WorldView& worldView) const;

    ~CmdTerminarPartidaCliente() = default;
};

#endif // CLIENT_CMD_TERMINAR_PARTIDA_H
