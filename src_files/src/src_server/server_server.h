#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

// #include "server_partida_empezada.h"
#include "../src_common/common_socket.h"
#include "server_aceptador.h"
#include "server_protocolo/server_protocolo.h"
#include "yaml-cpp/yaml.h"
#include <list>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

class Server {
    YAML::Node codigos;
    HiloAceptador hilo_aceptador;

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
