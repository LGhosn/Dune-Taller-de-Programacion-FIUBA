#ifndef SOLICITUD_CREAR_PARTIDA_H
#define SOLICITUD_CREAR_PARTIDA_H

#include "cliente_solicitud.h"
#include <string>
#include <stdint.h>

class SolicitudCrearPartida : public SolicitudCliente {
    std::string nombre_partida;
    std::string mapa;
    std::string casa;
    uint8_t jugadores_requeridos;
public:
    SolicitudCrearPartida(std::string& nombre_partida, std::string& mapa, std::string& casa,
    uint8_t jugadores_requeridos);

    void enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador);
    
    ~SolicitudCrearPartida() = default;
};

#endif
