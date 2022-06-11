#ifndef CLIENT_PROTOCOLO_H
#define CLIENT_PROTOCOLO_H

#include "client_DTO/Status.h"
#include "client_DTO/SolicitudDeCreacion.h"
#include "client_DTO/SolicitudDeUnion.h"
#include "../src_common/common_serializador.h"
#include "../src_common/common_socket.h"
#include "../src_common/common_coords.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <netinet/in.h>

#define CODIGO_COMIENZO_PARTIDA 0

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


    void enviarSolicitudCrearEdificio(uint8_t id_jugador, Coordenadas& coords, uint8_t tipo);
    void unirseAPartida(std::string& casa, std::string& nombre_partida);

    /*
     * Recibe el status de una petición de union o creacion, el mismo
     * será usado por el cliente para imprimir un mensaje.
     * */
    Status recibirStatus();
    void esperarAComienzoDePartida();

    /*
     * No tiene sentido copiar un ProtocoloCliente, tampoco moverlo.
     * */
    ProtocoloCliente(const ProtocoloCliente&) = delete;
    ProtocoloCliente& operator=(const ProtocoloCliente&) = delete;
    ProtocoloCliente(ProtocoloCliente&&) = delete;
    ProtocoloCliente& operator=(ProtocoloCliente&&) = delete;
};
#endif
