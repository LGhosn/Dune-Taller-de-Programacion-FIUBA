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

    // Constantes
    uint16_t tiempo_construccion_base;

public:
    Jugador(uint8_t id, uint8_t casa, std::string& nombre,
            ColaBloqueante<ComandoServer>* cola_comandos,
            YAML::Node& constantes);
    
    /*
     * Le envia al cliente todos los valores iniciales necesarios.
    */
    void empezarPartida();

    /*
     * Devuelve el id del jugador.
    */
    uint8_t obtenerId() const;

    /*
     * Devuelve el codigo de la casa del jugador.
     * Atreides = 0, Harkonnen = 1, Ordos = 2
    */
    uint8_t obtenerCasa() const;

    /*
     * Devuelve una refencia al nombre del jugador.
    */
    const std::string& obtenerNombre() const;
    bool comprarUnidad(uint8_t tipo_unidad);

    /*
     * Recibe el tipo de edificio a comprar, y, si es posible comprarlo,
     * resta el valor del edificio a la cantidad de especia actual, actualiza
     * los edificios comprables al cliente, y el nuevo valor de la especia.
     * De no ser posible comprar el edificio, simplemente devuelve false.
    */
    bool comprarEdificio(uint8_t tipo_edificio);

    uint16_t obtenerTiempoConstruccion();

    bool operator==(const uint8_t& id_jugador) const;

    Jugador& operator=(const Jugador& otro) = delete;
    Jugador(const Jugador& otro) = delete;
    Jugador& operator=(Jugador&& otro);
    Jugador(Jugador&& otro);
};

#endif
