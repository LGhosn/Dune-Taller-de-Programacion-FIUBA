#ifndef UNIDAD_DESVIADOR_H
#define UNIDAD_DESVIADOR_H

#include "unidades.h"

class Desviador : public Unidad {
public:
    Desviador(Jugador& duenio,
            Mapa& mapa,
            YAML::Node& atributos_unidad,
            YAML::Node& constantes,
            std::map< uint8_t, ColaBloqueante<ComandoServer>* >& colas_comandos,
            std::unordered_map<uint8_t, std::shared_ptr<Unidad> >& unidades);
    // virtual void atacar(Unidad& unidad);
    virtual uint8_t obtenerTipoDeUnidad();
    virtual ~Desviador() = default;
};

#endif