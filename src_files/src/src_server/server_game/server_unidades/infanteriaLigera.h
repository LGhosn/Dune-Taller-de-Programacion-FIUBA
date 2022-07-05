#ifndef UNIDAD_INFANTERIA_LIGERA_H
#define UNIDAD_INFANTERIA_LIGERA_H

#include "unidades.h"

class InfanteriaLigera : public Unidad {
public:
    InfanteriaLigera(Jugador& duenio,
                    Mapa& mapa,
                    YAML::Node& atributos_unidad, 
                    YAML::Node& constantes, std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                    std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades);
    // virtual void atacar(Unidad& unidad);
    virtual uint8_t obtenerTipoDeUnidad();
    virtual ~InfanteriaLigera() = default;
};
#endif