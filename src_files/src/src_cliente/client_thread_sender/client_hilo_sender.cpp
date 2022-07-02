#include "client_hilo_sender.h"

ClientHiloSender::ClientHiloSender(ColaBloqueante<SolicitudCliente> &cola_comandos, ProtocoloCliente &protocolo,
                                    uint8_t id_jugador) :
                                    cola_comandos(cola_comandos),
                                    protocolo(protocolo),
                                    id_jugador(id_jugador),
                                    thread(std::thread(&ClientHiloSender::handleThread, this)) {}

void ClientHiloSender::handleThread() {
    try {
        this->run();
    } catch (const SocketError& e) {
        std::cerr << "Cerrando Sender\n";
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
    if (solicitud)
        solicitud->enviarSolicitud(this->protocolo, id_jugador);
}

void ClientHiloSender::stop() {
    this->hay_que_seguir = false;
    this->cola_comandos.push(nullptr);
    this->thread.join();
    std::cerr << "Stop en sender" << std::endl;
}

ClientHiloSender::~ClientHiloSender() {
    if (this->thread.joinable()) {
        stop();
    }
    std::cerr << "Destruyendo Sender\n";
}
