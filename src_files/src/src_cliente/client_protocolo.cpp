#include "client_protocolo.h"

ProtocoloCliente::ProtocoloCliente(Socket& skt_cliente) :
skt_cliente(skt_cliente) {}
/* *****************************************************************
 *             METODOS REFERIDOS A UNIRSE A PARTIDAS
 * *****************************************************************/
void ProtocoloCliente::enviarSolicitudDeUnion(SolicitudDeUnion& solicitud) {
    // Establecemos lo que vamos a enviar.
    std::string operacion = "unirse";
    std::string nombre_partida = solicitud.nombre_partida;
    std::string casa = solicitud.casa;

    Serializador s;
    uint8_t codigo = s.obtenerCodigoOperacion(operacion);
    uint8_t codigo_casa = s.obtenerCodigoCasa(casa);

    // Finalmente lo enviamos.
    this->skt_cliente.sendall(&codigo, sizeof(uint8_t));
    this->skt_cliente.sendall(&codigo_casa, sizeof(uint8_t));

    uint16_t len_nombre = nombre_partida.length();
    len_nombre = s.uint16_hton(len_nombre);
    this->skt_cliente.sendall
            (&len_nombre, sizeof(uint16_t));

    this->skt_cliente.sendall
            (nombre_partida.c_str(), nombre_partida.length());
}

void ProtocoloCliente::unirseAPartida(std::string& casa, std::string& nombre_partida) {
    std::string operacion = "unirse";

    Serializador s;
    uint8_t codigo = s.obtenerCodigoOperacion(operacion);
    uint8_t codigo_casa = s.obtenerCodigoCasa(casa);

    this->skt_cliente.sendall(&codigo, sizeof(uint8_t));
    this->skt_cliente.sendall(&codigo_casa, sizeof(uint8_t));

    uint16_t len_nombre = nombre_partida.length();
    this->skt_cliente.sendall(&len_nombre, sizeof(uint16_t));

    this->skt_cliente.sendall(nombre_partida.c_str(), nombre_partida.length());
}

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR PARTIDAS
 * *****************************************************************/
void ProtocoloCliente::enviarSolicitudDeCreacion(SolicitudDeCreacion& solicitud) {
    // Establecemos lo que vamos a enviar
    std::string operacion = "crear";
    std::string nombre_partida = solicitud.nombre_partida;
    std::string casa = solicitud.casa;
    uint8_t requeridos = solicitud.jugadores_requeridos;

    Serializador s;
    uint8_t codigo = s.obtenerCodigoOperacion(operacion);
    uint8_t codigo_casa = s.obtenerCodigoCasa(casa);

    // Finalmente lo enviamos
    this->skt_cliente.sendall(&codigo, sizeof(uint8_t));
    this->skt_cliente.sendall(&codigo_casa, sizeof(uint8_t));
    this->skt_cliente.sendall(&requeridos, sizeof(uint8_t));

    uint16_t len_nombre = nombre_partida.length();
    len_nombre = s.uint16_hton(len_nombre);
    this->skt_cliente.sendall
            (&len_nombre, sizeof(uint16_t));

    this->skt_cliente.sendall
            (nombre_partida.c_str(), nombre_partida.length());
}

/* *****************************************************************
 *                METODOS REFERIDOS A CREAR EDIFICIOS
 * *****************************************************************/

void ProtocoloCliente::enviarSolicitudCrearEdificio(uint8_t id_jugador, Coordenadas& coords, uint8_t tipo) {
    Serializador s;
    std::string operacion = "crear_edificio";
    uint8_t codigo = s.obtenerCodigoOperacion(operacion);
    uint16_t x = s.uint16_hton(coords.x);
    uint16_t y = s.uint16_hton(coords.y);
    this->skt_cliente.sendall(&codigo, sizeof(uint8_t));
    this->skt_cliente.sendall(&id_jugador, sizeof(uint8_t));
    this->skt_cliente.sendall(&x, sizeof(uint16_t));
    this->skt_cliente.sendall(&y, sizeof(uint16_t));
}

/* *****************************************************************
 *                      METODOS AUXILIARES
 * *****************************************************************/

Status ProtocoloCliente::recibirStatus() {
    uint8_t status;
    this->skt_cliente.recvall(&status, sizeof(uint8_t));
    return Status(status);
}

void ProtocoloCliente::esperarAComienzoDePartida() {
    uint8_t codigo;
    this->skt_cliente.recvall(&codigo, sizeof(uint8_t));
    if (codigo != CODIGO_COMIENZO_PARTIDA) {
        throw std::runtime_error("No se recibió el comienzo de la partida.");
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

void ProtocoloCliente::recibirCodigoDeOperacion(uint8_t& codigo) {
    this->skt_cliente.recvall(&codigo, sizeof(uint8_t));
}

void ProtocoloCliente::recibirInfoSegunCodigo(uint8_t& codigo) {
    // if (codigo == 4) {
    //     this->recibirInfoMoverUnidad();
    // }
}