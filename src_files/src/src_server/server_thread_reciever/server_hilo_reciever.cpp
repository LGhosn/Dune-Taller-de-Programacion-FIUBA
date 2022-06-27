#include "server_hilo_reciever.h"

ServerHiloReceiver::ServerHiloReceiver(ProtocoloServidor* protocolo, YAML::Node* codigos, HandlerCliente *cliente_asociado) :
        protocolo(protocolo),
        hay_que_seguir(true),
        partida_comenzada(false),
        codigos(codigos),
        cliente_asociado(cliente_asociado) {
    this->thread = std::thread(&ServerHiloReceiver::handleThread, this);
}

void ServerHiloReceiver::handleThread() {
    try {
        this->run();
    } catch (const SocketError& e) {
        std::cerr << "Cerando Server Receiver\n"; 
    } catch (const std::exception &e) {
        std::cerr << "Excepción encontrada en ServerHiloReceiver: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Excepción encontrada en ServerHiloReceiver: " << std::endl;
    }
}

void ServerHiloReceiver::run() {
    while (this->hay_que_seguir) {
        uint8_t codigo = protocolo->recibirCodigoDeSolicitud();
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
        case 100000: // TODO: determinar codigo
            manejarSolicitudComprarUnidad();
        case 100001: // TODO: determinar codigo
            manejarSolicitudMoverUnidad();
        default:
            throw std::runtime_error("Código de solicitud no reconocido");
    }
}

void ServerHiloReceiver::manejarSolicitudCrearEdificio() {
    SolicitudCrearEdificioDTO solicitud = protocolo->recibirSolicitudCrearEdificio();
    SolicitudServer *solicitud_server = new SolicitudCrearEdificioServer(solicitud);
    cola_solicitudes->push(solicitud_server);
}

void ServerHiloReceiver::manejarSolicitudComprarUnidad() {
    SolicitudComprarUnidadDTO solicitud = protocolo->recibirSolicitudComprarUnidad();
    SolicitudServer *solicitud_server = new SolicitudComprarUnidad(solicitud);
    cola_solicitudes->push(solicitud_server);
}

void ServerHiloReceiver::manejarSolicitudMoverUnidad() {
    SolicitudMoverUnidadDTO solicitud = protocolo->recibirSolicitudMoverUnidad();
    SolicitudServer *solicitud_server = new SolicitudMoverUnidad(solicitud);
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
    SolicitudCrearPartidaDTO solicitud = protocolo->recibirSolicitudCrearPartida();
    this->cliente_asociado->crearPartida(solicitud);
}

void ServerHiloReceiver::recibirSolicitudDeUnion() {
    SolicitudUnirseAPartidaDTO solicitud = protocolo->recibirSolicitudUnirseAPartida();
    this->cliente_asociado->unirsePartida(solicitud);
}

/* *****************************************************************
 *                 METODOS DE INICIO-FINALIZACIÓN
 * *****************************************************************/

void ServerHiloReceiver::empezarPartida(ColaNoBloqueante<SolicitudServer>* cola_de_solicitudes) {
    this->cola_solicitudes = cola_de_solicitudes;
    this->partida_comenzada = true;
}

void ServerHiloReceiver::stop() {
    this->hay_que_seguir = false;
}

ServerHiloReceiver::~ServerHiloReceiver() {
    this->hay_que_seguir = false;
    if (this->thread.joinable()) {
        this->thread.join();
    }
}

/* *****************************************************************
 *                          MOVE SEMANTICS
 * *****************************************************************/

ServerHiloReceiver::ServerHiloReceiver(ServerHiloReceiver&& otro):
                                        cola_solicitudes(otro.cola_solicitudes),
                                        protocolo(otro.protocolo),
                                        thread(std::move(otro.thread)) {}

ServerHiloReceiver& ServerHiloReceiver::operator=(ServerHiloReceiver&& otro) {
    if (this == &otro) {
        return *this;
    }
    this->cola_solicitudes = otro.cola_solicitudes;
    this->protocolo = otro.protocolo;
    this->thread = std::move(otro.thread);
    return *this;
}
