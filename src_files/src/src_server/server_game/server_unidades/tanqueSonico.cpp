#include "tanqueSonico.h"

TanqueSonico::TanqueSonico(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad) : Unidad(duenio, mapa, Coordenadas(0, 0)) {
    this->id = id;
    this->tipo_unidad = VEHICULO;

    this->armas = atributos_unidad["TanqueSonico"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["TanqueSonico"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["TanqueSonico"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["TanqueSonico"]["TiempoEntrenamiento"].as<uint8_t>();
    this->vida = atributos_unidad["TanqueSonico"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["TanqueSonico"]["Costo"].as<uint8_t>();
    
    std::vector<char> aux = atributos_unidad["TanqueSonico"]["PenalizacionTerreno"].as<std::vector<char>>();
    std::vector<float> aux_float = atributos_unidad["TanqueSonico"]["PenalizacionVelocidad"].as<std::vector<float>>();
    for (int i = 0; i < (int)aux.size(); i++) {
        this->penalizacion_terreno.insert(std::pair<char, float>(aux[i], aux_float[i]));
    }
    this->terrenos_no_accesibles = atributos_unidad["TanqueSonico"]["TerrenosNoAccesibles"].as<std::vector<char>>();
}