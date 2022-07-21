#include "desviador.h"
#include "server_armas/LanzaMisiles.h"

Desviador::Desviador(Jugador& duenio,
                    Mapa& mapa,
                    YAML::Node& atributos_unidad,
                    YAML::Node& constantes,
                    std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                    ArmaFactory& arma_factory,
                    std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                    Unidad(duenio,
                            5,
                            mapa,
                            constantes,
                            colas_comandos,
                            atributos_unidad["Vehiculo"]["Desviador"]["Rango"].as<uint8_t>(),
                            atributos_unidad["Vehiculo"]["Desviador"]["Velocidad"].as<float>(),
                            atributos_unidad["Vehiculo"]["Desviador"]["TiempoEntrenamiento"].as<uint16_t>(),
                            atributos_unidad["Vehiculo"]["Desviador"]["Vida"].as<int16_t>(),
                            atributos_unidad["Vehiculo"]["Desviador"]["Costo"].as<uint16_t>(),
                            atributos_unidad["Vehiculo"]["Desviador"]["PenalizacionTerreno"].as<std::vector<float>>(),
                            atributos_unidad["Vehiculo"]["Desviador"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                            arma_factory,
                            unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t Desviador::obtenerTipoDeUnidad() {
    return 1;
}
