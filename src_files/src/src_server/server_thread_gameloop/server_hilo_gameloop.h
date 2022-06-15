#ifndef SERVER_HILO_GAMELOOP_H
#define SERVER_HILO_GAMELOOP_H

#include <vector>
#include <thread>
#include <string>
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../server_solicitudes/solicitud_juego/server_solicitud.h"
#include "../server_comandos/server_comando.h"
#include "../server_game/game.h"

#define TICKS_POR_SEGUNDO 60

class HiloGameLoop {
    ColaNoBloqueante<SolicitudServer>& cola_solicitudes;
    Game game;
    std::thread hilo;

    void manejarHilo();
    void run();

    // Hace un pop de todas las solicitudes de la cola y las ejecuta
    void manejarSolicitudes();

    // Actualiza el game a partir del numero de iteracion actual y devuelve si el hilo debe continuar
    bool update(long iter);

public:
    HiloGameLoop(std::vector<ColaBloqueante<ComandoServer>*>& colas_sender,
    ColaNoBloqueante<SolicitudServer>& sol_entrantes, std::string& ruta_mapa);

    void start();

    ~HiloGameLoop();

    HiloGameLoop &operator=(const HiloGameLoop &hilo_game_loop) = delete;
    HiloGameLoop(const HiloGameLoop &hilo_game_loop) = delete;
    HiloGameLoop &operator=(HiloGameLoop &&hilo_game_loop);
    HiloGameLoop(HiloGameLoop &&hilo_game_loop);
};

#endif
