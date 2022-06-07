#ifndef SDL_EVENTO_H
#define SDL_EVENTO_H

#include <SDL2pp/SDL2pp.hh>
#include "../../src_common/common_comandos/comando_a_enviar.h"
#include "../pix_a_coords.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"

class SDLEvento {
protected:
    ColaBloqueante<ComandoAEnviar>& cola_eventos;
    ColaNoBloqueante<ComandoAEnviar>& cola_eventos_no_bloqueantes;
public:
    SDLEvento(ColaBloqueante<ComandoAEnviar>& cola_eventos, ColaNoBloqueante<ComandoAEnviar>& cola_eventos_no_bloqueantes);
    virtual std::unique_ptr<SDLEvento> clasificar_evento(uint32_t eventType);
    virtual void ejecutar_evento(SDL_Event& keyEvent) = 0;
    ~SDLEvento();
};

class TeclaPresionada : public SDLEvento {
public:
    TeclaPresionada();
    virtual void ejecutar_evento(SDL_Event& keyEvent);
    ~TeclaPresionada();
};

class TeclaLevantada : public SDLEvento {
public:
    TeclaLevantada();
    virtual void ejecutar_evento(SDL_Event& keyEvent);
    ~TeclaLevantada();
};

class Rueda : public SDLEvento {
public:
    Rueda();
    virtual void ejecutar_evento(SDL_Event& wheelEvent);
    ~Rueda();
};

class ClickPresionado : public SDLEvento {
public:
    ClickPresionado();
    virtual void ejecutar_evento(SDL_Event& mouseButtonEvent);
    ~ClickPresionado();
};

class ClickLevantado : public SDLEvento {
public:
    ClickLevantado();
    virtual void ejecutar_evento(SDL_Event& mouseButtonEvent);
    ~ClickLevantado();
};


#endif // SDL_EVENTO_H
