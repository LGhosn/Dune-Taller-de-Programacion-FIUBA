#ifndef SERVER_JUGADOR_H
#define SERVER_JUGADOR_H

#include <cstdint>
#include <string>

struct Jugador {
    uint8_t id;
    uint8_t casa;
    std::string nombre;

    Jugador(uint8_t id, uint8_t casa, std::string& nombre) :
            id(id),
            casa(casa),
            nombre(nombre) {};
};

#endif
