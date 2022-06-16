#ifndef SERVER_HANDLER_CLIENTE_H
#define SERVER_HANDLER_CLIENTE_H

#include "../server_lobby.h"
#include "../server_solicitudes/solicitud_juego/server_solicitud.h"
#include "../server_comandos/server_comando.h"
#include "../server_thread_sender/server_hilo_sender.h"
#include "../server_thread_reciever/server_hilo_reciever.h"
#include "../../src_common/common_socket.h"
#include "../../src_common/common_socket_error.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../../src_common/common_DTO/dto_sol_crear_partida.h"
#include "../../src_common/common_DTO/dto_sol_unirse_a_partida.h"
#include "yaml-cpp/yaml.h"

#include <thread>

class Partida;
class Lobby;
class ServerHiloReceiver;
class ServerHiloSender;

class HandlerCliente {
    uint8_t id_cliente;
    Socket socket;
    Lobby *lobby;
    ProtocoloServidor protocolo;
    YAML::Node* codigos;
    ColaBloqueante<ComandoServer>* cola_comandos;
    ServerHiloSender* hilo_sender;
    ServerHiloReceiver* hilo_reciever;
    std::thread hilo;

public:
    /*
     * Constructor, lanza el HiloClienteLobby.
     */
    HandlerCliente(Socket& socket, Lobby* lobby, YAML::Node* codigos, uint8_t id_cliente);

    void unirsePartida(SolicitudUnirseAPartidaDTO& partida_a_unirse);
    void crearPartida(SolicitudCrearPartidaDTO& partida_a_unirse);

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


#endif //SERVER_HANDLER_CLIENTE_H
