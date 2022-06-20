#include "server_hilo_sender.h"

ServerHiloSender::ServerHiloSender(ColaBloqueante<ComandoServer>* cola_comandos,
                                   ProtocoloServidor* protocolo, YAML::Node* codigos) :
                                   cola_comandos(cola_comandos),
                                   protocolo(protocolo),
                                   codigos(nullptr) {}

void ServerHiloSender::start() {
    this->thread = std::thread(&ServerHiloSender::handleThread, this);
}

void ServerHiloSender::handleThread() {
    try {
        this->run();
    } catch (const std::exception& e) {
        std::cerr << "Excepción encontrada en ServerHiloSender: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción desconocida en ServerHiloSender: " << std::endl;
    }
}

void ServerHiloSender::run() {
    while (this->hay_que_seguir) {
        std::unique_ptr<ComandoServer> comando = this->cola_comandos->wait_and_pop();
        this->send(std::move(comando));
    }
}

void ServerHiloSender::send(std::unique_ptr<ComandoServer> comando) {
    if (comando)
        comando->enviarComando(*this->protocolo);
}

// void ServerHiloSender::stop() {
//     this->hay_que_seguir = false;
// }

ServerHiloSender::~ServerHiloSender() {
    this->hay_que_seguir = false;
    this->cola_comandos->push(nullptr);
    if (this->thread.joinable()) {
        this->thread.join();
    }
}

ServerHiloSender::ServerHiloSender(ServerHiloSender&& otro):
                                    thread(std::move(otro.thread)),
                                     cola_comandos(otro.cola_comandos),
                                     protocolo(otro.protocolo),
                                     hay_que_seguir(otro.hay_que_seguir),
                                     codigos(nullptr) {}

ServerHiloSender& ServerHiloSender::operator=(ServerHiloSender&& otro) {
    if (this == &otro) {
        return *this;
    }

    if (this->thread.joinable()) {
        this->thread.join();
    }

    this->thread = std::move(otro.thread);
    this->cola_comandos = otro.cola_comandos;
    this->protocolo = otro.protocolo;
    this->hay_que_seguir = otro.hay_que_seguir;
    return *this;
}
