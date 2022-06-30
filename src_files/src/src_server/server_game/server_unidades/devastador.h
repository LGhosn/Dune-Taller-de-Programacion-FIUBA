#ifndef UNIDAD_DEVASTADOR_H
#define UNIDAD_DEVASTADOR_H

#include "unidades.h"

class Devastador : public Unidad {
public:
    Devastador(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad);
    // virtual void atacar(Unidad& unidad);
    virtual ~Devastador() = default;
};

#endif