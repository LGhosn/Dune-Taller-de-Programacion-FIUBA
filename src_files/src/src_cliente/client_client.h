#ifndef CLIENT_CLIENT_H_
#define CLIENT_CLIENT_H_

#include "../src_common/common_socket.h"
#include "client_protocolo.h"
#include "client_thread_sender/client_hilo_sender.h"
#include "client_thread_reciever/client_hilo_reciever.h"
#include "../src_common/common_colas/cola_no_bloqueante.h"
#include "../src_common/common_colas/cola_bloqueante.h"
#include "client_comandos/client_comando.h"
#include "client_solicitudes/cliente_solicitud.h"

class ClientHiloReciever;
class ClientHiloSender;

class Client {
    Socket skt_cliente;
    ProtocoloCliente protocolo;
    ColaNoBloqueante<ComandoCliente> cola_comandos;
    ClientHiloReciever* receiver;
    ColaBloqueante<SolicitudCliente> cola_solicitudes;
    ClientHiloSender* sender;

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

    void enviarSolicitud(SolicitudCliente* solicitud);

    /*
     * No tiene sentido copiar un cliente y tampoco moverlo (al menos por ahora).
     * */
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    Client(Client&&) = delete;
    Client& operator=(Client&&) = delete;

    ~Client();
};
#endif  // CLIENT_CLIENT_H_
