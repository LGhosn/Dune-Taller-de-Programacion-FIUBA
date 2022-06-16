#ifndef CLIENT_SOL_CREAR_EDIFICIO_H
#define CLIENT_SOL_CREAR_EDIFICIO_H

#include "cliente_solicitud.h"
#include "../../src_common/common_coords.h"

class SolicitudCrearEdificio : public SolicitudCliente {
    uint8_t id_jugador;
    Coordenadas coords;
    uint8_t tipo;
public:
    SolicitudCrearEdificio(uint8_t id_jugador, Coordenadas& coords, uint8_t tipo);

    void enviarSolicitud(ProtocoloCliente& protocolo);

    ~SolicitudCrearEdificio() = default;
};

#endif
