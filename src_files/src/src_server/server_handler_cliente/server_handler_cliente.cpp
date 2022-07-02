#include "server_handler_cliente.h"
#include <iostream>
#include <sstream>

HandlerCliente::HandlerCliente(Socket& socket, Lobby& lobby, YAML::Node& codigos, uint8_t id_cliente) :
                                id_cliente(id_cliente),
                                socket(std::move(socket)),
                                lobby(lobby),
                                protocolo(this->socket, codigos),
                                hilo_sender(this->cola_comandos, this->protocolo),
                                hilo_reciever(new ServerHiloReceiver(this->protocolo, *this)) {
    std::stringstream stream;
    stream << "Jugador " << (int) id_cliente;
    nombre = stream.str();
    protocolo.enviarId(id_cliente);
}

void HandlerCliente::unirsePartida(SolicitudUnirseAPartidaDTO& partida_a_unirse) {
    lobby.unirAPartida(partida_a_unirse, *this);
}

void HandlerCliente::enviarStatusDeUnion(Status &status_de_union) {
    protocolo.enviarStatusDeUnion(status_de_union);
}

void HandlerCliente::crearPartida(SolicitudCrearPartidaDTO& partida_a_crear) {
    lobby.crearPartida(partida_a_crear, *this);
}

void HandlerCliente::enviarStatusDeCreacion(Status &status_de_creacion) {
    protocolo.enviarStatusDeCreacion(status_de_creacion);
}

void HandlerCliente::empezarPartida(ColaNoBloqueante<SolicitudServer>& cola) {
    this->hilo_reciever->empezarPartida(cola);
    this->hilo_sender.start();
}

ColaBloqueante<ComandoServer>& HandlerCliente::obtenerColaSender() {
    return this->cola_comandos;
}

bool HandlerCliente::haFinalizado() {
    if (hilo_reciever->haFinalizado()) {
        hilo_sender.stop();
        se_desconecto = true;
    }
    return se_desconecto;
}

void HandlerCliente::cerrar() {
    this->socket.shutdown(2);
    this->socket.close();
}

uint8_t HandlerCliente::obtenerId() const {
    return this->id_cliente;
}

std::string& HandlerCliente::obtenerNombre() {
    return this->nombre;
}

HandlerCliente::~HandlerCliente() {
    delete hilo_reciever;
}
