#ifndef SERVER_HILO_RECIEVER_H
#define SERVER_HILO_RECIEVER_H

#include "../../src_common/common_infoDTO/infoDTO.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"
#include "../server_protocolo/server_protocolo.h"
#include "../server_handler_cliente/server_handler_cliente.h"
#include "../server_DTO/dto_sol_crear_edificio.h"
#include "../server_DTO/dto_sol_comprar_unidad.h"
#include "../server_DTO/dto_sol_atacar_unidad.h"
#include "../server_DTO/dto_sol_atacar_edificio.h"
#include "../server_DTO/dto_sol_mover_unidad.h"
#include "../server_solicitudes/solicitud_juego/server_solicitud.h"
#include "../server_solicitudes/solicitud_juego/sol_crear_edificio.h"
#include "../server_solicitudes/solicitud_juego/sol_comprar_unidad.h"
#include "../server_solicitudes/solicitud_juego/sol_mover_unidad.h"
#include <thread>
#include <atomic>

class HandlerCliente;

class ServerHiloReceiver {
private:
    ColaNoBloqueante<SolicitudServer>* cola_solicitudes;
    ProtocoloServidor& protocolo;
    bool hay_que_seguir;
    std::atomic<bool> partida_comenzada;
    HandlerCliente& cliente_asociado;
    bool desconectado = false;
    std::thread thread;

    void handleThread();
    void run();
    void recibirSolicitudSegunCodigo(uint8_t codigo);
    void recibirSolicitudMenuSegunCodigo(uint8_t codigo);
    void armarComandoSegunInfo(InfoDTO& info);

    void recibirSolicitudDeCreacion();
    void recibirSolicitudDeUnion();

    void manejarSolicitudCrearEdificio();
    void manejarSolicitudComprarUnidad();
    void manejarSolicitudMoverUnidad();
    void manejarSoliciutdComprarEdificio();
    void manejarSolicitudAtacarUnidad();
    void manejarSolicitudAtacarEdificio();

public:
    ServerHiloReceiver(ProtocoloServidor& protocolo,
                        HandlerCliente& cliente_asociado);
    
    void empezarPartida(ColaNoBloqueante<SolicitudServer>& cola_solicitudes);

    void stop();

    bool haFinalizado() const;

    ~ServerHiloReceiver();

    ServerHiloReceiver(const ServerHiloReceiver&) = delete;
    ServerHiloReceiver& operator=(const ServerHiloReceiver&) = delete;
    ServerHiloReceiver(ServerHiloReceiver&&) = delete;
    ServerHiloReceiver& operator=(ServerHiloReceiver&&) = delete;
};


#endif //SERVER_HILO_RECIEVER_H