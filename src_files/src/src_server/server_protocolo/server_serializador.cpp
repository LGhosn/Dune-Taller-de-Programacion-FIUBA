#include "server_serializador.h"
#include <arpa/inet.h>

SerializadorServer::SerializadorServer(YAML::Node* codigos): codigos(codigos) {}

std::vector<uint8_t> SerializadorServer::serializarComandoCrearEdificio(uint8_t id_jugador,
uint8_t id_edificio, uint8_t tipo, const Coordenadas& coords, uint8_t casa) const {
    std::vector<uint8_t> buffer(9);
    uint8_t codigo = (*codigos)["CrearEdificio"].as<uint8_t>();
    buffer[0] = codigo;
    buffer[1] = id_jugador;
    buffer[2] = id_edificio;
    buffer[3] = tipo;
    buffer[4] = casa;
    uint16_t x = htons(coords.x);
    uint16_t y = htons(coords.y);
    uint16_t* aux = (uint16_t*) buffer.data() + 5;
    aux[0] = x;
    aux[1] = y;
    return buffer;
}

SerializadorServer::SerializadorServer(SerializadorServer&& otro) {
    this->codigos = otro.codigos;
}
SerializadorServer& SerializadorServer::operator=(SerializadorServer&& otro) {
    if (this == &otro) {
        return *this;
    }
    this->codigos = otro.codigos;
    return *this;
}
