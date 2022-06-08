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

    public:
    explicit ProtocoloCliente(Socket& skt_cliente);

    void enviarSolicitudDeCreacion(SolicitudDeCreacion& solicitud);
    void enviarSolicitudDeUnion(SolicitudDeUnion& solicitud);
    void enviarSolicitudMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y);

    void recibirCodigoDeOperacion(uint8_t& codigo);
    void recibirInfoSegunCodigo(uint8_t& codigo);
    // void recibirInfoMoverUnidad();


    /*
     * Recibe el status de una petición de union o creacion, el mismo
     * será usado por el cliente para imprimir un mensaje.
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
