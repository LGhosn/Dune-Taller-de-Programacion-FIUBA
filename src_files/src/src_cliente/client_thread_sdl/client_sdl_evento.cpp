#include "client_sdl_evento.h"
#include "../client_solicitudes/sol_mover_unidad.h"

TeclaPresionada::TeclaPresionada(ColaBloqueante<SolicitudCliente>& cola_solicitudes, ColaNoBloqueante<ComandoCliente>& cola_comandos) :
    cola_solicitudes(cola_solicitudes), cola_comandos(cola_comandos) {}

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
    ColaNoBloqueante<ComandoCliente>& cola_comandos) :
    cola_solicitudes(cola_solicitudes), cola_comandos(cola_comandos) {}

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


ClickPresionado::ClickPresionado(ColaBloqueante<SolicitudCliente>& cola_solicitudes, ColaNoBloqueante<ComandoCliente>& cola_comandos) :
    cola_solicitudes(cola_solicitudes), cola_comandos(cola_comandos) {}

void ClickPresionado::ejecutar_evento(SDL_Event& mouseButtonEvent) {
    SDL_MouseButtonEvent& mouseEvent = (SDL_MouseButtonEvent&) mouseButtonEvent;
    switch (mouseEvent.button) {
        case (SDL_BUTTON_LEFT):
            // temporal crear un comando para soldado
            break;
        
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

ClickLevantado::ClickLevantado(ColaBloqueante<SolicitudCliente>& cola_solicitudes, ColaNoBloqueante<ComandoCliente>& cola_comandos) :
    cola_solicitudes(cola_solicitudes), cola_comandos(cola_comandos) {}

void ClickLevantado::ejecutar_evento(SDL_Event &clickEvent) {
    
}

Rueda::Rueda(ColaBloqueante<SolicitudCliente>& cola_solicitudes, ColaNoBloqueante<ComandoCliente>& cola_comandos) :
    cola_solicitudes(cola_solicitudes), cola_comandos(cola_comandos) {}

void Rueda::ejecutar_evento(SDL_Event &ruedaEvent) {
    
}
