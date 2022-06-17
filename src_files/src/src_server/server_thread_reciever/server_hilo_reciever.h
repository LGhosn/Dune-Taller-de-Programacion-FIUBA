#ifndef SERVER_HILO_RECIEVER_H
#define SERVER_HILO_RECIEVER_H

#include "../../src_common/common_infoDTO/infoDTO.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../server_protocolo/server_protocolo.h"
#include "../server_handler_cliente/server_handler_cliente.h"
#include "../server_DTO/dto_sol_crear_edificio.h"
#include "../server_solicitudes/solicitud_juego/server_solicitud.h"
#include "../server_solicitudes/solicitud_juego/sol_crear_edificio.h"
#include "../server_solicitudes/solicitud_menu/server_solicitud_menu.h"
#include "yaml-cpp/yaml.h"
#include <thread>
#include <atomic>

class HandlerCliente;

class ServerHiloReceiver {
private:
    ColaNoBloqueante<SolicitudServer>* cola_solicitudes;
    ProtocoloServidor* protocolo;
    bool hay_que_seguir;
    std::atomic<bool> partida_comenzada;
    YAML::Node* codigos;
    HandlerCliente* cliente_asociado;
    std::thread thread;

    void handleThread();
    void run();
    void recibirSolicitudSegunCodigo(uint8_t codigo);
    void recibirSolicitudMenuSegunCodigo(uint8_t codigo);
    void armarComandoSegunInfo(InfoDTO& info);

    void recibirSolicitudDeCreacion();
    void recibirSolicitudDeUnion();

    void manejarSolicitudCrearEdificio();

public:
    ServerHiloReceiver(ProtocoloServidor* protocolo,
                        YAML::Node* codigos,
                        HandlerCliente* cliente_asociado);
    
    void empezarPartida(ColaNoBloqueante<SolicitudServer>* cola_solicitudes);

    void stop();

    ~ServerHiloReceiver();

    ServerHiloReceiver(const ServerHiloReceiver&) = delete;
    ServerHiloReceiver& operator=(const ServerHiloReceiver&) = delete;
    ServerHiloReceiver(ServerHiloReceiver&&);
    ServerHiloReceiver& operator=(ServerHiloReceiver&&);
};


#endif //SERVER_HILO_RECIEVER_H