#include "raider.h"
#include "server_armas/Canion22mm.h"

Raider::Raider(Jugador& duenio,
                Mapa& mapa,
                YAML::Node& atributos_unidad,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                ArmaFactory& arma_factory,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades) :
                Unidad(duenio,
                        7,
                        mapa,
                        constantes,
                        colas_comandos,
                        atributos_unidad["Vehiculo"]["Raider"]["Rango"].as<uint8_t>(),
                        atributos_unidad["Vehiculo"]["Raider"]["Velocidad"].as<float>(),
                        atributos_unidad["Vehiculo"]["Raider"]["TiempoEntrenamiento"].as<uint16_t>(),
                        atributos_unidad["Vehiculo"]["Raider"]["Vida"].as<int16_t>(),
                        atributos_unidad["Vehiculo"]["Raider"]["Costo"].as<uint16_t>(),
                        atributos_unidad["Vehiculo"]["Raider"]["PenalizacionTerreno"].as<std::vector<float>>(),
                        atributos_unidad["Vehiculo"]["Raider"]["TerrenosNoAccesibles"].as<std::vector<uint8_t>>(),
                        arma_factory,
                        unidades) {
    enviarComandoEmpezarEntrenamiento();
}

uint8_t Raider::obtenerTipoDeUnidad() {
    return 1;
}