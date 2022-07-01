#include "jugador.h"

float Jugador::obtenerMultiplicadorPorEdificios(uint8_t tipo_unidad) {
    return 1 / (float) cantidad_edificios[tipo_unidad];
}

Jugador::Jugador(uint8_t id, uint8_t casa, std::string& nombre,
                ColaBloqueante<ComandoServer>& cola_comandos,
                YAML::Node& constantes) :
                id(id),
                casa(casa),
                nombre(nombre),
                cola_comandos(cola_comandos),
                especia(cola_comandos, constantes),
                energia(cola_comandos, constantes),
                cantidad_edificios(8, 0),
                tiempo_construccion_base(constantes["Game"]["Precios"]["Edificios"]["TiempoConstruccionBase"].as<uint16_t>()) {}

void Jugador::empezarPartida() {
    especia.empezarPartida();
    energia.empezarPartida();
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

bool Jugador::comprarUnidad(uint8_t tipo_unidad) {
    return especia.comprarUnidad(tipo_unidad);
}

bool Jugador::comprarEdificio(uint8_t tipo_edificio) {
    return especia.comprarEdificio(tipo_edificio);
}

void Jugador::edificioCreado(uint8_t tipo_edificio) {
    energia.edificioCreado(tipo_edificio);
    cantidad_edificios[tipo_edificio]++;
}

uint16_t Jugador::obtenerTiempoConstruccionEdificio() {
    return tiempo_construccion_base * energia.obtenerMultiplicadorDeudaEnergetica();
}

uint16_t Jugador::obtenerTiempoConstruccionUnidad(uint8_t tipo_unidad) {
    float multiplicador_edificios = obtenerMultiplicadorPorEdificios(tipo_unidad);
    float multiplicador_deuda_energetica = energia.obtenerMultiplicadorDeudaEnergetica();
    return tiempo_construccion_base * multiplicador_edificios * multiplicador_deuda_energetica;
}

bool Jugador::operator==(const uint8_t& id_jugador) const {
    return id_jugador == id;
}
