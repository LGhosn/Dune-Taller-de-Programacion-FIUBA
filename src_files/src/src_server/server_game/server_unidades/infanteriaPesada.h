#ifndef UNIDAD_INFANTERIA_PESADA_H
#define UNIDAD_INFANTERIA_PESADA_H

#include "unidades.h"

class InfanteriaPesada : public Unidad {
public:
    InfanteriaPesada(Jugador& duenio,
                    Mapa& mapa,
                    YAML::Node& atributos_unidad,
                    YAML::Node& constantes, std::map< uint8_t,
                    ColaBloqueante<ComandoServer>* >& colas_comandos,
                    std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades);
    // virtual void atacar(Unidad& unidad);
    virtual ~InfanteriaPesada() = default;
};

#endif