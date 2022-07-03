#include "cosechadora.h"

Cosechadora::Cosechadora(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn) : Unidad(duenio, mapa, coords_spawn) {
    this->id = id;
    this->tipo_unidad = VEHICULO;

    this->velocidad = atributos_unidad["Vehiculo"]["Cosechadora"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Vehiculo"]["Cosechadora"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Vehiculo"]["Cosechadora"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Vehiculo"]["Cosechadora"]["Costo"].as<uint16_t>();
    
    std::vector<char> aux = atributos_unidad["Vehiculo"]["Cosechadora"]["PenalizacionTerreno"].as<std::vector<char>>();
    std::vector<float> aux_float = atributos_unidad["Vehiculo"]["Cosechadora"]["PenalizacionVelocidad"].as<std::vector<float>>();

    for (int i = 0; i < (int)aux.size(); i++) {
        this->penalizacion_terreno.insert(std::pair<char, float>(aux[i], aux_float[i]));
    }
    this->terrenos_no_accesibles = atributos_unidad["Vehiculo"]["Cosechadora"]["TerrenosNoAccesibles"].as<std::vector<char>>();
}
