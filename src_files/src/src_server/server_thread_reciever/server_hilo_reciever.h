#ifndef SERVER_HILO_RECIEVER_H
#define SERVER_HILO_RECIEVER_H

#include "../../src_common/common_infoDTO/infoDTO.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../../src_common/common_comandos/comando_a_enviar.h"
#include "../server_protocolo.h"
#include <thread>

class ServerHiloReciever {
private:
    ColaNoBloqueante<Comando>& cola_eventos;
    Protocolo_servidor protocolo;
    std::thread thread;
    bool hay_que_seguir = true;

public:
    ServerHiloReciever(ColaNoBloqueante<Comando>& cola_eventos, Protocolo_servidor& protocolo);
    void handleThread();
    void run();
    void stop();
    void armarComandoSegunInfo(InfoDTO& info);
    ~ServerHiloReciever();
};


#endif //SERVER_HILO_RECIEVER_H
