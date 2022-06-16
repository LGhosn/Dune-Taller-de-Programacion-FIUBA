#include "client_client.h"
#include "client_renderer/client_renderer.h"
#include "client_thread_sdl/client_hilo_sdl.h"

Client::Client(const char *hostname, const char *servicename) :
                skt_cliente(hostname, servicename),
                protocolo(skt_cliente),
                id_jugador(protocolo.obtenerId()),
                receiver(new ClientHiloReciever(cola_comandos, this)),
                sender(new ClientHiloSender(cola_solicitudes, this, id_jugador)) {}

ProtocoloCliente& Client::protocoloAsociado() {
    return this->protocolo;
}

void Client::enviarSolicitud(SolicitudCliente* solicitud) {
    cola_solicitudes.push(solicitud);
}

void Client::empezarPartida() {
    receiver->start();
    ClientRenderer renderer(cola_comandos, cola_solicitudes, id_jugador);
    ManejadorEventos manejador(cola_solicitudes, cola_comandos);
    renderer.start();
}

Client::~Client() {
    delete this->receiver;
    delete this->sender;
}
