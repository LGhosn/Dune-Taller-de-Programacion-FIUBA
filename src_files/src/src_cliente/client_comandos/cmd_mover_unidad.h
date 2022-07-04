#ifndef COMANDO_MOVER_UNIDAD_CLIENTE_H
#define COMANDO_MOVER_UNIDAD_CLIENTE_H

#include "client_comando.h"
#include "../client_DTO/dto_cmd_mover_unidad.h"

class CmdMoverUnidadCliente : public ComandoCliente {
    uint8_t id_unidad;
    uint8_t direccion;
    uint16_t tiempo;
public:
    CmdMoverUnidadCliente(CmdMoverUnidadClienteDTO& dto);

    virtual bool ejecutar(WorldView& worldView) const override;

    virtual ~CmdMoverUnidadCliente() = default;
};

#endif // COMANDO_MOVER_UNIDAD_CLIENTE_H
