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
        // Recibimos el código de operación.
        uint8_t codigo;
        protocolo.recibirCodigoDeOperacion(codigo);

        // En base a este código recibimos la info correspondiente.
        std::unique_ptr<InfoDTO> info = protocolo.recibirInfoSegunCodigo(codigo);

        // Tomamos esa información y encolamos.
        // Comando cmd = this->armarComandoSegunInfo(info);
        // cola_eventos.push(&cmd);
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