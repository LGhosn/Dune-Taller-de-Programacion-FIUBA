#ifndef _SERVER_ACEPTADOR_H
#define _SERVER_ACEPTADOR_H

#include "../src_common/common_socket.h"
#include "../src_server/server_lobby.h"
#include "server_thread_client_lobby/server_hilo_cliente_lobby.h"
#include <vector>
#include <algorithm>
#include <syslog.h>

class HiloAceptador {
    Socket& skt_aceptador;
    Lobby& lobby;
    std::atomic <bool>& hay_que_seguir;
    std::vector<HiloClienteLobby*> clientes;

    /*
     * Crea un nuevo cliente y lo guarda en el container
     * para que luego el mismo inicie la comunicacion con el
     * cliente.
     */
    void lanzarHandlerCliente(Socket& aceptado);

    /*
     * Devuelve un booleano que indica si el servidor
     * tiene o no que cerrarse.
     */
    bool hayQueSeguir();

    /*
     * En caso de que un HiloCliente haya finalizado su ejecucion
     * este metodo cierra el hilo y devuelve true, sino devuelve false.
     */
    static bool esperarSiHaFinalizado(HiloClienteLobby* cliente);

    /*
     * En caso de que se deba cerrar el servidor, se cierra
     * la conexion de cada socket que tenga cada HiloCliente
     * para luego cerra el hilo y liberar la memoria.
     */
    void esperarHandlersCliente();

    /*
     * Borra del container de clientes aquellos cuyo HiloCliente
     * finalizo su ejecucion.
     */
    void limpiarHandlersClientesFinalizados();

public:
    /*
     * Constructor de la clase, toma por parámetros un socket_aceptador,
     * lobby y un booleano por parte del servidor (todos por referencia)
     * para luego utilizar y pasar por movimiento a los clientes cada
     * socket aceptado (el lobby lo pasa por referencia).
     */
    HiloAceptador(Socket& skt_aceptador, Lobby& lobby, std::atomic <bool>& hay_que_seguir);

    /*
     * Metodo principal de este objeto, es el encargado de lanzar los
     * distintos hilos por cada cliente que se quiera conectar al server
     * mientras en el mismo no se ingrese una 'q' por entrada estandar,
     * tambien limpia el container que guarda los punteros a esos
     * HilosCliente para su liberacion de memoria.
     */
    void atenderClientes();

    /*
     * No tiene sentido copiar un HiloAceptador, tampoco moverlo.
     * */
    HiloAceptador(const HiloAceptador&) = delete;
    HiloAceptador& operator=(const HiloAceptador&) = delete;
    HiloAceptador(HiloAceptador&&) = delete;
    HiloAceptador& operator=(HiloAceptador&&) = delete;
};
#endif //_SERVER_ACEPTADOR_H
