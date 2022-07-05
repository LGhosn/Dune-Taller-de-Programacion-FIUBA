#ifndef SOL_ATACAR_UNIDAD_H
#define SOL_ATACAR_UNIDAD_H

#include "cliente_solicitud.h"
#include "../client_protocolo.h"
#include "../../src_common/common_coords.h"

class SolicitudAtacarUnidad : public SolicitudCliente {
    uint8_t id_unidad_atacante;
    uint8_t id_unidad_a_atacar;

public:
    SolicitudAtacarUnidad(uint8_t id_unidad_atacante,uint8_t id_unidad_a_atacar);
    virtual void enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador);
    virtual ~SolicitudAtacarUnidad() = default;
};

#endif // SOL_ATACAR_UNIDAD_H
