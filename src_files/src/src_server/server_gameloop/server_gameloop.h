#ifndef SERVER_HILO_GAMELOOP_H
#define SERVER_HILO_GAMELOOP_H

#include <vector>
#include <thread>
#include <string>
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../../src_common/common_comandos/comando_a_enviar.h"
#include "../../src_common/common_comandos/common_solicitud.h"
#include "../../src_game/game.h"

#define FRAME_RATE 33.0f

class GameLoop {
    std::vector<ColaBloqueante<ComandoAEnviar>&>& colas_eventos;
    ColaNoBloqueante<Solicitud>& sol_entrantes;
    Game game;

    void manejarHilo();
    void run();

    // Hace un pop de todas las solicitudes de la cola y las ejecuta
    void manejarSolicitudes();

    // Actualiza el game a partir del numero de iteracion actual y devuelve si el hilo debe continuar
    bool update(long iter);

public:
    GameLoop(std::vector<ColaBloqueante<ComandoAEnviar>&>& colas_sender,
    ColaNoBloqueante<Solicitud>& sol_entrantes, std::string& ruta_mapa);
};

#endif
