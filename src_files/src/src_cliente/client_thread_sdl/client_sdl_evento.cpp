#include "client_sdl_evento.h"
#include "../client_solicitudes/sol_mover_unidad.h"
#include "../client_comandos/cmd_click_en_mapa.h"
#include "../client_comandos/cmd_click_der_en_mapa.h"
#include "../client_comandos/cmd_marcador.h"

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
        case (SDLK_TAB): {
            ComandoCliente* comando = new ComandoMarcador(true);
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
         case (SDLK_TAB):{
            ComandoCliente *comando = new ComandoMarcador(false);
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
            ClickDerEnMapa* comando = new ClickDerEnMapa(mouseEvent.x, mouseEvent.y);
            cola_comandos.push(comando);
            break;
        }
    }
}

ClickLevantado::ClickLevantado(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                                ColaNoBloqueante<ComandoCliente>& cola_comandos,
                                YAML::Node& constantes) :
                                SDLEvento(cola_solicitudes, cola_comandos, constantes) {}

void ClickLevantado::ejecutar_evento(SDL_Event& mouseEvent) {}

MouseMovido::MouseMovido(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                        ColaNoBloqueante<ComandoCliente>& cola_comandos,
                        YAML::Node& constantes) :
                        SDLEvento(cola_solicitudes, cola_comandos, constantes) {}

void MouseMovido::ejecutar_evento(SDL_Event& mouseEvent) {
    SDL_MouseMotionEvent& mouseMotionEvent = (SDL_MouseMotionEvent&) mouseEvent;
    if (mouseMotionEvent.x < PADDING_MOVER) {
        ComandoCliente* comando = new MoverMapa(IZQUIERDA);
        cola_comandos.push(comando);
    } else if (mouseMotionEvent.x > ANCHO_VISTA_MAPA - PADDING_MOVER &&
                mouseMotionEvent.x < ANCHO_VISTA_MAPA) {
        ComandoCliente *comando = new MoverMapa(DERECHA);
        cola_comandos.push(comando);
    }
    
    if (mouseMotionEvent.y < PADDING_MOVER) {
        ComandoCliente *comando = new MoverMapa(ARRIBA);
        cola_comandos.push(comando);
    } else if (mouseMotionEvent.y > LARGO_VISTA_MAPA - PADDING_MOVER) {
        ComandoCliente *comando = new MoverMapa(ABAJO);
        cola_comandos.push(comando);
    }
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
