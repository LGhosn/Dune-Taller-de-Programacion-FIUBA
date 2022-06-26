#include "jugador.h"

Jugador::Jugador(uint8_t id, uint8_t casa, std::string& nombre,
                ColaBloqueante<ComandoServer>* cola_comandos,
                YAML::Node& constantes) :
                id(id),
                casa(casa),
                nombre(nombre),
                cola_comandos(cola_comandos),
                especia(cola_comandos, constantes) {}

void Jugador::empezarPartida() {
    especia.empezarPartida();
}

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

Jugador& Jugador::operator=(Jugador&& otro) {
    if (this == &otro)
        return *this;
    id = otro.id;
    casa = otro.casa;
    nombre = otro.nombre;
    cola_comandos = otro.cola_comandos;
    especia = std::move(otro.especia);
    otro.cola_comandos = nullptr;
    return *this;
}

Jugador::Jugador(Jugador&& otro) :
            id(otro.id),
            casa(otro.casa),
            nombre(otro.nombre),
            cola_comandos(otro.cola_comandos),
            especia(std::move(otro.especia)) {
    if (this != &otro)
        otro.cola_comandos = nullptr;
}
