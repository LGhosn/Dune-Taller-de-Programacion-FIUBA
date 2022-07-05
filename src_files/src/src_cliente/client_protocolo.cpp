#include "client_protocolo.h"

#define SIZEOF_BYTE 1
#define SIZEOF_TWO_BYTES 2

ProtocoloCliente::ProtocoloCliente(Socket& skt_cliente) :
skt_cliente(skt_cliente) {}

void ProtocoloCliente::cerrarSocket() {
    skt_cliente.shutdown(2);
    skt_cliente.close();
}

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
        this->skt_cliente.recvall(&casa, SIZEOF_BYTE);
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


void ProtocoloCliente::enviarSolicitudMoverUnidad(uint8_t id_jugador,
                                                    uint8_t id_unidad,
                                                    Coordenadas& coords_a_moverse) {
    std::vector<uint8_t> buffer = serializador.serializarSolicitudMoverUnidad(id_jugador, id_unidad, coords_a_moverse);
    this->enviarBuffer(buffer);
}

uint16_t ProtocoloCliente::recibirComandoModificarEspecia() {
    uint16_t cantidad_especia;
    this->skt_cliente.recvall(&cantidad_especia, SIZEOF_TWO_BYTES);
    cantidad_especia = ntohs(cantidad_especia);
    return cantidad_especia;
}

/* *****************************************************************
 *          METODOS REFERIDOS A COMPRA DE EDIFICIOS
 * *****************************************************************/

void ProtocoloCliente::enviarSolicitudComprarEdificio(uint8_t id_jugador, uint8_t tipo) {
    uint8_t codigo = 25;
    this->skt_cliente.sendall(&codigo, SIZEOF_BYTE);
    this->skt_cliente.sendall(&id_jugador, SIZEOF_BYTE);
    this->skt_cliente.sendall(&tipo, SIZEOF_BYTE);
}

std::vector<bool> ProtocoloCliente::recibirComandoActualizarTiendaEdificios() {
    std::vector<bool> buffer(8);
    for (uint8_t i = 0; i < buffer.size(); i++) {
        uint8_t estado;
        skt_cliente.recvall(&estado, SIZEOF_BYTE);
        buffer[i] = (bool) estado;
    }
    return buffer;
}

CmdEmpezarConstruccionEdificioDTO ProtocoloCliente::recibirComandoEmpezarConstruccionEdificio() {
    uint8_t tipo;
    this->skt_cliente.recvall(&tipo, SIZEOF_BYTE);
    uint16_t tiempo_construccion;
    this->skt_cliente.recvall(&tiempo_construccion, SIZEOF_TWO_BYTES);
    tiempo_construccion = ntohs(tiempo_construccion);
    return CmdEmpezarConstruccionEdificioDTO(tipo, tiempo_construccion);
}

/* *****************************************************************
 *          METODOS REFERIDOS A UNIDADES
 * *****************************************************************/

void ProtocoloCliente::enviarSolicitudComprarUnidad(uint8_t id_jugador, uint8_t tipo) {
    std::vector<uint8_t> buffer = serializador.serializarSolicitudComprarUnidad(id_jugador, tipo);
    enviarBuffer(buffer);
}

std::vector<bool> ProtocoloCliente::recibirComandoActualizarTiendaUnidades() {
    std::vector<bool> buffer(11);
    for (uint8_t i = 0; i < buffer.size(); i++) {
        uint8_t estado;
        skt_cliente.recvall(&estado, SIZEOF_BYTE);
        buffer[i] = estado;
    }
    return buffer;
}

CmdEmpezarEntrenamientoClienteDTO ProtocoloCliente::recibirComandoEmpezarEntrenamientoUnidad() {
    uint8_t id_unidad;
    this->skt_cliente.recvall(&id_unidad, SIZEOF_BYTE);
    uint8_t tipo_unidad;
    this->skt_cliente.recvall(&tipo_unidad, SIZEOF_BYTE);
    uint16_t coord_x;
    this->skt_cliente.recvall(&coord_x, SIZEOF_TWO_BYTES);
    coord_x = ntohs(coord_x);
    uint16_t coord_y;
    this->skt_cliente.recvall(&coord_y, SIZEOF_TWO_BYTES);
    coord_y = ntohs(coord_y);
    uint16_t tiempo_de_entrenamiento;
    this->skt_cliente.recvall(&tiempo_de_entrenamiento, SIZEOF_TWO_BYTES);
    tiempo_de_entrenamiento = ntohs(tiempo_de_entrenamiento);
    uint16_t vida;
    this->skt_cliente.recvall(&vida, SIZEOF_TWO_BYTES);
    vida = ntohs(vida);
    return CmdEmpezarEntrenamientoClienteDTO(id_unidad, tipo_unidad, tiempo_de_entrenamiento, coord_x, coord_y, vida);
}

CmdMoverUnidadClienteDTO ProtocoloCliente::recibirComandoMoverUnidad() {
    uint8_t direccion;
    this->skt_cliente.recvall(&direccion, SIZEOF_BYTE);
    uint8_t id_unidad;
    this->skt_cliente.recvall(&id_unidad, SIZEOF_BYTE);
    uint16_t tiempo;
    this->skt_cliente.recvall(&tiempo, SIZEOF_TWO_BYTES);
    tiempo = ntohs(tiempo);
    return CmdMoverUnidadClienteDTO(direccion, id_unidad, tiempo);
}

CmdEnemigoDespliegaUnidadDTO ProtocoloCliente::recibirComandoEnemigoDespliegaUnidad() {
    uint8_t id_unidad;
    this->skt_cliente.recvall(&id_unidad, SIZEOF_BYTE);
    uint8_t id_jugador;
    this->skt_cliente.recvall(&id_jugador, SIZEOF_BYTE);
    uint8_t tipo_unidad;
    this->skt_cliente.recvall(&tipo_unidad, SIZEOF_BYTE);
    uint16_t coord_x;
    this->skt_cliente.recvall(&coord_x, SIZEOF_TWO_BYTES);
    coord_x = ntohs(coord_x);
    uint16_t coord_y;
    this->skt_cliente.recvall(&coord_y, SIZEOF_TWO_BYTES);
    coord_y = ntohs(coord_y);
    uint16_t tiempo;
    this->skt_cliente.recvall(&tiempo, SIZEOF_TWO_BYTES);
    tiempo = ntohs(tiempo);
    uint16_t vida;
    this->skt_cliente.recvall(&vida, SIZEOF_TWO_BYTES);
    vida = ntohs(vida);
    return CmdEnemigoDespliegaUnidadDTO(id_unidad, id_jugador, tipo_unidad, tiempo, coord_x, coord_y, vida);
}


/* *****************************************************************
 *                  METODOS REFERIDOS A ENERGIA
 * *****************************************************************/

int16_t ProtocoloCliente::recibirComandoModificarEnergia() {
    int16_t cantidad_energia;
    this->skt_cliente.recvall(&cantidad_energia, SIZEOF_TWO_BYTES);
    return ntohs(cantidad_energia);
}

/* *****************************************************************
 *                 METODOS REFERIDOS A PUNTAJE
 * *****************************************************************/

CmdActualizarPuntajesClienteDTO ProtocoloCliente::recibirComandoActualizarPuntajes() {
    uint8_t id_jugador;
    this->skt_cliente.recvall(&id_jugador, SIZEOF_BYTE);
    uint16_t nuevo_puntaje;
    this->skt_cliente.recvall(&nuevo_puntaje, SIZEOF_TWO_BYTES);
    nuevo_puntaje = ntohs(nuevo_puntaje);
    return CmdActualizarPuntajesClienteDTO(id_jugador, nuevo_puntaje);
}

/* *****************************************************************
 *                 METODOS REFERIDOS A ATAQUES
 * *****************************************************************/

void ProtocoloCliente::enviarSolicitudAtacarUnidad(uint8_t id_jugador_atacante, uint8_t id_unidad_atacante, uint8_t id_unidad_atacada) {
    std::vector<uint8_t> buffer = serializador.serializarSolicitudAtacarUnidad(id_jugador_atacante, id_unidad_atacante, id_unidad_atacada);
    enviarBuffer(buffer);
}

CmdModificarVidaUnidadClienteDTO ProtocoloCliente::recibirComandoModificarVidaUnidad() {
    uint16_t nueva_cant_vida;
    this->skt_cliente.recvall(&nueva_cant_vida, SIZEOF_TWO_BYTES);
    nueva_cant_vida = ntohs(nueva_cant_vida);
    uint8_t id_unidad;
    this->skt_cliente.recvall(&id_unidad, SIZEOF_BYTE);
    return CmdModificarVidaUnidadClienteDTO(nueva_cant_vida, id_unidad);
}

/* *****************************************************************
 *                  METODOS REFERIDOS A ATAQUES
 * *****************************************************************/

uint8_t ProtocoloCliente::recibirComandoTerminarPartida() {
    uint8_t id_ganador;
    this->skt_cliente.recvall(&id_ganador, SIZEOF_BYTE);
    return id_ganador;
}

/* *****************************************************************
 *                          METODOS AUXILIARES
 * *****************************************************************/

void ProtocoloCliente::recibirCodigoDeComando(uint8_t& codigo) {
    this->skt_cliente.recvall(&codigo, SIZEOF_BYTE);
}

void ProtocoloCliente::recibirInfoSegunCodigo(uint8_t& codigo) {
    // if (codigo == 4) {
    //     this->recibirInfoMoverUnidad();
    // }
}