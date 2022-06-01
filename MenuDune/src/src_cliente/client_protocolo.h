#ifndef CLIENT_PROTOCOLO_H
#define CLIENT_PROTOCOLO_H

#include "../src_common/common_serializador.h"
#include "../src_common/common_socket.h"
#include "../src_common/common_DTOs.h"
#include "../src_server/server_partida.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <netinet/in.h>

class ProtocoloCliente {
    private:
    bool was_closed = false;
    Socket& skt_cliente;
    std::map<std::string, uint8_t> operaciones = {{"unirse", 1}, {"listar", 2}, {"crear", 3}};
    std::map<std::string, uint8_t> casas = {{"Harkonnen", 0}, {"Atreides", 1}, {"Ordos", 2}};

    public:
    /*
     * Constructor de la clase.
     * */
    explicit ProtocoloCliente(Socket& skt_cliente);

    void enviarSolicitudDeCreacion(SolicitudDeCreacion& solicitud);
    void enviarSolicitudDeUnion(SolicitudDeUnion& solicitud);

    /*
     * Recibe el status de una peticion de union o creacion, el mismo
     * sera usado por el cliente para imprimir un mensaje.
     * */
    StatusDTO recibirStatus();

    /*
     * No tiene sentido copiar un ProtocoloCliente, tampoco moverlo.
     * */
    ProtocoloCliente(const ProtocoloCliente&) = delete;
    ProtocoloCliente& operator=(const ProtocoloCliente&) = delete;
    ProtocoloCliente(ProtocoloCliente&&) = delete;
    ProtocoloCliente& operator=(ProtocoloCliente&&) = delete;
};
#endif
