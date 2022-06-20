#include "client_sdl_evento.h"
#include "../client_solicitudes/sol_mover_unidad.h"
#include "../client_comandos/cmd_click_en_mapa.h"

SDLEvento::SDLEvento(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                    ColaNoBloqueante<ComandoCliente>& cola_comandos,
                    YAML::Node& constantes) :
                        cola_solicitudes(cola_solicitudes),
                        cola_comandos(cola_comandos),
                        constantes(constantes) {}

TeclaPresionada::TeclaPresionada(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                                ColaNoBloqueante<ComandoCliente>& cola_comandos,
                                YAML::Node& constantes) :
                                SDLEvento(cola_solicitudes, cola_comandos, constantes) {}

void TeclaPresionada::ejecutar_evento(SDL_Event& keyEvent) {
    SDL_KeyboardEvent& teclaEvent = (SDL_KeyboardEvent&) keyEvent;
    switch (teclaEvent.keysym.sym) {
        case (SDLK_LEFT): {
            ComandoCliente* comando = new MoverMapa(IZQUIERDA);
            cola_comandos.push(comando);
            break;
        }
        case (SDLK_RIGHT): {
            ComandoCliente* comando = new MoverMapa(DERECHA);
            cola_comandos.push(comando);
            break;
        }
        case (SDLK_UP): {
            ComandoCliente* comando = new MoverMapa(ARRIBA);
            cola_comandos.push(comando);
            break;
        }
        case (SDLK_DOWN): {
            ComandoCliente* comando = new MoverMapa(ABAJO);
            cola_comandos.push(comando);
            break;
        }
        case (SDLK_ESCAPE): {
            ComandoCliente* comando = new ComandoSalir();
            cola_comandos.push(comando);
            break;
        }
    }
}

TeclaLevantada::TeclaLevantada(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                                ColaNoBloqueante<ComandoCliente>& cola_comandos,
                                YAML::Node& constantes) :
                                SDLEvento(cola_solicitudes, cola_comandos, constantes) {}

void TeclaLevantada::ejecutar_evento(SDL_Event& keyEvent) {
    SDL_KeyboardEvent& teclaEvent = (SDL_KeyboardEvent&) keyEvent;
    switch (teclaEvent.keysym.sym) {
        case (SDLK_LEFT): {
            ComandoCliente* comando = new MoverMapa(DEJAR_DE_MOVER_H);
            cola_comandos.push(comando);
            break;
        }
        case (SDLK_RIGHT):{
            ComandoCliente *comando = new MoverMapa(DEJAR_DE_MOVER_H);
            cola_comandos.push(comando);
            break;
        }

        case (SDLK_UP):{
            ComandoCliente *comando = new MoverMapa(DEJAR_DE_MOVER_V);
            cola_comandos.push(comando);
            break;
        }
        case (SDLK_DOWN):{
            ComandoCliente *comando = new MoverMapa(DEJAR_DE_MOVER_V);
            cola_comandos.push(comando);
            break;
        }
    }
}


ClickPresionado::ClickPresionado(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                                ColaNoBloqueante<ComandoCliente>& cola_comandos,
                                YAML::Node& constantes) :
                                SDLEvento(cola_solicitudes, cola_comandos, constantes) {}

void ClickPresionado::ejecutar_evento(SDL_Event& mouseButtonEvent) {
    SDL_MouseButtonEvent& mouseEvent = (SDL_MouseButtonEvent&) mouseButtonEvent;
    switch (mouseEvent.button) {
        case (SDL_BUTTON_LEFT): {
            ClickEnMapa* comando = new ClickEnMapa(mouseEvent.x, mouseEvent.y);
            cola_comandos.push(comando);
            break;
        }
        case (SDL_BUTTON_RIGHT): {
            uint16_t x = mouseButtonEvent.button.x;
            uint16_t y = mouseButtonEvent.button.y;

            PixACoords coords_normalizadas(x, y);
            SolicitudMoverUnidad* solicitud = new SolicitudMoverUnidad(1, coords_normalizadas.get_x(), coords_normalizadas.get_y());
            this->cola_solicitudes.push(solicitud);
            break;
        }
    }
}

ClickLevantado::ClickLevantado(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                                ColaNoBloqueante<ComandoCliente>& cola_comandos,
                                YAML::Node& constantes) :
                                SDLEvento(cola_solicitudes, cola_comandos, constantes) {}

void ClickLevantado::ejecutar_evento(SDL_Event &clickEvent) {
}

Rueda::Rueda(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
            ColaNoBloqueante<ComandoCliente>& cola_comandos,
            YAML::Node& constantes) :
            SDLEvento(cola_solicitudes, cola_comandos, constantes) {}

void Rueda::ejecutar_evento(SDL_Event &ruedaEvent) {
    if (ruedaEvent.wheel.y > 0) {
        ComandoCliente* comando = new ComandoZoom(ZOOM_IN);
        cola_comandos.push(comando);
    } else if (ruedaEvent.wheel.y < 0) {
        ComandoCliente* comando = new ComandoZoom(ZOOM_OUT);
        cola_comandos.push(comando);
    }
}

EventoSalir::EventoSalir(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                        ColaNoBloqueante<ComandoCliente>& cola_comandos,
                        YAML::Node& constantes) :
                        SDLEvento(cola_solicitudes, cola_comandos, constantes) {}

void EventoSalir::ejecutar_evento(SDL_Event &quitEvent) {
    ComandoCliente* comando = new ComandoSalir();
    cola_comandos.push(comando);
}
