#include "trike.h"
#include "server_armas/Rifle.h"

Trike::Trike(Jugador& duenio,
            Mapa& mapa,
            YAML::Node& atributos_unidad,
            YAML::Node& constantes,
            std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
            ArmaFactory& arma_factory,
            std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
            Unidad(duenio,
                    CODIGO_TRIKE,
                    mapa,
                    constantes,
                    colas_comandos,
                    atributos_unidad["Vehiculo"]["Trike"]["Rango"].as<uint8_t>(),
                    atributos_unidad["Vehiculo"]["Trike"]["Velocidad"].as<float>(),
                    atributos_unidad["Vehiculo"]["Trike"]["TiempoEntrenamiento"].as<uint16_t>(),
                    atributos_unidad["Vehiculo"]["Trike"]["Vida"].as<int16_t>(),
                    atributos_unidad["Vehiculo"]["Trike"]["Costo"].as<uint16_t>(),
                    atributos_unidad["Vehiculo"]["Trike"]["PenalizacionTerreno"].as<std::vector<float>>(),
                    atributos_unidad["Vehiculo"]["Trike"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                    arma_factory,
                    unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t Trike::obtenerTipoDeUnidad() {
    return 1;
}
