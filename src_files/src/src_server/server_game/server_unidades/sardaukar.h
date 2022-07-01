#ifndef UNIDAD_SARDAUKAR_H
#define UNIDAD_SARDAUKAR_H

#include "unidades.h"

class Sardaukar : public Unidad {
public:
    Sardaukar(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn);
    // virtual void atacar(Unidad& unidad);
    virtual ~Sardaukar() = default;
};

#endif