#include "raider.h"

Raider::Raider(Jugador& duenio,
                Mapa& mapa,
                YAML::Node& atributos_unidad,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                Unidad(duenio, 7, mapa, constantes, colas_comandos, unidades) {

    this->armas = atributos_unidad["Vehiculo"]["Raider"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["Vehiculo"]["Raider"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Vehiculo"]["Raider"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Vehiculo"]["Raider"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Vehiculo"]["Raider"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Vehiculo"]["Raider"]["Costo"].as<uint16_t>();
    
    this->penalizacion_terreno = atributos_unidad["Vehiculo"]["Raider"]["PenalizacionTerreno"].as<std::vector<float>>();

    this->terrenos_no_accesibles = atributos_unidad["Vehiculo"]["Raider"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>();

    enviarComandoEmpezarEntrenamiento();
}
