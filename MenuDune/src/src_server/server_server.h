#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include "../src_common/common_socket.h"
#include "server_aceptador.h"
#include "server_handler.h"
#include "server_protocolo.h"
#include <string>
#include <vector>
#include <thread>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

class Server {
    bool was_closed = false;
    std::atomic<bool> el_server_no_debe_cerrarse;
    Socket skt_aceptador;
    Lobby lobby;

    public:
    /*
     * Constructor de la clase, inicializa el socket
     * aceptador.
     * */
    explicit Server(const char* servicename);

    /*
     * Lanza el hilo aceptador del cual derivaran los
     * hilos encargados de manejar cada cliente.
     * */
    void iniciar();
    void lanzarHiloAceptador();
    /*
     * Se encarga de cerrar completamente el socket
     * aceptador y cambiar el booleano utilizado para
     * esperar clientes en el HiloAceptador.
     * */
    void detener();

    /*
     * No tiene sentido copiar un server y tampoco moverlo (al menos por ahora).
     * */
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    Server(Server&&) = delete;
    Server& operator=(Server&&) = delete;
};
#endif  //  SERVER_SERVER_H_
