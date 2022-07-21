#include "sardaukar.h"
#include "server_armas/LanzaMisiles.h"

Sardaukar::Sardaukar(Jugador& duenio,
                    Mapa& mapa,
                    YAML::Node& atributos_unidad,
                    YAML::Node& constantes,
                    std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                    ArmaFactory& arma_factory,
                    std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
            Unidad(duenio,
                    3,
                    mapa,
                    constantes,
                    colas_comandos,
                    atributos_unidad["Infanteria"]["Sardaukar"]["Rango"].as<uint8_t>(),
                    atributos_unidad["Infanteria"]["Sardaukar"]["Velocidad"].as<float>(),
                    atributos_unidad["Infanteria"]["Sardaukar"]["TiempoEntrenamiento"].as<uint16_t>(),
                    atributos_unidad["Infanteria"]["Sardaukar"]["Vida"].as<int16_t>(),
                    atributos_unidad["Infanteria"]["Sardaukar"]["Costo"].as<uint16_t>(),
                    atributos_unidad["Infanteria"]["Sardaukar"]["PenalizacionTerreno"].as<std::vector<float>>(),
                    atributos_unidad["Infanteria"]["Sardaukar"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                    arma_factory,
                    unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t Sardaukar::obtenerTipoDeUnidad() {
    return 0;
}
