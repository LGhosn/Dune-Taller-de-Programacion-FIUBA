#ifndef UNIDAD_TANQUE_H
#define UNIDAD_TANQUE_H

#include "unidades.h"

class Tanque : public Unidad {
public:
    Tanque(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn, YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos);
    // virtual void atacar(Unidad& unidad);
    virtual ~Tanque() = default;
};

#endif // UNIDAD_TANQUE_H
