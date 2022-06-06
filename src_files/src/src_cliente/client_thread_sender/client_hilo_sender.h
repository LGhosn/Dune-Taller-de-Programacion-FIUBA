#ifndef CLIENT_HILO_SENDER_H
#define CLIENT_HILO_SENDER_H

#include "../client_protocolo.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_comandos/comando_a_enviar.h"
#include <thread>

class ClientHiloSender {
private:
    ColaBloqueante<ComandoAEnviar> &cola_comandos;
    std::thread thread;
    ProtocoloCliente &protocolo;
    bool hay_que_seguir = true;

public:
    ClientHiloSender(ColaBloqueante<ComandoAEnviar> &cola_comandos, ProtocoloCliente &protocolo);
    void handleThread();
    void run();
    void send();
    void stop();
    ~ClientHiloSender();
};
#endif // CLIENT_HILO_SENDER_H
