#ifndef UNIDAD_DESVIADOR_H
#define UNIDAD_DESVIADOR_H

#include "unidades.h"

class Desviador : public Unidad {
public:
    Desviador(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn);
    // virtual void atacar(Unidad& unidad);
    virtual ~Desviador() = default;
};

#endif