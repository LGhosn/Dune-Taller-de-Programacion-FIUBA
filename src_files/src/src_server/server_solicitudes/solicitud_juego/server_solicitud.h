#ifndef SERVER_SOLICITUD_H
#define SERVER_SOLICITUD_H

#include "../../server_game/game.h"

class SolicitudServer {
public:
    virtual bool ejecutar(Game& game) const = 0;

    virtual ~SolicitudServer() = default;
};

#endif // SERVER_SOLICITUD_H
