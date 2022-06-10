#ifndef CLIENT_SOLICITUD_DE_CREACION_H
#define CLIENT_SOLICITUD_DE_CREACION_H

#include <string>

struct SolicitudDeCreacion {
    const std::string nombre_partida;
    const std::string mapa;
    const std::string casa;
    const uint8_t jugadores_requeridos;

    SolicitudDeCreacion(std::string& nombre_partida,
                        std::string& mapa,
                        std::string& casa,
                        uint8_t& jugadores_requeridos
    ) :
            nombre_partida(std::move(nombre_partida)),
            mapa(std::move(mapa)),
            casa(std::move(casa)),
            jugadores_requeridos(jugadores_requeridos) {};
};

#endif //CLIENT_SOLICITUD_DE_CREACION_H
