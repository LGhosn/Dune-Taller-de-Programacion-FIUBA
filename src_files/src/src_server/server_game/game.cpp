#include "game.h"
#include <utility>
#include "../server_solicitudes/solicitud_juego/sol_crear_edificio.h"
#include "../server_comandos/cmd_crear_edificio.h"
#include "../server_comandos/cmd_empezar_partida.h"
#include "../server_comandos/cmd_mover_unidad.h"
#include "../server_DTO/dto_unidad_info.h"
#include "../server_comandos/cmd_empezar_construccion_edificio.h"
#include "../server_comandos/cmd_construccion_invalida.h"
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

void Game::crearCentro(uint8_t id_jugador, const Coordenadas& coords) {
    mapa.construirCentro(id_jugador, coords);
    Jugador& jugador = encontrarJugador(id_jugador);
    for (auto& cola : colas_comandos) {
        CmdCrearEdificioServer* comando =
                new CmdCrearEdificioServer(id_jugador, conts_id_edificios, CODIGO_CENTRO, coords, jugador.obtenerCasa());
        cola.second->push(comando);
    }
    jugador.edificioCreado(CODIGO_CENTRO);
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
            atributos_unidades(YAML::LoadFile(RUTA_ATRIBUTOS_UNIDADES)),
            gusano(constantes["Game"]["Gusano"]["VictimasADevorar"].as<int>(),
                    constantes["Game"]["Gusano"]["TiempoEntreVictimas"].as<uint16_t>(), this->mapa) {}

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
        jugador.edificioCreado(tipo);
    } else {
        CmdConstruccionInvalidaServer* comando = new CmdConstruccionInvalidaServer();
        colas_comandos[id_jugador]->push(comando);
    }
}

std::shared_ptr<Unidad> Game::clasificarUnidad(uint8_t tipo_unidad, Jugador& jugador) {
    switch (tipo_unidad) {
        case 0:
            return std::shared_ptr<Unidad>(new Fremen(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 1:
            return std::shared_ptr<Unidad>(new InfanteriaLigera(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 2:
            return std::shared_ptr<Unidad>(new InfanteriaPesada(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 3:
            return std::shared_ptr<Unidad>(new Sardaukar(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 4:
            return std::shared_ptr<Unidad>(new Cosechadora(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 5:
            return std::shared_ptr<Unidad>(new Desviador(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 6:
            return std::shared_ptr<Unidad>(new Devastador(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 7:
            return std::shared_ptr<Unidad>(new Raider(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 8:
            return std::shared_ptr<Unidad>(new Tanque(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 9:
            return std::shared_ptr<Unidad>(new TanqueSonico(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        case 10:
            return std::shared_ptr<Unidad>(new Trike(jugador, this->mapa, this->atributos_unidades, constantes, colas_comandos, unidades));
        default:
            throw std::runtime_error("Game: Tipo de unidad no reconocido");
    }
}

void Game::comprarUnidad(uint8_t id_jugador, uint8_t tipo_unidad) {
    Jugador& jugador = encontrarJugador(id_jugador);
    bool resultado = jugador.comprarUnidad(tipo_unidad);
    if (resultado) {
        std::shared_ptr<Unidad> unidad = this->clasificarUnidad(tipo_unidad, jugador);
        this->unidades[unidad->obtenerId()] = unidad;
    }
}

void Game::moverUnidad(uint8_t id_jugador, uint8_t id_unidad, const Coordenadas& destino) {
    std::shared_ptr<Unidad>& unidad = this->unidades.at(id_unidad);
    if (id_jugador == unidad->obtenerIdJugador()) {
        unidad->empezarMovimiento(destino);
    }
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
    jugadores.emplace_back(id_jugador, casa, nombre, colas_comandos, constantes);
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

void Game::atacarUnidad(uint8_t id_jugador_atacante, uint8_t id_unidad_atacante, uint8_t id_unidad_a_atacar) {
    this->unidades.at(id_unidad_atacante)->atacar(this->unidades.at(id_unidad_a_atacar));
}

void Game::updateUnidad(long iter) {
    for (auto it = unidades.begin(); it != unidades.end(); it++) {
        if (!it->second->update(iter)) {
            it = unidades.erase(it);
        }
    }
}

void Game::updateGusano(long iter) {
    uint8_t victima;
    if (gusano.devorar(iter, &victima)) {
        // std::unique_ptr<Unidad>& unidad = unidades.at(victima);
        // for (auto& cola_jugador: colas_comandos) {
            // cola_jugador.second->push(new CmdGusanoDevoroServer(victima));
        // }
    }
}

bool Game::update(long iter) {
    updateUnidad(iter);
    updateGusano(iter);
    return true;
}

bool Game::haTerminado() const {
    return finished;
}
