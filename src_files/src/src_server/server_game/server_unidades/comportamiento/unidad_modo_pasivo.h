#ifndef SERVER_UNIDAD_MODO_PASIVO_H
#define SERVER_UNIDAD_MODO_PASIVO_H

#include "unidad_comportamiento.h"

class UnidadModoPasivo : public UnidadComportamiento {
    Coordenadas destino;
    bool moviendose = false;
public:
    UnidadModoPasivo(Unidad* unidad, const Coordenadas& destino_inicial);
    
    virtual void atacar(std::shared_ptr<EntidadServer> entidad_a_atacar);
    virtual void moverA(const Coordenadas& destino);

    virtual void update(long ticks_transcurridos);
};

#endif // SERVER_UNIDAD_MODO_PASIVO_H
