#include "server_handler_cliente.h"
#include <iostream>

HandlerCliente::HandlerCliente(Socket& socket, Lobby* lobby, YAML::Node* codigos, uint8_t id_cliente) :
                                id_cliente(id_cliente),
                                socket(std::move(socket)),
                                lobby(lobby),
                                protocolo(&this->socket, codigos),
                                codigos(codigos),
                                cola_comandos(new ColaBloqueante<ComandoServer>()),
                                hilo_sender(new ServerHiloSender(this->cola_comandos, &this->protocolo, codigos)),
                                hilo_reciever(new ServerHiloReceiver(&this->protocolo, codigos, this)) {
    protocolo.enviarId(id_cliente);
}

void HandlerCliente::unirsePartida(SolicitudUnirseAPartidaDTO& partida_a_unirse) {
    lobby->unirAPartida(partida_a_unirse, this);
}

void HandlerCliente::enviarStatusDeUnion(Status &status_de_union) {
    protocolo.enviarStatusDeUnion(status_de_union);
}

void HandlerCliente::crearPartida(SolicitudCrearPartidaDTO& partida_a_crear) {
    lobby->crearPartida(partida_a_crear, this);
}

void HandlerCliente::enviarStatusDeCreacion(Status &status_de_creacion) {
    protocolo.enviarStatusDeCreacion(status_de_creacion);
}

void HandlerCliente::empezarPartida(ColaNoBloqueante<SolicitudServer>* cola, std::string& nombre_mapa) {
    this->hilo_reciever->empezarPartida(cola);
    this->hilo_sender->start();
    protocolo.enviarComienzoDePartida(nombre_mapa);
}

ColaBloqueante<ComandoServer>* HandlerCliente::obtenerColaSender() {
    return this->cola_comandos;
}

bool HandlerCliente::haFinalizado() const {
    return false; // TODO: implementar
}

void HandlerCliente::cerrar() {
    this->socket.shutdown(2);
    this->socket.close();
}

uint8_t HandlerCliente::obtenerId() const {
    return this->id_cliente;
}

HandlerCliente::~HandlerCliente() {
    delete cola_comandos;
    delete hilo_sender;
    delete hilo_reciever;
}

HandlerCliente::HandlerCliente(HandlerCliente&& otro):
                                socket(std::move(otro.socket)),
                                protocolo(&this->socket, otro.codigos),
                                cola_comandos(otro.cola_comandos),
                                hilo_sender(std::move(otro.hilo_sender)),
                                hilo_reciever(otro.hilo_reciever) {}

HandlerCliente& HandlerCliente::operator=(HandlerCliente&& otro) {
    if (this == &otro) {
        return *this;
    }
    delete this->cola_comandos;
    this->socket = std::move(otro.socket);
    this->protocolo = ProtocoloServidor(&this->socket, otro.codigos);
    this->cola_comandos = otro.cola_comandos;
    this->hilo_sender = otro.hilo_sender;
    this->hilo_reciever = otro.hilo_reciever;
    return *this;
}
