#ifndef LANZA_MISILES_H
#define LANZA_MISILES_H

#include "arma.h"

class LanzaMisiles : public Arma {
public:
    LanzaMisiles(YAML::Node& atributos_armamento);
};

#endif