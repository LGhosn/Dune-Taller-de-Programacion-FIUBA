#include "server_gameloop.h"
#include <exception>
#include <iostream>
#include <chrono>

void GameLoop::manejarHilo() {
    try {
        this->run();
    } catch (const std::exception &e) {
        std::cerr << "Excepción encontrada en el hilo GameLoop: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción encontrada en el hilo GameLoop" << std::endl;
    }
}

void GameLoop::run() {
    long iter = 0;
    bool running = true;
    auto t1 = std::chrono::steady_clock::now();
    while(running) {
        auto t2 = std::chrono::steady_clock::now();
		float tiempo_transcurrido = std::chrono::duration<float, std::milli>(t2 - t1).count();
		t1 = t2;
        this->manejarSolicitudes();
        running = this->update(iter);
        float rest = FRAME_RATE - tiempo_transcurrido;
        if (rest < 0) {
            float demora = - rest;
            rest = FRAME_RATE - (int) demora % (int) FRAME_RATE;
            float tiempo_perdido = demora + rest;
            iter += tiempo_perdido / FRAME_RATE;
        } else {
            iter++;
        }
    }
}

void GameLoop::manejarSolicitudes() {
    std::queue<std::unique_ptr<SolicitudServer>> solicitudes = this->cola_solicitudes.popAll();
    while(!solicitudes.empty()) {
        std::unique_ptr<SolicitudServer> solicitud = std::move(solicitudes.front());
        solicitudes.pop();
        solicitud->ejecutar(this->game);
    }
}

bool GameLoop::update(long iter) {
    return this->game.update(iter);
}

GameLoop::GameLoop(std::vector<ColaBloqueante<ComandoServer>*>& colas_comandos,
ColaNoBloqueante<SolicitudServer>& cola_solicitudes, std::string& ruta_mapa):
cola_solicitudes(cola_solicitudes), game(colas_comandos),
hilo(&GameLoop::manejarHilo, this) {}
