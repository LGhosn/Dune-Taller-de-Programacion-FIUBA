#include "unidades_mapa.h"

UnidadesMapa::UnidadesMapa(char parada_sobre) : parada_sobre(parada_sobre) {}

char UnidadesMapa::obtenerTipo() {
    return 'U';
}

char UnidadesMapa::obtenerTerrenoQueEstaParada() {
    return parada_sobre;
}
