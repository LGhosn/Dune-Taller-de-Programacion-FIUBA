#ifndef SERVER_PARTIDA_H
#define SERVER_PARTIDA_H

#include "../server_handler_cliente/server_handler_cliente.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../server_thread_gameloop/server_hilo_gameloop.h"
#include "../server_solicitudes/solicitud_juego/server_solicitud.h"
#include <list>
#include <stack>
#include <string>
#include <map>

class HandlerCliente;
class Lobby;

class Partida {
    std::string nombre_partida;
    uint8_t jugadores_actuales = 1;
    uint8_t jugadores_requeridos;
    std::string nombre_mapa;
    std::list<HandlerCliente*> clientes_conectados;
    ColaNoBloqueante<SolicitudServer>  cola_solicitudes;
    HiloGameLoop hilo_gameloop;

    friend class Lobby;

    std::string obtenerRutaMapa() const;

public:
    Partida(const std::string& nombre_partida, uint8_t jugadores_requeridos,
            const std::string& nombre_mapa);
    void empezar();
    void agregarJugador(HandlerCliente& cliente, uint8_t casa);
    bool estaCompleta() const;
    bool haFinalizado() const;
    std::string getNombre() const;

    Partida& operator=(const Partida&) = delete;
    Partida(const Partida&) = delete;
    Partida& operator=(Partida&&) = delete;
    Partida(Partida&&) = delete;
};

#endif //SERVER_PARTIDA_H
