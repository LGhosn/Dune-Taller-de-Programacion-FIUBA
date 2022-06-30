#include "infanteriaPesada.h"

InfanteriaPesada::InfanteriaPesada(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn) : Unidad(duenio, mapa, coords_spawn) {
    this->id = id;
    this->tipo_unidad = INFANTERIA;

    this->armas = atributos_unidad["InfanteriaPesada"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["InfanteriaPesada"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["InfanteriaPesada"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["InfanteriaPesada"]["TiempoEntrenamiento"].as<uint8_t>();
    this->vida = atributos_unidad["InfanteriaPesada"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["InfanteriaPesada"]["Costo"].as<uint8_t>();
    
    std::vector<char> aux = atributos_unidad["InfanteriaPesada"]["PenalizacionTerreno"].as<std::vector<char>>();
    std::vector<float> aux_float = atributos_unidad["InfanteriaPesada"]["PenalizacionVelocidad"].as<std::vector<float>>();
    for (int i = 0; i < (int)aux.size(); i++) {
        this->penalizacion_terreno.insert(std::pair<char, float>(aux[i], aux_float[i]));
    }
    this->terrenos_no_accesibles = atributos_unidad["InfanteriaPesada"]["TerrenosNoAccesibles"].as<std::vector<char>>();
}