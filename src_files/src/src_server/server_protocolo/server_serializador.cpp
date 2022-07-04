#include "server_serializador.h"
#include <arpa/inet.h>
#include <tuple>
#include <iostream>

SerializadorServer::SerializadorServer(YAML::Node& codigos): codigos(codigos) {}

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
    std::vector<uint8_t> buffer(12);
    buffer[0] = 22;
    for (uint8_t i = 0; i < 11; i++)
        buffer[i + 1] = unidades_comprables[i];
    return buffer;
}

std::vector<uint8_t> SerializadorServer::serializarEmpezarEntrenamientoUnidad(uint8_t id_unidad, uint8_t tipo_unidad,
                                                                            uint16_t tiempo_construccion,
                                                                            Coordenadas& coords_spawn) {
    std::vector<uint8_t> buffer(9);
    buffer[0] = CODIGO_EMPEZAR_ENTRENAMIENTO;
    buffer[1] = id_unidad;
    buffer[2] = tipo_unidad;
    uint16_t* aux = (uint16_t*) (buffer.data() + 3);
    aux[0] = htons(coords_spawn.x);
    aux[1] = htons(coords_spawn.y);
    aux[2] = htons(tiempo_construccion);
    return buffer;
}

std::vector<uint8_t> SerializadorServer::serializarComandoEnemigoDespliegaUnidad(uint8_t id_unidad, uint8_t id_jugador, uint8_t tipo_unidad, uint16_t tiempo, Coordenadas& coords) {
    std::vector<uint8_t> buffer(10);
    buffer[0] = CODIGO_ENEMIGO_DESPLIEGA_UNIDAD;
    buffer[1] = id_unidad;
    buffer[2] = id_jugador;
    buffer[3] = tipo_unidad;
    uint16_t* aux = (uint16_t*) (buffer.data() + 4);
    aux[0] = htons(coords.x);
    aux[1] = htons(coords.y);
    aux[2] = htons(tiempo);
    return buffer;
}


/* *****************************************************************
 *                  METODOS REFERIDOS A MOVER UNIDAD
 * *****************************************************************/
std::vector<uint8_t> SerializadorServer::serializarComandoMoverUnidad(uint8_t id_unidad, uint8_t direccion, uint16_t tiempo){
    std::vector<uint8_t> buffer(5);
    buffer[0] = CODIGO_MOVER_UNIDAD;
    buffer[1] = direccion;
    buffer[2] = id_unidad;
    uint16_t* aux2 = (uint16_t*)(buffer.data() + 3);
    aux2[0] = htons(tiempo);
    return buffer;
}

/* *****************************************************************
 *                  METODOS REFERIDOS A PUNTAJE
 * *****************************************************************/

std::vector<uint8_t> SerializadorServer::serializarComandoActualizarPuntaje(uint8_t id_jugador, uint16_t nuevo_puntaje) {
    std::vector<uint8_t> buffer(4);
    buffer[0] = CODIGO_ACTUALIZAR_PUNTAJE;
    buffer[1] = id_jugador;
    uint16_t* aux = (uint16_t*) (buffer.data() + 2);
    aux[0] = htons(nuevo_puntaje);
    return buffer;
}
