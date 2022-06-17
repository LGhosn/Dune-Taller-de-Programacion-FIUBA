#ifndef SERVER_PARTIDA_DTO_H
#define SERVER_PARTIDA_DTO_H

#include <string>
#include <stdint.h>
#include <vector>

struct PartidaDTO {
    const std::string nombre_partida;
    const uint8_t jugadores_actuales;
    const uint8_t jugadores_requeridos;
    const std::string nombre_mapa;

    PartidaDTO(const std::string& nombre_partida,
               uint8_t jugadores_actuales,
               uint8_t jugadores_requeridos,
               const std::string& nombre_mapa) :
            nombre_partida(nombre_partida),
            jugadores_actuales(jugadores_actuales),
            jugadores_requeridos(jugadores_requeridos),
            nombre_mapa(nombre_mapa) {}
};

struct PartidasDTO {
    std::vector<PartidaDTO>& partidas_creadas;

    explicit PartidasDTO
            (std::vector<PartidaDTO>& partidas_creadas) :
            partidas_creadas(partidas_creadas) {}
};

#endif
