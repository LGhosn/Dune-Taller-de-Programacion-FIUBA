#ifndef UNIDAD_TANQUE_H
#define UNIDAD_TANQUE_H

#include "unidades.h"

class Tanque : public Unidad {
public:
    Tanque(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn);
    // virtual void atacar(Unidad& unidad);
    virtual ~Tanque() = default;
};

#endif // UNIDAD_TANQUE_H
