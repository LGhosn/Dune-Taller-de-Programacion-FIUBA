#include "tanque.h"
#include "server_armas/Canion.h"

Tanque::Tanque(Jugador& duenio,
                Mapa& mapa,
                YAML::Node& atributos_unidad,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                Unidad(duenio, 8, mapa, constantes, colas_comandos, unidades) {
    this->rango = atributos_unidad["Vehiculo"]["Tanque"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Vehiculo"]["Tanque"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Vehiculo"]["Tanque"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Vehiculo"]["Tanque"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Vehiculo"]["Tanque"]["Costo"].as<uint16_t>();
    
    this->penalizacion_terreno = atributos_unidad["Vehiculo"]["Tanque"]["PenalizacionTerreno"].as<std::vector<float>>();
    this->terrenos_no_accesibles = atributos_unidad["Vehiculo"]["Tanque"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>();

    this->arma = std::unique_ptr<Arma>(new Canion(atributos_unidad, ticks));

    enviarComandoEmpezarEntrenamiento();
}

uint8_t Tanque::obtenerTipoDeUnidad() {
    return 1;
}