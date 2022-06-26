#include "edificios.h"

/* ******************************************************************
 *                        EDIFICIOS
 * *****************************************************************/
int Edificio::obtenerDimensionX() {
    return this->dimension_x;
}

int Edificio::obtenerDimensionY() {
    return this->dimension_y;
}

char Edificio::obtenerTipo() {
    return this->tipo;
}

/* ******************************************************************
 *                        CUARTEL
 * *****************************************************************/
Cuartel::Cuartel(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["Cuartel"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["Cuartel"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["Cuartel"]["Tipo"].as<char>();
}


/* ******************************************************************
 *                        FABRICA LIGERA
 * *****************************************************************/
FabricaLigera::FabricaLigera(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["FabricaLigera"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["FabricaLigera"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["FabricaLigera"]["Tipo"].as<char>();
}


/* ******************************************************************
 *                        FABRICA PESADA
 * *****************************************************************/
FabricaPesada::FabricaPesada(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["FabricaPesada"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["FabricaPesada"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["FabricaPesada"]["Tipo"].as<char>();
}

/* ******************************************************************
 *                        PALACIO
 * *****************************************************************/
Palacio::Palacio(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["Palacio"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["Palacio"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["Palacio"]["Tipo"].as<char>();
}

/* ******************************************************************
 *                        REFINERIA
 * *****************************************************************/
Refineria::Refineria(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["Refineria"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["Refineria"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["Refineria"]["Tipo"].as<char>();
}

/* ******************************************************************
 *                        SILO
 * *****************************************************************/
Silo::Silo(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["Silo"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["Silo"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["Silo"]["Tipo"].as<char>();
}

/* ******************************************************************
 *                        TRAMPA DE AIRE
 * *****************************************************************/
TrampaDeAire::TrampaDeAire(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["TrampaDeAire"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["TrampaDeAire"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["TrampaDeAire"]["Tipo"].as<char>();
}
