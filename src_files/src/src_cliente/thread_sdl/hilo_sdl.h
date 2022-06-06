#ifndef CLIENT_HILO_SDL_H
#define CLIENT_HILO_SDL_H

#include <SDL2/SDL.h>
#include <thread>

#include "sdl_evento.h"
// #include "../cola_bloqueante.h"
// #include "../cola_no_bloqueante.h"
// #include "../comandos/comando_a_enviar.h"

class ManejadorEventos {
private:
    bool hay_que_seguir;
    std::thread thread;
    SDL_Event event;
    SDLEvento *evento_ocurrido;
    // ColaBloqueante<ComandoAEnviar*>& cola_comandos;
    // ColaNoBloqueante<ComandoAEnviar*>& cola_comandos_no_bloqueantes;

public:
    ManejadorEventos();
    void manejar_evento();
    void manejar_tecla(SDL_KeyboardEvent& keyEvent);
    void manejar_mouse(SDL_MouseButtonEvent& keyEvent);
    ~ManejadorEventos();
};

#endif //CLIENT_HILO_SDL_H
