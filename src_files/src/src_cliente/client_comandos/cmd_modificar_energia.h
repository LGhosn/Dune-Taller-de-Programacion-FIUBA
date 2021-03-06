#ifndef CLIENT_CMD_MODIFICAR_ENERGIA_H
#define CLIENT_CMD_MODIFICAR_ENERGIA_H

#include "client_comando.h"

class CmdModificarEnergiaCliente : public ComandoCliente {
    int16_t cantidad_energia;
public:
    CmdModificarEnergiaCliente(int16_t cantidad_energia);

    virtual bool ejecutar(WorldView& worldView) const override;

    virtual ~CmdModificarEnergiaCliente() = default;
};

#endif // CLIENT_CMD_MODIFICAR_ENERGIA_H
