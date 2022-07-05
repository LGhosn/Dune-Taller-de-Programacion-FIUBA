#include "sardaukar.h"

Sardaukar::Sardaukar(Jugador& duenio,
                    Mapa& mapa,
                    YAML::Node& atributos_unidad,
                    YAML::Node& constantes,
                    std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos, 
                    std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                    Unidad(duenio, 3, mapa, constantes, colas_comandos, unidades) {
    this->armas = atributos_unidad["Infanteria"]["Sardaukar"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["Infanteria"]["Sardaukar"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Infanteria"]["Sardaukar"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Infanteria"]["Sardaukar"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Infanteria"]["Sardaukar"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Infanteria"]["Sardaukar"]["Costo"].as<uint16_t>();
    
    this->penalizacion_terreno = atributos_unidad["Infanteria"]["Sardaukar"]["PenalizacionTerreno"].as<std::vector<float>>();

    this->terrenos_no_accesibles = atributos_unidad["Infanteria"]["Sardaukar"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>();

    enviarComandoEmpezarEntrenamiento();
}
