#ifndef SERVER_HILO_PREPARTIDA_H
#define SERVER_HILO_PREPARTIDA_H

#include "../server_solicitudes/server_solicitud_menu.h"
#include "../server_lobby.h"
#include "../server_comandos/server_comando.h"
#include "../../src_common/common_colas/cola_bloqueante.h"
#include <map>
#include <thread>
#include <atomic>

class HiloPrepartida {
    std::atomic<bool> hay_que_seguir = true;
    ColaBloqueante<SolicitudMenuServer>* cola_solicitudes_menu;
    std::map<uint8_t, ColaBloqueante<ComandoServer>*>* colas_sender;
    Lobby* lobby;
    std::thread hilo;

    void manejarHilo();
    void run();

public:
    HiloPrepartida(ColaBloqueante<SolicitudMenuServer>* cola_solicitudes_menu,
                    std::map<uint8_t, ColaBloqueante<ComandoServer>*>* colas_sender);

    void start();

    void stop();
    
    ~HiloPrepartida();
};

#endif //SERVER_HILO_PREPARTIDA_H
