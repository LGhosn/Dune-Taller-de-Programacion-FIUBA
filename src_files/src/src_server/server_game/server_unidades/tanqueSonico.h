#ifndef UNIDAD_TANQUE_SONICO_H
#define UNIDAD_TANQUE_SONICO_H

#include "unidades.h"

class TanqueSonico : public Unidad {
public:
    TanqueSonico(Jugador& duenio,
                Mapa& mapa,
                YAML::Node& atributos_unidad,
                YAML::Node& constantes,
                std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
                ArmaFactory& arma_factory,
                std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades);
    // virtual void atacar(Unidad& unidad);
    virtual uint8_t obtenerTipoDeUnidad();
    virtual ~TanqueSonico() = default;
};
#endif