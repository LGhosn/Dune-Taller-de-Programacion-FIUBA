#ifndef CANION_22_MM_H
#define CANION_22_MM_H

#include "arma.h"

class Canion22mm : public Arma {
public:
    Canion22mm(YAML::Node& atributos_armamento, uint8_t id_unidad_portador, uint16_t ticks);
};

#endif