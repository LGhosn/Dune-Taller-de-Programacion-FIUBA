#ifndef UNIDADES_H
#define UNIDADES_H

#include <cstdint>

#include "../entidades_mapa.h"

class Unidades : public Entidades {
protected:
    char parada_sobre;
    uint16_t id_jugador;

public:
    Unidades(char parada_sobre);
    virtual char obtenerTipo();
    virtual char obtenerTerrenoQueEstaParada();
    virtual ~Unidades() = default;
};

#endif // UNIDADES_H
