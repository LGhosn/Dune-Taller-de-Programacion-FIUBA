#include "server_server.h"


#define CENTINELA 'q'
#define RUTA_CODIGOS RESOURCE_PATH "constantes/codigos.yaml"

Server::Server(const char* servicename) : codigos(YAML::LoadFile(RUTA_CODIGOS)),
hilo_aceptador(servicename, &codigos) {}

void Server::iniciar() {
    char entrada = 0;
    do {
        std::cin >> entrada;
    } while (entrada != CENTINELA);
}
