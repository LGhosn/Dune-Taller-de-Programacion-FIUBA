#include "infanteriaPesada.h"

InfanteriaPesada::InfanteriaPesada(Jugador& duenio,
                                Mapa& mapa,
                                YAML::Node& atributos_unidad,
                                YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) : 
                                    Unidad(duenio, 2, mapa, constantes, colas_comandos, unidades) {
    this->armas = atributos_unidad["Infanteria"]["InfanteriaPesada"]["Arma"].as<std::vector<std::string>>();
    this->rango = atributos_unidad["Infanteria"]["InfanteriaPesada"]["Rango"].as<uint8_t>();
    this->velocidad = atributos_unidad["Infanteria"]["InfanteriaPesada"]["Velocidad"].as<int16_t>();
    this->tiempo_entrenamiento = atributos_unidad["Infanteria"]["InfanteriaPesada"]["TiempoEntrenamiento"].as<uint16_t>();
    this->vida = atributos_unidad["Infanteria"]["InfanteriaPesada"]["Vida"].as<int16_t>();
    this->costo = atributos_unidad["Infanteria"]["InfanteriaPesada"]["Costo"].as<uint16_t>();
    
    this->penalizacion_terreno = atributos_unidad["Infanteria"]["InfanteriaPesada"]["PenalizacionTerreno"].as<std::vector<float>>();

    this->terrenos_no_accesibles = atributos_unidad["Infanteria"]["InfanteriaPesada"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>();

    enviarComandoEmpezarEntrenamiento();
}

uint8_t InfanteriaPesada::obtenerTipoDeUnidad() {
    return 0;
}