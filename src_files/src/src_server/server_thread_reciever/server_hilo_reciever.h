#ifndef SERVER_HILO_RECIEVER_H
#define SERVER_HILO_RECIEVER_H

#include "../../src_common/common_infoDTO/infoDTO.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../server_solicitudes/server_solicitud.h"
#include "../server_protocolo.h"
#include <thread>

class ServerHiloReciever {
private:
    ColaNoBloqueante<SolicitudServer>* cola_solicitudes;
    ProtocoloServidor& protocolo;
    std::thread thread;
    bool hay_que_seguir = true;

public:
    ServerHiloReciever(ProtocoloServidor& protocolo);
    void handleThread();
    void run();
    void start(ColaNoBloqueante<SolicitudServer>* cola_solicitudes);
    void stop();
    void armarComandoSegunInfo(InfoDTO& info);
    ~ServerHiloReciever();
};


#endif //SERVER_HILO_RECIEVER_H
