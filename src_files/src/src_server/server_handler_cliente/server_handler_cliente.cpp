#include "server_handler_cliente.h"
#include <iostream>

HandlerCliente::HandlerCliente(Socket& socket, Lobby* lobby, YAML::Node* codigos, uint8_t id_cliente) :
                                id_cliente(id_cliente),
                                socket(std::move(socket)),
                                lobby(lobby),
                                protocolo(&this->socket, codigos),
                                codigos(codigos),
                                cola_comandos(new ColaBloqueante<ComandoServer>()) {
    this->hilo_sender = new ServerHiloSender(this->cola_comandos, &this->protocolo, codigos);        
    this->hilo_reciever = new ServerHiloReceiver(&this->protocolo, codigos, this);
    //this->hilo = std::thread(&HandlerCliente::manejarHilo, this);
}

void HandlerCliente::unirsePartida(SolicitudUnirseAPartidaDTO& partida_a_unirse) {
    bool el_jugador_se_unio = lobby->unirAPartida(partida_a_unirse, this);
    protocolo.enviarStatusDeUnion(el_jugador_se_unio);
}

void HandlerCliente::crearPartida(SolicitudCrearPartidaDTO& partida_a_crear) {
    bool la_partida_se_creo = lobby->crearPartida(partida_a_crear, this);
    protocolo.enviarStatusDeCreacion(la_partida_se_creo);
}

void HandlerCliente::empezarPartida(ColaNoBloqueante<SolicitudServer>* cola) {
    this->hilo_reciever->empezarPartida(cola);
    protocolo.enviarComienzoDePartida();
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
