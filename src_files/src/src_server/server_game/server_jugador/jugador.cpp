#include "jugador.h"

float Jugador::obtenerMultiplicadorPorEdificios(uint8_t tipo_unidad) {
    return 1 / (float) cantidad_edificios[edificios_multiplicadores[tipo_unidad]];
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
                validador_de_unidades(constantes, casa, cantidad_edificios, cola_comandos),
                tiempo_construccion_base(constantes["Game"]["Precios"]["Edificios"]["TiempoConstruccionBase"].as<uint16_t>()),
                edificios_multiplicadores(constantes["Game"]["Unidades"]["EdificioMultiplicador"].as<std::vector<uint8_t>>()),
                tiempo_entrenamiento_por_unidad(constantes["Game"]["Unidades"]["TiempoDeEntrenamiento"].as<std::vector<uint16_t>>()) {}

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
    if (validador_de_unidades.unidadDisponible(tipo_unidad)) {
        if (especia.comprarUnidad(tipo_unidad)) {
            validador_de_unidades.actualizarUnidadesDisponibles(especia.obtenerUnidadesComprables());
            return true;
        }
    }
    return false;
}

bool Jugador::comprarEdificio(uint8_t tipo_edificio) {
    if(especia.comprarEdificio(tipo_edificio, cantidad_edificios, casa)) {
        validador_de_unidades.actualizarUnidadesDisponibles(especia.obtenerUnidadesComprables());
        return true;
    }
    return false;
}

void Jugador::edificioCreado(uint8_t tipo_edificio) {
    energia.edificioCreado(tipo_edificio);
    cantidad_edificios[tipo_edificio]++;
    validador_de_unidades.actualizarUnidadesDisponibles(especia.obtenerUnidadesComprables());
}

uint16_t Jugador::obtenerTiempoConstruccionEdificio() {
    return tiempo_construccion_base * energia.obtenerMultiplicadorDeudaEnergetica();
}

uint16_t Jugador::obtenerTiempoConstruccionUnidad(uint8_t tipo_unidad) {
    uint16_t tiempo_entrenamiento_base = tiempo_entrenamiento_por_unidad[tipo_unidad];
    float multiplicador_edificios = obtenerMultiplicadorPorEdificios(tipo_unidad);
    std::cout << "Multiplicador Edificios: " << multiplicador_edificios << std::endl;
    float multiplicador_deuda_energetica = energia.obtenerMultiplicadorDeudaEnergetica();
    std::cout << "Multiplicador Deuda Energetica: " << multiplicador_deuda_energetica << std::endl;
    uint16_t resultado = tiempo_entrenamiento_base * multiplicador_edificios * multiplicador_deuda_energetica;
    std::cout << "Resultado: " << resultado << std::endl;
    return resultado;
}

bool Jugador::operator==(const uint8_t& id_jugador) const {
    return id_jugador == id;
}
