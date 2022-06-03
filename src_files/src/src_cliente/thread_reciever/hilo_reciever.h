#ifndef CLIENT_HILO_RECEIVER_H
#define CLIENT_HILO_RECEIVER_H

#include "../cola_no_bloqueante.h"
#include "../client_protocolo.h"
#include "../comandos/comando.h"

class HiloReceiver {
    std::thread hilo;
    ProtocoloCliente& protocolo;
    ColaNoBloqueante<Comando>& cola_eventos;
    bool hayQueSeguirRecibiendo = true;
public:
    HiloReceiver(ColaNoBloqueante<Comando>& cola_eventos, ProtocoloCliente& protocolo);
    void manejarHilo();
    void recibirInfoYPushearComandos();
    void push();
};


#endif //CLIENT_HILO_RECEIVER_H
