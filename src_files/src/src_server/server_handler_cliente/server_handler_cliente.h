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
class ServerHiloSender;
class ServerHiloReceiver;

class HandlerCliente {
    uint8_t id_cliente;
    std::string nombre;
    Socket socket;
    Lobby& lobby;
    ProtocoloServidor protocolo;
    ColaBloqueante<ComandoServer> cola_comandos;
    ServerHiloSender hilo_sender;
    /* 
     * En el heap para evitar problemas por dependencia circular
     * (HandlerCliente->Receiver->HandlerCliente). Idealmente se evitaria
     * la dependencia circular para asi tener todo en el stack.
    */
    ServerHiloReceiver* hilo_reciever;
    bool se_desconecto = false;
    std::thread hilo;

public:
    /*
     * Constructor, lanza el HiloClienteLobby.
     */
    HandlerCliente(Socket& socket, Lobby& lobby, YAML::Node& codigos, uint8_t id_cliente);

    void unirsePartida(SolicitudUnirseAPartidaDTO& partida_a_unirse);
    void enviarStatusDeUnion(Status &status_de_union);

    void crearPartida(SolicitudCrearPartidaDTO& partida_a_unirse);
    void enviarStatusDeCreacion(Status &status_de_creacion);

    void empezarPartida(ColaNoBloqueante<SolicitudServer>& cola);

    ColaBloqueante<ComandoServer>& obtenerColaSender();

    bool haFinalizado();

    void cerrar();

    uint8_t obtenerId() const;

    std::string& obtenerNombre();

    ~HandlerCliente();

    HandlerCliente(const HandlerCliente&) = delete;
    HandlerCliente& operator=(const HandlerCliente&) = delete;
    HandlerCliente(HandlerCliente&&) = delete;
    HandlerCliente& operator=(HandlerCliente&&) = delete;
};


#endif //SERVER_HANDLER_CLIENTE_H
