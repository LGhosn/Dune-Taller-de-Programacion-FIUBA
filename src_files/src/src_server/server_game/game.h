#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../server_comandos/server_comando.h"
#include "server_mapa/server_mapa.h"
#include "server_jugador/jugador.h"
#include "yaml-cpp/yaml.h"

#define RUTA_CONSTANTES RESOURCE_PATH "/constantes/server_constantes.yaml"

class Game {
    bool finished = false;
    std::map< uint8_t, ColaBloqueante<ComandoServer>* > colas_comandos;
    std::list<Jugador> jugadores;
    Mapa mapa;
    std::string nombre_mapa;
    uint8_t conts_id_edificios = 0;
    YAML::Node constantes;

    std::map<uint8_t, Coordenadas> sortearCentros() const;

    void crearCentro(uint16_t id_jugador, const Coordenadas& coords);
    void crearCentrosDeConstruccion(std::map<uint8_t, Coordenadas>& centros_sorteados);
    
    /*
     * Encuentra un Jugador en base a la id dada. Si no se encuentra el jugador, se
     * lanza una excepcion de tipo runtime_error.
    */
    Jugador* encontrarJugador(uint8_t id_jugador);

public:
    Game(const std::string& nombre_mapa);

    void crearEdificio(uint16_t id_jugador, uint16_t id_edificio, const Coordenadas& coords);

    void comprarUnidad(uint16_t id_jugador, uint8_t tipo_unidad);

    void moverUnidad(uint16_t id_jugador, uint8_t tipo_unidad, const Coordenadas& origen, const Coordenadas& destino);

    void agregarJugador(ColaBloqueante<ComandoServer>* cola_comando, uint8_t id_jugador, 
                        uint8_t casa, std::string& nombre);

    /*
     * Envia un Comando EmpezarPartida a cada cliente, con todos los detalles necesarios.
     * Ademas, distribuye los centros de construccion del mapa a cada jugador, y los
     * construye (envia el CmdCrearEdificio a cada cliente)
    */
    void empezarPartida();

    bool update(long iter);

    Game &operator=(const Game &game) = delete;
    Game(const Game &game) = delete;
    Game &operator=(Game &&game);
    Game(Game &&game);
};


#endif //GAME_H
