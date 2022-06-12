#ifndef SERVER_HANDLER_CLIENTE_H
#define SERVER_HANDLER_CLIENTE_H

#include "../server_lobby.h"
#include "../server_solicitudes/server_solicitud.h"
#include "../server_comandos/server_comando.h"
#include "../server_thread_client_lobby/server_hilo_cliente_lobby.h"
#include "../server_thread_reciever/server_hilo_reciever.h"
#include "../server_thread_sender/server_hilo_sender.h"
#include "../../src_common/common_socket.h"
#include "../../src_common/common_socket_error.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"

class Partida;
class Lobby;
class HiloClienteLobby;

class HandlerCliente {
    Socket socket;
    Lobby* lobby;
    ProtocoloServidor protocolo;
    HiloClienteLobby* hilo_cliente_lobby;
    ColaBloqueante<ComandoServer>* cola_comandos;
    ServerHiloSender hilo_sender;
    ServerHiloReciever hilo_receiver;

    /*
     * Lanza hilos sender y reciever.
     */
    void lanzarHilos(ColaNoBloqueante<SolicitudServer>* cola);
public:
    /*
     * Constructor, lanza el HiloClienteLobby.
     */
    HandlerCliente(Socket& socket, Lobby* lobby);

    void empezarPartida(ColaNoBloqueante<SolicitudServer>* cola);

    void notificarInicioDePartida();

    ColaBloqueante<ComandoServer>* obtenerColaSender();

    bool haFinalizado() const;

    void cerrar();

    ~HandlerCliente();

    HandlerCliente(const HandlerCliente&) = delete;
    HandlerCliente& operator=(const HandlerCliente&) = delete;
    HandlerCliente(HandlerCliente&&);
    HandlerCliente& operator=(HandlerCliente&&);
};


#endif //SERVER_HANDLER_CLIENTE_H
