#ifndef SERVER_JUGADOR_H
#define SERVER_JUGADOR_H

#include <cstdint>
#include <string>
#include "../../../src_common/common_colas/cola_bloqueante.h"
#include "../../server_comandos/server_comando.h"
#include "especia_acumulada.h"

class Jugador {
    uint8_t id;
    uint8_t casa;
    std::string nombre;
    ColaBloqueante<ComandoServer>* cola_comandos;
    EspeciaAcumulada especia;

public:
    Jugador(uint8_t id, uint8_t casa, std::string& nombre,
            ColaBloqueante<ComandoServer>* cola_comandos,
            YAML::Node& constantes);
    
    void empezarPartida();

    uint8_t obtenerId() const;
    uint8_t obtenerCasa() const;
    const std::string& obtenerNombre() const;

    bool operator==(const uint8_t& id_jugador) const;

    Jugador& operator=(const Jugador& otro) = delete;
    Jugador(const Jugador& otro) = delete;
    Jugador& operator=(Jugador&& otro);
    Jugador(Jugador&& otro);
};

#endif
