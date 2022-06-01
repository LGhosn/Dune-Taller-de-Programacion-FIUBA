#include "server_protocolo.h"

Protocolo_servidor::Protocolo_servidor(Socket& comunicador)
: skt_comunicador(comunicador) {}

void Protocolo_servidor::recibirOperacion
(uint8_t& codigo_operacion, bool& socket_cerrado) {
        this->skt_comunicador.recvall
        (&codigo_operacion, sizeof(codigo_operacion), &socket_cerrado);
}

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR PARTIDAS
 * *****************************************************************/

PartidaDTO Protocolo_servidor::recibirSolicitudDeCreacion
(bool& socket_cerrado) {
    uint8_t casa;
    this->skt_comunicador.recvall(&casa, sizeof(uint8_t), &socket_cerrado);

    uint8_t requeridos;
    this->skt_comunicador.recvall
    (&requeridos, sizeof(uint8_t), &socket_cerrado);

    uint16_t len_nombre;
    this->skt_comunicador.recvall
    (&len_nombre, sizeof(uint16_t), &socket_cerrado);
    len_nombre = ntohs(len_nombre);

    std::vector<char> buff(len_nombre);
    this->skt_comunicador.recvall(&buff.front(), len_nombre, &socket_cerrado);
    std::string nombre_partida(buff.begin(), buff.end());

    return PartidaDTO(nombre_partida, 1, requeridos);
}

void Protocolo_servidor::enviarStatusDeCreacion
(bool la_partida_se_creo, bool& socket_cerrado) {
    if (la_partida_se_creo) {
        uint8_t status = 0;
        this->skt_comunicador.sendall
        (&status, sizeof(uint8_t), &socket_cerrado);
    } else {
        uint8_t status = 1;
        this->skt_comunicador.sendall
        (&status, sizeof(uint8_t), &socket_cerrado);
    }
}

/* *****************************************************************
 *             METODOS REFERIDOS A UNIRSE A PARTIDAS
 * *****************************************************************/

PartidaDTO Protocolo_servidor::recibirSolicitudDeUnion(bool& socket_cerrado) {
    uint8_t casa;
    this->skt_comunicador.recvall(&casa, sizeof(uint8_t), &socket_cerrado);

    uint16_t len_nombre;
    this->skt_comunicador.recvall
    (&len_nombre, sizeof(uint16_t), &socket_cerrado);
    len_nombre = ntohs(len_nombre);

    std::vector<char> buff(len_nombre);
    this->skt_comunicador.recvall(&buff.front(), len_nombre, &socket_cerrado);
    std::string nombre_partida(buff.begin(), buff.end());

    return PartidaDTO(nombre_partida, 0, 0);
}

void Protocolo_servidor::enviarStatusDeUnion
(bool el_jugador_se_unio, bool& socket_cerrado) {
    if (el_jugador_se_unio) {
        uint8_t status = 0;
        this->skt_comunicador.sendall
        (&status, sizeof(uint8_t), &socket_cerrado);
    } else {
        uint8_t status = 1;
        this->skt_comunicador.sendall
        (&status, sizeof(uint8_t), &socket_cerrado);
    }
}
