#include <string>
#include <vector>
#include "infanteriaLigera.h"
#include "server_armas/Rifle.h"

InfanteriaLigera::InfanteriaLigera(Jugador& duenio,
                                    Mapa& mapa,
                                    YAML::Node& atributos_unidad,
                                    YAML::Node& constantes,
                                    std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                                    ArmaFactory& arma_factory,
                                    std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) : 
            Unidad(duenio,
                    1,
                    mapa,
                    constantes,
                    colas_comandos,
                    atributos_unidad["Infanteria"]["InfanteriaLigera"]["Rango"].as<uint8_t>(),
                    atributos_unidad["Infanteria"]["InfanteriaLigera"]["Velocidad"].as<float>(),
                    atributos_unidad["Infanteria"]["InfanteriaLigera"]["TiempoEntrenamiento"].as<uint16_t>(),
                    atributos_unidad["Infanteria"]["InfanteriaLigera"]["Vida"].as<int16_t>(),
                    atributos_unidad["Infanteria"]["InfanteriaLigera"]["Costo"].as<uint16_t>(),
                    atributos_unidad["Infanteria"]["InfanteriaLigera"]["PenalizacionTerreno"].as<std::vector<float>>(),
                    atributos_unidad["Infanteria"]["InfanteriaLigera"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                    arma_factory,
                    unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t InfanteriaLigera::obtenerTipoDeUnidad() {
    return 0;
}