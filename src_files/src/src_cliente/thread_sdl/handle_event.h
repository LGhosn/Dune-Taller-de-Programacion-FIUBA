#ifndef HANDLE_EVENT_H
#define HANDLE_EVENT_H

#include <SDL2/SDL.h>
#include <thread>

class HandleEvent {
private:
    std::thread thread;
    SDL_Event event;
    // falta cola bloqueante
    // falta cola no bloqueante

public:
    HandleEvent();
    void handle_event();
    ~HandleEvent();
};

#endif //HANDLE_EVENT_H
