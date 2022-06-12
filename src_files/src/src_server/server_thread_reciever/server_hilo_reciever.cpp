#include "server_hilo_reciever.h"

// SolicitudServer* ServerHiloReciever::recibirComandoSegunCodigo(uint8_t codigo) {
//     // switch (codigo) {
//     //     case 
//     // }
//     //codigos[codigo] 
// }

ServerHiloReciever::ServerHiloReciever(ProtocoloServidor* protocolo) :
                                    protocolo(protocolo) {}

void ServerHiloReciever::handleThread() {
    try {
        this->run();
    } catch (const std::exception &e) {
        std::cerr << "Excepción encontrada en ServerHiloReciever: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción encontrada en ServerHiloReciever: " << std::endl;
    }
}

void ServerHiloReciever::run() {
    while (this->hay_que_seguir) {
        uint8_t codigo;
        protocolo->recibirCodigoDeOperacion(codigo, hay_que_seguir);

        // En base a este código recibimos la info correspondiente.
        // SolicitudServer* solicitud = this->recibirComandoSegunCodigo(codigo);

        // Tomamos esa información y encolamos.
        // cola_solicitudes->push(solicitud);
    }
}

void ServerHiloReciever::start(ColaNoBloqueante<SolicitudServer>* cola_de_solicitudes) {
    this->cola_solicitudes = cola_de_solicitudes;
    this->thread = std::thread(&ServerHiloReciever::handleThread, this);
}

void ServerHiloReciever::stop() {
    this->hay_que_seguir = false;
}

ServerHiloReciever::~ServerHiloReciever() {
    if (this->thread.joinable()) {
        this->thread.join();
    }
}

ServerHiloReciever::ServerHiloReciever(ServerHiloReciever&& otro):
                                        cola_solicitudes(otro.cola_solicitudes),
                                        protocolo(otro.protocolo),
                                        thread(std::move(otro.thread)) {}

ServerHiloReciever& ServerHiloReciever::operator=(ServerHiloReciever&& otro) {
    if (this == &otro) {
        return *this;
    }
    this->cola_solicitudes = otro.cola_solicitudes;
    this->protocolo = otro.protocolo;
    this->thread = std::move(otro.thread);
    return *this;
}
