#ifndef HILO_SENDER_H
#define HILO_SENDER_H

#include "../cola_bloqueante.h"
#include "../comandos/comando_a_enviar.h"
#include "../client_protocolo.h"

#include <thread>

class HiloSender {
private:
    ColaBloqueante<ComandoAEnviar> &cola_comandos;
    std::thread thread;
    ProtocoloCliente &protocolo;

public:
    HiloSender(ColaBloqueante<ComandoAEnviar> &cola_comandos, ProtocoloCliente &protocolo);
    void run();
    void stop();
    ~HiloSender();
};

#endif // HILO_SENDER_H
