#include "client_client.h"

Client::Client(const char *hostname, const char *servicename) :
skt_cliente(hostname, servicename), protocolo(skt_cliente) {}

ProtocoloCliente& Client::protocoloAsociado() {
    return this->protocolo;
}
