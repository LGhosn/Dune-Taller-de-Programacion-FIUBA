#ifndef CLIENT_HILO_SENDER_H
#define CLIENT_HILO_SENDER_H

#include "../client_protocolo.h"
#include "../client_client.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../client_solicitudes/cliente_solicitud.h"
#include <thread>

class Client;

class ClientHiloSender {
private:
    ColaBloqueante<SolicitudCliente> &cola_comandos;
    Client* cliente;
    ProtocoloCliente &protocolo;
    bool hay_que_seguir = true;
    std::thread thread;

public:
    ClientHiloSender(ColaBloqueante<SolicitudCliente> &cola_comandos, Client* cliente);
    void handleThread();
    void run();
    void send(std::unique_ptr<SolicitudCliente>& solicitud);
    void stop();
    ~ClientHiloSender();
};
#endif // CLIENT_HILO_SENDER_H
