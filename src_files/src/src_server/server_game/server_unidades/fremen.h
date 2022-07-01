#ifndef UNIDAD_FREMEN_H
#define UNIDAD_FREMEN_H

#include "unidades.h"

class Fremen : public Unidad {
public:
    Fremen(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn);
    // virtual void atacar(Unidad& unidad);
    virtual ~Fremen() = default;
};

#endif