#include "trike.h"
#include "server_armas/Rifle.h"

Trike::Trike(Jugador& duenio,
            Mapa& mapa,
            YAML::Node& atributos_unidad,
            YAML::Node& constantes,
            std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
            std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
            Unidad(duenio, CODIGO_TRIKE, mapa, constantes, colas_comandos, unidades) {
    this->rango = atributos_unidad["Vehiculo"]["Trike"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Vehiculo"]["Trike"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Vehiculo"]["Trike"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Vehiculo"]["Trike"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Vehiculo"]["Trike"]["Costo"].as<uint16_t>();
    
    this->penalizacion_terreno = atributos_unidad["Vehiculo"]["Trike"]["PenalizacionTerreno"].as<std::vector<float>>();
    this->terrenos_no_accesibles = atributos_unidad["Vehiculo"]["Trike"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>();

    this->arma = std::unique_ptr<Arma>(new Rifle(atributos_unidad, id, ticks));

    enviarComandoEmpezarEntrenamiento();
}

uint8_t Trike::obtenerTipoDeUnidad() {
    return 1;
}
