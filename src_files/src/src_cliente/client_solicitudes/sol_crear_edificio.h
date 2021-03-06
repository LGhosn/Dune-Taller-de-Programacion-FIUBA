#ifndef SOL_CREAR_EDIFICIO_H
#define SOL_CREAR_EDIFICIO_H

#include "cliente_solicitud.h"
#include "../../src_common/common_coords.h"

class SolicitudCrearEdificio : public SolicitudCliente {
    Coordenadas coords;
    uint8_t tipo;
public:
    SolicitudCrearEdificio(Coordenadas& coords, uint8_t tipo);

    void enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador);

    ~SolicitudCrearEdificio() = default;
};

#endif
