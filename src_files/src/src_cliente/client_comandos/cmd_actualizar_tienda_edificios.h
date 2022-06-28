#ifndef CLIENTE_COMANDO_ACTUALIZAR_TIENDA_EDIFICIOS_H
#define CLIENTE_COMANDO_ACTUALIZAR_TIENDA_EDIFICIOS_H

#include "client_comando.h"

class CmdActualizarTiendaEdificiosCliente: public ComandoCliente {
    std::vector<bool> edificios_comprables;
public:
    CmdActualizarTiendaEdificiosCliente(std::vector<bool> edificios_comprables);

    virtual bool ejecutar(WorldView& worldView) const override;

    ~CmdActualizarTiendaEdificiosCliente() = default;
};

#endif
