#ifndef SERVER_PARTIDA_H_
#define SERVER_PARTIDA_H_

#include <iostream>
#include <string>

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

#endif  // SERVER_PARTIDA_H_
