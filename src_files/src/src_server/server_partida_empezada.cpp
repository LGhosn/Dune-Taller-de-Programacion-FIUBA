#include "server_partida_empezada.h"

PartidaEmpezada::PartidaEmpezada(std::vector<Jugador>& jugadores, std::string& ruta_mapa, Protocolo_servidor& protocolo) :
    jugadores(jugadores), ruta_mapa(ruta_mapa), protocolo(protocolo) {
    this->hilo = std::thread(&PartidaEmpezada::handleThread, this);
}

void PartidaEmpezada::handleThread() {
    try {
        this->run();
    } catch (const std::exception &e) {
        std::cerr << "Excepción encontrada en PartidaEmpezada: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción encontrada en PartidaEmpezada: " << std::endl;
    }
}

void PartidaEmpezada::run() {
    for (auto& jugador : jugadores) {
        this->colas_jugadores[jugadores] = ColaBloqueante<ComandoAEnviar>();
    }
    std::vector<ServerHiloReciever> hilos_reciever;
    std::vector<ServerHiloSender> hilos_sender;
    ColaNoBloqueante<Solicitud> cola_solicitudes;
    for (auto& jugador : jugadores) {
        hilos_reciever.emplace_back(cola_solicitudes, protocolo);
        hilos_sender.emplace_back(cola_jugadores[jugador], protocolo);
    }
    GameLoop game_loop(cola_jugadores, cola_solicitudes, ruta_mapa);
}

PartidaEmpezada::~PartidaEmpezada() {
    if(this->hilo.joinable()) {
        this->hilo.join();
    }
}
