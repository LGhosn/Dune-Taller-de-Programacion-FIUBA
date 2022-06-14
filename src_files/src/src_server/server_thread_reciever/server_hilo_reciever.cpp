#include "server_hilo_reciever.h"

void ServerHiloReciever::recibirSolicitudSegunCodigo(uint8_t codigo) {
    // switch (codigo) {
    //     case 
    // }
    //codigos[codigo] 
}

void ServerHiloReciever::recibirSolicitudMenuSegunCodigo(uint8_t codigo) {
    switch (codigo) {
        // Solicitan unirse a una partida.
        case 1:
        this->recibirSolicitudDeUnion();
        break;

        // Solicitan crear una partida.
        case 3:
        this->recibirSolicitudDeCreacion();
        break;
    }
}

void ServerHiloReciever::recibirSolicitudDeCreacion() {
    PartidaDTO solicitud = this->protocolo->recibirSolicitudDeCreacion();
    this->cliente_asociado->crearPartida(solicitud);
}

void ServerHiloReciever::recibirSolicitudDeUnion() {
    PartidaDTO solicitud = protocolo->recibirSolicitudDeUnion();
    this->cliente_asociado->unirsePartida(solicitud);
}

ServerHiloReciever::ServerHiloReciever(ProtocoloServidor* protocolo, YAML::Node* codigos, HandlerCliente *cliente_asociado) :
                                    protocolo(protocolo),
                                    hay_que_seguir(true),
                                    partida_comenzada(false),
                                    codigos(codigos),
                                    cliente_asociado(cliente_asociado) {
    this->thread = std::thread(&ServerHiloReciever::handleThread, this);
}

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
        protocolo->recibirCodigoDeOperacion(codigo);
        if (partida_comenzada) {
            this->recibirSolicitudSegunCodigo(codigo);
        } else {
            std::cout << codigo << std::endl;
            this->recibirSolicitudMenuSegunCodigo(codigo);
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
