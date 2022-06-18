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
                nombre_mapa(nombre_mapa),
                cola_solicitudes(new ColaNoBloqueante<SolicitudServer>()),
                colas_sender(new std::vector<ColaBloqueante<ComandoServer>*>()),
                hilo_gameloop(colas_sender, cola_solicitudes, nombre_mapa) {}

bool Partida::estaCompleta() const {
    return (this->jugadores_actuales == this->jugadores_requeridos);
}

void Partida::agregarJugador(HandlerCliente* cliente) {
    this->clientes_conectados.push_back(cliente);
    // colas_sender->push_back(cliente->obtenerColaSender());
}

void Partida::empezar() {
    for (auto cliente : this->clientes_conectados) {
        colas_sender->push_back(cliente->obtenerColaSender());
        std::cout << "nombre mapa: " << this->nombre_mapa << std::endl;
        cliente->empezarPartida(this->cola_solicitudes, this->nombre_mapa);
    }
    std::string ruta_mapa = obtenerRutaMapa();
    hilo_gameloop.start();
}

std::string Partida::getNombre() const {
    return this->nombre_partida;
}

Partida::~Partida() {
    if (this->cola_solicitudes != nullptr) {
        delete this->cola_solicitudes;
    }
    if (this->colas_sender != nullptr) {
        delete this->colas_sender;
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
    this->colas_sender = otra.colas_sender;
    this->cola_solicitudes = otra.cola_solicitudes;
    return *this;
}

Partida::Partida(Partida&& otra) :
        nombre_partida(std::move(otra.nombre_partida)),
        jugadores_actuales(otra.jugadores_actuales),
        jugadores_requeridos(otra.jugadores_requeridos),
        nombre_mapa(std::move(otra.nombre_mapa)),
        clientes_conectados(std::move(otra.clientes_conectados)),
        cola_solicitudes(otra.cola_solicitudes),
        colas_sender(otra.colas_sender),
        hilo_gameloop(std::move(otra.hilo_gameloop)) {
    otra.colas_sender = nullptr;
    otra.cola_solicitudes = nullptr;
}
