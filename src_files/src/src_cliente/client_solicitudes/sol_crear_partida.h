#ifndef SOLICITUD_CREAR_PARTIDA_H
#define SOLICITUD_CREAR_PARTIDA_H

#include "cliente_solicitud.h"
#include <string>
#include <stdint.h>

class SolicitudCrearPartida : public SolicitudCliente {
    std::string casa;
    std::string nombre_partida;
    std::string mapa;
    uint8_t jugadores_requeridos;
public:
    SolicitudCrearPartida(std::string casa, std::string nombre_partida, std::string mapa,
    uint8_t jugadores_requeridos);

    void enviarSolicitud(ProtocoloCliente& protocolo);
    
    ~SolicitudCrearPartida() = default;
};

#endif
