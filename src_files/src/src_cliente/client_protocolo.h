#ifndef CLIENT_PROTOCOLO_H
#define CLIENT_PROTOCOLO_H

#include "../src_common/common_DTO/Status.h"
#include "../src_common/common_DTO/dto_sol_crear_partida.h"
#include "../src_common/common_DTO/dto_sol_unirse_a_partida.h"
#include "client_DTO/dto_cmd_crear_edificio.h"
#include "client_serializador.h"
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
    Socket& skt_cliente;
    SerializadorCliente serializador;

    void enviarBuffer(const std::vector<uint8_t>& buffer) const;
    std::string recibirNombre() const;

public:
    explicit ProtocoloCliente(Socket& skt_cliente);

    uint8_t obtenerId() const;

    void enviarSolicitudCrearPartida(SolicitudCrearPartidaDTO& solicitud);
    void enviarSolicitudUnirseAPartida(SolicitudUnirseAPartidaDTO& solicitud);
    void enviarSolicitudMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y);

    void recibirCodigoDeComando(uint8_t& codigo);
    void recibirInfoSegunCodigo(uint8_t& codigo);
    // void recibirInfoMoverUnidad();

    ComandoCrearEdificioDTO recibirComandoCrearEdificio();
    void enviarSolicitudCrearEdificio(uint8_t id_jugador, Coordenadas& coords, uint8_t tipo);
    void enviarSolicitudUnirseAPartida(std::string& casa, std::string& nombre_partida);

    /*
     * Recibe el status de una petición de union o creacion, el mismo
     * será usado por el cliente para imprimir un mensaje.
     * */
    Status recibirStatus();
    bool esperarAComienzoDePartida(std::string *nombre_mapa);

    /*
     * No tiene sentido copiar un ProtocoloCliente, tampoco moverlo.
     * */
    ProtocoloCliente(const ProtocoloCliente&) = delete;
    ProtocoloCliente& operator=(const ProtocoloCliente&) = delete;
    ProtocoloCliente(ProtocoloCliente&&) = delete;
    ProtocoloCliente& operator=(ProtocoloCliente&&) = delete;
};
#endif
