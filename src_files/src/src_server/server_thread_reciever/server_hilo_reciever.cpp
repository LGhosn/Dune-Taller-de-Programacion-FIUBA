#include "server_hilo_reciever.h"

void ServerHiloReceiver::recibirSolicitudSegunCodigo(uint8_t codigo) {
    // switch (codigo) {
    //     case 
    // }
    //codigos[codigo] 
}

void ServerHiloReceiver::manejarSolicitudMenuSegunCodigo(uint8_t codigo) {
    switch (codigo) {
        // Solicitan unirse a una partida.
        case 1:
        this->manejarSolicitudUnirseAPartida();
        break;

        // Solicitan crear una partida.
        case 3:
        this->manejarSolicitudCrearPartida();
        break;
    }
}

void ServerHiloReceiver::manejarSolicitudCrearPartida() {
    SolicitudCrearPartidaDTO solicitud = this->protocolo->recibirSolicitudCrearPartida();
    this->cliente_asociado->crearPartida(solicitud);
}

void ServerHiloReceiver::manejarSolicitudUnirseAPartida() {
    SolicitudUnirseAPartidaDTO solicitud = protocolo->recibirSolicitudUnirseAPartida();
    this->cliente_asociado->unirsePartida(solicitud);
}

ServerHiloReceiver::ServerHiloReceiver(ProtocoloServidor* protocolo, YAML::Node* codigos, HandlerCliente *cliente_asociado) :
                                    protocolo(protocolo),
                                    hay_que_seguir(true),
                                    partida_comenzada(false),
                                    codigos(codigos),
                                    cliente_asociado(cliente_asociado) {
    this->thread = std::thread(&ServerHiloReceiver::handleThread, this);
}

void ServerHiloReceiver::handleThread() {
    try {
        this->run();
    } catch (const SocketError& e) {
        
    } catch (const std::exception &e) {
        std::cerr << "Excepción encontrada en ServerHiloReceiver: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción encontrada en ServerHiloReceiver: " << std::endl;
    }
}

void ServerHiloReceiver::run() {
    while (this->hay_que_seguir) {
        uint8_t codigo;
        protocolo->recibirCodigoDeOperacion(codigo);
        if (partida_comenzada) {
            this->recibirSolicitudSegunCodigo(codigo);
        } else {
            std::cout << codigo << std::endl;
            this->manejarSolicitudMenuSegunCodigo(codigo);
        }
    }
}

void ServerHiloReceiver::empezarPartida(ColaNoBloqueante<SolicitudServer>* cola_de_solicitudes) {
    this->cola_solicitudes = cola_de_solicitudes;
    this->partida_comenzada = true;
}

void ServerHiloReceiver::stop() {
    this->hay_que_seguir = false;
}

ServerHiloReceiver::~ServerHiloReceiver() {
    if (this->thread.joinable()) {
        this->thread.join();
    }
}

ServerHiloReceiver::ServerHiloReceiver(ServerHiloReceiver&& otro):
                                        cola_solicitudes(otro.cola_solicitudes),
                                        protocolo(otro.protocolo),
                                        thread(std::move(otro.thread)) {}

ServerHiloReceiver& ServerHiloReceiver::operator=(ServerHiloReceiver&& otro) {
    if (this == &otro) {
        return *this;
    }
    this->cola_solicitudes = otro.cola_solicitudes;
    this->protocolo = otro.protocolo;
    this->thread = std::move(otro.thread);
    return *this;
}
