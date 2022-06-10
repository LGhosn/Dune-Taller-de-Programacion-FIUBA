#include "client_client.h"

Client::Client(const char *hostname, const char *servicename) :
skt_cliente(hostname, servicename), protocolo(skt_cliente), receiver(new ClientHiloReciever(cola_comandos, this)),
sender(new ClientHiloSender(cola_solicitudes, this)) {}

ProtocoloCliente& Client::protocoloAsociado() {
    return this->protocolo;
}

void Client::enviarSolicitud(SolicitudCliente* solicitud) {
    cola_solicitudes.push(solicitud);
}

Client::~Client() {
    delete this->receiver;
    delete this->sender;
}
