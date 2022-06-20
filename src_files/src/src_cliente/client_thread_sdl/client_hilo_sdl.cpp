#include "client_hilo_sdl.h"
#include <iostream>


ManejadorEventos::ManejadorEventos(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                                    ColaNoBloqueante<ComandoCliente>& cola_comandos,
                                    YAML::Node& constantes) :
                                    constantes(constantes),
                                    cola_solicitudes(cola_solicitudes),
                                    cola_comandos(cola_comandos) {
    this->thread = std::thread(&ManejadorEventos::manejar_evento, this);
}

void ManejadorEventos::manejar_evento() {
    while (this->hay_que_seguir) {
        if (!SDL_WaitEvent(&this->event)) {
            std::runtime_error("Error al esperar evento");
        }
        std::unique_ptr<SDLEvento> evento = this->clasificarEvento(this->event.type);
        if (evento)
            evento->ejecutar_evento(this->event);

    }// fin while
}

std::unique_ptr<SDLEvento> ManejadorEventos::clasificarEvento(uint32_t eventType) {
    switch (eventType) {
        case SDL_KEYDOWN:
            return std::unique_ptr<TeclaPresionada>(
                new TeclaPresionada(cola_solicitudes, cola_comandos, constantes));
        case SDL_KEYUP:
            return std::unique_ptr<TeclaLevantada>(
                new TeclaLevantada(cola_solicitudes, cola_comandos, constantes));
        case SDL_MOUSEWHEEL:
            return std::unique_ptr<Rueda>(
                new Rueda(cola_solicitudes, cola_comandos, constantes));
        case SDL_MOUSEBUTTONDOWN:
            return std::unique_ptr<ClickPresionado>(
                new ClickPresionado(cola_solicitudes, cola_comandos, constantes));
        case SDL_MOUSEBUTTONUP:
            return std::unique_ptr<ClickLevantado>(
                new ClickLevantado(cola_solicitudes, cola_comandos, constantes));
        case SDL_QUIT:
            this->hay_que_seguir = false;
            return std::unique_ptr<EventoSalir>(
                new EventoSalir(cola_solicitudes, cola_comandos, constantes));
        default:
            return nullptr;
    }
}

ManejadorEventos::~ManejadorEventos() {
    if (this->thread.joinable()) {
        this->hay_que_seguir = false;
        this->thread.join();
    }
    std::cerr << "Destruyendo ManejadorEventos\n";
}
