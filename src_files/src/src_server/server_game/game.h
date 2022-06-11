#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../server_comandos/server_comando.h"

class Game {
    bool finished = false;
    std::vector< ColaBloqueante<ComandoServer>* >& colas_comandos;
public:
    Game(std::vector< ColaBloqueante<ComandoServer>* >& colas_comandos);

    bool update(long iter);

    Game &operator=(const Game &game) = delete;
    Game(const Game &game) = delete;
    Game &operator=(Game &&game);
    Game(Game &&game);
};


#endif //GAME_H
