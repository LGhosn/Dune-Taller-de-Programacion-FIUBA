#include "server_hilo_gameloop.h"
#include <exception>
#include <iostream>
#include <chrono>

void ServerHiloGameLoop::manejarHilo() {
    try {
        this->run();
    } catch (const std::exception &e) {
        std::cerr << "Excepción encontrada en el hilo GameLoop: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción encontrada en el hilo GameLoop" << std::endl;
    }
}

void ServerHiloGameLoop::run() {
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
        }
        iter++;
    }
}

void ServerHiloGameLoop::manejarSolicitudes() {
    std::queue<std::unique_ptr<Solicitud>> solicitudes = this->sol_entrantes.popAll();
    while(!solicitudes.empty()) {
        std::unique_ptr<Solicitud> solicitud = std::move(solicitudes.front());
        solicitudes.pop();
        solicitud->ejecutar(this->game);
    }
}

bool ServerHiloGameLoop::update(long iter) {
    return this->game.update(iter);
}

ServerHiloGameLoop::ServerHiloGameLoop(std::vector<ColaBloqueante<ComandoAEnviar>&>& colas_eventos, ColaNoBloqueante<Solicitud>& sol_entrantes):
colas_eventos(colas_eventos), sol_entrantes(sol_entrantes), game(colas_eventos) {
    thread = std::thread(&ServerHiloGameLoop::manejarHilo, this);
}

ServerHiloGameLoop::~ServerHiloGameLoop() {
    if (this->thread.joinable()) {
        this->thread.join();
    }
}