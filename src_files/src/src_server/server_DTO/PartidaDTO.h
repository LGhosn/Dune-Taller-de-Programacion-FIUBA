#ifndef SERVER_PARTIDA_DTO_H
#define SERVER_PARTIDA_DTO_H

#include <vector>
#include <string>
#include <map>

struct Partida {
    const std::string nombre_partida;
    uint8_t jugadores_actuales;
    const uint8_t jugadores_requeridos;

    Partida(const std::string& nombre_partida, uint8_t jugadores_requeridos);
};

struct PartidaCmp {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        if (lhs < rhs) {
            return true;
        }
        return false;
    }
};

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

#endif //SERVER_PARTIDA_DTO_H
