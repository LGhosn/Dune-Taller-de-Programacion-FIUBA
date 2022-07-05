#include "server_hilo_reciever.h"
#include "../server_solicitudes/solicitud_juego/sol_crear_edificio.h"
#include "../server_solicitudes/solicitud_juego/sol_comprar_edificio.h"
#include "../server_solicitudes/solicitud_juego/sol_atacar_unidad.h"
#include "../server_solicitudes/solicitud_juego/sol_atacar_edificio.h"

ServerHiloReceiver::ServerHiloReceiver(ProtocoloServidor& protocolo,
                                    HandlerCliente& cliente_asociado) :
                            protocolo(protocolo),
                            hay_que_seguir(true),
                            partida_comenzada(false),
                            cliente_asociado(cliente_asociado) {
    this->thread = std::thread(&ServerHiloReceiver::handleThread, this);
}

void ServerHiloReceiver::handleThread() {
    try {
        this->run();
    } catch (const SocketError& e) {
        std::cerr << "Cerrando Server Receiver\n"; 
        desconectado = true;
    } catch (const std::exception &e) {
        std::cerr << "Excepción encontrada en ServerHiloReceiver: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción encontrada en ServerHiloReceiver: " << std::endl;
    }
}

void ServerHiloReceiver::run() {
    while (this->hay_que_seguir) {
        uint8_t codigo = protocolo.recibirCodigoDeSolicitud();
        if (partida_comenzada) {
            this->recibirSolicitudSegunCodigo(codigo);
        } else {
            this->recibirSolicitudMenuSegunCodigo(codigo);
        }
    }
}

/* *****************************************************************
 *              METODOS DE SOLICITUDES EN PARTIDA
 * *****************************************************************/

void ServerHiloReceiver::recibirSolicitudSegunCodigo(uint8_t codigo) {
    switch (codigo) {
        // Solicitan crear un edificio
        case 5:
            manejarSolicitudCrearEdificio();
            break;
        case 11:
            manejarSolicitudComprarUnidad();
            break;
        case 25: {
            manejarSoliciutdComprarEdificio();
            break;
        }
        case 50: {
            manejarSolicitudMoverUnidad();
            break;
        }
        case 51: {
            manejarSolicitudAtacarUnidad();
            break;
        }
        case 52: {
            manejarSolicitudAtacarEdificio();
            break;
        }
        default:
            throw std::runtime_error("Código de solicitud no reconocido");
    }
}

void ServerHiloReceiver::manejarSolicitudCrearEdificio() {
    SolicitudCrearEdificioDTO solicitud = protocolo.recibirSolicitudCrearEdificio();
    SolicitudServer *solicitud_server = new SolicitudCrearEdificioServer(solicitud);
    cola_solicitudes->push(solicitud_server);
}

void ServerHiloReceiver::manejarSolicitudAtacarEdificio() {
    SolicitudAtacarEdificioDTO solicitud = protocolo.recibirSolicitudAtacarEdificio();
    SolicitudServer *solicitud_server = new SolicitudAtacarEdificioServer(solicitud);
    cola_solicitudes->push(solicitud_server);
}

void ServerHiloReceiver::manejarSolicitudComprarUnidad() {
    SolicitudComprarUnidadDTO solicitud = protocolo.recibirSolicitudComprarUnidad();
    SolicitudServer *solicitud_server = new SolicitudComprarUnidad(solicitud);
    cola_solicitudes->push(solicitud_server);
}

void ServerHiloReceiver::manejarSolicitudMoverUnidad() {
    SolicitudMoverUnidadDTO solicitud = protocolo.recibirSolicitudMoverUnidad();
    SolicitudServer *solicitud_server = new SolicitudMoverUnidad(solicitud);
    cola_solicitudes->push(solicitud_server);
}

void ServerHiloReceiver::manejarSoliciutdComprarEdificio() {
    SolComprarEdificioDTO solicitud_dto = protocolo.recibirSolicitudComprarEdificio();
    SolComprarEdificioServer* solicitud =
            new SolComprarEdificioServer(solicitud_dto.id_jugador, solicitud_dto.tipo);
    cola_solicitudes->push(solicitud);
}

void ServerHiloReceiver::manejarSolicitudAtacarUnidad() {
    SolicitudAtacarUnidadDTO solicitud = protocolo.recibirSolicitudAtacarUnidad();
    SolicitudServer *solicitud_server = new SolicitudAtacarUnidadServer(solicitud);
    cola_solicitudes->push(solicitud_server);
}

/* *****************************************************************
 *              METODOS DE SOLICITUDES DEL MENÚ
 * *****************************************************************/

void ServerHiloReceiver::recibirSolicitudMenuSegunCodigo(uint8_t codigo) {
    switch (codigo) {
        // Solicitan unirse a una partida.
        case 1:
            recibirSolicitudDeUnion();
            break;

        // Solicitan crear una partida.
        case 3:
            recibirSolicitudDeCreacion();
            break;
    }
}

void ServerHiloReceiver::recibirSolicitudDeCreacion() {
    SolicitudCrearPartidaDTO solicitud = protocolo.recibirSolicitudCrearPartida();
    this->cliente_asociado.crearPartida(solicitud);
}

void ServerHiloReceiver::recibirSolicitudDeUnion() {
    SolicitudUnirseAPartidaDTO solicitud = protocolo.recibirSolicitudUnirseAPartida();
    this->cliente_asociado.unirsePartida(solicitud);
}

/* *****************************************************************
 *                 METODOS DE INICIO-FINALIZACIÓN
 * *****************************************************************/

void ServerHiloReceiver::empezarPartida(ColaNoBloqueante<SolicitudServer>& cola_de_solicitudes) {
    this->cola_solicitudes = &cola_de_solicitudes;
    this->partida_comenzada = true;
}

void ServerHiloReceiver::stop() {
    this->hay_que_seguir = false;
}

bool ServerHiloReceiver::haFinalizado() const {
    return desconectado;
}

ServerHiloReceiver::~ServerHiloReceiver() {
    this->hay_que_seguir = false;
    protocolo.cerrarSocket();
    if (this->thread.joinable()) {
        this->thread.join();
    }
}
