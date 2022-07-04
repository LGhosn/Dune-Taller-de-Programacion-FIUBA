#ifndef UNIDAD_DESVIADOR_H
#define UNIDAD_DESVIADOR_H

#include "unidades.h"

class Desviador : public Unidad {
public:
    Desviador(uint8_t id,
            Jugador& duenio,
            Mapa& mapa,
            YAML::Node& atributos_unidad,
            Coordenadas& coords_spawn,
            YAML::Node& constantes,
            std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos);
    // virtual void atacar(Unidad& unidad);
    virtual ~Desviador() = default;
};

#endif