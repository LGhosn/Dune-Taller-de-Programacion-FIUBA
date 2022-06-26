#include "server_serializador.h"
#include <arpa/inet.h>
#include <tuple>
#include <iostream>

SerializadorServer::SerializadorServer(YAML::Node* codigos): codigos(codigos) {}

std::vector<uint8_t> SerializadorServer::serializarComandoCrearEdificio(uint8_t id_jugador,
uint8_t id_edificio, uint8_t tipo, const Coordenadas& coords, uint8_t casa) const {
    std::vector<uint8_t> buffer(9);
    // uint8_t codigo = (*codigos)["CrearEdificio"].as<uint8_t>();
    uint8_t codigo = 5;
    buffer[0] = codigo;
    buffer[1] = id_jugador;
    buffer[2] = id_edificio;
    buffer[3] = tipo;
    buffer[4] = casa;
    uint16_t x = htons(coords.x);
    uint16_t y = htons(coords.y);
    uint16_t* aux = (uint16_t*) (buffer.data() + 5);
    aux[0] = x;
    aux[1] = y;
    return buffer;
}

std::vector<uint8_t> SerializadorServer::serializarString(const std::string& string) const {
    uint16_t largo_nombre = string.length();
    std::vector<uint8_t> buffer(largo_nombre + 2);

    uint16_t* ptr_16 = (uint16_t*)buffer.data();
    ptr_16[0] = htons(largo_nombre);

    for (int i = 0; i < largo_nombre; i++) {
        buffer[i + 2] = string[i]; 
    }
    return buffer;
}

void SerializadorServer::concatenarBuffers(std::vector<uint8_t> buffer_destino,
                                            std::vector<uint8_t> buffer_origen) const {
    // buffer_destino.insert(buffer_destino.end(), buffer_origen.begin(), buffer_origen.end());
    for (size_t i = 0; i < buffer_origen.size(); i++) {
        buffer_destino.push_back(buffer_origen[i]);
    }
}

std::vector<uint8_t> SerializadorServer::serializarComienzoDePartida(const InfoPartidaDTO& info_partida) const {
    std::vector<uint8_t> buffer(5);
    buffer[0] = 0;
    uint16_t* aux = (uint16_t*) (buffer.data() + 1);
    aux[0] = htons(info_partida.coords_iniciales.x);
    aux[1] = htons(info_partida.coords_iniciales.y);
    std::cout << "Size antes de mapa: " << buffer.size() << std::endl;
    std::vector<uint8_t> buffer_mapa = serializarString(info_partida.nombre_mapa);
    std::cout << "Size buffer mapa: " << buffer_mapa.size() << std::endl;
    concatenarBuffers(buffer, buffer_mapa);
    std::cout << std::endl;
    std::cout << "Size despues de mapa: " << buffer.size() << std::endl;
    uint8_t cantidad_jugadores = info_partida.info_jugadores.size();
    buffer.emplace_back(cantidad_jugadores);
    for(auto& jugador: info_partida.info_jugadores) {
        std::vector<uint8_t> buffer_jugador(2);
        buffer_jugador[0] = jugador.first;
        buffer_jugador[1] = std::get<0>(jugador);
        std::vector<uint8_t> buffer_nombre = serializarString(std::get<1>(jugador.second));
        concatenarBuffers(buffer_jugador, buffer_nombre);
        concatenarBuffers(buffer, buffer_jugador);
    }
    return buffer;
}

/* *****************************************************************
 *             METODOS REFERIDOS A ACTUALIZAR ESPECIA
 * *****************************************************************/

std::vector<uint8_t> SerializadorServer::serializarComandoModificarEspecia(uint16_t cantidad_especia) {
    std::vector<uint8_t> buffer(3);
    buffer[0] = (*codigos)["ModificarEspecia"].as<uint8_t>();
    uint16_t* aux = (uint16_t*) (buffer.data() + 1);
    aux[0] = htons(cantidad_especia);
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
