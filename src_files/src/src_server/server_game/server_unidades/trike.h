#ifndef UNIDAD_TRIKE_H
#define UNIDAD_TRIKE_H

#include "unidades.h"

class Trike : public Unidad {
public:
    Trike(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad);
    // virtual void atacar(Unidad& unidad);
    virtual ~Trike() = default;
};

#endif