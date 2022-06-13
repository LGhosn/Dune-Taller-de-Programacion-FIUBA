#include "server_protocolo.h"

/* *****************************************************************
 *                      METODOS AUXILIARES
 * *****************************************************************/

void ProtocoloServidor::enviarBuffer(const std::vector<uint8_t>& buffer) const {
    bool socket_cerrado = false;
    this->skt_comunicador->sendall(buffer.data(), buffer.size());
}

ProtocoloServidor::ProtocoloServidor(Socket* comunicador, YAML::Node* codigos):
skt_comunicador(comunicador), serializador(codigos) {}

void ProtocoloServidor::recibirOperacion
(uint8_t& codigo_operacion) {
        this->skt_comunicador->recvall
        (&codigo_operacion, sizeof(codigo_operacion));
}

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR PARTIDAS
 * *****************************************************************/

PartidaDTO ProtocoloServidor::recibirSolicitudDeCreacion() {
    uint8_t casa;
    this->skt_comunicador->recvall(&casa, sizeof(uint8_t));

    uint8_t requeridos;
    this->skt_comunicador->recvall
    (&requeridos, sizeof(uint8_t));

    uint16_t len_nombre;
    this->skt_comunicador->recvall
    (&len_nombre, sizeof(uint16_t));
    len_nombre = ntohs(len_nombre);

    std::vector<char> buff(len_nombre);
    this->skt_comunicador->recvall(&buff.front(), len_nombre);
    std::string nombre_partida(buff.begin(), buff.end());

    return PartidaDTO(nombre_partida, 1, requeridos, "sdasd"); // TODO: cambiar esto
}

void ProtocoloServidor::enviarStatusDeCreacion
(bool la_partida_se_creo) {
    if (la_partida_se_creo) {
        uint8_t status = 0;
        this->skt_comunicador->sendall
        (&status, sizeof(uint8_t));
    } else {
        uint8_t status = 1;
        this->skt_comunicador->sendall
        (&status, sizeof(uint8_t));
    }
}

/* *****************************************************************
 *             METODOS REFERIDOS A UNIRSE A PARTIDAS
 * *****************************************************************/

PartidaDTO ProtocoloServidor::recibirSolicitudDeUnion() {
    uint8_t casa;
    this->skt_comunicador->recvall(&casa, sizeof(uint8_t));

    uint16_t len_nombre;
    this->skt_comunicador->recvall
    (&len_nombre, sizeof(uint16_t));
    len_nombre = ntohs(len_nombre);

    std::vector<char> buff(len_nombre);
    this->skt_comunicador->recvall(&buff.front(), len_nombre);
    std::string nombre_partida(buff.begin(), buff.end());

    return PartidaDTO(nombre_partida, 0, 0, "asdads"); // TODO: cambiar esto
}

void ProtocoloServidor::enviarStatusDeUnion
(bool el_jugador_se_unio) {
    if (el_jugador_se_unio) {
        uint8_t status = 0;
        this->skt_comunicador->sendall
        (&status, sizeof(uint8_t));
    } else {
        uint8_t status = 1;
        this->skt_comunicador->sendall
        (&status, sizeof(uint8_t));
    }
}

/* *****************************************************************
 *             METODOS REFERIDOS A MOVER UNIDADES
 * *****************************************************************/

void ProtocoloServidor::enviarInstruccionMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y) {}

void ProtocoloServidor::recibirCodigoDeOperacion(uint8_t& codigo, bool& socket_cerrado) {
    this->skt_comunicador->recvall(&codigo, sizeof(uint8_t));
}

std::unique_ptr<InfoDTO> ProtocoloServidor::recibirInfoSegunCodigo(uint8_t& codigo, bool& socket_cerrado) {
    uint16_t id_unidad;
    uint16_t x;
    uint16_t y;

    this->skt_comunicador->recvall(&id_unidad, sizeof(uint8_t));
    this->skt_comunicador->recvall(&x, sizeof(uint8_t);
    this->skt_comunicador->recvall(&y, sizeof(uint8_t);
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

ProtocoloServidor::ProtocoloServidor(ProtocoloServidor&& otro) :
    skt_comunicador(otro.skt_comunicador), serializador(std::move(otro.serializador)) {}

ProtocoloServidor& ProtocoloServidor::operator=(ProtocoloServidor&& otro) {
    this->skt_comunicador = otro.skt_comunicador;
    this->serializador = std::move(otro.serializador);
    return *this;
}
