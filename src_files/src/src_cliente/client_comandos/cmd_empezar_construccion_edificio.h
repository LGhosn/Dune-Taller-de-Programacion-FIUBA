#ifndef CLIENT_CMD_EMPEZAR_CONSTRUCCION_EDIFICIO_H
#define CLIENT_CMD_EMPEZAR_CONSTRUCCION_EDIFICIO_H

#include "client_comando.h"

class CmdEmpezarConstruccionEdificioCliente : public ComandoCliente {
    uint8_t tipo;
    uint16_t tiempo_construccion;
public:
    CmdEmpezarConstruccionEdificioCliente(uint8_t tipo, uint16_t tiempo_construccion);

    virtual bool ejecutar(WorldView& worldView) const override;

    ~CmdEmpezarConstruccionEdificioCliente() = default;
};

#endif // CLIENT_CMD_EMPEZAR_CONSTRUCCION_EDIFICIO_H
