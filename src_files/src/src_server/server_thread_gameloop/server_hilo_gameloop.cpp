#include "server_hilo_gameloop.h"
#include <exception>
#include <iostream>
#include <chrono>
#include <utility>

void HiloGameLoop::manejarHilo() {
    try {
        this->run();
    } catch (const std::exception &e) {
        std::cerr << "Excepción encontrada en el hilo GameLoop: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción encontrada en el hilo GameLoop" << std::endl;
    }
}

void HiloGameLoop::run() {
    using namespace std::chrono;
    long iter_actual = 0, iter_anterior = 0;
    time_point t1 = system_clock::now();
    milliseconds tick_rate(1000 / TICKS_POR_SEGUNDO);
    while(corriendo) {
        long iter_transcurridos = iter_actual - iter_anterior;
        this->manejarSolicitudes();
        this->update(iter_transcurridos);
        time_point t2 = system_clock::now();
		milliseconds tiempo_transcurrido = duration_cast<milliseconds>(t2 - t1);
		t1 = t2;
        milliseconds rest;
        iter_anterior = iter_actual;
        if (tiempo_transcurrido.count() > tick_rate.count()) {
			milliseconds demora = duration_cast<milliseconds>(tiempo_transcurrido - tick_rate);
			rest = duration_cast<milliseconds>(demora % tick_rate);
			milliseconds tiempo_perdido = demora + rest;
			iter_actual += tiempo_perdido.count() / tick_rate.count();
		} else {
			rest = duration_cast<milliseconds>(tick_rate - tiempo_transcurrido);
            iter_actual++;
		}
        std::this_thread::sleep_for(rest);
    }
}

void HiloGameLoop::manejarSolicitudes() {
    std::queue<std::unique_ptr<SolicitudServer>> solicitudes = cola_solicitudes.popAll();
    while(!solicitudes.empty()) {
        std::unique_ptr<SolicitudServer> solicitud = std::move(solicitudes.front());
        solicitudes.pop();
        solicitud->ejecutar(game);
    }
}

bool HiloGameLoop::update(long iter) {
    return game.update(iter);
}

HiloGameLoop::HiloGameLoop(ColaNoBloqueante<SolicitudServer>& cola_solicitudes,
                                        const std::string& nombre_mapa):
                                        cola_solicitudes(cola_solicitudes),
                                        game(nombre_mapa) {}

void HiloGameLoop::agregarJugador(ColaBloqueante<ComandoServer>& cola_comando,
                                    uint8_t id_jugador, uint8_t casa, std::string& nombre) {
    game.agregarJugador(cola_comando, id_jugador, casa, nombre);
}

void HiloGameLoop::start() {
    game.empezarPartida();
    std::cout << "Hilo Gameloop empezado" << std::endl;
    this->hilo = std::thread(&HiloGameLoop::manejarHilo, this);
}

bool HiloGameLoop::haTerminado() const {
    return game.haTerminado();
}

HiloGameLoop::~HiloGameLoop() {
    if (hilo.joinable()) {
        corriendo = false;
        hilo.join();
    }
}
