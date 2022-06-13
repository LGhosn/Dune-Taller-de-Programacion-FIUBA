#ifndef SERVER_HANDLER_CLIENTE_H
#define SERVER_HANDLER_CLIENTE_H

#include "../server_lobby.h"
#include "../server_solicitudes/server_solicitud.h"
#include "../server_comandos/server_comando.h"
#include "../server_thread_reciever/server_hilo_reciever.h"
#include "../server_thread_sender/server_hilo_sender.h"
#include "../../src_common/common_socket.h"
#include "../../src_common/common_socket_error.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"

class Partida;
class Lobby;

class HandlerCliente {
    static uint8_t contador_ids;
    uint8_t id_cliente;
    Socket socket;
    ProtocoloServidor protocolo;
    ColaBloqueante<ComandoServer>* cola_comandos;
    ServerHiloSender hilo_sender;
    ServerHiloReciever hilo_receiver;

public:
    /*
     * Constructor, lanza el HiloClienteLobby.
     */
    HandlerCliente(Socket& socket, Lobby* lobby, YAML::Node* codigos,
                    ColaBloqueante<SolicitudMenuServer>* cola_solicitudes_menu);

    void empezarPartida(ColaNoBloqueante<SolicitudServer>* cola);


    ColaBloqueante<ComandoServer>* obtenerColaSender();

    bool haFinalizado() const;

    void cerrar();

    uint8_t obtenerId() const;

    ~HandlerCliente();

    HandlerCliente(const HandlerCliente&) = delete;
    HandlerCliente& operator=(const HandlerCliente&) = delete;
    HandlerCliente(HandlerCliente&&);
    HandlerCliente& operator=(HandlerCliente&&);
};

uint8_t HandlerCliente::contador_ids = 0;

#endif //SERVER_HANDLER_CLIENTE_H
