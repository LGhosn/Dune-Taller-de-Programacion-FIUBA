#include "jugador.h"

Jugador::Jugador(uint8_t id, uint8_t casa, std::string& nombre) :
                id(id),
                casa(casa),
                nombre(nombre) {}

uint8_t Jugador::obtenerId() const {
    return id;
}

uint8_t Jugador::obtenerCasa() const {
    return casa;
}

const std::string& Jugador::obtenerNombre() const {
    return nombre;
}

bool Jugador::operator==(const uint8_t& id_jugador) const {
    return id_jugador == id;
}
