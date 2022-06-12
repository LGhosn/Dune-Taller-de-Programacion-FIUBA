#include "server_protocolo.h"

/* *****************************************************************
 *                      METODOS AUXILIARES
 * *****************************************************************/

void ProtocoloServidor::enviarBuffer(const std::vector<uint8_t>& buffer) const {
    bool socket_cerrado = false;
    this->skt_comunicador->sendall(buffer.data(), buffer.size(), &socket_cerrado);
}

ProtocoloServidor::ProtocoloServidor(Socket* comunicador)
: skt_comunicador(comunicador) {}

void ProtocoloServidor::recibirOperacion
(uint8_t& codigo_operacion, bool& socket_cerrado) {
        this->skt_comunicador->recvall
        (&codigo_operacion, sizeof(codigo_operacion), &socket_cerrado);
}

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR PARTIDAS
 * *****************************************************************/

PartidaDTO ProtocoloServidor::recibirSolicitudDeCreacion
(bool& socket_cerrado) {
    uint8_t casa;
    this->skt_comunicador->recvall(&casa, sizeof(uint8_t), &socket_cerrado);

    uint8_t requeridos;
    this->skt_comunicador->recvall
    (&requeridos, sizeof(uint8_t), &socket_cerrado);

    uint16_t len_nombre;
    this->skt_comunicador->recvall
    (&len_nombre, sizeof(uint16_t), &socket_cerrado);
    len_nombre = ntohs(len_nombre);

    std::vector<char> buff(len_nombre);
    this->skt_comunicador->recvall(&buff.front(), len_nombre, &socket_cerrado);
    std::string nombre_partida(buff.begin(), buff.end());

    return PartidaDTO(nombre_partida, 1, requeridos);
}

void ProtocoloServidor::enviarStatusDeCreacion
(bool la_partida_se_creo, bool& socket_cerrado) {
    if (la_partida_se_creo) {
        uint8_t status = 0;
        this->skt_comunicador->sendall
        (&status, sizeof(uint8_t), &socket_cerrado);
    } else {
        uint8_t status = 1;
        this->skt_comunicador->sendall
        (&status, sizeof(uint8_t), &socket_cerrado);
    }
}

/* *****************************************************************
 *             METODOS REFERIDOS A UNIRSE A PARTIDAS
 * *****************************************************************/

PartidaDTO ProtocoloServidor::recibirSolicitudDeUnion(bool& socket_cerrado) {
    uint8_t casa;
    this->skt_comunicador->recvall(&casa, sizeof(uint8_t), &socket_cerrado);

    uint16_t len_nombre;
    this->skt_comunicador->recvall
    (&len_nombre, sizeof(uint16_t), &socket_cerrado);
    len_nombre = ntohs(len_nombre);

    std::vector<char> buff(len_nombre);
    this->skt_comunicador->recvall(&buff.front(), len_nombre, &socket_cerrado);
    std::string nombre_partida(buff.begin(), buff.end());

    return PartidaDTO(nombre_partida, 0, 0);
}

void ProtocoloServidor::enviarStatusDeUnion
(bool el_jugador_se_unio, bool& socket_cerrado) {
    if (el_jugador_se_unio) {
        uint8_t status = 0;
        this->skt_comunicador->sendall
        (&status, sizeof(uint8_t), &socket_cerrado);
    } else {
        uint8_t status = 1;
        this->skt_comunicador->sendall
        (&status, sizeof(uint8_t), &socket_cerrado);
    }
}

/* *****************************************************************
 *             METODOS REFERIDOS A MOVER UNIDADES
 * *****************************************************************/

void ProtocoloServidor::enviarInstruccionMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y) {}

void ProtocoloServidor::recibirCodigoDeOperacion(uint8_t& codigo, bool& socket_cerrado) {
    this->skt_comunicador->recvall(&codigo, sizeof(uint8_t), &socket_cerrado);
}

std::unique_ptr<InfoDTO> ProtocoloServidor::recibirInfoSegunCodigo(uint8_t& codigo, bool& socket_cerrado) {
    uint16_t id_unidad;
    uint16_t x;
    uint16_t y;

    this->skt_comunicador->recvall(&id_unidad, sizeof(uint8_t), &socket_cerrado);
    this->skt_comunicador->recvall(&x, sizeof(uint8_t), &socket_cerrado);
    this->skt_comunicador->recvall(&y, sizeof(uint8_t), &socket_cerrado);
    return std::unique_ptr<InfoDTO>(new MovimientoDTO(id_unidad, x, y));
}

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR EDIFICIOS
 * *****************************************************************/

void ProtocoloServidor::enviarComandoCrearEdificio(uint8_t id_jugador, uint8_t id_edificio, 
                                            uint8_t tipo, const Coordenadas& coords) const {
    std::vector<uint8_t> buffer = serializador.serializarComandoCrearEdificio(id_jugador, id_edificio, tipo, coords);
    this->enviarBuffer(buffer);
}

void ProtocoloServidor::notificarComienzoDePartida() {
    uint8_t start = 1;
    bool fue_cerrado = false;
    this->skt_comunicador->sendall(&start, sizeof(uint8_t), &fue_cerrado);
}

ProtocoloServidor::ProtocoloServidor(ProtocoloServidor&& otro) {
    this->skt_comunicador = otro.skt_comunicador;
}

ProtocoloServidor& ProtocoloServidor::operator=(ProtocoloServidor&& otro) {
    this->skt_comunicador = otro.skt_comunicador;
    return *this;
}
