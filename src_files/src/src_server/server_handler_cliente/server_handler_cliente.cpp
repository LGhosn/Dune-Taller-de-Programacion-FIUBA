#include "server_handler_cliente.h"

HandlerCliente::HandlerCliente(Socket& socket, Lobby& lobby) :
                                socket(std::move(socket)),
                                lobby(lobby),
                                protocolo(this->socket),
                                hilo_cliente_lobby(this->protocolo, this->lobby),
                                hilo_sender(this->cola_comandos, this->protocolo),
                                hilo_reciever(this->protocolo) {}

void HandlerCliente::lanzarHilos(ColaNoBloqueante<SolicitudServer>* cola) {
    hilo_reciever.start(cola);
    hilo_sender.start();
}

void HandlerCliente::empezarPartida(ColaNoBloqueante<SolicitudServer>* cola) {
    this->lanzarHilos(cola);
    this->notificarInicioDePartida();
    hilo_cliente_lobby.cerrar_hilo();
}

void HandlerCliente::notificarInicioDePartida() {
    protocolo.notificarComienzoDePartida();
}

ColaBloqueante<ComandoServer>* HandlerCliente::obtenerColaSender() {
    return &this->cola_comandos;
}