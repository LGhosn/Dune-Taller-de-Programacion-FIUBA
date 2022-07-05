#ifndef SOL_ATACAR_EDIFICIO_H
#define SOL_ATACAR_EDIFICIO_H

#include "cliente_solicitud.h"
#include "../client_protocolo.h"
#include "../../src_common/common_coords.h"

class SolicitudAtacarEdificio : public SolicitudCliente {
    uint8_t id_unidad_atacante;
    uint8_t id_edificio_a_atacar;

public:
    SolicitudAtacarEdificio(uint8_t id_unidad_atacante,uint8_t id_edificio_a_atacar);
    virtual void enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador);
    virtual ~SolicitudAtacarEdificio() = default;
};

#endif // SOL_ATACAR_EDIFICIO_H
