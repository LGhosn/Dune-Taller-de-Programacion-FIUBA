#include "server_hilo_sender.h"

ServerHiloSender::ServerHiloSender(ColaBloqueante<ComandoServer>& cola_comandos,
                                   ProtocoloServidor& protocolo) :
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
    while (hay_que_seguir) {
        std::unique_ptr<ComandoServer> comando = cola_comandos.wait_and_pop();
        send(std::move(comando));
    }
}

void ServerHiloSender::send(std::unique_ptr<ComandoServer> comando) {
    if (comando)
        comando->enviarComando(this->protocolo);
}

void ServerHiloSender::stop() {
    if (thread.joinable()) {
        hay_que_seguir = false;
        cola_comandos.push(nullptr);
        thread.join();
    }
}

ServerHiloSender::~ServerHiloSender() {
    stop();
}
