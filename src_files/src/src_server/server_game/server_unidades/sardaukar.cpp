#include "sardaukar.h"

Sardaukar::Sardaukar(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn) : Unidad(duenio, mapa, coords_spawn) {
    this->id = id;
    this->tipo_unidad = INFANTERIA;

    this->armas = atributos_unidad["Infanteria"]["Sardaukar"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["Infanteria"]["Sardaukar"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Infanteria"]["Sardaukar"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Infanteria"]["Sardaukar"]["TiempoEntrenamiento"].as<float>();
    this->vida = atributos_unidad["Infanteria"]["Sardaukar"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Infanteria"]["Sardaukar"]["Costo"].as<uint8_t>();
    
    std::vector<char> aux = atributos_unidad["Infanteria"]["Sardaukar"]["PenalizacionTerreno"].as<std::vector<char>>();
    std::vector<float> aux_float = atributos_unidad["Infanteria"]["Sardaukar"]["PenalizacionVelocidad"].as<std::vector<float>>();
    for (int i = 0; i < (int)aux.size(); i++) {
        this->penalizacion_terreno.insert(std::pair<char, float>(aux[i], aux_float[i]));
    }
    this->terrenos_no_accesibles = atributos_unidad["Infanteria"]["Sardaukar"]["TerrenosNoAccesibles"].as<std::vector<char>>();
}
