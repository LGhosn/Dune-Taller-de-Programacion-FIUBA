#include "handle_event.h"

HandleEvent::HandleEvent() {
    this->thread = std::thread(&HandleEvent::handle_event, this);
}

void HandleEvent::handle_event() {
    while (true) {
        if (!SDL_WaitEvent(&this->event)) {
            //TODO lanzar excepcion porque ocurrio un error mientras esperaba un evento.
        }
        switch (this->event.type) {
            case SDL_KEYDOWN: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        break;
                    case SDLK_RIGHT:
                        break;
                    }
                } // Fin KEY_DOWN
                break;

            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&) event;
                switch (keyEvent.keysym.sym) {
                    case SDLK_LEFT:
                        break;
                    case SDLK_RIGHT:
                        break;
                    } 
                }// Fin KEY_UP
                break;

            case SDL_MOUSEWHEEL: {
                SDL_MouseWheelEvent& wheelEvent = (SDL_MouseWheelEvent&) event;
                if (wheelEvent.y > 0) {
                    // Scroll Up
                } else {
                    // Scroll Down
                }
                break;
            } // Fin MOUSE_WHEEL

            case SDL_MOUSEBUTTONDOWN: {
                SDL_MouseButtonEvent& mouseEvent = (SDL_MouseButtonEvent&) event;
                switch (mouseEvent.button) {
                    case SDL_BUTTON_LEFT:
                        break;
                    case SDL_BUTTON_RIGHT:
                        break;
                    }
                } // Fin MOUSE_BUTTON_DOWN
                break;
            
            case SDL_MOUSEBUTTONUP: {
                SDL_MouseButtonEvent& mouseEvent = (SDL_MouseButtonEvent&) event;
                switch (mouseEvent.button) {
                    case SDL_BUTTON_LEFT:
                        break;
                    case SDL_BUTTON_RIGHT:
                        break;
                    }
                } // Fin MOUSE_BUTTON_UP
                break;

            case SDL_QUIT:
                break;
            
            default:
                break;
        } //fin switch
    } // fin while
}

HandleEvent::~HandleEvent() {
    this->thread.join();
}
