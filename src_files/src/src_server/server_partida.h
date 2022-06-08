#ifndef SERVER_PARTIDA_H_
#define SERVER_PARTIDA_H_

#include "server_handler.h"
#include <iostream>
#include <string>
#include <vector>

struct Partida {
    const std::string nombre_partida;
    uint8_t jugadores_actuales;
    const uint8_t jugadores_requeridos;
    std::vector <HandlerCliente*> jugadores;

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
