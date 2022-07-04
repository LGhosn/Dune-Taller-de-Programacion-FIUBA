#ifndef UNIDAD_TRIKE_H
#define UNIDAD_TRIKE_H

#include "unidades.h"

class Trike : public Unidad {
public:
    Trike(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn, YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos);
    // virtual void atacar(Unidad& unidad);
    virtual ~Trike() = default;
};

#endif