#ifndef CLIENT_HILO_SDL_H
#define CLIENT_HILO_SDL_H

#include <SDL2/SDL.h>
#include <thread>

#include "client_sdl_evento.h"
#include "../..//src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../client_comandos/client_comando.h"
#include "../client_solicitudes/cliente_solicitud.h"

#define TICKS_POR_SEGUNDO 120

class ManejadorEventos {
private:
    YAML::Node& constantes;
    bool hay_que_seguir = true;
    std::thread thread;
    SDL_Event event;
    SDLEvento *evento_ocurrido;
    ColaBloqueante<SolicitudCliente>& cola_solicitudes;
    ColaNoBloqueante<ComandoCliente>& cola_comandos;

public:
    ManejadorEventos(ColaBloqueante<SolicitudCliente>& cola_solicitudes,
                    ColaNoBloqueante<ComandoCliente>& cola_comandos,
                    YAML::Node& constantes);
    void manejar_evento();
    std::unique_ptr<SDLEvento> clasificarEvento(uint32_t eventType);
    void manejar_tecla(SDL_KeyboardEvent& keyEvent);
    void manejar_mouse(SDL_MouseButtonEvent& keyEvent);
    ~ManejadorEventos();
};

#endif //CLIENT_HILO_SDL_H
