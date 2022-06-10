#ifndef SOL_MOVER_UNIDAD_H
#define SOL_MOVER_UNIDAD_H

#include "cliente_solicitud.h"
#include "../client_protocolo.h"

class SolicitudMoverUnidad : public SolicitudCliente {
    uint16_t id_unidad;
    uint16_t x;
    uint16_t y;

public:
    SolicitudMoverUnidad(uint16_t id_unidad, uint16_t x, uint16_t y);
    virtual void enviarSolicitud(ProtocoloCliente& protocolo);
    virtual ~SolicitudMoverUnidad() = default;
};

#endif // CMD_MOVER_UNIDAD_H
