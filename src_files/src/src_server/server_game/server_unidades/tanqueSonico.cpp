#include "tanqueSonico.h"
#include "server_armas/OndasDeSonido.h"

TanqueSonico::TanqueSonico(Jugador& duenio,
                            Mapa& mapa,
                            YAML::Node& atributos_unidad,
                            YAML::Node& constantes,
                            std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                            ArmaFactory& arma_factory,
                            std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                            Unidad(duenio,
                                    9,
                                    mapa,
                                    constantes,
                                    colas_comandos,
                                    atributos_unidad["Vehiculo"]["TanqueSonico"]["Rango"].as<uint8_t>(),
                                    atributos_unidad["Vehiculo"]["TanqueSonico"]["Velocidad"].as<float>(),
                                    atributos_unidad["Vehiculo"]["TanqueSonico"]["TiempoEntrenamiento"].as<uint16_t>(),
                                    atributos_unidad["Vehiculo"]["TanqueSonico"]["Vida"].as<int16_t>(),
                                    atributos_unidad["Vehiculo"]["TanqueSonico"]["Costo"].as<uint16_t>(),
                                    atributos_unidad["Vehiculo"]["TanqueSonico"]["PenalizacionTerreno"].as<std::vector<float>>(),
                                    atributos_unidad["Vehiculo"]["TanqueSonico"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                                    arma_factory,
                                    unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t TanqueSonico::obtenerTipoDeUnidad() {
    return 1;
}