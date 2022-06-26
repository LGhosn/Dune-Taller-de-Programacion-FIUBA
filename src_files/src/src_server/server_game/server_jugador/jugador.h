#ifndef SERVER_JUGADOR_H
#define SERVER_JUGADOR_H

#include <cstdint>
#include <string>

class Jugador {
    uint8_t id;
    uint8_t casa;
    std::string nombre;

public:
    Jugador(uint8_t id, uint8_t casa, std::string& nombre) :
            id(id),
            casa(casa),
            nombre(nombre) {};
    
    uint8_t obtenerId() const;
    uint8_t obtenerCasa() const;
    const std::string& obtenerNombre() const;

    bool operator==(const uint8_t& id_jugador) const;
};

#endif
