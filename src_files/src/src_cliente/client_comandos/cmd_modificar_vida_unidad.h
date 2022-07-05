#ifndef CLIENTE_CMD_MODIFICAR_VIDA_UNIDAD_H
#define CLIENTE_CMD_MODIFICAR_VIDA_UNIDAD_H

#include "client_comando.h"
#include "../client_DTO/dto_cmd_modificar_vida_unidad_cliente.h"

class CmdModificarVidaUnidadCliente : public ComandoCliente {
    uint8_t id_unidad;
    uint16_t nueva_cant_vida;
public:
    CmdModificarVidaUnidadCliente(CmdModificarVidaUnidadClienteDTO& dto);

    virtual bool ejecutar(WorldView& worldView) const;

    ~CmdModificarVidaUnidadCliente() = default;
};

#endif // CLIENTE_CMD_MODIFICAR_VIDA_UNIDAD_H
