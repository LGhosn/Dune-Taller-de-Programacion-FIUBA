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
                cola_solicitudes(new ColaNoBloqueante<SolicitudServer>()),
                hilo_gameloop(cola_solicitudes, nombre_mapa) {}

bool Partida::estaCompleta() const {
    return (this->jugadores_actuales == this->jugadores_requeridos);
}

void Partida::agregarJugador(HandlerCliente* cliente, uint8_t casa) {
    this->clientes_conectados.push_back(cliente);
    this->hilo_gameloop.agregarJugador(cliente->obtenerColaSender(),
                                        cliente->obtenerId(),
                                        casa,
                                        cliente->obtenerNombre());
    // colas_sender->push_back(cliente->obtenerColaSender());
}

void Partida::empezar() {
    // std::map<uint8_t, Coordenadas> centros_por_jugador = sortearCentros();
    // for (auto& cliente : this->clientes_conectados) {
    //     cliente->empezarPartida(this->cola_solicitudes, this->nombre_mapa);
    // }
    // std::string ruta_mapa = obtenerRutaMapa();
    std::cout << "Empezando partida..." << std::endl;
    hilo_gameloop.start();
    for (auto& cliente : this->clientes_conectados) {
        cliente->empezarPartida(this->cola_solicitudes);
    }
}

std::string Partida::getNombre() const {
    return this->nombre_partida;
}

Partida::~Partida() {
    if (this->cola_solicitudes != nullptr) {
        delete this->cola_solicitudes;
    }
}

Partida& Partida::operator=(Partida&& otra) {
    if (this == &otra)
        return *this;
    this->nombre_partida = otra.nombre_partida;
    this->jugadores_actuales = otra.jugadores_actuales;
    this->jugadores_requeridos = otra.jugadores_requeridos;
    this->nombre_mapa = otra.nombre_mapa;
    this->clientes_conectados = std::move(otra.clientes_conectados);
    this->cola_solicitudes = otra.cola_solicitudes;
    std::cout << "Partida movida" << std::endl;
    return *this;
}

Partida::Partida(Partida&& otra) :
        nombre_partida(std::move(otra.nombre_partida)),
        jugadores_actuales(otra.jugadores_actuales),
        jugadores_requeridos(otra.jugadores_requeridos),
        nombre_mapa(std::move(otra.nombre_mapa)),
        clientes_conectados(std::move(otra.clientes_conectados)),
        cola_solicitudes(otra.cola_solicitudes),
        hilo_gameloop(std::move(otra.hilo_gameloop)) {
    otra.cola_solicitudes = nullptr;
    std::cout << "Partida movida" << std::endl;
}
