#ifndef SERVER_JUGADOR_H
#define SERVER_JUGADOR_H

#include <cstdint>
#include <string>
#include <map>
#include "../../../src_common/common_colas/cola_bloqueante.h"
#include "../../server_comandos/server_comando.h"
#include "especia_acumulada.h"
#include "energia_acumulada.h"
#include "validador_unidades.h"

class Jugador {
    uint8_t id;
    uint8_t casa;
    std::string nombre;
    std::map<uint8_t, ColaBloqueante<ComandoServer>*>& colas_comandos;
    EspeciaAcumulada especia;
    EnergiaAcumulada energia;
    std::vector<uint8_t> cantidad_edificios;
    ValidadorUnidades validador_de_unidades;

    // Constantes
    const uint16_t tiempo_construccion_base;
    const std::vector<uint8_t> edificios_multiplicadores;
    const std::vector<uint16_t> tiempo_entrenamiento_por_unidad;

    float obtenerMultiplicadorPorEdificios(uint8_t tipo_unidad);

public:
    Jugador(uint8_t id, uint8_t casa, std::string& nombre,
            std::map<uint8_t, ColaBloqueante<ComandoServer>*>& colas_comandos,
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

    /*
     * Aumenta/disminuye la energia disponible dependiendo del tipo de edificio, y envia la info
     * al cliente.
    */
    void edificioCreado(uint8_t tipo_edificio);

    uint16_t obtenerTiempoConstruccionEdificio();
    uint16_t obtenerTiempoConstruccionUnidad(uint8_t tipo_unidad);

    bool operator==(const uint8_t& id_jugador) const;

    Jugador& operator=(const Jugador& otro) = delete;
    Jugador(const Jugador& otro) = delete;
    Jugador& operator=(Jugador&& otro) = delete;
    Jugador(Jugador&& otro) = delete;
};

#endif
