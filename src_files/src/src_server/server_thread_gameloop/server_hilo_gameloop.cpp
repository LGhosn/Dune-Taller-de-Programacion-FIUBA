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
    long iter = 0;
    bool running = true;
    time_point t1 = system_clock::now();
    milliseconds tick_rate(1000 / TICKS_POR_SEGUNDO);
    while(running) {
        this->manejarSolicitudes();
        running = this->update(iter);
        time_point t2 = system_clock::now();
		milliseconds tiempo_transcurrido = duration_cast<milliseconds>(t2 - t1);
		t1 = t2;
        milliseconds rest;
        if (tiempo_transcurrido.count() > tick_rate.count()) {
			milliseconds demora = duration_cast<milliseconds>(tiempo_transcurrido - tick_rate);
			rest = duration_cast<milliseconds>(demora % tick_rate);
			milliseconds tiempo_perdido = demora + rest;
			iter += tiempo_perdido.count() / tick_rate.count();
		} else {
			rest = duration_cast<milliseconds>(tick_rate - tiempo_transcurrido);
            iter++;
		}
        std::this_thread::sleep_for(rest);
    }
}

void HiloGameLoop::manejarSolicitudes() {
    std::queue<std::unique_ptr<SolicitudServer>> solicitudes = this->cola_solicitudes->popAll();
    while(!solicitudes.empty()) {
        std::unique_ptr<SolicitudServer> solicitud = std::move(solicitudes.front());
        solicitudes.pop();
        solicitud->ejecutar(this->game);
    }
}

bool HiloGameLoop::update(long iter) {
    return this->game.update(iter);
}

HiloGameLoop::HiloGameLoop(ColaNoBloqueante<SolicitudServer>* cola_solicitudes,
                                        const std::string& nombre_mapa):
                                        cola_solicitudes(cola_solicitudes),
                                        game(nombre_mapa) {}

void HiloGameLoop::agregarJugador(ColaBloqueante<ComandoServer>* cola_comando,
                                    uint8_t id_jugador, uint8_t casa, std::string& nombre) {
    game.agregarJugador(cola_comando, id_jugador, casa, nombre);
}

void HiloGameLoop::start() {
    game.empezarPartida();
    std::cout << "Hilo Gameloop empezado" << std::endl;
    this->hilo = std::thread(&HiloGameLoop::manejarHilo, this);
}

HiloGameLoop::~HiloGameLoop() {
    if (this->hilo.joinable()) {
        this->hilo.join();
    }
}

HiloGameLoop& HiloGameLoop::operator=(HiloGameLoop&& otro) {
    if (this == &otro)
        return *this;
    this->cola_solicitudes = otro.cola_solicitudes;
    this->game = std::move(otro.game);
    this->hilo = std::move(otro.hilo);

    otro.cola_solicitudes = nullptr;
    return *this;
}
HiloGameLoop::HiloGameLoop(HiloGameLoop &&otro) :
                            cola_solicitudes(otro.cola_solicitudes),
                            game(std::move(otro.game)),
                            hilo(std::move(otro.hilo)) {}
