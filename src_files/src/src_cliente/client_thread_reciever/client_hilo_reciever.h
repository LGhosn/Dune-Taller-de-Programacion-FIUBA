#ifndef CLIENT_HILO_RECEIVER_H
#define CLIENT_HILO_RECEIVER_H

#include <thread>

#include "../client_client.h"
#include "../client_protocolo.h"
#include "../../src_common/common_colas/cola_no_bloqueante.h"

// COMANDOS
#include "../client_comandos/client_comando.h"
#include "../client_comandos/cmd_crear_edificio.h"
#include "../client_comandos/cmd_salir.h"
#include "../client_comandos/cmd_modificar_especia.h"
#include "../client_comandos/cmd_actualizar_tienda_edificios.h"
#include "../client_comandos/cmd_empezar_construccion_edificio.h"
#include "../client_comandos/cmd_empezar_entrenamiento.h"
#include "../client_comandos/cmd_modificar_energia.h"
#include "../client_comandos/cmd_mover_unidad.h"

// DTOs
#include "../client_DTO/dto_cmd_crear_edificio.h"
#include "../client_DTO/dto_cmd_empezar_construccion_edificio.h"
#include "../client_DTO/dto_cmd_mover_unidad.h"

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
    ComandoCliente *crearComandoSegunCodigo(uint8_t codigo_comando);

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
