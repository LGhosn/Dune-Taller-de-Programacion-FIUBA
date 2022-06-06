#include "client_hilo_sdl.h"

ManejadorEventos::ManejadorEventos() :
     hay_que_seguir(true) {
    this->thread = std::thread(&ManejadorEventos::manejar_evento, this);
}


void ManejadorEventos::manejar_evento() {
    while (this->hay_que_seguir) {
        if (!SDL_WaitEvent(&this->event)) {
            //TODO lanzar excepcion porque ocurrio un error mientras esperaba un evento.
        }

        std::unique_ptr<SDLEvento> evento = evento_ocurrido->clasificar_evento(this->event.type);
        evento->ejecutar_evento(this->event);

    }// fin while
}

ManejadorEventos::~ManejadorEventos() {
    this->thread.join();
}
