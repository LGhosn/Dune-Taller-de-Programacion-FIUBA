#include "fremen.h"
#include "server_armas/Rifle.h"

Fremen::Fremen(Jugador& duenio,
                Mapa& mapa,
                YAML::Node& atributos_unidad,
                YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                ArmaFactory& arma_factory,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) : 
            Unidad(duenio,
                    0,
                    mapa,
                    constantes,
                    colas_comandos,
                    atributos_unidad["Infanteria"]["Fremen"]["Rango"].as<uint8_t>(),
                    atributos_unidad["Infanteria"]["Fremen"]["Velocidad"].as<float>(),
                    atributos_unidad["Infanteria"]["Fremen"]["TiempoEntrenamiento"].as<uint16_t>(),
                    atributos_unidad["Infanteria"]["Fremen"]["Vida"].as<int16_t>(),
                    atributos_unidad["Infanteria"]["Fremen"]["Costo"].as<uint16_t>(),
                    atributos_unidad["Infanteria"]["Fremen"]["PenalizacionTerreno"].as<std::vector<float>>(),
                    atributos_unidad["Infanteria"]["Fremen"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                    arma_factory,
                    unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t Fremen::obtenerTipoDeUnidad() {
    return 0;
}