#ifndef SERVER_HILO_SENDER_H
#define SERVER_HILO_SENDER_H

#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../../src_common/common_comandos/comando_a_enviar.h"
#include "../server_protocolo.h"
#include <thread>

class ServerHiloSender {
private:
    std::thread th;
    ColaBloqueante<ComandoAEnviar>& cola_comandos;
    Protocolo_servidor& protocolo;
    bool hay_que_seguir = true;
public:
    ServerHiloSender(ColaBloqueante<ComandoAEnviar> &cola_comandos, Protocolo_servidor &protocolo);
    void run();
    void handleThread();
    void send(ComandoAEnviar& comando);
    void stop();
    ~ServerHiloSender();
};
#endif //SERVER_HILO_SENDER_H
