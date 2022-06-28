#ifndef UNIDADES_H
#define UNIDADES_H

#include <cstdint>

#include "../entidades_mapa.h"

class UnidadesMapa : public Entidades {
protected:
    char parada_sobre;
    uint16_t id_jugador;

public:
    UnidadesMapa(char parada_sobre);
    virtual char obtenerTipo();
    virtual char obtenerTerrenoQueEstaParada();
    virtual ~UnidadesMapa() = default;
};

#endif // UNIDADES_H
