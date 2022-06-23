#include "client_protocolo.h"
#include <map>

#define SIZEOF_BYTE 1
#define SIZEOF_TWO_BYTES 2

ProtocoloCliente::ProtocoloCliente(Socket& skt_cliente) :
skt_cliente(skt_cliente) {}

uint8_t ProtocoloCliente::obtenerId() const {
    uint8_t id_jugador;
    skt_cliente.recvall(&id_jugador, SIZEOF_BYTE);
    return id_jugador;
}

/* *****************************************************************
 *             METODOS REFERIDOS A UNIRSE A PARTIDAS
 * *****************************************************************/

void ProtocoloCliente::enviarSolicitudUnirseAPartida(SolicitudUnirseAPartidaDTO& solicitud) {
    std::vector<uint8_t> buffer = serializador.serializarSolicitudUnirseAPartida(solicitud);
    enviarBuffer(buffer);
}

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR PARTIDAS
 * *****************************************************************/
void ProtocoloCliente::enviarSolicitudCrearPartida(SolicitudCrearPartidaDTO& solicitud) {
    std::vector<uint8_t> buffer = serializador.serializarSolicitudCrearPartida(solicitud);
    enviarBuffer(buffer);
}

/* *****************************************************************
 *                METODOS REFERIDOS A CREAR EDIFICIOS
 * *****************************************************************/

void ProtocoloCliente::enviarSolicitudCrearEdificio(uint8_t id_jugador, Coordenadas& coords,
                                                    uint8_t tipo) {
    std::vector<uint8_t> buffer = serializador.serializarSolicitudCrearEdificio(id_jugador, coords, tipo);
    this->enviarBuffer(buffer);
}

ComandoCrearEdificioDTO ProtocoloCliente::recibirComandoCrearEdificio() {
    uint8_t id_jugador;
    skt_cliente.recvall(&id_jugador, SIZEOF_BYTE);
    uint8_t id_edificio;
    skt_cliente.recvall(&id_edificio, SIZEOF_BYTE);
    uint8_t tipo;
    skt_cliente.recvall(&tipo, SIZEOF_BYTE);
    uint8_t casa;
    skt_cliente.recvall(&casa, SIZEOF_BYTE);
    uint16_t x;
    skt_cliente.recvall(&x, SIZEOF_TWO_BYTES);
    x = ntohs(x);
    uint16_t y;
    skt_cliente.recvall(&y, SIZEOF_TWO_BYTES);
    y = ntohs(y);
    Coordenadas coords(x, y);
    return ComandoCrearEdificioDTO(id_edificio, id_jugador, coords, tipo, casa);
}

/* *****************************************************************
 *                      METODOS AUXILIARES
 * *****************************************************************/

std::string ProtocoloCliente::recibirNombre() const {
    uint16_t largo_nombre;
    this->skt_cliente.recvall(&largo_nombre, SIZEOF_TWO_BYTES);
    largo_nombre = ntohs(largo_nombre);

    std::vector<uint8_t> buffer_nombre(largo_nombre);
    this->skt_cliente.recvall(buffer_nombre.data(), largo_nombre);
    std::string nombre_partida(buffer_nombre.begin(), buffer_nombre.end());
    return nombre_partida;
}

Coordenadas ProtocoloCliente::recibirCoordenadas()const {
    uint16_t x, y;
    this->skt_cliente.recvall(&x, SIZEOF_TWO_BYTES);
    this->skt_cliente.recvall(&y, SIZEOF_TWO_BYTES);
    x = ntohs(x);
    y = ntohs(y);
    return Coordenadas(x, y);
}

void ProtocoloCliente::enviarBuffer(const std::vector<uint8_t>& buffer) const {
    this->skt_cliente.sendall(buffer.data(), buffer.size());
}

std::map<uint8_t, std::pair<uint8_t, std::string>> ProtocoloCliente::recibirInfoJugadores() {
    uint8_t cantidad_jugadores;
    this->skt_cliente.recvall(&cantidad_jugadores, SIZEOF_BYTE);
    std::map<uint8_t, std::pair<uint8_t, std::string>> info_jugadores;
    for (uint8_t i = 0; i < cantidad_jugadores; i++) {
        uint8_t id_jugador;
        this->skt_cliente.recvall(&id_jugador, SIZEOF_BYTE);
        uint8_t casa;
        this->skt_cliente.recvall(&id_jugador, SIZEOF_BYTE);
        std::string nombre = this->recibirNombre();
        info_jugadores[id_jugador] = std::pair<uint8_t, std::string>(casa, nombre);
    }
    return info_jugadores;
}

Status ProtocoloCliente::recibirStatus() {
    uint8_t status_conexion;
    this->skt_cliente.recvall(&status_conexion, SIZEOF_BYTE);

    uint8_t status_partida;
    this->skt_cliente.recvall(&status_partida, SIZEOF_BYTE);
    return Status(status_conexion, status_partida);
}

InfoPartidaDTO ProtocoloCliente::recibirInfoComienzoDePartida() {
    std::cerr << "Esperando comienzo de partida\n";
    uint8_t codigo_comienzo;
    this->skt_cliente.recvall(&codigo_comienzo, SIZEOF_BYTE);
    if (codigo_comienzo != CODIGO_COMIENZO_PARTIDA) {
        throw std::runtime_error("No se recibió el comienzo de la partida.");
    }
    Coordenadas coords_iniciales = recibirCoordenadas();
    std::string nombre_mapa = recibirNombre();
    std::map<uint8_t, std::pair<uint8_t, std::string>> info_jugadores = recibirInfoJugadores();
    return InfoPartidaDTO(nombre_mapa, info_jugadores, coords_iniciales);                                                     
}


void ProtocoloCliente::enviarSolicitudMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y){
	Serializador s;
    std::string operacion = "mover";
	uint8_t codigo = s.obtenerCodigoOperacion(operacion);

    id_unidad = s.uint16_hton(id_unidad);
    x = s.uint16_hton(x);
    y = s.uint16_hton(y);

	this->skt_cliente.sendall(&codigo, SIZEOF_BYTE);
	this->skt_cliente.sendall(&id_unidad, SIZEOF_TWO_BYTES);
	this->skt_cliente.sendall(&x, SIZEOF_TWO_BYTES);
	this->skt_cliente.sendall(&y, SIZEOF_TWO_BYTES);
}

void ProtocoloCliente::recibirCodigoDeComando(uint8_t& codigo) {
    this->skt_cliente.recvall(&codigo, SIZEOF_BYTE);
}

void ProtocoloCliente::recibirInfoSegunCodigo(uint8_t& codigo) {
    // if (codigo == 4) {
    //     this->recibirInfoMoverUnidad();
    // }
}