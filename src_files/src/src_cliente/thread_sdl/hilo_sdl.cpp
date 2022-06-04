#include "hilo_sdl.h"

ManejadorEventos::ManejadorEventos() {
    this->thread = std::thread(&ManejadorEventos::manejar_evento, this);
}


void ManejadorEventos::manejar_evento() {
    while (this->hay_que_seguir) {
        if (!SDL_WaitEvent(&this->event)) {
            //TODO lanzar excepcion porque ocurrio un error mientras esperaba un evento.
        }

        SDLEvento *evento_ocurrido = xxx->clasificar_evento(this->event.type);
        evento_ocurrido->ejecutar_evento(this->event);

    }// fin while
}

ManejadorEventos::~ManejadorEventos() {
    this->thread.join();
}
