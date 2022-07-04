#ifndef UNIDAD_DEVASTADOR_H
#define UNIDAD_DEVASTADOR_H

#include "unidades.h"

class Devastador : public Unidad {
public:
    Devastador(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn,
                YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos);
    // virtual void atacar(Unidad& unidad);
    virtual ~Devastador() = default;
};

#endif