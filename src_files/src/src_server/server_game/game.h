#ifndef GAME_H
#define GAME_H

#include <vector>
#include <list>
#include <unordered_map>
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../server_comandos/server_comando.h"
#include "server_unidades/unidades.h"
#include "server_mapa/server_mapa.h"
#include "server_jugador/jugador.h"
#include "yaml-cpp/yaml.h"
#include "server_gusano.h"

#define RUTA_CONSTANTES RESOURCE_PATH "/constantes/server_constantes.yaml"
#define RUTA_ATRIBUTOS_UNIDADES RESOURCE_PATH "/constantes/atributos_unidades.yaml"

class Game {
    bool finished = false;
    std::map< uint8_t, ColaBloqueante<ComandoServer>* > colas_comandos;
    std::list<Jugador> jugadores;
    std::unordered_map<uint8_t, std::unique_ptr<Unidad> > unidades;
    Mapa mapa;
    std::string nombre_mapa;
    uint8_t conts_id_edificios = 0;
    uint8_t conts_id_unidad = 0;
    YAML::Node constantes;
    YAML::Node atributos_unidades;
    Gusano gusano;

    std::map<uint8_t, Coordenadas> sortearCentros() const;

    void crearCentro(uint16_t id_jugador, const Coordenadas& coords);
    void crearCentrosDeConstruccion(std::map<uint8_t, Coordenadas>& centros_sorteados);
    
    /*
     * Encuentra un Jugador en base a la id dada. Si no se encuentra el jugador, se
     * lanza una excepcion de tipo runtime_error.
    */
    Jugador& encontrarJugador(uint8_t id_jugador);
    
    std::unique_ptr<Unidad> clasificarUnidad(uint8_t tipo_unidad, Jugador& jugador, uint8_t id_unidad, Coordenadas& coords_spawn);
    
    void updateUnidad(long iter);
    void updateGusano(long iter);

public:
    Game(const std::string& nombre_mapa);

    void crearEdificio(uint8_t id_jugador, uint8_t id_edificio, const Coordenadas& coords);

    void comprarEdificio(uint8_t id_jugador, uint8_t id_edificio);

    void comprarUnidad(uint16_t id_jugador, uint8_t tipo_unidad);

    void moverUnidad(uint16_t id_unidad, const Coordenadas& destino);

    void agregarJugador(ColaBloqueante<ComandoServer>& cola_comando, uint8_t id_jugador, 
                        uint8_t casa, std::string& nombre);

    /*
     * Envia un Comando EmpezarPartida a cada cliente, con todos los detalles necesarios.
     * Ademas, distribuye los centros de construccion del mapa a cada jugador, y los
     * construye (envia el CmdCrearEdificio a cada cliente)
    */
    void empezarPartida();

    bool update(long iter);

    bool haTerminado() const;

    Game &operator=(const Game &game) = delete;
    Game(const Game &game) = delete;
    Game &operator=(Game &&game) = delete;
    Game(Game &&game) = delete;
};


#endif //GAME_H
