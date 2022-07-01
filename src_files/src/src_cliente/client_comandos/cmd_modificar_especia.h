#ifndef COMANDO_CLIENT_MODIFICAR_ESPECIA_H
#define COMANDO_CLIENT_MODIFICAR_ESPECIA_H

#include "client_comando.h"

class CmdModificarEspeciaServer : public ComandoCliente {
    uint16_t cantidad_especia;
public:
    CmdModificarEspeciaServer(uint16_t cantidad_especia);

    virtual bool ejecutar(WorldView& worldView) const override;

    virtual ~CmdModificarEspeciaServer() = default;
};

#endif // COMANDO_CLIENT_MODIFICAR_ESPECIA_H
