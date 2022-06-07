#include "client_sdl_evento.h"
#include "../../src_common/common_comandos/comando_a_enviar.h"
#include "../../src_common/common_comandos/cmd_sol_mover_unidad.h"

std::unique_ptr<SDLEvento> SDLEvento::clasificar_evento(uint32_t eventType) {
    switch (eventType) {
        case SDL_KEYDOWN:
            return std::unique_ptr<TeclaPresionada>();
        case SDL_KEYUP:
            return std::unique_ptr<TeclaLevantada>();
        case SDL_MOUSEWHEEL:
            return std::unique_ptr<Rueda>();
        case SDL_MOUSEBUTTONDOWN:
            return std::unique_ptr<ClickPresionado>();
        case SDL_MOUSEBUTTONUP:
            return std::unique_ptr<ClickLevantado>();
        default:
            throw std::runtime_error("Evento no reconocido");
    }
}

void TeclaPresionada::ejecutar_evento(SDL_Event& keyEvent) {
    SDL_KeyboardEvent& teclaEvent = (SDL_KeyboardEvent&) keyEvent;
    switch (teclaEvent.keysym.sym) {
        case (SDLK_LEFT):
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
    SDL_KeyboardEvent& teclaEvent = (SDL_KeyboardEvent&) keyEvent;
    switch (teclaEvent.keysym.sym) {
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
    SDL_MouseButtonEvent& mouseEvent = (SDL_MouseButtonEvent&) mouseButtonEvent;
    switch (mouseEvent.button) {
        case (SDL_BUTTON_LEFT):
            // temporal crear un comando para soldado
            break;
        
        case (SDL_BUTTON_RIGHT):
            uint16_t x = mouseButtonEvent.button.x;
            uint16_t y = mouseButtonEvent.button.y;

            PixACoords coords_normalizadas(x, y);
            uint16_t id = 1;        // TODO: obtener id de la unidad
            SolicitudMoverUnidad solicitud(id, coords_normalizadas.get_x(), coords_normalizadas.get_y());
            this->cola_eventos.push(&solicitud);
            break;
    }
}