#ifndef SERVER_PROTOCOLO_H_
#define SERVER_PROTOCOLO_H_

#include "../server_DTO/partida_DTO.h"
#include "../../src_common/common_infoDTO/infoDTO.h"
#include "../../src_common/common_infoDTO/MovimientoDTO.h"
#include "../../src_common/common_serializador.h"
#include "../../src_common/common_socket.h"
#include "../../src_common/common_coords.h"
#include "server_serializador.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include "yaml-cpp/yaml.h"

class PartidaDTO;

class ProtocoloServidor {
    private:
    Socket* skt_comunicador;
    SerializadorServer serializador;
    enum class Operaciones : uint8_t {unirse = 1, listar = 2, crear = 3};

    void enviarBuffer(const std::vector<uint8_t>& buffer) const;

    public:
    /*
     * Construye la clase, estableciendo un socket
     * válido como su atributo.
     * */
    explicit ProtocoloServidor(Socket* comunicador, YAML::Node* codigos);

    /*
     * Recibe el codigo de operacion solicitado
     * por el cliente.
     * */
    void recibirOperacion(uint8_t& codigo_operacion);

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
    PartidaDTO recibirSolicitudDeUnion();
    void enviarStatusDeUnion(bool el_jugador_se_unio);
    void notificarComienzoDePartida();

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
    PartidaDTO recibirSolicitudDeCreacion();
    void enviarStatusDeCreacion(bool la_partida_se_creo);

    void recibirCodigoDeOperacion(uint8_t& codigo);
    std::unique_ptr<InfoDTO> recibirInfoSegunCodigo(uint8_t& codigo);

/* *****************************************************************
 *             METODOS REFERIDOS A MOVER UNIDADES
 * *****************************************************************/

    void enviarInstruccionMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y);

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR EDIFICIOS
 * *****************************************************************/

    void enviarComandoCrearEdificio(uint8_t id_jugador, uint8_t id_edificio, uint8_t tipo, const Coordenadas& coords) const;

    /*
     * No tiene sentido copiar un ProtocoloServidor.
     * */
    ProtocoloServidor(const ProtocoloServidor&) = delete;
    ProtocoloServidor& operator=(const ProtocoloServidor&) = delete;
    ProtocoloServidor(ProtocoloServidor&&);
    ProtocoloServidor& operator=(ProtocoloServidor&&);
};
#endif  // SERVER_PROTOCOLO_H_
