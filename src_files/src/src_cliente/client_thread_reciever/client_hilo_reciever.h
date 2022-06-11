#ifndef CLIENT_HILO_RECEIVER_H
#define CLIENT_HILO_RECEIVER_H

#include "../client_client.h"
#include "../client_protocolo.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../client_comandos/client_comando.h"
#include <thread>

class Client;

class ClientHiloReciever {
private:
    Client* cliente;
    ProtocoloCliente& protocolo;
    ColaNoBloqueante<ComandoCliente>& cola_eventos;
    bool hay_que_seguir = true;
    std::thread thread;

    void run();
    void handleThread();
    void push(ComandoCliente* comando_creado);
    void stop();

public:
    ClientHiloReciever(ColaNoBloqueante<ComandoCliente>& cola_eventos, Client* cliente);
    
    void start();

    ~ClientHiloReciever();

    /*
     * No tiene sentido copiar un ClientHiloReciever, tampoco moverlo.
     * */
    ClientHiloReciever(const ClientHiloReciever&) = delete;
    ClientHiloReciever& operator=(const ClientHiloReciever&) = delete;
    ClientHiloReciever(ClientHiloReciever&&) = delete;
    ClientHiloReciever& operator=(ClientHiloReciever&&) = delete;
};


#endif //CLIENT_HILO_RECEIVER_H
