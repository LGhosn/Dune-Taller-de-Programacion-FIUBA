#include "game.h"
#include "../server_solicitudes/solicitud_juego/sol_crear_edificio.h"
#include "../server_comandos/cmd_crear_edificio.h"

Game::Game(std::vector<ColaBloqueante<ComandoServer>* >& colas_comandos) :
            colas_comandos(colas_comandos),
            mapa(100, 100) {}

void Game::crearEdificio(uint16_t id_jugador, uint16_t tipo, const Coordenadas& coords) {
    bool resultado = mapa.construirEdificio(id_jugador, tipo, coords);
    if (resultado) {
        // uint16_t id_edificio = edificios.add(id_jugador, tipo, coords);
        for (auto& cola : colas_comandos) {
            CmdCrearEdificioServer* comando = new CmdCrearEdificioServer(id_jugador, conts_id_edificios, tipo, coords, 0); // fix
            cola->push(comando);
        }
        conts_id_edificios++;
    }
}

bool Game::update(long iter) {
    return true;
}

Game::Game(Game&& game) : finished(game.finished), colas_comandos(game.colas_comandos),
mapa(100,100) {}    // TODO: cambiar constructor mapa

Game& Game::operator=(Game&& game) {
    if (this == &game)
        return *this;
    this->finished = game.finished;
    this->colas_comandos = std::move(game.colas_comandos);
    return *this;
}
