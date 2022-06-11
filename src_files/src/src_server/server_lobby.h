#ifndef LOBBY_H
#define LOBBY_H

#include "server_DTO/partida_DTO.h"
#include "server_partida/server_partida.h"
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <mutex>

class Partida;

class Lobby {
    std::map<std::string, Partida, PartidaCmp> partidas_creadas;
    std::mutex m;

    /*
     * Lista una partida si y solo si dicha partida no
     * fue creada anteriormente, es decir, no existe una
     * partida con el mismo nombre en la lista de partidas.
     * */
    void listarPartida(Partida& nueva_partida);

public:
    /*
     * Devuelve true en caso de poder crearse la partida (en tal
     * caso es listada), false en caso contrario.
     * */
    bool crearPartida(const PartidaDTO& partida_a_crear);

    /*
     * Devuelve true en caso de poder unir un jugador a la partida
     * (si el juador se puede unir y con el se puede comenzar la
     * partida, se imprime un mensaje que lo informa), false en 
     * caso contrario.
     * */
    bool unirAPartida(const PartidaDTO& partida_a_unirse);
    
    /*
     * Devuelve un objeto DTO para enviarlo al protocolo.
     * */
    PartidasDTO getListado();
};
#endif
