#include "server_hilo_reciever.h"

SolicitudServer* ServerHiloReciever::recibirSolicitudSegunCodigo(uint8_t codigo) {
    // switch (codigo) {
    //     case 
    // }
    //codigos[codigo] 
}

SolicitudMenuServer* ServerHiloReciever::recibirSolicitudMenuSegunCodigo(uint8_t codigo) {
    // switch (codigo) {
    //     case 
    // }
    //codigos[codigo] 
}

ServerHiloReciever::ServerHiloReciever(ProtocoloServidor* protocolo, YAML::Node* codigos,
                                    ColaBloqueante<SolicitudMenuServer>* cola_solicitudes_menu,
                                    HandlerCliente* handler_cliente_padre) :
                                    cola_solicitudes_menu(cola_solicitudes_menu),
                                    protocolo(protocolo),
                                    thread(std::thread(&ServerHiloReciever::handleThread, this)),
                                    codigos(codigos),
                                    handler_cliente_padre(handler_cliente_padre) {}

void ServerHiloReciever::handleThread() {
    try {
        this->run();
    } catch (const SocketError& e) {
        
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
        if (partida_comenzada) {
            SolicitudServer* solicitud = this->recibirSolicitudSegunCodigo(codigo);
            this->cola_solicitudes->push(solicitud);
        } else {
            SolicitudMenuServer* solicitud = this->recibirSolicitudMenuSegunCodigo(codigo);
            this->cola_solicitudes_menu->push(solicitud);
        }
    }
}

void ServerHiloReciever::empezarPartida(ColaNoBloqueante<SolicitudServer>* cola_de_solicitudes) {
    this->cola_solicitudes = cola_de_solicitudes;
    this->partida_comenzada = true;
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
                                        cola_solicitudes_menu(otro.cola_solicitudes_menu),
                                        cola_solicitudes(otro.cola_solicitudes),
                                        protocolo(otro.protocolo),
                                        thread(std::move(otro.thread)) {}

ServerHiloReciever& ServerHiloReciever::operator=(ServerHiloReciever&& otro) {
    if (this == &otro) {
        return *this;
    }
    this->cola_solicitudes_menu = otro.cola_solicitudes_menu;
    this->cola_solicitudes = otro.cola_solicitudes;
    this->protocolo = otro.protocolo;
    this->thread = std::move(otro.thread);
    return *this;
}
