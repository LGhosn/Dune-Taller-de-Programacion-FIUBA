#include "server_server.h"
#include <iostream>

#define CENTINELA 'q'
#define RUTA_YAML "../../assets/constantes/codigos.yaml"

Server::Server(const char* servicename) : codigos(NULL), hilo_aceptador(servicename, codigos) {}

void Server::iniciar() {
    char entrada = 0;
    do {
        std::cin >> entrada;
    } while (entrada != CENTINELA);
    hilo_aceptador.terminar();
}
