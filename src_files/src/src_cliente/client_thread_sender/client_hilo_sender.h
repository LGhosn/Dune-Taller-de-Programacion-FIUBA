#ifndef CLIENT_HILO_SENDER_H
#define CLIENT_HILO_SENDER_H

#include "../client_protocolo.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../client_solicitudes/cliente_solicitud.h"
#include <thread>

class ClientHiloSender {
private:
    ColaBloqueante<SolicitudCliente> &cola_comandos;
    std::thread thread;
    ProtocoloCliente &protocolo;
    bool hay_que_seguir = true;

public:
    ClientHiloSender(ColaBloqueante<SolicitudCliente> &cola_comandos, ProtocoloCliente &protocolo);
    void handleThread();
    void run();
    void send(std::unique_ptr<SolicitudCliente>& solicitud);
    void stop();
    ~ClientHiloSender();
};
#endif // CLIENT_HILO_SENDER_H
