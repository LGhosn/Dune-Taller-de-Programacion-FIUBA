#include "client_client.h"
#include "client_renderer/client_renderer.h"
#include "client_thread_sdl/client_hilo_sdl.h"

Client::Client(const char *hostname, const char *servicename) :
                skt_cliente(hostname, servicename),
                protocolo(skt_cliente),
                id_jugador(protocolo.obtenerId()),
                constantes(YAML::LoadFile(RUTA_CONSTANTES)),
                receiver(cola_comandos, protocolo),
                sender(cola_solicitudes, protocolo, id_jugador) {}

ProtocoloCliente& Client::protocoloAsociado() {
    return this->protocolo;
}

void Client::enviarSolicitud(SolicitudCliente* solicitud) {
    cola_solicitudes.push(solicitud);
}

void Client::establecerPartidaEmpezada() {
    this->partida_empezada = true;
}

bool Client::estaEnPartida() {
    return this->partida_empezada;
}

void Client::setInfoPartida(InfoPartidaDTO& info_partida) {
    this->info_partida = info_partida;
}

void Client::empezarPartida() {
    receiver.start();
    ClientRenderer renderer(cola_comandos, cola_solicitudes, id_jugador, info_partida, constantes);
    ManejadorEventos manejador(cola_solicitudes, cola_comandos, constantes);
    renderer.start();
    std::cerr << "Cliente cerrandose" << std::endl;
    sender.stop();
    receiver.stop();
}
