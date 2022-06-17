#ifndef CLIENT_SOLICITUD_CREAR_PARTIDA_DTO_H
#define CLIENT_SOLICITUD_CREAR_PARTIDA_DTO_H

#include <string>

struct SolicitudCrearPartidaDTO {
    const std::string nombre_partida;
    const std::string mapa;
    std::string casa;
    uint8_t casa_codigo;
    const uint8_t jugadores_requeridos;

    SolicitudCrearPartidaDTO(std::string& nombre_partida,
                        std::string& mapa,
                        std::string& casa,
                        uint8_t jugadores_requeridos) :
                        nombre_partida(std::move(nombre_partida)),
                        mapa(std::move(mapa)),
                        casa(casa),
                        jugadores_requeridos(jugadores_requeridos) {};
    
    SolicitudCrearPartidaDTO(std::string& nombre_partida,
                        std::string& mapa,
                        uint8_t casa_codigo,
                        uint8_t jugadores_requeridos) :
                        nombre_partida(std::move(nombre_partida)),
                        mapa(std::move(mapa)),
                        casa_codigo(casa_codigo),
                        jugadores_requeridos(jugadores_requeridos) {};

    
};

#endif //CLIENT_SOLICITUD_CREAR_PARTIDA_DTO_H
