#include "server_protocolo.h"

#define SIZEOF_BYTE 1
#define SIZEOF_TWO_BYTES 2

/* *****************************************************************
 *                      METODOS AUXILIARES
 * *****************************************************************/

void ProtocoloServidor::enviarBuffer(const std::vector<uint8_t>& buffer) const {
    this->skt_comunicador.sendall(buffer.data(), buffer.size());
}

std::string ProtocoloServidor::recibirNombre() const {
    uint16_t largo_nombre;
    this->skt_comunicador.recvall(&largo_nombre, SIZEOF_TWO_BYTES);
    largo_nombre = ntohs(largo_nombre);

    std::vector<uint8_t> buffer_nombre(largo_nombre);
    this->skt_comunicador.recvall(buffer_nombre.data(), largo_nombre);
    std::string nombre_partida(buffer_nombre.begin(), buffer_nombre.end());
    return nombre_partida;
}

ProtocoloServidor::ProtocoloServidor(Socket& comunicador, YAML::Node& codigos):
skt_comunicador(comunicador), serializador(codigos) {}

void ProtocoloServidor::recibirOperacion(uint8_t& codigo_operacion) {
    this->skt_comunicador.recvall(&codigo_operacion, SIZEOF_BYTE);
}

void ProtocoloServidor::enviarId(uint8_t id_cliente) {
    this->skt_comunicador.sendall(&id_cliente, SIZEOF_BYTE);
}

void ProtocoloServidor::enviarComienzoDePartida(const InfoPartidaDTO& info_partida) {
    // std::vector<uint8_t> buffer = serializador.serializarComienzoDePartida(info_partida);
    // enviarBuffer(buffer);
    uint8_t codigo = 0;
    this->skt_comunicador.sendall(&codigo, SIZEOF_BYTE);
    uint16_t x = htons(info_partida.coords_iniciales.x);
    uint16_t y = htons(info_partida.coords_iniciales.y);
    this->skt_comunicador.sendall(&x, SIZEOF_TWO_BYTES);
    this->skt_comunicador.sendall(&y, SIZEOF_TWO_BYTES);
    std::vector<uint8_t> buffer_mapa = serializador.serializarString(info_partida.nombre_mapa);
    enviarBuffer(buffer_mapa);
    uint8_t cant_jugadores = info_partida.info_jugadores.size();
    this->skt_comunicador.sendall(&cant_jugadores, SIZEOF_BYTE);
    for (auto& jugador: info_partida.info_jugadores) {
        uint8_t id = jugador.first;
        this->skt_comunicador.sendall(&id, SIZEOF_BYTE);
        uint8_t casa = std::get<0>(jugador.second);
        this->skt_comunicador.sendall(&casa, SIZEOF_BYTE);
        std::vector<uint8_t> buffer_nombre = serializador.serializarString(std::get<1>(jugador.second));
        enviarBuffer(buffer_nombre);
    }
}



/* *****************************************************************
 *             METODOS REFERIDOS A CREAR PARTIDAS
 * *****************************************************************/

SolicitudCrearPartidaDTO ProtocoloServidor::recibirSolicitudCrearPartida() {
    uint8_t casa_codigo;
    this->skt_comunicador.recvall(&casa_codigo, SIZEOF_BYTE);

    uint8_t jugadores_requeridos;
    this->skt_comunicador.recvall(&jugadores_requeridos, SIZEOF_BYTE);

    std::string nombre_partida = this->recibirNombre();

    std::string nombre_mapa = this->recibirNombre();
    return SolicitudCrearPartidaDTO(nombre_partida, nombre_mapa, casa_codigo, jugadores_requeridos);
}

void ProtocoloServidor::enviarStatusDeCreacion(Status &status_de_creacion) {
    uint8_t status_conexion = status_de_creacion.obtenerCodigoDeConexion();
    uint8_t status_partida = status_de_creacion.obtenerCodigoDePartida();
    this->skt_comunicador.sendall(&status_conexion, SIZEOF_BYTE);
    this->skt_comunicador.sendall(&status_partida, SIZEOF_BYTE);
}

/* *****************************************************************
 *             METODOS REFERIDOS A UNIRSE A PARTIDAS
 * *****************************************************************/

SolicitudUnirseAPartidaDTO ProtocoloServidor::recibirSolicitudUnirseAPartida() {
    uint8_t casa;
    this->skt_comunicador.recvall(&casa, SIZEOF_BYTE);

    std::string nombre_partida = recibirNombre();

    return SolicitudUnirseAPartidaDTO(nombre_partida, casa);
}

void ProtocoloServidor::enviarStatusDeUnion(Status &status_de_union) {
    uint8_t status_conexion = status_de_union.obtenerCodigoDeConexion();
    uint8_t status_partida = status_de_union.obtenerCodigoDePartida();
    this->skt_comunicador.sendall(&status_conexion, SIZEOF_BYTE);
    this->skt_comunicador.sendall(&status_partida, SIZEOF_BYTE);
}

/* *****************************************************************
 *             METODOS REFERIDOS A MOVER UNIDADES
 * *****************************************************************/

SolicitudMoverUnidadDTO ProtocoloServidor::recibirSolicitudMoverUnidad() {
    uint8_t id_jugador;
    this->skt_comunicador.recvall(&id_jugador, SIZEOF_BYTE);
    
    uint8_t id_unidad;
    this->skt_comunicador.recvall(&id_unidad, SIZEOF_BYTE);

    uint16_t x;
    this->skt_comunicador.recvall(&x, SIZEOF_TWO_BYTES);
    x = ntohs(x);

    uint16_t y;
    this->skt_comunicador.recvall(&y, SIZEOF_TWO_BYTES);
    y = ntohs(y);

    const Coordenadas coords(x,y);
    return SolicitudMoverUnidadDTO(id_jugador, id_unidad, coords);
}


void ProtocoloServidor::enviarComandoMoverUnidad(uint8_t id_unidad, uint8_t direccion, uint16_t tiempo) {
    std::vector<uint8_t> buffer = serializador.serializarComandoMoverUnidad(id_unidad, direccion, tiempo);
    enviarBuffer(buffer);
}

uint8_t ProtocoloServidor::recibirCodigoDeSolicitud() {
    uint8_t codigo;
    this->skt_comunicador.recvall(&codigo, SIZEOF_BYTE);
    return codigo;
}

/* *****************************************************************
 *             METODOS REFERIDOS A CREAR EDIFICIOS
 * *****************************************************************/

void ProtocoloServidor::enviarComandoEmpezarConstruccionEdificio(uint8_t tipo_edificio,
                                                uint16_t tiempo_construccion) {
    std::vector<uint8_t> buffer = serializador.serializarComandoEmpezarConstruccionEdificio(
                                        tipo_edificio, tiempo_construccion);
    enviarBuffer(buffer);
}

SolComprarEdificioDTO ProtocoloServidor::recibirSolicitudComprarEdificio() {
    uint8_t id_jugador;
    this->skt_comunicador.recvall(&id_jugador, SIZEOF_BYTE);
    uint8_t tipo;
    this->skt_comunicador.recvall(&tipo, SIZEOF_BYTE);
    return SolComprarEdificioDTO(id_jugador, tipo);
}

void ProtocoloServidor::enviarComandoCrearEdificio(uint8_t id_jugador, uint8_t id_edificio, 
                                            uint8_t tipo, const Coordenadas& coords,
                                            uint8_t casa) const {
    std::vector<uint8_t> buffer = serializador.serializarComandoCrearEdificio(id_jugador, id_edificio, tipo, coords, casa);
    this->enviarBuffer(buffer);
}

SolicitudCrearEdificioDTO ProtocoloServidor::recibirSolicitudCrearEdificio() {
    uint8_t id_jugador;
    this->skt_comunicador.recvall(&id_jugador, SIZEOF_BYTE);
    uint8_t tipo;
    this->skt_comunicador.recvall(&tipo, SIZEOF_BYTE);
    uint16_t x;
    this->skt_comunicador.recvall(&x, SIZEOF_TWO_BYTES);
    uint16_t y;
    this->skt_comunicador.recvall(&y, SIZEOF_TWO_BYTES);
    x = ntohs(x);
    y = ntohs(y);
    Coordenadas coords(x, y);
    return SolicitudCrearEdificioDTO(id_jugador, tipo, coords);
}

SolicitudComprarUnidadDTO ProtocoloServidor::recibirSolicitudComprarUnidad() {
    uint8_t id_jugador;
    this->skt_comunicador.recvall(&id_jugador, SIZEOF_BYTE);
    uint8_t tipo;
    this->skt_comunicador.recvall(&tipo, SIZEOF_BYTE);
    return SolicitudComprarUnidadDTO(id_jugador,tipo);
}

// void ProtocoloServidor::enviarComandoComprarUnidad(uint16_t id_jugador, uint8_t tipo_unidad) {}

void ProtocoloServidor::enviarComandoConstruccionInvalida() {
    uint8_t codigo = 6;
    this->skt_comunicador.sendall(&codigo, SIZEOF_BYTE);
}

void ProtocoloServidor::enviarComandoEnemigoDespliegaUnidad(uint8_t id_unidad, uint8_t id_jugador, uint8_t tipo_unidad, uint16_t tiempo, Coordenadas& coords) {
    std::vector<uint8_t> buffer = serializador.serializarComandoEnemigoDespliegaUnidad(id_unidad, id_jugador, tipo_unidad, tiempo, coords);
    this->enviarBuffer(buffer);
}

/* *****************************************************************
 *             METODOS REFERIDOS A ACTUALIZAR ESPECIA Y ENERGIA
 * *****************************************************************/

void ProtocoloServidor::enviarComandoModificarEspecia(uint16_t cantidad_especia) {
    std::vector<uint8_t> buffer = serializador.serializarComandoModificarEspecia(cantidad_especia);
    enviarBuffer(buffer);
}

void ProtocoloServidor::enviarComandoModificarEnergia(int16_t cantidad_energia) {
    uint8_t codigo = 30;
    this->skt_comunicador.sendall(&codigo, SIZEOF_BYTE);
    cantidad_energia = htons(cantidad_energia);
    this->skt_comunicador.sendall(&cantidad_energia, SIZEOF_TWO_BYTES);
}

/* *****************************************************************
 * METODOS REFERIDOS A ACTUALIZAR ESTADO COMPRA EDIFICIOS Y UNIDADES
 * *****************************************************************/

void ProtocoloServidor::enviarComandoActualizarTiendaEdificios(const std::vector<bool>& edificios_comprables) {
    enviarBuffer(serializador.serializarComandoActualizarTiendaEdificios(edificios_comprables));
}

void ProtocoloServidor::enviarComandoActualizarTiendaUnidades(const std::vector<bool>& unidades_comprables) {
    enviarBuffer(serializador.serializarComandoActualizarTiendaUnidades(unidades_comprables));
}

void ProtocoloServidor::enviarComandoEmpezarEntrenamientoUnidad(uint8_t id_unidad, uint8_t tipo_unidad, uint16_t tiempo_construccion, Coordenadas& coords_spawn) {
    std::vector<uint8_t> buffer = serializador.serializarEmpezarEntrenamientoUnidad(id_unidad, tipo_unidad, tiempo_construccion, coords_spawn);
    enviarBuffer(buffer);
}

/* *****************************************************************
 *                  METODOS REFERIDOS A PUNTAJE
 * *****************************************************************/

void ProtocoloServidor::enviarComandoActualizarPuntaje(uint8_t id_jugador, uint16_t nuevo_puntaje) {
    std::vector<uint8_t> buffer = serializador.serializarComandoActualizarPuntaje(id_jugador, nuevo_puntaje);
    enviarBuffer(buffer);
}

void ProtocoloServidor::cerrarSocket() {
    this->skt_comunicador.shutdown(2);
    this->skt_comunicador.close();
}

/* *****************************************************************
 *                  METODOS REFERIDOS A ATAQUES
 * *****************************************************************/
SolicitudAtacarUnidadDTO ProtocoloServidor::recibirSolicitudAtacarUnidad() {
    uint8_t id_jugador_atacante;
    this->skt_comunicador.recvall(&id_jugador_atacante, SIZEOF_BYTE);
    uint8_t id_unidad_atacante;
    this->skt_comunicador.recvall(&id_unidad_atacante, SIZEOF_BYTE);
    uint8_t id_unidad_atacada;
    this->skt_comunicador.recvall(&id_unidad_atacada, SIZEOF_BYTE);
    uint16_t x;
    this->skt_comunicador.recvall(&x, SIZEOF_TWO_BYTES);
    uint16_t y;
    this->skt_comunicador.recvall(&y, SIZEOF_TWO_BYTES);
    x = ntohs(x);
    y = ntohs(y);
    return SolicitudAtacarUnidadDTO(id_jugador_atacante, id_unidad_atacante, id_unidad_atacada, x, y);
}

