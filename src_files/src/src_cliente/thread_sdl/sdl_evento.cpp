#include "sdl_evento.h"

SDLEvento* SDLEvento::clasificar_evento(uint32_t eventType) {
    switch (eventType) {
        case SDL_KEYDOWN:
            return new TeclaPresionada();
        case SDL_KEYUP:
            return new TeclaLevantada();
        case SDL_MOUSEWHEEL:
            return new Rueda();
        case SDL_MOUSEBUTTONDOWN:
            return new ClickPresionado();
        case SDL_MOUSEBUTTONUP:
            return new ClickLevantado();
    }
}

void TeclaPresionada::ejecutar_evento(SDL_Event& keyEvent) {
    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) keyEvent;
    switch (keyEvent.keysym.sym) {
        case (SDLK_LEFT):
            this->
            break;
        
        case (SDLK_RIGHT):
            /* code */
            break;

        case (SDLK_UP):
            /* code */
            break;
        
        case (SDLK_DOWN):
            /* code */
            break;
    }
    // this->comando->ejecutar(keyEvent);
}

void TeclaLevantada::ejecutar_evento(SDL_Event& keyEvent) {
    SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) keyEvent;
    switch (keyEvent.keysym.sym) {
        case (SDLK_LEFT):
            /* code */
            break;
        
        case (SDLK_RIGHT):
            /* code */
            break;

        case (SDLK_UP):
            /* code */
            break;
        
        case (SDLK_DOWN):
            /* code */
            break;
    }
    // this->comando->ejecutar(keyEvent);
}

void ClickPresionado::ejecutar_evento(SDL_Event& mouseButtonEvent) {
    SDL_MouseButtonEvent& mouseButtonEvent = (SDL_MouseButtonEvent&) mouseButtonEvent;
    switch (mouseButtonEvent.button) {
        case (SDL_BUTTON_LEFT):
            // temporal crear un comando para soldado
            break;
        
        case (SDL_BUTTON_RIGHT):
            // obtener coords del click y mover soldado
            break;
    }
}