#ifndef LOBBY_H
#define LOBBY_H

#include "../src_common/common_DTOs.h"
#include "server_partida.h"
#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <mutex>

class Lobby {
    std::map<std::string, Partida, PartidaCmp> partidas_creadas;
    std::mutex m;

    /*
     * Lista una partida si y solo si dicha partida no
     * fue creada anteriormente, es decir, no existe una
     * partida con el mismo nombre en la lista de partidas.
     * */
    void listarPartida(const Partida& nueva_partida);

public:
    /*
     * Devuelve true en caso de poder crearse la partida (en tal
     * caso es listada), false en caso contrario.
     * */
    bool crearPartida(const PartidaDTO& partida_a_crear, HandlerCliente *handler);

    /*
     * Devuelve true en caso de poder unir un jugador a la partida
     * (si el juador se puede unir y con el se puede comenzar la
     * partida, se imprime un mensaje que lo informa), false en 
     * caso contrario.
     * */
    bool unirAPartida(const PartidaDTO& partida_a_unirse, HandlerCliente *handler);
    
    /*
     * Devuelve un objeto DTO para enviarlo al protocolo.
     * */
    PartidasDTO getListado();
};
#endif
