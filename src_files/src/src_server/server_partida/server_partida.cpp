#include "server_partida.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../server_comandos/server_comando.h"
#include <sstream>

std::string Partida::obtenerRutaMapa() const {
    std::stringstream ruta_mapa;
    ruta_mapa << RESOURCE_PATH << "/maps/" << nombre_mapa << ".yaml";
    return ruta_mapa.str();
}

Partida::Partida(const std::string& nombre_partida, uint8_t jugadores_requeridos,
                const std::string& nombre_mapa) :
                nombre_partida(nombre_partida),
                jugadores_requeridos(jugadores_requeridos),
                nombre_mapa(nombre_mapa) {}

bool Partida::estaCompleta() const {
    return (this->jugadores_actuales == this->jugadores_requeridos);
}

void Partida::agregarJugador(HandlerCliente* cliente) {
    this->clientes_conectados.push_back(cliente);
    colas_sender.push_back(cliente->obtenerColaSender());
}

void Partida::empezar() {
    for (auto cliente : this->clientes_conectados) {
        colas_sender.push_back(cliente->obtenerColaSender());
        cliente->empezarPartida(&this->cola_solicitudes);
    }
    std::string ruta_mapa = obtenerRutaMapa();
    HiloGameLoop hilo_gameloop(colas_sender, this->cola_solicitudes, ruta_mapa);
    hilo_gameloop.start();
}

std::string Partida::getNombre() const {
    return this->nombre_partida;
}

Partida& Partida::operator=(Partida&& otra) {
    if (this == &otra)
        return *this;
    this->nombre_partida = otra.nombre_partida;
    this->jugadores_actuales = otra.jugadores_actuales;
    this->jugadores_requeridos = otra.jugadores_requeridos;
    this->clientes_conectados = std::move(otra.clientes_conectados);
    this->cola_solicitudes = std::move(otra.cola_solicitudes);
    return *this;
}

Partida::Partida(Partida&& otra) {
    this->nombre_partida = otra.nombre_partida;
    this->jugadores_actuales = otra.jugadores_actuales;
    this->jugadores_requeridos = otra.jugadores_requeridos;
    this->clientes_conectados = std::move(otra.clientes_conectados);
    this->cola_solicitudes = std::move(otra.cola_solicitudes);
}
