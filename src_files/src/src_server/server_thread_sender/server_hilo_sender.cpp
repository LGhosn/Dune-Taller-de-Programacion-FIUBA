#include "server_hilo_sender.h"

ServerHiloSender::ServerHiloSender(ColaBloqueante<ComandoServer> &cola_comandos,
                                   ProtocoloServidor &protocolo) :
                                   cola_comandos(cola_comandos),
                                   protocolo(protocolo) {}

void ServerHiloSender::start() {
    this->thread = std::thread(&ServerHiloSender::handleThread, this);
}

void ServerHiloSender::handleThread() {
    try {
        this->run();
    } catch (const std::exception& e) {
        std::cerr << "Excepción encontrada en ServerHiloSender: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida en ServerHiloSender: " << std::endl;
    }
}

void ServerHiloSender::run() {
    while (this->hay_que_seguir) {
        std::unique_ptr<ComandoServer> comando = this->cola_comandos.wait_and_pop();
        this->send(std::move(comando));
    }
}

void ServerHiloSender::send(std::unique_ptr<ComandoServer> comando) {
    comando->enviarComando(this->protocolo);
}

void ServerHiloSender::stop() {
    this->hay_que_seguir = false;
}

ServerHiloSender::~ServerHiloSender() {
    if (this->thread.joinable()) {
        this->thread.join();
    }
}