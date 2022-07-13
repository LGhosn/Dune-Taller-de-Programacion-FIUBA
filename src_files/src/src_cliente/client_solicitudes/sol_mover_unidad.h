#ifndef SOL_MOVER_UNIDAD_H
#define SOL_MOVER_UNIDAD_H

#include "cliente_solicitud.h"
#include "../client_protocolo.h"
#include "../../src_common/common_coords.h"

class SolicitudMoverUnidad : public SolicitudCliente {
    uint8_t id_unidad;
    Coordenadas coords_a_moverse;

public:
    SolicitudMoverUnidad(uint8_t id_unidad, const Coordenadas& coords_a_moverse);
    virtual void enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador);
    virtual ~SolicitudMoverUnidad() = default;
};

#endif // CMD_MOVER_UNIDAD_H
