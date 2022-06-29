#include "edificios_mapa.h"
#include <iostream>

/* ******************************************************************
 *                        EDIFICIOS
 * *****************************************************************/
int Edificio::obtenerDimensionX() {
    return this->dimension_x;
}

int Edificio::obtenerDimensionY() {
    return this->dimension_y;
}

char Edificio::obtenerIdentificador() {
    return this->tipo;
}

uint16_t Edificio::obtenerIdJugador() {
    return this->id_jugador;
}

char Edificio::obtenerTipoDeEntidad() {
    return this->tipo_entidad;
}

/* ******************************************************************
 *                        CENTRO DE CONSTRUCCION
 * *****************************************************************/
CentroDeConstruccion::CentroDeConstruccion(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["CentroDeConstruccion"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["CentroDeConstruccion"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["CentroDeConstruccion"]["Tipo"].as<uint8_t>();
    this->tipo_entidad = 'E';
}

/* ******************************************************************
 *                        CUARTEL
 * *****************************************************************/
Cuartel::Cuartel(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["Cuartel"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["Cuartel"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["Cuartel"]["Tipo"].as<uint8_t>();
    this->tipo_entidad = 'E';
}


/* ******************************************************************
 *                        FABRICA LIGERA
 * *****************************************************************/
FabricaLigera::FabricaLigera(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["FabricaLigera"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["FabricaLigera"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["FabricaLigera"]["Tipo"].as<uint8_t>();
    this->tipo_entidad = 'E';
}


/* ******************************************************************
 *                        FABRICA PESADA
 * *****************************************************************/
FabricaPesada::FabricaPesada(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["FabricaPesada"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["FabricaPesada"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["FabricaPesada"]["Tipo"].as<uint8_t>();
    this->tipo_entidad = 'E';
}

/* ******************************************************************
 *                        PALACIO
 * *****************************************************************/
Palacio::Palacio(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["Palacio"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["Palacio"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["Palacio"]["Tipo"].as<uint8_t>();
    this->tipo_entidad = 'E';
}

/* ******************************************************************
 *                        REFINERIA
 * *****************************************************************/
Refineria::Refineria(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["Refineria"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["Refineria"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["Refineria"]["Tipo"].as<uint8_t>();
    this->tipo_entidad = 'E';
}

/* ******************************************************************
 *                        SILO
 * *****************************************************************/
Silo::Silo(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["Silo"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["Silo"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["Silo"]["Tipo"].as<uint8_t>();
    this->tipo_entidad = 'E';
}

/* ******************************************************************
 *                        TRAMPA DE AIRE
 * *****************************************************************/
TrampaDeAire::TrampaDeAire(YAML::Node& edificio_config, uint16_t id_jugador) {
    this->dimension_x = edificio_config["TrampaDeAire"]["DimensionX"].as<int>();
    this->dimension_y = edificio_config["TrampaDeAire"]["DimensionY"].as<int>();
    this->id_jugador = id_jugador;
    this->tipo = edificio_config["TrampaDeAire"]["Tipo"].as<uint8_t>();
    this->tipo_entidad = 'E';
}

/* ******************************************************************
 *                        MOVE SEMANTICS
 * *****************************************************************/

Edificio::Edificio(Edificio &&edificio) : 
    dimension_x(edificio.dimension_x), dimension_y(edificio.dimension_y), id_jugador(edificio.id_jugador),  tipo_entidad(edificio.tipo_entidad) {
    edificio.dimension_x = 0;
    edificio.dimension_y = 0;
    edificio.id_jugador = 0;
    edificio.tipo_entidad = ' ';
}

Edificio &Edificio::operator=(Edificio &&edificio){
    if (this == &edificio) {
        return *this;
    }
    this->dimension_x = edificio.dimension_x;
    this->dimension_y = edificio.dimension_y;
    this->id_jugador = edificio.id_jugador;
    this->tipo_entidad = edificio.tipo_entidad;

    edificio.dimension_x = 0;
    edificio.dimension_y = 0;
    edificio.id_jugador = 0;
    edificio.tipo_entidad = ' ';
    return *this;
}
