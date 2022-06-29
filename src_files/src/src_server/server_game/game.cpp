#include "game.h"
#include "../server_solicitudes/solicitud_juego/sol_crear_edificio.h"
#include "../server_comandos/cmd_crear_edificio.h"
#include "../server_comandos/cmd_empezar_partida.h"
#include "../server_comandos/cmd_empezar_entrenamiento.h"
#include "../server_comandos/cmd_mover_unidad.h"
#include "../server_DTO/dto_unidad_info.h"
#include "../server_comandos/cmd_empezar_construccion_edificio.h"

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
    Jugador* jugador = encontrarJugador(id_jugador);
    for (auto& cola : colas_comandos) {
        CmdCrearEdificioServer* comando =
                new CmdCrearEdificioServer(id_jugador, conts_id_edificios, CODIGO_CENTRO, coords, jugador->obtenerCasa());
        cola.second->push(comando);
    }
    jugador->edificioCreado(CODIGO_CENTRO);
    conts_id_edificios++;
}

Jugador* Game::encontrarJugador(uint8_t id_jugador) {
    for (Jugador& jugador: jugadores)
        if (jugador == id_jugador)
            return &jugador;
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
            constantes(YAML::LoadFile(RUTA_CONSTANTES)) {}


void Game::crearEdificio(uint8_t id_jugador, uint8_t tipo, const Coordenadas& coords) {
    bool resultado = mapa.construirEdificio(id_jugador, tipo, coords);
    if (resultado) {
        Jugador* jugador = encontrarJugador(id_jugador);
        for (auto& cola : colas_comandos) {
            CmdCrearEdificioServer* comando =
                new CmdCrearEdificioServer(id_jugador, conts_id_edificios, tipo, coords, jugador->obtenerCasa());
            cola.second->push(comando);
        }
        conts_id_edificios++;
        jugador->edificioCreado(tipo);
    }
}

std::unique_ptr<Unidad> Game::clasificarUnidad(uint8_t tipo_unidad, Jugador* jugador, uint8_t id_unidad) {
    switch (tipo_unidad) {
        case 1:
            // return std::unique_ptr<Unidad>(new Tanque(id_unidad, jugador, this->mapa));
        default:
            throw std::runtime_error("Game: Tipo de unidad no reconocido");
    }
}

void Game::comprarUnidad(uint16_t id_jugador, uint8_t tipo_unidad) {
    Jugador* jugador = encontrarJugador(id_jugador);
    bool resultado = jugador->comprarUnidad(tipo_unidad);
    if (resultado) {
        uint16_t tiempo_construccion = jugador->obtenerTiempoConstruccionUnidad(tipo_unidad);
        CmdEmpezarEntrenamientoServer* comando =
                        new CmdEmpezarEntrenamientoServer(tipo_unidad, tiempo_construccion);
        colas_comandos[id_jugador]->push(comando);
    }
}

void Game::moverUnidad(uint16_t id_unidad, const Coordenadas& destino) {
    std::unique_ptr<Unidad>& unidad = this->unidades.at(id_unidad);
    unidad->empezarMovimiento(destino);
}


void Game::comprarEdificio(uint8_t id_jugador, uint8_t tipo) {
    Jugador* jugador = encontrarJugador(id_jugador);
    bool resultado = jugador->comprarEdificio(tipo);
    if (resultado) {
        uint16_t tiempo_construccion = jugador->obtenerTiempoConstruccionEdificio();
        CmdEmpezarConstruccionEdificioServer* comando =
                        new CmdEmpezarConstruccionEdificioServer(tipo, tiempo_construccion);
        colas_comandos[id_jugador]->push(comando);
    }
}

void Game::agregarJugador(ColaBloqueante<ComandoServer>* cola_comando,
                            uint8_t id_jugador, uint8_t casa, std::string& nombre) {
    colas_comandos[id_jugador] = cola_comando;
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
            for (auto& cola: colas_comandos) {
                CmdMoverUnidadServer* comando =
                    new CmdMoverUnidadServer(unidades_jugador.first, direccion, tiempo);
                cola.second->push(comando);
            }
            tiempo = -1;
            direccion = ' ';
        }
        
    }
}

bool Game::update(long iter) {
    updateUnidad(iter);
    return true;
}

Game::Game(Game&& game) :
            finished(game.finished),
            colas_comandos(std::move(game.colas_comandos)),
            jugadores(std::move(game.jugadores)),
            mapa(game.nombre_mapa),
            nombre_mapa(game.nombre_mapa),
            constantes(std::move(game.constantes)) {}

Game& Game::operator=(Game&& game) {
    if (this == &game)
        return *this;
    this->finished = game.finished;
    this->colas_comandos = std::move(game.colas_comandos);
    this->jugadores = std::move(game.jugadores);
    this->mapa = Mapa(game.nombre_mapa);
    this->nombre_mapa = std::move(game.nombre_mapa);
    this->constantes = std::move(game.constantes);
    return *this;
}
