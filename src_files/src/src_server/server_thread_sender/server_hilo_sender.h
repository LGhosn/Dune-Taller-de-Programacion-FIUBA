#ifndef SERVER_HILO_SENDER_H
#define SERVER_HILO_SENDER_H

#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../server_comandos/server_comando.h"
#include "../server_protocolo.h"
#include <thread>

class ServerHiloSender {
private:
    std::thread thread;
    ColaBloqueante<ComandoServer>& cola_comandos;
    ProtocoloServidor& protocolo;
    bool hay_que_seguir = true;

    void handleThread();
    void run();
    void send(std::unique_ptr<ComandoServer> comando);
    void stop();
public:
    ServerHiloSender(ColaBloqueante<ComandoServer> &cola_comandos, ProtocoloServidor &protocolo);
    void start();
    ~ServerHiloSender();
};
#endif //SERVER_HILO_SENDER_H
