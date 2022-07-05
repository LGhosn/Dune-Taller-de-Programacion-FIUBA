#ifndef UNIDAD_RAIDER_H
#define UNIDAD_RAIDER_H

#include "unidades.h"

class Raider : public Unidad {
public:
    Raider(uint8_t id, Jugador& duenio, Mapa& mapa, YAML::Node& atributos_unidad, Coordenadas& coords_spawn, 
            YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
            std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades);
    // virtual void atacar(Unidad& unidad);
    virtual uint8_t obtenerTipoDeUnidad();
    virtual ~Raider() = default;
};

#endif