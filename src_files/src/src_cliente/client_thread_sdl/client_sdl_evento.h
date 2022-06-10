#ifndef SDL_EVENTO_H
#define SDL_EVENTO_H

#include <SDL2pp/SDL2pp.hh>
#include "../client_solicitudes/cliente_solicitud.h"
#include "../client_comandos/client_comando.h"
#include "../client_comandos/cmd_mover_mapa.h"
#include "../client_comandos/cmd_salir.h"
#include "../pix_a_coords.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"

class SDLEvento {
public:
    SDLEvento() = default;
    virtual void ejecutar_evento(SDL_Event& keyEvent) = 0;
    virtual ~SDLEvento() = default;
};

class TeclaPresionada : public SDLEvento {
private:
    ColaBloqueante<SolicitudCliente>& cola_solicitudes;
    ColaNoBloqueante<ComandoCliente>& cola_comandos;

public:
    TeclaPresionada(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
    ColaNoBloqueante<ComandoCliente>& cola_comandos);
    virtual void ejecutar_evento(SDL_Event& keyEvent);
    ~TeclaPresionada() = default;
};

class TeclaLevantada : public SDLEvento {
private:
    ColaBloqueante<SolicitudCliente>& cola_solicitudes;
    ColaNoBloqueante<ComandoCliente>& cola_comandos;

public:
    TeclaLevantada(ColaBloqueante<SolicitudCliente>& cola_solicitudes, ColaNoBloqueante<ComandoCliente>& cola_comandos);
    virtual void ejecutar_evento(SDL_Event& keyEvent);
    ~TeclaLevantada() = default;
};

class Rueda : public SDLEvento {
private:
    ColaBloqueante<SolicitudCliente>& cola_solicitudes;
    ColaNoBloqueante<ComandoCliente>& cola_comandos;
public:
    Rueda(ColaBloqueante<SolicitudCliente>& cola_solicitudes, ColaNoBloqueante<ComandoCliente>& cola_comandos);
    virtual void ejecutar_evento(SDL_Event& wheelEvent);
    ~Rueda() = default;
};

class ClickPresionado : public SDLEvento {
private:
    ColaBloqueante<SolicitudCliente>& cola_solicitudes;
    ColaNoBloqueante<ComandoCliente>& cola_comandos;
public:
    ClickPresionado(ColaBloqueante<SolicitudCliente>& cola_solicitudes, ColaNoBloqueante<ComandoCliente>& cola_comandos);
    virtual void ejecutar_evento(SDL_Event& mouseButtonEvent);
    ~ClickPresionado() = default;
};

class ClickLevantado : public SDLEvento {
private:
    ColaBloqueante<SolicitudCliente>& cola_solicitudes;
    ColaNoBloqueante<ComandoCliente>& cola_comandos;
public:
    ClickLevantado(ColaBloqueante<SolicitudCliente>& cola_solicitudes, ColaNoBloqueante<ComandoCliente>& cola_comandos);
    virtual void ejecutar_evento(SDL_Event& mouseButtonEvent);
    ~ClickLevantado() = default;
};


#endif // SDL_EVENTO_H
