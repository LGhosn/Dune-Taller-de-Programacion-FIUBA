#ifndef SDL_EVENTO_H
#define SDL_EVENTO_H

#include <SDL2pp/SDL2pp.hh>
#include "../client_solicitudes/cliente_solicitud.h"
#include "../client_comandos/client_comando.h"
#include "../client_comandos/cmd_mover_mapa.h"
#include "../client_comandos/cmd_zoom.h"
#include "../client_comandos/cmd_salir.h"
#include "../pix_a_coords.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"

#define ANCHO_MENU 300
#define ANCHO_VISTA_MAPA 924
#define LARGO_VISTA_MAPA 768
#define PADDING_MOVER 100

class SDLEvento {
protected:
    ColaBloqueante<SolicitudCliente>& cola_solicitudes;
    ColaNoBloqueante<ComandoCliente>& cola_comandos;
    YAML::Node& constantes;
public:
    SDLEvento(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
            ColaNoBloqueante<ComandoCliente>& cola_comandos,
            YAML::Node& constantes);
    virtual void ejecutar_evento(SDL_Event& keyEvent) = 0;
    virtual ~SDLEvento() = default;
};

class TeclaPresionada : public SDLEvento {
public:
    TeclaPresionada(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
    ColaNoBloqueante<ComandoCliente>& cola_comandos,
    YAML::Node& constantes);
    virtual void ejecutar_evento(SDL_Event& keyEvent);
    ~TeclaPresionada() = default;
};

class TeclaLevantada : public SDLEvento {
public:
    TeclaLevantada(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                    ColaNoBloqueante<ComandoCliente>& cola_comandos,
                    YAML::Node& constantes);
    virtual void ejecutar_evento(SDL_Event& keyEvent);
    ~TeclaLevantada() = default;
};

class Rueda : public SDLEvento {
public:
    Rueda(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
            ColaNoBloqueante<ComandoCliente>& cola_comandos,
            YAML::Node& constantes);
    virtual void ejecutar_evento(SDL_Event& wheelEvent);
    ~Rueda() = default;
};

class ClickPresionado : public SDLEvento {
public:
    ClickPresionado(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                    ColaNoBloqueante<ComandoCliente>& cola_comandos,
                    YAML::Node& constantes);
    virtual void ejecutar_evento(SDL_Event& mouseButtonEvent);
    ~ClickPresionado() = default;
};

class ClickLevantado : public SDLEvento {
public:
    ClickLevantado(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                    ColaNoBloqueante<ComandoCliente>& cola_comandos,
                    YAML::Node& constantes);
    virtual void ejecutar_evento(SDL_Event& mouseButtonEvent);
    ~ClickLevantado() = default;
};

class MouseMovido : public SDLEvento {
public:
    MouseMovido(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                ColaNoBloqueante<ComandoCliente>& cola_comandos,
                YAML::Node& constantes);
    virtual void ejecutar_evento(SDL_Event& mouseEvent);
    ~MouseMovido() = default;
};

class EventoSalir : public SDLEvento {
public:
    EventoSalir(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                ColaNoBloqueante<ComandoCliente>& cola_comandos,
                YAML::Node& constantes);
    virtual void ejecutar_evento(SDL_Event& quitEvent);
    ~EventoSalir() = default;
};


#endif // SDL_EVENTO_H
