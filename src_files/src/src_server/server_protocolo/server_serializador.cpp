#include "server_serializador.h"
#include <arpa/inet.h>

SerializadorServer::SerializadorServer(): codigos(YAML::LoadFile(RUTA_CODIGOS)) {}

std::vector<uint8_t> SerializadorServer::serializarComandoCrearEdificio(uint8_t id_jugador,
uint8_t id_edificio, uint8_t tipo, const Coordenadas& coords) const {
    std::vector<uint8_t> buffer(8);
    uint8_t codigo = this->codigos["CrearEdificio"].as<uint8_t>();
    buffer[0] = codigo;
    buffer[1] = id_jugador;
    buffer[2] = tipo;
    uint16_t x = htons(coords.x);
    uint16_t y = htons(coords.y);
    uint16_t* aux = (uint16_t*) buffer.data() + 3;
    aux[0] = x;
    aux[1] = y;
    return buffer;
}
