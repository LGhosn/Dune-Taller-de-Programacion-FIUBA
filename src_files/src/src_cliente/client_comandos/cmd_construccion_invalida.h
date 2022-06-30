#ifndef CLIENTE_CMD_CONSTRUCCION_INVALIDA_H
#define CLIENTE_CMD_CONSTRUCCION_INVALIDA_H

#include "client_comando.h"

class CmdConstruccionInvalidaCliente : public ComandoCliente {
public:
    CmdConstruccionInvalidaCliente() = default;

    virtual bool ejecutar(WorldView& worldView) const;

    ~CmdConstruccionInvalidaCliente() = default;
};

#endif // CLIENTE_CMD_CONSTRUCCION_INVALIDA_H
