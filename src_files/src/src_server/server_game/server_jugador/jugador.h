#ifndef SERVER_JUGADOR_H
#define SERVER_JUGADOR_H

#include <cstdint>
#include <string>
#include "../../../src_common/common_colas/cola_bloqueante.h"
#include "../../server_comandos/server_comando.h"

class Jugador {
    uint8_t id;
    uint8_t casa;
    std::string nombre;
    ColaBloqueante<ComandoServer>& cola_comandos;

public:
    Jugador(uint8_t id, uint8_t casa, std::string& nombre,
            ColaBloqueante<ComandoServer>& cola_comandos);
    
    uint8_t obtenerId() const;
    uint8_t obtenerCasa() const;
    const std::string& obtenerNombre() const;

    bool operator==(const uint8_t& id_jugador) const;
};

#endif
