#ifndef CLIENTE_SOL_COMPRAR_EDIFICIO_H
#define CLIENTE_SOL_COMPRAR_EDIFICIO_H

#include "cliente_solicitud.h"

class SolComprarEdificioCliente : public SolicitudCliente {
    uint8_t tipo;
public:
    SolComprarEdificioCliente(uint8_t tipo);

    void enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador);

    ~SolComprarEdificioCliente() = default;
};

#endif // CLIENTE_SOL_COMPRAR_EDIFICIO_H
