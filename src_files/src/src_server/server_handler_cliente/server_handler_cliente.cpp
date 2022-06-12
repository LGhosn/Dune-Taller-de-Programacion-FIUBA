#include "server_handler_cliente.h"

HandlerCliente::HandlerCliente(Socket& socket, Lobby* lobby) :
                                socket(std::move(socket)),
                                lobby(lobby),
                                protocolo(&this->socket),
                                hilo_cliente_lobby(new HiloClienteLobby(this->protocolo, this->lobby)),
                                cola_comandos(new ColaBloqueante<ComandoServer>()),
                                hilo_sender(this->cola_comandos, &this->protocolo),
                                hilo_receiver(&this->protocolo) {}

void HandlerCliente::lanzarHilos(ColaNoBloqueante<SolicitudServer>* cola) {
    hilo_receiver.start(cola);
    hilo_sender.start();
}

void HandlerCliente::empezarPartida(ColaNoBloqueante<SolicitudServer>* cola) {
    this->notificarInicioDePartida();
    this->lanzarHilos(cola);
}

void HandlerCliente::notificarInicioDePartida() {
    protocolo.notificarComienzoDePartida();
}

ColaBloqueante<ComandoServer>* HandlerCliente::obtenerColaSender() {
    return this->cola_comandos;
}

bool HandlerCliente::haFinalizado() const {
    return false; // TODO: implementar
}

void HandlerCliente::cerrar() {
    delete this->hilo_cliente_lobby;
    this->socket.shutdown(2);
    this->socket.close();
}

HandlerCliente::~HandlerCliente() {
    delete this->hilo_cliente_lobby;
}

HandlerCliente::HandlerCliente(HandlerCliente&& otro):
                                socket(std::move(otro.socket)),
                                lobby(otro.lobby),
                                protocolo(&this->socket),
                                hilo_cliente_lobby(otro.hilo_cliente_lobby),
                                cola_comandos(otro.cola_comandos),
                                hilo_sender(std::move(otro.hilo_sender)),
                                hilo_receiver(std::move(otro.hilo_receiver)) {}

HandlerCliente& HandlerCliente::operator=(HandlerCliente&& otro) {
    if (this == &otro) {
        return *this;
    }
    delete this->hilo_cliente_lobby;
    delete this->cola_comandos;
    this->socket = std::move(otro.socket);
    this->lobby = otro.lobby;
    this->protocolo = ProtocoloServidor(&this->socket);
    this->hilo_cliente_lobby = otro.hilo_cliente_lobby;
    this->cola_comandos = otro.cola_comandos;
    this->hilo_sender = std::move(otro.hilo_sender);
    this->hilo_receiver = std::move(otro.hilo_receiver);
    return *this;
}
