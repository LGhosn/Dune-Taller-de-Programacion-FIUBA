#ifndef UNIDAD_INFANTERIA_LIGERA_H
#define UNIDAD_INFANTERIA_LIGERA_H

#include "unidades.h"

class InfanteriaLigera : public Unidad {
public:
    InfanteriaLigera(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn);
    // virtual void atacar(Unidad& unidad);
    virtual ~InfanteriaLigera() = default;
};
#endif