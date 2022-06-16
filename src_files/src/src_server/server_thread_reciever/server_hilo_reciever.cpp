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
    }
}

void ServerHiloReceiver::manejarSolicitudCrearEdificio() {
    SolicitudCrearEdificioDTO solicitud = protocolo->recibirSolicitudCrearEdificio();
    SolicitudServer *solicitud_server = new SoliCrearEdificioServer(solicitud);
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
    // PartidaDTO solicitud = this->protocolo->recibirSolicitudDeCreacion();
    // this->cliente_asociado->crearPartida(solicitud);
}

void ServerHiloReceiver::recibirSolicitudDeUnion() {
    // PartidaDTO solicitud = protocolo->recibirSolicitudDeUnion();
    // this->cliente_asociado->unirsePartida(solicitud);
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
