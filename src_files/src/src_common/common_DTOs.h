#ifndef COMMON_DTOS_H_
#define COMMON_DTOS_H_

#include "../src_server/server_partida.h"
#include <map>
#include <string>

struct PartidaDTO {
    const std::string nombre_partida;
    const uint8_t jugadores_actuales;
    const uint8_t jugadores_requeridos;

    PartidaDTO(const std::string& nombre_partida,
                uint8_t jugadores_actuales,
                uint8_t jugadores_requeridos) :
    nombre_partida(nombre_partida),
    jugadores_actuales(jugadores_actuales),
    jugadores_requeridos(jugadores_requeridos) {}
};

struct PartidasDTO {
    std::map<std::string, Partida, PartidaCmp> partidas_creadas;

    explicit PartidasDTO
    (const std::map<std::string, Partida, PartidaCmp>& partidas_creadas) :
    partidas_creadas(partidas_creadas) {}
};

struct StatusDTO {
    const uint8_t status;
    explicit StatusDTO(uint8_t status) : status(status) {}
};

struct SolicitudCrearPartida {
    const std::string nombre_partida;
    const std::string mapa;
    const std::string casa;
    const uint8_t jugadores_requeridos;

    SolicitudCrearPartida(std::string& nombre_partida,
                        std::string& mapa,
                        std::string& casa,
                        uint8_t& jugadores_requeridos
                        ) :
            nombre_partida(std::move(nombre_partida)),
            mapa(std::move(mapa)),
            casa(std::move(casa)),
            jugadores_requeridos(jugadores_requeridos) {};
};

struct SolicitudUnirseAPartidaDTO {
    const std::string nombre_partida;
    const std::string casa;

    SolicitudUnirseAPartidaDTO(std::string& nombre_partida, std::string& casa) :
            nombre_partida(std::move(nombre_partida)),
            casa(std::move(casa)) {}
};

#endif  // COMMON_DTOS_H_
