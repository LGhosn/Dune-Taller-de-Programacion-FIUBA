#include "unidades_mapa.h"
#include <iostream>

UnidadesMapa::UnidadesMapa(char parada_sobre, uint8_t tipo_unidad, uint8_t id_jugador, uint8_t id_unidad) : 
                            parada_sobre(parada_sobre), id_jugador(id_jugador), id_unidad(id_unidad), tipo_unidad(tipo_unidad), tipo_entidad('U') {}

char UnidadesMapa::obtenerIdentificador() {
    return 'U';
}

char UnidadesMapa::obtenerTerrenoQueEstaParada() {
    return parada_sobre;
}

char UnidadesMapa::obtenerTipoDeEntidad() {
    return this->tipo_entidad;
}

uint8_t UnidadesMapa::obtenerIdJugador() {
    return this->id_jugador;
}

uint8_t UnidadesMapa::obtenerTipoDeUnidad() {
    return this->tipo_unidad;
}

uint8_t UnidadesMapa::obtenerIdUnidad() {
    return this->id_unidad;
}
