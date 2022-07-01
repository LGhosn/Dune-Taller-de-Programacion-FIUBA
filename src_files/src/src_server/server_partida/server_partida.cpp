#include "server_partida.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../server_comandos/server_comando.h"
#include <sstream>
#include <algorithm>
#include <random>

std::string Partida::obtenerRutaMapa() const {
    std::stringstream ruta_mapa;
    ruta_mapa << RESOURCE_PATH << "/maps/" << nombre_mapa << ".yaml";
    return ruta_mapa.str();
}

Partida::Partida(const std::string& nombre_partida, uint8_t jugadores_requeridos,
                const std::string& nombre_mapa) :
                nombre_partida(nombre_partida),
                jugadores_requeridos(jugadores_requeridos),
                nombre_mapa(nombre_mapa),
                hilo_gameloop(cola_solicitudes, nombre_mapa) {}

bool Partida::estaCompleta() const {
    return (this->jugadores_actuales == this->jugadores_requeridos);
}

void Partida::agregarJugador(HandlerCliente& cliente, uint8_t casa) {
    this->clientes_conectados.emplace_back(&cliente);
    this->hilo_gameloop.agregarJugador(cliente.obtenerColaSender(),
                                        cliente.obtenerId(),
                                        casa,
                                        cliente.obtenerNombre());
}

void Partida::empezar() {
    std::cout << "Empezando partida..." << std::endl;
    hilo_gameloop.start();
    for (auto& cliente : this->clientes_conectados) {
        cliente->empezarPartida(this->cola_solicitudes);
    }
}

std::string Partida::getNombre() const {
    return this->nombre_partida;
}
