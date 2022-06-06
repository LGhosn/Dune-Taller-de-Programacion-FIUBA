#ifndef CLIENT_HILO_RECEIVER_H
#define CLIENT_HILO_RECEIVER_H

#include "../client_protocolo.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../../src_common/common_comandos/comando.h"
#include <thread>

class ClientHiloReciever {
private:
    std::thread thread;
    ProtocoloCliente& protocolo;
    ColaNoBloqueante<Comando>& cola_eventos;
    bool hay_que_seguir = true;

    void run();
    void handleThread();
    void push(Comando& comando_creado);
    void stop();

public:
    ClientHiloReciever(ColaNoBloqueante<Comando>& cola_eventos, ProtocoloCliente& protocolo);
    void ~ClientHiloReciever();

    /*
     * No tiene sentido copiar un ClientHiloReciever, tampoco moverlo.
     * */
    ClientHiloReciever(const ClientHiloReciever&) = delete;
    ClientHiloReciever& operator=(const ClientHiloReciever&) = delete;
    ClientHiloReciever(ClientHiloReciever&&) = delete;
    ClientHiloReciever& operator=(ClientHiloReciever&&) = delete;
};


#endif //CLIENT_HILO_RECEIVER_H
