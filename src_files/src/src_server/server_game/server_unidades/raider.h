#ifndef UNIDAD_RAIDER_H
#define UNIDAD_RAIDER_H

#include "unidades.h"

class Raider : public Unidad {
public:
    Raider(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn, YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos);
    // virtual void atacar(Unidad& unidad);
    virtual ~Raider() = default;
};

#endif