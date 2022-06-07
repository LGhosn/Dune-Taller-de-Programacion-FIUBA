#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "../../src_game/game.h"

class Solicitud {
public:
    virtual bool ejecutar(Game& game) const = 0;

    virtual ~Solicitud();
};

#endif
