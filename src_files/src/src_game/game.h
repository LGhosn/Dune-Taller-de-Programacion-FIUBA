#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../src_common/common_colas/cola_bloqueante.h"
#include "../src_common/common_comandos/comando_a_enviar.h"

class Game {
    bool finished = false;
    std::vector<ColaBloqueante<ComandoAEnviar>&>& colas_eventos;
public:
    Game(std::vector<ColaBloqueante<ComandoAEnviar>&>& colas_eventos);

    bool update(long iter);
};


#endif //GAME_H
