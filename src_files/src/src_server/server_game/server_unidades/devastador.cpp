#include "devastador.h"
#include "server_armas/CanionDePlasma.h"

Devastador::Devastador(Jugador& duenio,
                        Mapa& mapa,
                        YAML::Node& atributos_unidad,
                        YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                        ArmaFactory& arma_factory,
                        std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) : 
                        Unidad(duenio,
                                6,
                                mapa,
                                constantes,
                                colas_comandos,
                                atributos_unidad["Vehiculo"]["Devastador"]["Rango"].as<uint8_t>(),
                                atributos_unidad["Vehiculo"]["Devastador"]["Velocidad"].as<float>(),
                                atributos_unidad["Vehiculo"]["Devastador"]["TiempoEntrenamiento"].as<uint16_t>(),
                                atributos_unidad["Vehiculo"]["Devastador"]["Vida"].as<int16_t>(),
                                atributos_unidad["Vehiculo"]["Devastador"]["Costo"].as<uint16_t>(),
                                atributos_unidad["Vehiculo"]["Devastador"]["PenalizacionTerreno"].as<std::vector<float>>(),
                                atributos_unidad["Vehiculo"]["Devastador"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                                arma_factory,
                                unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t Devastador::obtenerTipoDeUnidad() {
    return 1;
}