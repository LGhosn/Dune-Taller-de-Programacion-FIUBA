#include "fremen.h"

Fremen::Fremen(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn,
            YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
            std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) : 
            Unidad(duenio, mapa, coords_spawn, constantes, colas_comandos, unidades) {
    this->id = id;
    this->tipo_unidad = INFANTERIA;

    this->armas = atributos_unidad["Infanteria"]["Fremen"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["Infanteria"]["Fremen"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Infanteria"]["Fremen"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Infanteria"]["Fremen"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Infanteria"]["Fremen"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Infanteria"]["Fremen"]["Costo"].as<uint16_t>();
    
    this->penalizacion_terreno = atributos_unidad["Infanteria"]["Fremen"]["PenalizacionTerreno"].as<std::vector<float>>();

    this->terrenos_no_accesibles = atributos_unidad["Infanteria"]["Fremen"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>();
}
