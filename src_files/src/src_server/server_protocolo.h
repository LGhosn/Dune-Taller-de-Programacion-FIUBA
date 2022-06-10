#ifndef SERVER_PROTOCOLO_H_
#define SERVER_PROTOCOLO_H_

#include "server_DTO/PartidaDTO.h"
#include "../src_common/common_infoDTO/infoDTO.h"
#include "../src_common/common_infoDTO/MovimientoDTO.h"
#include "../src_common/common_serializador.h"
#include "../src_common/common_socket.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <netinet/in.h>

class ProtocoloServidor {
    private:
    Socket& skt_comunicador;
    enum class Operaciones : uint8_t {unirse = 1, listar = 2, crear = 3};

    public:
    /*
     * Construye la clase, estableciendo un socket
     * válido como su atributo.
     * */
    explicit ProtocoloServidor(Socket& comunicador);

    /*
     * Recibe el codigo de operacion solicitado
     * por el cliente.
     * */
    void recibirOperacion(uint8_t& codigo_operacion, bool& socket_cerrado);

/* *****************************************************************
 *             METODOS REFERIDOS A UNIRSE A PARTIDAS
 * *****************************************************************/

    /*
     * Recibe la casa a utilizar por el jugador y
     * el nombre de la partida a la cual quiere unirse,
     * luego en función de si la partida fue o no creada,
     * y está o no completa, envía un status al cliente.
     * Si la partida se completa, el servidor lo informa
     * con un mensaje.
     * */
    PartidaDTO recibirSolicitudDeUnion(bool& socket_cerrado);
    void enviarStatusDeUnion(bool el_jugador_se_unio, bool& socket_cerrado);
    void notificarComenzarPartida(bool& socket_cerrado);

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR PARTIDAS
 * *****************************************************************/

    /*
     * Recibe la casa a utilizar por el jugador, los
     * jugadores requeridos para iniciar la partida
     * y el nombre de dicha partida, luego en función
     * de si la partida fue o no creada, envía un status
     * al cliente
     * */
    PartidaDTO recibirSolicitudDeCreacion(bool& socket_cerrado);
    void enviarStatusDeCreacion(bool la_partida_se_creo, bool& socket_cerrado);

    void recibirCodigoDeOperacion(uint8_t& codigo, bool& socket_cerrado);
    std::unique_ptr<InfoDTO> recibirInfoSegunCodigo(uint8_t& codigo, bool& socket_cerrado);

/* *****************************************************************
 *             METODOS REFERIDOS A MOVER UNIDADES
 * *****************************************************************/

    void enviarInstruccionMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y);

    /*
     * No tiene sentido copiar un protocolo_servidor, tampoco moverlo.
     * */
    ProtocoloServidor(const ProtocoloServidor&) = delete;
    ProtocoloServidor& operator=(const ProtocoloServidor&) = delete;
    ProtocoloServidor(ProtocoloServidor&&) = delete;
    ProtocoloServidor& operator=(ProtocoloServidor&&) = delete;
};
#endif  // SERVER_PROTOCOLO_H_
