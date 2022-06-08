#include "server_handler.h"

HandlerCliente::HandlerCliente(Socket& comunicador, Lobby& lobby) :
        flag_sigue_conectado(true),
        flag_ha_finalizado(false),
        skt_comunicador(std::move(comunicador)),
        protocolo(skt_comunicador),
        lobby(lobby) {}

void HandlerCliente::iniciarComunicacion() {
    hilo = std::thread(&HandlerCliente::comunicarseConCliente, this);
}

void HandlerCliente::comunicarseConCliente() {
    try {
        uint8_t codigo;
        while (!this->fue_cerrado) {
            protocolo.recibirOperacion(codigo, this->fue_cerrado);
            this->evaluarOperacion(codigo);
        }
    } catch (const SocketError &e) {
            skt_comunicador.shutdown(SHUT_RDWR);
            skt_comunicador.close();
            flag_ha_finalizado = true;
            flag_sigue_conectado = false;
            syslog(LOG_CRIT, "Un error: %s", e.what());
    } catch (...) {
            syslog(LOG_CRIT, "Error desconocido.\n");
    }
}

void HandlerCliente::evaluarOperacion(uint8_t operacion) {
    switch (operacion) {
        case (uint8_t) Operaciones::unirse:
            this->unirsePartida();
            break;
        case (uint8_t) Operaciones::crear:
            this->crearPartida();
            break;
    }
}

void HandlerCliente::unirsePartida() {
    PartidaDTO partida_a_unirse = protocolo.recibirSolicitudDeUnion(this->fue_cerrado);
    bool el_jugador_se_unio = lobby.unirAPartida(partida_a_unirse, this);
    protocolo.enviarStatusDeUnion(el_jugador_se_unio, this->fue_cerrado);
}

void HandlerCliente::crearPartida() {
    PartidaDTO partida_a_crear = protocolo.recibirSolicitudDeCreacion(this->fue_cerrado);
    bool la_partida_se_creo = lobby.crearPartida(partida_a_crear, this);
    protocolo.enviarStatusDeCreacion(la_partida_se_creo, this->fue_cerrado);
}

bool HandlerCliente::haFinalizado() {
    return flag_ha_finalizado;
}

void HandlerCliente::cerrar_conexion() {
    flag_sigue_conectado = false;
    flag_ha_finalizado = true;
    skt_comunicador.shutdown(SHUT_RDWR);
    skt_comunicador.close();
}

void HandlerCliente::cerrar_hilo() {
    hilo.join();
}

void HandlerCliente::comenzarPartida() {
    protocolo.notificarComenzarPartida(this->fue_cerrado);
}

