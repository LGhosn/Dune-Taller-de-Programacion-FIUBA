#ifndef HILO_SDL_H
#define HILO_SDL_H

#include <SDL2/SDL.h>
#include <thread>

#include "sdl_evento.h"
#include "../cola_bloqueante.h"
#include "../cola_no_bloqueante.h"

class ManejadorEventos {
private:
    bool hay_que_seguir;
    std::thread thread;
    SDL_Event event;
    SDLEvento *xxx;
    ColaBloqueante<SDLEvento*> *cola_eventos;
    ColaNoBloqueante<SDLEvento*> *cola_eventos_no_bloqueantes;

public:
    ManejadorEventos();
    void manejar_evento();
    void manejar_tecla(SDL_KeyboardEvent& keyEvent);
    void manejar_mouse(SDL_MouseButtonEvent& keyEvent);
    ~ManejadorEventos();
};

#endif //HILO_SDL_H
