#include "hilo_sender.h"

ServerHiloSender::ServerHiloSender(ColaBloqueante<ComandoAEnviar> &cola_comandos,
                                   Protocolo_servidor &protocolo) :
                                   cola_comandos(cola_comandos),
                                   protocolo(protocolo) {
    this->th = std::thread(&ServerHiloSender::handleThread, this);
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
        std::unique_ptr<ComandoAEnviar> comando = this->cola_comandos.wait_and_pop();
        this->send(comando);
    }
}

void ServerHiloSender::send(ComandoAEnviar &comando) {
    comando->enviar_instruccion(this->protocolo);
}

void ServerHiloSender::stop() {
    this->hay_que_seguir = false;
}

ServerHiloSender::~ServerHiloSender() {
    if (this->th.joinable()) {
        this->th.join();
    }
}