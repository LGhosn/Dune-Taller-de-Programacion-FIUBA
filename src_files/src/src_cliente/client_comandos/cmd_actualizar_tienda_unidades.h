#ifndef CLIENTE_COMANDO_ACTUALIZAR_TIENDA_UNIDADES_H
#define CLIENTE_COMANDO_ACTUALIZAR_TIENDA_UNIDADES_H

#include "client_comando.h"

class CmdActualizarTiendaUnidadesCliente: public ComandoCliente {
    std::vector<bool> unidades_comprables;
public:
    CmdActualizarTiendaUnidadesCliente(std::vector<bool> unidades_comprables);

    virtual bool ejecutar(WorldView& worldView) const override;

    virtual ~CmdActualizarTiendaUnidadesCliente() = default;
};

#endif
