#ifndef CMD_SALIR_H
#define CMD_SALIR_H

#include "client_comando.h"

class ComandoSalir : public ComandoCliente {
public:
    virtual bool ejecutar(WorldView& worldView) const override;

    virtual ~ComandoSalir() = default;
};

#endif
