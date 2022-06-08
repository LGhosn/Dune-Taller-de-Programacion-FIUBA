#include "client_hilo_reciever.h"

ClientHiloReciever::ClientHiloReciever(ColaNoBloqueante<Comando>& cola_eventos,  ProtocoloCliente& protocolo) :
                                        cola_eventos(cola_eventos),
                                        protocolo(protocolo) {
    this->thread = std::thread(&ClientHiloSender::handleThread, this);
}

void ClientHiloReciever::handleThread() {
    try {
        this->run();
    } catch (const std::exception& e) {
        std::cerr << "Excepción encontrada en ClientHiloReceiver: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida en ClientHiloReceiver: " << std::endl;
    }
}

void ClientHiloReciever::run() {
    while (this->hay_que_seguir) {
        // Recibimos la info del server
        // - Primero recibimos el codigo de la operacion
        // - En función al codigo invocamos al metodo que recibe la info respectiva
        uint8_t codigo;
        protocolo.recibirCodigoDeOperacion(codigo);
        // protocolo.recibirInfoSegunCodigo(codigo);
        // Luego la traducimos a un comando
        // Finalmente encolamos el comando
    }
}

void ClientHiloReciever::stop() {
    this->hay_que_seguir = false;
}

void ClientHiloReciever::push(Comando& comando_creado) {
    this->cola_eventos.push(comando_creado);
}

ClientHiloReciever::~ClientHiloReciever() {
    if (this->thread.joinable()) {
        this->thread.join();
    }
}