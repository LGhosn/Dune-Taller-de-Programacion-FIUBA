#ifndef SERVER_MODO_ATAQUE_H
#define SERVER_MODO_ATAQUE_H

#include "unidad_comportamiento.h"

class UnidadModoAtaque : public UnidadComportamiento {
public:
    UnidadModoAtaque(Unidad* unidad,
                    std::shared_ptr<EntidadServer>& entidad_a_atacar);

    virtual std::unique_ptr<UnidadComportamiento> atacar(std::shared_ptr<EntidadServer> entidad_a_atacar);
    virtual std::unique_ptr<UnidadComportamiento> moverA(const Coordenadas& destino);

    virtual void update(long ticks_transcurridos);
};

#endif // SERVER_MODO_ATAQUE_H
