#include "client_hilo_sender.h"

ClientHiloSender::ClientHiloSender(ColaBloqueante<ComandoAEnviar> &cola_comandos, ProtocoloCliente &protocolo) : cola_comandos(cola_comandos), protocolo(protocolo) {
    this->thread = std::thread(&ClientHiloSender::handleThread, this);
}

void ClientHiloSender::handleThread() {
    try {
        this->run();
    } catch (const std::exception& e) {
        std::cerr << "Excepción encontrada en ClientHiloSender: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida en ClientHiloSender: " << std::endl;
    }
}

void ClientHiloSender::run() {
    while (this->hay_que_seguir) {
        std::unique_ptr<ComandoAEnviar> comando = this->cola_comandos.wait_and_pop();
        this->send(comando);
    }
}

void ClientHiloSender::send(ComandoAEnviar &comando) {
    comando->enviarSolicitud(this->protocolo);
}

void ClientHiloSender::stop() {
    this->hay_que_seguir = false;
}

ClientHiloSender::~ClientHiloSender() {
    if (this->thread.joinable()) {
        this->thread.join();
    }
}
