#include "infanteriaPesada.h"
#include "server_armas/LanzaMisiles.h"

InfanteriaPesada::InfanteriaPesada(Jugador& duenio,
                                Mapa& mapa,
                                YAML::Node& atributos_unidad,
                                YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                                ArmaFactory& arma_factory,
                                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) : 
        Unidad(duenio,
                2,
                mapa,
                constantes,
                colas_comandos,
                atributos_unidad["Infanteria"]["InfanteriaPesada"]["Rango"].as<uint8_t>(),
                atributos_unidad["Infanteria"]["InfanteriaPesada"]["Velocidad"].as<float>(),
                atributos_unidad["Infanteria"]["InfanteriaPesada"]["TiempoEntrenamiento"].as<uint16_t>(),
                atributos_unidad["Infanteria"]["InfanteriaPesada"]["Vida"].as<int16_t>(),
                atributos_unidad["Infanteria"]["InfanteriaPesada"]["Costo"].as<uint16_t>(),
                atributos_unidad["Infanteria"]["InfanteriaPesada"]["PenalizacionTerreno"].as<std::vector<float>>(),
                atributos_unidad["Infanteria"]["InfanteriaPesada"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                arma_factory,
                unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t InfanteriaPesada::obtenerTipoDeUnidad() {
    return 0;
}