#include "server_serializador.h"
#include <arpa/inet.h>
#include <tuple>
#include <iostream>

SerializadorServer::SerializadorServer(YAML::Node* codigos): codigos(codigos) {}

std::vector<uint8_t> SerializadorServer::serializarComandoEmpezarConstruccionEdificio(
                                                            uint8_t tipo_edificio,
                                                            uint16_t tiempo_construccion) {
    std::vector<uint8_t> buffer(4);
    uint8_t codigo = 25;
    buffer[0] = codigo;
    buffer[1] = tipo_edificio;
    uint16_t* aux = (uint16_t*) (buffer.data() + 2);
    aux[0] = htons(tiempo_construccion);
    return buffer;
}

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

/* *****************************************************************
 *             METODOS REFERIDOS A ACTUALIZAR ESPECIA
 * *****************************************************************/

std::vector<uint8_t> SerializadorServer::serializarComandoModificarEspecia(uint16_t cantidad_especia) {
    std::vector<uint8_t> buffer(3);
    // buffer[0] = (*codigos)["ModificarEspecia"].as<uint8_t>();
    buffer[0] = 20;
    uint16_t* aux = (uint16_t*) (buffer.data() + 1);
    aux[0] = htons(cantidad_especia);
    return buffer;
}

/* *****************************************************************
 * METODOS REFERIDOS A ACTUALIZAR ESTADO COMPRA EDIFICIOS Y UNIDADES
 * *****************************************************************/

std::vector<uint8_t> SerializadorServer::serializarComandoActualizarTiendaEdificios(const std::vector<bool>& edificios_comprables) {
    std::vector<uint8_t> buffer(edificios_comprables.size() + 1);
    buffer[0] = 21;
    for (uint8_t i = 0; i < edificios_comprables.size(); i++)
        buffer[i + 1] = edificios_comprables[i];
    return buffer;
}
std::vector<uint8_t> SerializadorServer::serializarComandoActualizarTiendaUnidades(const std::vector<bool>& unidades_comprables) {
    std::vector<uint8_t> buffer(unidades_comprables.size() + 1);
    buffer[0] = 21;
    for (uint8_t i = 0; i < unidades_comprables.size(); i++)
        buffer[i + 1] = unidades_comprables[i];
    return buffer;
}

std::vector<uint8_t> SerializadorServer::serializarEmpezarEntrenamientoUnidad(uint8_t tipo_unidad,
                                                                            uint16_t tiempo_construccion) {
    std::vector<uint8_t> buffer(4);
    buffer[0] = CODIGO_EMPEZAR_ENTRENAMIENTO;
    buffer[1] = tipo_unidad;
    uint16_t* aux = (uint16_t*) (buffer.data() + 2);
    aux[0] = htons(tiempo_construccion);
    return buffer;
}

/* *****************************************************************
 *                          MOVE SEMANTICS
 * *****************************************************************/

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
