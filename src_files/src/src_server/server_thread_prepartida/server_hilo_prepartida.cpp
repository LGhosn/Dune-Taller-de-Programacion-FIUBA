#include "server_hilo_prepartida.h"

HiloPrepartida::HiloPrepartida(ColaBloqueante<SolicitudMenuServer>* cola_solicitudes_menu,
                    std::map<uint8_t, ColaBloqueante<ComandoServer>*>* colas_sender):
                    cola_solicitudes_menu(cola_solicitudes_menu), colas_sender(colas_sender) {}

void HiloPrepartida::manejarHilo() {
    try {
        this->run();
    } catch (const std::exception &e) {
        std::cerr << "Excepción encontrada en HiloPrepartida: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción encontrada en HiloPrepartida: " << std::endl;
    }
}

void HiloPrepartida::run() {
    while (this->hay_que_seguir) {
        std::unique_ptr<SolicitudMenuServer> solicitud =
                    this->cola_solicitudes_menu->wait_and_pop();
        if (solicitud)
            solicitud->manejarSolicitud(*lobby);
    }
}

void HiloPrepartida::start() {
    this->hilo = std::thread(&HiloPrepartida::manejarHilo, this);
}

void HiloPrepartida::stop() {
    this->hay_que_seguir = false;
   this->cola_solicitudes_menu->push(NULL);
}

HiloPrepartida::~HiloPrepartida() {
    if (this->hilo.joinable())
        this->hilo.join();
}
