#include "server_server.h"

Server::Server(const char* servicename) :
el_server_no_debe_cerrarse(true),
skt_aceptador(servicename) {}

void Server::iniciar() {
    std::thread aceptador(&Server::lanzarHiloAceptador, this);
    while (true) {
        std::string input;
        std::cin >> input;
        if (input == "q") {
            this->detener();
            break;
        }
    }
    aceptador.join();
}

void Server::lanzarHiloAceptador() {
    HiloAceptador hilo_aceptador(skt_aceptador, lobby, el_server_no_debe_cerrarse);
    // Guardo los Manejadores para poder esperarlos.
    hilo_aceptador.atenderClientes();
}

void Server::detener() {
    el_server_no_debe_cerrarse = false;
    skt_aceptador.shutdown(SHUT_RDWR);
    skt_aceptador.close();
}
