#ifndef ONDAS_DE_SONIDO_H
#define ONDAS_DE_SONIDO_H

#include "arma.h"

class OndasDeSonido : public Arma {
public:
    OndasDeSonido(YAML::Node& atributos_armamento, uint8_t id_unidad_portador, uint16_t ticks);
};

#endif
