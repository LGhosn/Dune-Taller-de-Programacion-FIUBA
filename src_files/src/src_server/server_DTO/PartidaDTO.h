#ifndef SERVER_PARTIDA_DTO_H
#define SERVER_PARTIDA_DTO_H

//#include "../server_handler_cliente/server_handler_cliente.h"
#include <list>
#include <string>
#include <map>

class Partida {
    const std::string nombre_partida;
    uint8_t jugadores_actuales;
    const uint8_t jugadores_requeridos;
    std::list<HandlerCliente*> clientes_conectados;

public:
    Partida(const std::string& nombre_partida, uint8_t jugadores_requeridos);
    void empezar();
    void agregarJugador(HandlerCliente* cliente);
    const bool estaCompleta();
};

struct PartidaCmp {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        if (lhs < rhs) {
            return true;
        }
        return false;
    }
};

struct PartidaDTO {
    const std::string nombre_partida;
    const uint8_t jugadores_actuales;
    const uint8_t jugadores_requeridos;

    PartidaDTO(const std::string& nombre_partida,
               uint8_t jugadores_actuales,
               uint8_t jugadores_requeridos) :
            nombre_partida(nombre_partida),
            jugadores_actuales(jugadores_actuales),
            jugadores_requeridos(jugadores_requeridos) {}
};

struct PartidasDTO {
    std::map<std::string, Partida, PartidaCmp> partidas_creadas;

    explicit PartidasDTO
            (const std::map<std::string, Partida, PartidaCmp>& partidas_creadas) :
            partidas_creadas(partidas_creadas) {}
};

#endif //SERVER_PARTIDA_DTO_H
