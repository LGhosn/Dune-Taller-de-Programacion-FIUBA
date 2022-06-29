#ifndef SERVER_SOLICITUD_MENU_H
#define SERVER_SOLICITUD_MENU_H

#include "../server_lobby.h"

class Lobby;

class SolicitudMenuServer {
public:
    SolicitudMenuServer() = default;
    virtual void manejarSolicitud(Lobby& lobby) const = 0;
    virtual ~SolicitudMenuServer() = default;
};

#endif // SERVER_SOLICITUD_MENU_H
