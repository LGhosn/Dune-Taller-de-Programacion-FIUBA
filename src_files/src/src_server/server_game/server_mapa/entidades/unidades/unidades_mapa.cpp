#include "unidades_mapa.h"

Unidades::Unidades(char parada_sobre) : parada_sobre(parada_sobre) {}

char Unidades::obtenerTipo() {
    return 'U';
}

char Unidades::obtenerTerrenoQueEstaParada() {
    return parada_sobre;
}
