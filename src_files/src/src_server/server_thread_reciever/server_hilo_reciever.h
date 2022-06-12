#ifndef SERVER_HILO_RECIEVER_H
#define SERVER_HILO_RECIEVER_H

#include "../../src_common/common_infoDTO/infoDTO.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../server_solicitudes/server_solicitud.h"
#include "../server_protocolo/server_protocolo.h"
#include <thread>

class ServerHiloReciever {
private:
    ColaNoBloqueante<SolicitudServer>* cola_solicitudes;
    ProtocoloServidor* protocolo;
    std::thread thread;
    bool hay_que_seguir = true;

    void handleThread();
    void run();
    SolicitudServer* recibirComandoSegunCodigo(uint8_t codigo);
    void armarComandoSegunInfo(InfoDTO& info);

public:
    ServerHiloReciever(ProtocoloServidor* protocolo);
    
    void start(ColaNoBloqueante<SolicitudServer>* cola_solicitudes);
    void stop();

    ~ServerHiloReciever();

    ServerHiloReciever(const ServerHiloReciever&) = delete;
    ServerHiloReciever& operator=(const ServerHiloReciever&) = delete;
    ServerHiloReciever(ServerHiloReciever&&);
    ServerHiloReciever& operator=(ServerHiloReciever&&);
};


#endif //SERVER_HILO_RECIEVER_H
