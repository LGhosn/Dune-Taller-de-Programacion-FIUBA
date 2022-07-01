#ifndef UNIDAD_TANQUE_SONICO_H
#define UNIDAD_TANQUE_SONICO_H

#include "unidades.h"

class TanqueSonico : public Unidad {
public:
    TanqueSonico(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn);
    // virtual void atacar(Unidad& unidad);
    virtual ~TanqueSonico() = default;
};

#endif