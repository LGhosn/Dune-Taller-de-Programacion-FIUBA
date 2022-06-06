#ifndef CMD_MOVER_UNIDAD_H
#define CMD_MOVER_UNIDAD_H

#include "comando_a_enviar.h"
#include "../client_protocolo.h"

class SolicitudMoverUnidad : public ComandoAEnviar {
    uint16_t id_unidad;
    uint16_t x;
    uint16_t y;

public:
    SolicitudMoverUnidad(uint16_t id_unidad, uint16_t x, uint16_t y);
    virtual void enviar_instruccion(ProtocoloCliente& protocolo);
    virtual ~SolicitudMoverUnidad();
};

#endif // CMD_MOVER_UNIDAD_H
