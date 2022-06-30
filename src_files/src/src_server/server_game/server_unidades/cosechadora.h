#ifndef UNIDAD_COSECHADORA_H
#define UNIDAD_COSECHADORA_H

#include "unidades.h"

class Cosechadora : public Unidad {
public:
    Cosechadora(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad);
    // virtual void atacar(Unidad& unidad);
    virtual ~Cosechadora() = default;
};

#endif
