#include "cosechadora.h"

Cosechadora::Cosechadora(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn) : Unidad(duenio, mapa, coords_spawn) {
    this->id = id;
    this->tipo_unidad = VEHICULO;

    std::cout << "Creando una cosechadora" << std::endl;
    std::cout << "Velocidad: " << std::endl;
    this->velocidad = atributos_unidad["Vehiculo"]["Cosechadora"]["Velocidad"].as<int16_t>();
    std::cout << "Tiempo entrenamiento: " << std::endl;
    this->tiempo_entrenamiento = atributos_unidad["Vehiculo"]["Cosechadora"]["TiempoEntrenamiento"].as<uint16_t>();
    std::cout << "Vida: " << std::endl;
    this->vida = atributos_unidad["Vehiculo"]["Cosechadora"]["Vida"].as<int16_t>();
    std::cout << "Costo: " << std::endl;
    this->costo = atributos_unidad["Vehiculo"]["Cosechadora"]["Costo"].as<uint8_t>();
    
    std::cout << "Penalizacion terreno: " << std::endl;
    std::vector<char> aux = atributos_unidad["Vehiculo"]["Cosechadora"]["PenalizacionTerreno"].as<std::vector<char>>();
    std::cout << "Penalizacion velocidad: " << std::endl;
    std::vector<float> aux_float = atributos_unidad["Vehiculo"]["Cosechadora"]["PenalizacionVelocidad"].as<std::vector<float>>();

    for (int i = 0; i < (int)aux.size(); i++) {
        this->penalizacion_terreno.insert(std::pair<char, float>(aux[i], aux_float[i]));
    }
    std::cout << "Terrenos no accesibles: " << std::endl;
    this->terrenos_no_accesibles = atributos_unidad["Vehiculo"]["Cosechadora"]["TerrenosNoAccesibles"].as<std::vector<char>>();
}
