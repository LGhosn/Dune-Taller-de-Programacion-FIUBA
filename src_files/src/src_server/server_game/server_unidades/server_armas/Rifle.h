#ifndef RIFLE_H
#define RIFLE_H

#include "arma.h"

class Rifle : public Arma {
public:
    Rifle(YAML::Node& atributos_armamento, uint16_t ticks);
};

#endif