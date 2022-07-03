#include "desviador.h"

Desviador::Desviador(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn) : Unidad(duenio, mapa, coords_spawn) {
    this->id = id;
    this->tipo_unidad = VEHICULO;

    this->armas = atributos_unidad["Vehiculo"]["Desviador"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["Vehiculo"]["Desviador"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Vehiculo"]["Desviador"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Vehiculo"]["Desviador"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Vehiculo"]["Desviador"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Vehiculo"]["Desviador"]["Costo"].as<uint16_t>();
    
    std::vector<char> aux = atributos_unidad["Vehiculo"]["Desviador"]["PenalizacionTerreno"].as<std::vector<char>>();
    std::vector<float> aux_float = atributos_unidad["Vehiculo"]["Desviador"]["PenalizacionVelocidad"].as<std::vector<float>>();
    for (int i = 0; i < (int)aux.size(); i++) {
        this->penalizacion_terreno.insert(std::pair<char, float>(aux[i], aux_float[i]));
    }
    this->terrenos_no_accesibles = atributos_unidad["Vehiculo"]["Desviador"]["TerrenosNoAccesibles"].as<std::vector<char>>();
}
