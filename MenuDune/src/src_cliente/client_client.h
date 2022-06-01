#ifndef CLIENT_CLIENT_H_
#define CLIENT_CLIENT_H_

#include "../src_common/common_socket.h"
#include "../src_menu/MenuDune.h"
#include "client_protocolo.h"
#include <vector>
#include <mutex>
#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

class Client {
    Socket skt_cliente;
    ProtocoloCliente protocolo;

    public:
    /*
     * Constructor de la clase donde se inicializan
     * el socket del cliente y el protocolo que va
     * a utilizar el mismo para comunicarse con el
     * servidor.
     * */
    Client(const char *hostname, const char *servicename);

    /*
     * Devuelve una referencia al protocolo con el cual
     * cuenta el Cliente desde su creación.
     * */
    ProtocoloCliente& protocoloAsociado();

    /*
     * No tiene sentido copiar un cliente y tampoco moverlo (al menos por ahora).
     * */
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    Client(Client&&) = delete;
    Client& operator=(Client&&) = delete;
};
#endif  // CLIENT_CLIENT_H_
