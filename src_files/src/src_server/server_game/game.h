#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../server_comandos/server_comando.h"
#include "server_mapa/server_mapa.h"

class Game {
    bool finished = false;
    std::vector< ColaBloqueante<ComandoServer>* >& colas_comandos;
    Mapa mapa;

public:
    Game(std::vector< ColaBloqueante<ComandoServer>* >& colas_comandos);

    void crearEdificio(uint16_t id_jugador, uint16_t id_edificio, Coordenadas& coords);

    bool update(long iter);

    Game &operator=(const Game &game) = delete;
    Game(const Game &game) = delete;
    Game &operator=(Game &&game);
    Game(Game &&game);
};


#endif //GAME_H
