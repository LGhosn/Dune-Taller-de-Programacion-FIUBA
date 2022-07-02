#ifndef CMD_ENEMIGO_DESPLIEGA_UNIDAD_CLIENTE_H
#define CMD_ENEMIGO_DESPLIEGA_UNIDAD_CLIENTE_H

#include "client_comando.h"
#include "../client_DTO/dto_cmd_enemigo_despliega_unidad.h"

class CmdEnemigoDespliegaUnidadCliente : public ComandoCliente {
private:
    uint8_t id_jugador;
    uint8_t id_unidad;
    uint8_t tipo_unidad;
    long tiempo_entrenamiento;
    Coordenadas& coords_spawn;

public:
    CmdEnemigoDespliegaUnidadCliente(CmdEnemigoDespliegaUnidadDTO& dto);
    virtual bool ejecutar(WorldView& wordView) const override;
    virtual ~CmdEnemigoDespliegaUnidadCliente() = default;
};

#endif // CMD_ENEMIGO_DESPLIEGA_UNIDAD_CLIENTE_H