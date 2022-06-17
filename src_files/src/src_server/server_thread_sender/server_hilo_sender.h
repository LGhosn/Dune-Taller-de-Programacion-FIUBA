#ifndef SERVER_HILO_SENDER_H
#define SERVER_HILO_SENDER_H

#include "../../src_common/common_colas/cola_bloqueante.h"
#include "../server_comandos/server_comando.h"
#include "../server_protocolo/server_protocolo.h"
#include <thread>
#include "yaml-cpp/yaml.h"

class ServerHiloSender {
private:
    std::thread thread;
    ColaBloqueante<ComandoServer>* cola_comandos;
    ProtocoloServidor* protocolo;
    bool hay_que_seguir = true;
    YAML::Node* codigos;

    void handleThread();
    void run();
    void send(std::unique_ptr<ComandoServer> comando);
    void stop();
public:
    ServerHiloSender(ColaBloqueante<ComandoServer>* cola_comandos,
                        ProtocoloServidor* protocolo,
                        YAML::Node* codigos);
    void start();
    ~ServerHiloSender();

    ServerHiloSender(const ServerHiloSender&) = delete;
    ServerHiloSender& operator=(const ServerHiloSender&) = delete;
    ServerHiloSender(ServerHiloSender&&);
    ServerHiloSender& operator=(ServerHiloSender&&);
};
#endif //SERVER_HILO_SENDER_H
