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
    bool corriendo = true;
    std::thread hilo;

    void manejarHilo();
    void run();

    // Hace un pop de todas las solicitudes de la cola y las ejecuta
    void manejarSolicitudes();

    // Actualiza el game a partir del numero de iteracion actual y devuelve si el hilo debe continuar
    bool update(long iter);

public:
    HiloGameLoop(ColaNoBloqueante<SolicitudServer>& cola_solicitudes,
                    const std::string& nombre_mapa);

    void agregarJugador(ColaBloqueante<ComandoServer>& cola_comando,
                        uint8_t id_jugador, uint8_t casa, std::string& nombre);

    void start();

    bool haTerminado() const;

    ~HiloGameLoop();

    HiloGameLoop &operator=(const HiloGameLoop &hilo_game_loop) = delete;
    HiloGameLoop(const HiloGameLoop &hilo_game_loop) = delete;
    HiloGameLoop &operator=(HiloGameLoop &&hilo_game_loop) = delete;
    HiloGameLoop(HiloGameLoop &&hilo_game_loop) = delete;
};

#endif
