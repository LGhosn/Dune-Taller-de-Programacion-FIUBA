#ifndef SERVER_PARTIDA_H
#define SERVER_PARTIDA_H

#include "../server_handler_cliente/server_handler_cliente.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../server_thread_gameloop/server_hilo_gameloop.h"
#include "../server_solicitudes/server_solicitud.h"
#include <list>
#include <string>
#include <map>

class HandlerCliente;
class Lobby;

class Partida {
    std::string nombre_partida;
    uint8_t jugadores_actuales;
    uint8_t jugadores_requeridos;
    std::list<HandlerCliente*> clientes_conectados;
    ColaNoBloqueante<SolicitudServer>  cola_solicitudes;

    friend class Lobby;
public:
    Partida(const std::string& nombre_partida, uint8_t jugadores_requeridos);
    void empezar();
    void agregarJugador(HandlerCliente* cliente);
    bool estaCompleta() const;
    std::string getNombre() const;

    Partida& operator=(const Partida&) = delete;
    Partida(const Partida&) = delete;
    Partida& operator=(Partida&&);
    Partida(Partida&&);
};

struct PartidaCmp {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        if (lhs < rhs) {
            return true;
        }
        return false;
    }
};

#endif //SERVER_PARTIDA_H
