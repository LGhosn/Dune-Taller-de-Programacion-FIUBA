#ifndef SERVER_HILO_GAMELOOP_H
#define SERVER_HILO_GAMELOOP_H

#include <vector>
#include <thread>
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../../src_common/common_comandos/comando_a_enviar.h"
#include "../../src_common/common_comandos/common_solicitud.h"
#include "../../src_game/game.h"

#define FRAME_RATE 33.0f

class ServerHiloGameLoop {
    std::vector<ColaBloqueante<ComandoAEnviar>&>& colas_eventos;
    ColaNoBloqueante<Solicitud>& sol_entrantes;
    Game game;
    std::thread thread;

    void manejarHilo();
    void run();

    void manejarSolicitudes();

    bool update(long iter);

public:
    ServerHiloGameLoop(std::vector<ColaBloqueante<ComandoAEnviar>&>& colas_sender, ColaNoBloqueante<Solicitud>& sol_entrantes);

    ~ServerHiloGameLoop();
};

#endif
