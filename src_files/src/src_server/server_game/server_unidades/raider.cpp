#include "raider.h"

Raider::Raider(uint8_t id,
                Jugador& duenio,
                Mapa& mapa,
                YAML::Node& atributos_unidad,
                Coordenadas& coords_spawn,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos) :
                Unidad(duenio, mapa, coords_spawn, constantes, colas_comandos) {
    this->id = id;
    this->tipo_unidad = VEHICULO;

    this->armas = atributos_unidad["Vehiculo"]["Raider"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["Vehiculo"]["Raider"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Vehiculo"]["Raider"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Vehiculo"]["Raider"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Vehiculo"]["Raider"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Vehiculo"]["Raider"]["Costo"].as<uint16_t>();
    
    this->penalizacion_terreno = atributos_unidad["Vehiculo"]["Raider"]["PenalizacionTerreno"].as<std::vector<float>>();

    this->terrenos_no_accesibles = atributos_unidad["Vehiculo"]["Raider"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>();
}
