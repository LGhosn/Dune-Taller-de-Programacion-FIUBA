#include "game.h"

Game::Game(std::vector<ColaBloqueante<ComandoServer>* >& colas_comandos) : colas_comandos(colas_comandos) {}

Game::Game(Game&& game) {
    this->finished = game.finished;
    this->colas_comandos = std::move(game.colas_comandos);
}

Game& Game::operator=(Game&& game) {
    if (this == &game)
        return *this;
    this->finished = game.finished;
    this->colas_comandos = std::move(game.colas_comandos);
    return *this;
}
