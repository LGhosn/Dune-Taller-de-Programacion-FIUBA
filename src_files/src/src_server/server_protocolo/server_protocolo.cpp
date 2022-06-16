#include "server_protocolo.h"

/* *****************************************************************
 *                      METODOS AUXILIARES
 * *****************************************************************/

void ProtocoloServidor::enviarBuffer(const std::vector<uint8_t>& buffer) const {
    this->skt_comunicador->sendall(buffer.data(), buffer.size());
}

ProtocoloServidor::ProtocoloServidor(Socket* comunicador, YAML::Node* codigos):
skt_comunicador(comunicador), serializador(codigos) {}

void ProtocoloServidor::recibirOperacion
(uint8_t& codigo_operacion) {
        this->skt_comunicador->recvall
        (&codigo_operacion, sizeof(codigo_operacion));
}

void ProtocoloServidor::enviarComienzoDePartida() {
    uint8_t codigo_comienzo = 0;
    this->skt_comunicador->sendall(&codigo_comienzo, sizeof(codigo_comienzo));
    std::cout << "Se envio la señal de comienzo de partida" << std::endl;
}

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR PARTIDAS
 * *****************************************************************/

SolicitudCrearPartidaDTO ProtocoloServidor::recibirSolicitudCrearPartida() {
    uint8_t casa_codigo;
    this->skt_comunicador->recvall(&casa_codigo, sizeof(uint8_t));

    uint8_t jugadores_requeridos;
    this->skt_comunicador->recvall(&jugadores_requeridos, sizeof(uint8_t));

    uint16_t largo_nombre;
    this->skt_comunicador->recvall(&largo_nombre, sizeof(uint16_t));
    largo_nombre = ntohs(largo_nombre);

    std::vector<uint8_t> buffer_nombre(largo_nombre);
    this->skt_comunicador->recvall(buffer_nombre.data(), largo_nombre);
    std::string nombre_partida(buffer_nombre.begin(), buffer_nombre.end());

    uint16_t largo_mapa;
    this->skt_comunicador->recvall(&largo_mapa, sizeof(uint16_t));
    largo_mapa = ntohs(largo_mapa);

    std::vector<uint8_t> buffer_mapa(largo_mapa);
    this->skt_comunicador->recvall(buffer_mapa.data(), largo_mapa);
    std::string mapa(buffer_mapa.begin(), buffer_mapa.end());

    return SolicitudCrearPartidaDTO(nombre_partida, mapa, casa_codigo, jugadores_requeridos);
}

void ProtocoloServidor::enviarStatusDeCreacion(bool la_partida_se_creo) {
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

SolicitudUnirseAPartidaDTO ProtocoloServidor::recibirSolicitudUnirseAPartida() {
    uint8_t casa;
    this->skt_comunicador->recvall(&casa, sizeof(uint8_t));

    uint16_t largo_nombre;
    this->skt_comunicador->recvall(&largo_nombre, sizeof(uint16_t));
    largo_nombre = ntohs(largo_nombre);

    std::vector<char> buffer_nombre(largo_nombre);
    this->skt_comunicador->recvall(buffer_nombre.data(), largo_nombre);
    std::string nombre_partida(buffer_nombre.begin(), buffer_nombre.end());

    return SolicitudUnirseAPartidaDTO(nombre_partida, casa);
}

void ProtocoloServidor::enviarStatusDeUnion(bool el_jugador_se_unio) {
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

void ProtocoloServidor::recibirCodigoDeOperacion(uint8_t& codigo) {
    this->skt_comunicador->recvall(&codigo, sizeof(uint8_t));
}

std::unique_ptr<InfoDTO> ProtocoloServidor::recibirInfoSegunCodigo(uint8_t& codigo) {
    uint16_t id_unidad;
    uint16_t x;
    uint16_t y;

    this->skt_comunicador->recvall(&id_unidad, sizeof(uint8_t));
    this->skt_comunicador->recvall(&x, sizeof(uint8_t));
    this->skt_comunicador->recvall(&y, sizeof(uint8_t));
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

ProtocoloServidor::ProtocoloServidor(ProtocoloServidor&& otro) :
    skt_comunicador(otro.skt_comunicador), serializador(std::move(otro.serializador)) {}

ProtocoloServidor& ProtocoloServidor::operator=(ProtocoloServidor&& otro) {
    this->skt_comunicador = otro.skt_comunicador;
    this->serializador = std::move(otro.serializador);
    return *this;
}
