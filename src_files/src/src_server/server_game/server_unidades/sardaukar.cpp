#include "sardaukar.h"

Sardaukar::Sardaukar(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad) : Unidad(duenio, mapa, Coordenadas(0, 0)) {
    this->id = id;
    this->tipo_unidad = INFANTERIA;

    this->armas = atributos_unidad["Sardaukar"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["Sardaukar"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Sardaukar"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Sardaukar"]["TiempoEntrenamiento"].as<uint8_t>();
    this->vida = atributos_unidad["Sardaukar"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Sardaukar"]["Costo"].as<uint8_t>();
    
    std::vector<char> aux = atributos_unidad["Sardaukar"]["PenalizacionTerreno"].as<std::vector<char>>();
    std::vector<float> aux_float = atributos_unidad["Sardaukar"]["PenalizacionVelocidad"].as<std::vector<float>>();
    for (int i = 0; i < (int)aux.size(); i++) {
        this->penalizacion_terreno.insert(std::pair<char, float>(aux[i], aux_float[i]));
    }
    this->terrenos_no_accesibles = atributos_unidad["Sardaukar"]["TerrenosNoAccesibles"].as<std::vector<char>>();
}