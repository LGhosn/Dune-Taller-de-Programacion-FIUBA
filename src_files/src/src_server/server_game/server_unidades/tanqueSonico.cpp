#include "tanqueSonico.h"

TanqueSonico::TanqueSonico(Jugador& duenio,
                            Mapa& mapa,
                            YAML::Node& atributos_unidad,
                            YAML::Node& constantes,
                            std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                            std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                            Unidad(duenio, 9, mapa, constantes, colas_comandos, unidades) {
    this->armas = atributos_unidad["Vehiculo"]["TanqueSonico"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["Vehiculo"]["TanqueSonico"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Vehiculo"]["TanqueSonico"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Vehiculo"]["TanqueSonico"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Vehiculo"]["TanqueSonico"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Vehiculo"]["TanqueSonico"]["Costo"].as<uint16_t>();
    this->penalizacion_terreno = atributos_unidad["Vehiculo"]["TanqueSonico"]["PenalizacionTerreno"].as<std::vector<float>>();

    this->terrenos_no_accesibles = atributos_unidad["Vehiculo"]["TanqueSonico"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>();

    enviarComandoEmpezarEntrenamiento();
}
