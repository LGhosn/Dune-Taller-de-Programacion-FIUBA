#include "game.h"
#include <utility>
#include "../server_solicitudes/solicitud_juego/sol_crear_edificio.h"
#include "../server_comandos/cmd_crear_edificio.h"
#include "../server_comandos/cmd_empezar_partida.h"
#include "../server_comandos/cmd_empezar_entrenamiento.h"
#include "../server_comandos/cmd_mover_unidad.h"
#include "../server_DTO/dto_unidad_info.h"
#include "../server_comandos/cmd_empezar_construccion_edificio.h"
#include "../server_comandos/cmd_construccion_invalida.h"
#include "../server_comandos/cmd_enemigo_despliega_unidad.h"
//unidades
#include "server_unidades/cosechadora.h"
#include "server_unidades/desviador.h"
#include "server_unidades/devastador.h"
#include "server_unidades/fremen.h"
#include "server_unidades/infanteriaLigera.h"
#include "server_unidades/infanteriaPesada.h"
#include "server_unidades/raider.h"
#include "server_unidades/sardaukar.h"
#include "server_unidades/tanque.h"
#include "server_unidades/tanqueSonico.h"
#include "server_unidades/trike.h"

#define CODIGO_CENTRO 0

std::map<uint8_t, Coordenadas> Game::sortearCentros() const {
    std::list<Coordenadas> centros = mapa.obtenerCoordsCentros();
    std::map<uint8_t, Coordenadas> centros_sorteados;
    for (auto& jugador: jugadores) {
        centros_sorteados[jugador.obtenerId()] = centros.back();
        centros.pop_back();
    }
    return centros_sorteados;
}

void Game::crearCentro(uint16_t id_jugador, const Coordenadas& coords) {
    mapa.construirCentro(id_jugador, coords);
    Jugador& jugador = encontrarJugador(id_jugador);
    for (auto& cola : colas_comandos) {
        CmdCrearEdificioServer* comando =
                new CmdCrearEdificioServer(id_jugador, conts_id_edificios, CODIGO_CENTRO, coords, jugador.obtenerCasa());
        cola.second->push(comando);
    }
    // jugador.edificioCreado(CODIGO_CENTRO);
    conts_id_edificios++;
}

Jugador& Game::encontrarJugador(uint8_t id_jugador) {
    for (Jugador& jugador: jugadores)
        if (jugador == id_jugador)
            return jugador;
    throw std::runtime_error("Game: Jugador no encontrado");
}

void Game::crearCentrosDeConstruccion(std::map<uint8_t, Coordenadas>& centros_sorteados) {
    for (auto& jugador_centro: centros_sorteados) {
        this->crearCentro(jugador_centro.first, jugador_centro.second);
    }
}

Game::Game(const std::string& nombre_mapa) :
            mapa(nombre_mapa),
            nombre_mapa(nombre_mapa),
            constantes(YAML::LoadFile(RUTA_CONSTANTES)),
            atributos_unidades(YAML::LoadFile(RUTA_ATRIBUTOS_UNIDADES)) {}


void Game::crearEdificio(uint8_t id_jugador, uint8_t tipo, const Coordenadas& coords) {
    bool resultado = mapa.construirEdificio(id_jugador, tipo, coords);
    if (resultado) {
        Jugador& jugador = encontrarJugador(id_jugador);
        for (auto& cola : colas_comandos) {
            CmdCrearEdificioServer* comando =
                new CmdCrearEdificioServer(id_jugador, conts_id_edificios, tipo, coords, jugador.obtenerCasa());
            cola.second->push(comando);
        }
        conts_id_edificios++;
        // jugador.edificioCreado(tipo);
    } else {
        CmdConstruccionInvalidaServer* comando = new CmdConstruccionInvalidaServer();
        colas_comandos[id_jugador]->push(comando);
    }
}

std::unique_ptr<Unidad> Game::clasificarUnidad(uint8_t tipo_unidad, Jugador& jugador, uint8_t id_unidad, Coordenadas& coords_spawn) {
    switch (tipo_unidad) {
        case 0:
            return std::unique_ptr<Unidad>(new InfanteriaLigera(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 1:
            return std::unique_ptr<Unidad>(new InfanteriaPesada(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 2:
            return std::unique_ptr<Unidad>(new Fremen(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 3:
            return std::unique_ptr<Unidad>(new Sardaukar(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 4:
            return std::unique_ptr<Unidad>(new Trike(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 5:
            return std::unique_ptr<Unidad>(new Raider(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 6:
            return std::unique_ptr<Unidad>(new Tanque(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 7:
            return std::unique_ptr<Unidad>(new TanqueSonico(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 8:
            return std::unique_ptr<Unidad>(new Desviador(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 9:
            return std::unique_ptr<Unidad>(new Devastador(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        case 10:
            return std::unique_ptr<Unidad>(new Cosechadora(id_unidad, jugador, this->mapa, this->atributos_unidades, coords_spawn));
        default:
            throw std::runtime_error("Game: Tipo de unidad no reconocido");
    }
}

void Game::comprarUnidad(uint16_t id_jugador, uint8_t tipo_unidad) {
    Jugador& jugador = encontrarJugador(id_jugador);
    bool resultado = jugador.comprarUnidad(tipo_unidad);
    if (resultado) {
        uint8_t id_uni = this->conts_id_unidad++;
        Coordenadas& coords_spawn = this->mapa.obtenerCoordenadasSpawn(id_jugador);
        this->mapa.spawnearUnidad(id_jugador, tipo_unidad, id_uni, coords_spawn);
        std::unique_ptr<Unidad> uni = this->clasificarUnidad(tipo_unidad, jugador, id_uni, coords_spawn);
        this->unidades.insert(std::make_pair(id_uni, std::move(uni)));

        uint16_t tiempo_construccion = jugador.obtenerTiempoConstruccionUnidad(tipo_unidad);
        CmdEmpezarEntrenamientoServer* comando =
                        new CmdEmpezarEntrenamientoServer(id_uni, tipo_unidad, tiempo_construccion, coords_spawn);
        colas_comandos[id_jugador]->push(comando);

        for (auto& cola : colas_comandos) {
            if (cola.first == id_jugador) {
                continue;
            }
            CmdEnemigoDespliegaUnidadServer* comando =
                new CmdEnemigoDespliegaUnidadServer(id_uni, cola.first, tipo_unidad, tiempo_construccion, coords_spawn);
            cola.second->push(comando);
        }
    }
}

void Game::moverUnidad(uint16_t id_unidad, const Coordenadas& destino) {
    std::unique_ptr<Unidad>& unidad = this->unidades.at(id_unidad);
    unidad->empezarMovimiento(destino);
}


void Game::comprarEdificio(uint8_t id_jugador, uint8_t tipo) {
    Jugador& jugador = encontrarJugador(id_jugador);
    bool resultado = jugador.comprarEdificio(tipo);
    if (resultado) {
        uint16_t tiempo_construccion = jugador.obtenerTiempoConstruccionEdificio();
        CmdEmpezarConstruccionEdificioServer* comando =
                        new CmdEmpezarConstruccionEdificioServer(tipo, tiempo_construccion);
        colas_comandos[id_jugador]->push(comando);
    }
}

void Game::agregarJugador(ColaBloqueante<ComandoServer>& cola_comando,
                            uint8_t id_jugador, uint8_t casa, std::string& nombre) {
    // colas_comandos.emplace(id_jugador, cola_comando);
    colas_comandos[id_jugador] = &cola_comando;
    jugadores.emplace_back(id_jugador, casa, nombre, cola_comando, constantes);
}

void Game::empezarPartida() {
    std::map<uint8_t, Coordenadas> centros_sorteados = sortearCentros();
    std::map<uint8_t, std::pair<uint8_t, std::string>> info_jugadores;
    for (auto& jugador: jugadores) {
        info_jugadores[jugador.obtenerId()] = 
                            std::pair<uint8_t, std::string>(jugador.obtenerCasa(), jugador.obtenerNombre());   
    }
    for (auto& cola_jugador: colas_comandos) {
        uint8_t id = cola_jugador.first;
        InfoPartidaDTO info_partida(nombre_mapa, info_jugadores, centros_sorteados[id]);
        CmdEmpezarPartida* comando = new CmdEmpezarPartida(info_partida);
        cola_jugador.second->push(comando);
    }
    crearCentrosDeConstruccion(centros_sorteados);
    for (auto& jugador: jugadores)
        jugador.empezarPartida();
}

void Game::updateUnidad(long iter) {
    long tiempo = -1;
    char direccion = ' ';
    for (auto& unidades_jugador: unidades) {
        unidades_jugador.second->update(iter, &tiempo, &direccion);

        if (tiempo != -1){
            uint8_t id_jugador_actual = unidades_jugador.second->obtenerIdJugador();
            colas_comandos[id_jugador_actual]->push(new CmdMoverUnidadServer(unidades_jugador.first, tiempo, direccion));
            tiempo = -1;
            direccion = ' ';
        }
        
    }
}

bool Game::update(long iter) {
    updateUnidad(iter);
    return true;
}
