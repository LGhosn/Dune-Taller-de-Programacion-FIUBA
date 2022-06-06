#ifndef CLIENT_HILO_RECEIVER_H
#define CLIENT_HILO_RECEIVER_H

#include "../cola_no_bloqueante.h"
#include "../client_protocolo.h"
#include "../comandos/comando.h"
#include <thread>

class ClientHiloReciever {
    std::thread th;
    ProtocoloCliente& protocolo;
    ColaNoBloqueante<Comando>& cola_eventos;
    bool hay_que_seguir = true;
public:
    ClientHiloReciever(ColaNoBloqueante<Comando>& cola_eventos, ProtocoloCliente& protocolo);
    void run();
    void handleThread();
    void push(Comando& comando_creado);
    void stop();
    void ~ClientHiloReciever();
};


#endif //CLIENT_HILO_RECEIVER_H
