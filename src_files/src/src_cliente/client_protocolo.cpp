#include "client_protocolo.h"

ProtocoloCliente::ProtocoloCliente(Socket& skt_cliente) :
skt_cliente(skt_cliente) {}

uint8_t ProtocoloCliente::obtenerId() const {
    uint8_t id_jugador;
    skt_cliente.recvall(&id_jugador, sizeof(id_jugador));
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
    skt_cliente.recvall(&id_jugador, sizeof(id_jugador));
    uint8_t id_edificio;
    skt_cliente.recvall(&id_edificio, sizeof(id_edificio));
    uint8_t tipo;
    skt_cliente.recvall(&tipo, sizeof(tipo));
    uint8_t casa;
    skt_cliente.recvall(&casa, sizeof(casa));
    uint16_t x;
    skt_cliente.recvall(&x, sizeof(x));
    x = ntohs(x);
    uint16_t y;
    skt_cliente.recvall(&y, sizeof(y));
    y = ntohs(y);
    Coordenadas coords(x, y);
    return ComandoCrearEdificioDTO(id_edificio, id_jugador, coords, tipo, casa);
}

/* *****************************************************************
 *                      METODOS AUXILIARES
 * *****************************************************************/

void ProtocoloCliente::enviarBuffer(const std::vector<uint8_t>& buffer) const {
    this->skt_cliente.sendall(buffer.data(), buffer.size());
}

Status ProtocoloCliente::recibirStatus() {
    uint8_t status;
    this->skt_cliente.recvall(&status, sizeof(uint8_t));
    return Status(status);
}

bool ProtocoloCliente::esperarAComienzoDePartida() {
    std::cout << "Esperando comienzo de partida" << std::endl;
    uint8_t codigo_comienzo;
    this->skt_cliente.recvall(&codigo_comienzo, sizeof(uint8_t));
    if (codigo_comienzo != CODIGO_COMIENZO_PARTIDA) {
        throw std::runtime_error("No se recibió el comienzo de la partida.");
        return false;
    } else {
        return true;
    }
}


void ProtocoloCliente::enviarSolicitudMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y){
	Serializador s;
    std::string operacion = "mover";
	uint8_t codigo = s.obtenerCodigoOperacion(operacion);

    id_unidad = s.uint16_hton(id_unidad);
    x = s.uint16_hton(x);
    y = s.uint16_hton(y);

	this->skt_cliente.sendall(&codigo, sizeof(uint8_t));
	this->skt_cliente.sendall(&id_unidad, sizeof(uint16_t));
	this->skt_cliente.sendall(&x, sizeof(uint16_t));
	this->skt_cliente.sendall(&y, sizeof(uint16_t));
}

void ProtocoloCliente::recibirCodigoDeComando(uint8_t& codigo) {
    this->skt_cliente.recvall(&codigo, sizeof(uint8_t));
}

void ProtocoloCliente::recibirInfoSegunCodigo(uint8_t& codigo) {
    // if (codigo == 4) {
    //     this->recibirInfoMoverUnidad();
    // }
}