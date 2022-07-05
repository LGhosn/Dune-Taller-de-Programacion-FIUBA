#ifndef CANION_H
#define CANION_H

#include "arma.h"

class Canion : public Arma {
public:
    Canion(YAML::Node& atributos_armamento, uint16_t ticks);
};

#endif