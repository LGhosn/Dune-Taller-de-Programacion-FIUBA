#include "tanque.h"
#include "server_armas/Canion.h"

Tanque::Tanque(Jugador& duenio,
                Mapa& mapa,
                YAML::Node& atributos_unidad,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                ArmaFactory& arma_factory,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                Unidad(duenio,
                        8,
                        mapa,
                        constantes,
                        colas_comandos,
                        atributos_unidad["Vehiculo"]["Tanque"]["Rango"].as<uint8_t>(),
                        atributos_unidad["Vehiculo"]["Tanque"]["Velocidad"].as<float>(),
                        atributos_unidad["Vehiculo"]["Tanque"]["TiempoEntrenamiento"].as<uint16_t>(),
                        atributos_unidad["Vehiculo"]["Tanque"]["Vida"].as<int16_t>(),
                        atributos_unidad["Vehiculo"]["Tanque"]["Costo"].as<uint16_t>(),
                        atributos_unidad["Vehiculo"]["Tanque"]["PenalizacionTerreno"].as<std::vector<float>>(),
                        atributos_unidad["Vehiculo"]["Tanque"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                        arma_factory,
                        unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t Tanque::obtenerTipoDeUnidad() {
    return 1;
}