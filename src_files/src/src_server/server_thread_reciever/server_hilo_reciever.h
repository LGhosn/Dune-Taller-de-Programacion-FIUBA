#ifndef SERVER_HILO_RECIEVER_H
#define SERVER_HILO_RECIEVER_H

#include "../../src_common/common_infoDTO/infoDTO.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../server_solicitudes/server_solicitud.h"
#include "../server_protocolo/server_protocolo.h"
#include "../server_solicitudes/server_solicitud_menu.h"
#include "../server_handler_cliente/server_handler_cliente.h"
#include "yaml-cpp/yaml.h"
#include <thread>
#include <atomic>

class HandlerCliente;

class ServerHiloReciever {
private:
    ColaBloqueante<SolicitudMenuServer>* cola_solicitudes_menu;
    ColaNoBloqueante<SolicitudServer>* cola_solicitudes;
    ProtocoloServidor* protocolo;
    std::thread thread;
    bool hay_que_seguir = true;
    std::atomic<bool> partida_comenzada = false;
    YAML::Node* codigos;
    HandlerCliente* handler_cliente_padre;

    void handleThread();
    void run();
    SolicitudServer* recibirSolicitudSegunCodigo(uint8_t codigo);
    SolicitudMenuServer* recibirSolicitudMenuSegunCodigo(uint8_t codigo);
    void armarComandoSegunInfo(InfoDTO& info);

public:
    ServerHiloReciever(ProtocoloServidor* protocolo, YAML::Node* codigos,
                        ColaBloqueante<SolicitudMenuServer>* cola_solicitudes_menu,
                        HandlerCliente* handler_cliente_padre);
    
    void empezarPartida(ColaNoBloqueante<SolicitudServer>* cola_solicitudes);

    void stop();

    ~ServerHiloReciever();

    ServerHiloReciever(const ServerHiloReciever&) = delete;
    ServerHiloReciever& operator=(const ServerHiloReciever&) = delete;
    ServerHiloReciever(ServerHiloReciever&&);
    ServerHiloReciever& operator=(ServerHiloReciever&&);
};


#endif //SERVER_HILO_RECIEVER_H
