#include "unidades_mapa.h"
#include <iostream>

UnidadesMapa::UnidadesMapa(char parada_sobre) : parada_sobre(parada_sobre), tipo_entidad('U') {}

char UnidadesMapa::obtenerIdentificador() {
    return 'U';
}

char UnidadesMapa::obtenerTerrenoQueEstaParada() {
    return parada_sobre;
}

char UnidadesMapa::obtenerTipoDeEntidad() {
    return this->tipo_entidad;
}

uint16_t UnidadesMapa::obtenerIdJugador() {
    return this->id_jugador;
}
