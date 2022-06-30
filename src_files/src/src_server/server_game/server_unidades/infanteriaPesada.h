#ifndef UNIDAD_INFANTERIA_PESADA_H
#define UNIDAD_INFANTERIA_PESADA_H

#include "unidades.h"

class InfanteriaPesada : public Unidad {
public:
    InfanteriaPesada(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad);
    // virtual void atacar(Unidad& unidad);
    virtual ~InfanteriaPesada() = default;
};

#endif