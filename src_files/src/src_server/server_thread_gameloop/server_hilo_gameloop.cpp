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
    std::queue<std::unique_ptr<SolicitudServer>> solicitudes = this->cola_solicitudes.popAll();
    while(!solicitudes.empty()) {
        std::unique_ptr<SolicitudServer> solicitud = std::move(solicitudes.front());
        solicitudes.pop();
        solicitud->ejecutar(this->game);
    }
}

bool HiloGameLoop::update(long iter) {
    return this->game.update(iter);
}

HiloGameLoop::HiloGameLoop(std::vector<ColaBloqueante<ComandoServer>*>& colas_comandos,
                                        ColaNoBloqueante<SolicitudServer>& cola_solicitudes,
                                        std::string& ruta_mapa):
                                        cola_solicitudes(cola_solicitudes),
                                        colas_comandos(colas_comandos),
                                        game(colas_comandos) {}

void HiloGameLoop::start() {
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
    this->cola_solicitudes = std::move(otro.cola_solicitudes);
    this->colas_comandos = std::move(otro.colas_comandos);
    this->game = std::move(otro.game);
    this->hilo = std::move(otro.hilo);
    return *this;
}
HiloGameLoop::HiloGameLoop(HiloGameLoop &&otro) :
                            cola_solicitudes(otro.cola_solicitudes),
                            colas_comandos(otro.colas_comandos),
                            game(std::move(otro.game)),
                            hilo(std::move(otro.hilo)) {}
