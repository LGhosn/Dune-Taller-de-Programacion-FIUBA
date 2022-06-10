#include "client_hilo_sender.h"

ClientHiloSender::ClientHiloSender(ColaBloqueante<SolicitudCliente> &cola_comandos, Client* cliente) :
                                    cola_comandos(cola_comandos),
                                    cliente(cliente),
                                    protocolo(cliente->protocoloAsociado()),
                                    thread(std::thread(&ClientHiloSender::handleThread, this)) {}

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
        std::unique_ptr<SolicitudCliente> solicitud = this->cola_comandos.wait_and_pop();
        this->send(solicitud);
    }
}

void ClientHiloSender::send(std::unique_ptr<SolicitudCliente>& solicitud) {
    solicitud->enviarSolicitud(this->protocolo);
}

void ClientHiloSender::stop() {
    this->hay_que_seguir = false;
}

ClientHiloSender::~ClientHiloSender() {
    if (this->thread.joinable()) {
        this->thread.join();
    }
}
