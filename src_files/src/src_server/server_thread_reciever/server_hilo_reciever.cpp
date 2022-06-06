#include "server_hilo_reciever.h"

ServerHiloReciever::ServerHiloSender(ColaNoBloqueante<Comando>& cola_eventos, Protocolo_servidor protocolo) :
                                    cola_eventos(cola_eventos),
                                    protocolo(protocolo) {
    this->thread = std::thread(&ServerHiloSender::handleThread, this);
}

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
        protocolo.recibirCodigoDeOperacion(codigo);
        std::unique_ptr<InfoDTO> info = protocolo.recibirInfoSegunCodigo(codigo);
        SolicitudMoverUnidad solicitud(info->getUnidad(), info->getX(), info->getY());
        cola_eventos.push(&solicitud);
    }
}

void ServerHiloReciever::stop() {
    this->hay_que_seguir = false;
}

ServerHiloReciever::~ServerHiloReciever() {
    if (this->thread.joinable()) {
        this->thread.join();
    }
}