#ifndef CLIENTE_SOL_COMPRAR_UNIDAD_H
#define CLIENTE_SOL_COMPRAR_UNIDAD_H

#include "cliente_solicitud.h"

class SolComprarUnidadCliente : public SolicitudCliente {
    uint8_t id_jugador;
    uint8_t tipo;
public:
    SolComprarUnidadCliente(uint8_t tipo);

    void enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador);

    ~SolComprarUnidadCliente() = default;
};

#endif // CLIENTE_SOL_COMPRAR_UNIDAD_H
