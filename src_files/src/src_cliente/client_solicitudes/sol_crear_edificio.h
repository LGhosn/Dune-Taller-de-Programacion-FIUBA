#ifndef SOL_CREAR_EDIFICIO_H
#define SOL_CREAR_EDIFICIO_H

#include "cliente_solicitud.h"
#include "../../src_common/common_coords.h"

class SolicitudCrearEdificio : public Solicitud {

    uint8_t id_jugador;
    Coordenadas coords;
    uint8_t tipo;
public:
    SolicitudCrearEdificio(uint8_t id_jugador, Coordenadas& coords, uint8_t tipo);

    virtual void enviarSolicitud(ProtocoloCliente& protocolo) override;
};

#endif
