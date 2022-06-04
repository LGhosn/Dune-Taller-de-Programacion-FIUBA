#ifndef SDL_EVENTO_H
#define SDL_EVENTO_H

#include <SDL2/SDL.h>
#include "../comandos/comando.h"

class SDLEvento {
protected:
    Comando* comando;
public:
    SDLEvento();
    virtual SDLEvento *clasificar_evento(uint32_t eventType);
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
