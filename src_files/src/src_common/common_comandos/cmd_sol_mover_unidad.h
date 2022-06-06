#ifndef CMD_MOVER_UNIDAD_H
#define CMD_MOVER_UNIDAD_H

#include "comando_a_enviar.h"
#include "../../src_cliente/client_protocolo.h"
#include "../../src_server/server_protocolo.h"

class SolicitudMoverUnidad : public ComandoAEnviar {
    uint16_t& id_unidad;
    uint16_t& x;
    uint16_t& y;

public:
    SolicitudMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y);
    virtual void enviarInstruccion(Protocolo_servidor& protocolo);
    virtual void enviarSolicitud(ProtocoloCliente& protocolo);
    virtual ~SolicitudMoverUnidad();
};

#endif // CMD_MOVER_UNIDAD_H
