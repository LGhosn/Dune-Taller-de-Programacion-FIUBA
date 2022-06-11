#include "PartidaDTO.h"

Partida::Partida(const std::string& nombre_partida, uint8_t jugadores_requeridos) :
        nombre_partida(nombre_partida), jugadores_requeridos(jugadores_requeridos) {
    this->jugadores_actuales = 1;  // El unico jugador es el que creó la partida.
}

bool Partida::estaCompleta() {
    return (this->jugadores_actuales < this->jugadores_requeridos);
}

void Partida::agregarJugador(HandlerCliente* cliente) {
    this->clientes_conectados.push_back(cliente);
}