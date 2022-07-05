#ifndef CANION_DE_PLASMA_H
#define CANION_DE_PLASMA_H

#include "arma.h"

class CanionDePlasma : public Arma {
public:
    CanionDePlasma(YAML::Node& atributos_armamento, uint8_t id_unidad_portador, uint16_t ticks);
};

#endif