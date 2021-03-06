#ifndef LOBBY_H
#define LOBBY_H

#include "server_DTO/partida_DTO.h"
#include "server_partida/server_partida.h"
#include "../src_common/common_DTO/dto_sol_crear_partida.h"
#include "../src_common/common_DTO/dto_sol_unirse_a_partida.h"
#include "../src_common/common_DTO/Status.h"
#include <list>
#include <string>
#include <iostream>
#include <cstdlib>
#include <mutex>

class HandlerCliente;
class Partida;
class Status;

class Lobby {
    std::list<Partida> partidas_creadas;
    std::mutex m;

    Partida* encontrarPartida(const std::string& nombre);

public:
    /*
     * Devuelve true en caso de poder crearse la partida (en tal
     * caso es listada), false en caso contrario.
     * */
    void crearPartida(const SolicitudCrearPartidaDTO& partida_a_crear, HandlerCliente& cliente);

    /*
     * Devuelve true en caso de poder unir un jugador a la partida
     * (si el jugador se puede unir y con el se puede comenzar la
     * partida, se imprime un mensaje que lo informa), false en 
     * caso contrario.
     * */
    void unirAPartida(const SolicitudUnirseAPartidaDTO& partida_a_unirse, HandlerCliente& cliente);

    /*
     * Imprime en la consola del servidor cuando una partida comienza.
     * */
    static void informarPartidaComenzada(std::string &nombre_partida);

    void limpiarPartidasFinalizadas();

    void terminarPartidas();

    /*
     * Devuelve un objeto DTO para enviarlo al protocolo.
     * */
    // PartidasDTO getListado();
};
#endif
