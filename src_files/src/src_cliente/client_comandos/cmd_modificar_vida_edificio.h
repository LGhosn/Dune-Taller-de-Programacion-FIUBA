#ifndef CLIENTE_CMD_MODIFICAR_VIDA_EDIFICIO_H
#define CLIENTE_CMD_MODIFICAR_VIDA_EDIFICIO_H

#include "client_comando.h"

class CmdModificarVidaEdificioCliente : public ComandoCliente {
    uint8_t id_edificio;
    uint8_t unidad_atacante;
    uint16_t vida;
public:
    CmdModificarVidaEdificioCliente(uint8_t id_edificio, uint8_t unidad_atacante,
                                    uint16_t vida);

    virtual bool ejecutar(WorldView& worldView) const;

    ~CmdModificarVidaEdificioCliente() = default;
};

#endif // CLIENTE_CMD_MODIFICAR_VIDA_EDIFICIO_H
