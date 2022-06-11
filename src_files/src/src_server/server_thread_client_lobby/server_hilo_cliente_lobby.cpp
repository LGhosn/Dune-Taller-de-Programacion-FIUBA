#include "server_hilo_cliente_lobby.h"

HiloClienteLobby::HiloClienteLobby(ProtocoloServidor& protocolo, Lobby* lobby) :
        flag_ha_finalizado(false),
        protocolo(protocolo),
        lobby(lobby) {}

void HiloClienteLobby::iniciarComunicacion() {
    hilo = std::thread(&HiloClienteLobby::comunicarseConCliente, this);
}

void HiloClienteLobby::comunicarseConCliente() {
    try {
        uint8_t codigo;
        while (!this->fue_cerrado) {
            protocolo.recibirOperacion(codigo, this->fue_cerrado);
            this->evaluarOperacion(codigo);
        }
    } catch (const SocketError &e) {
            flag_ha_finalizado = true;

            syslog(LOG_CRIT, "Un error: %s", e.what());
    } catch (...) {
            syslog(LOG_CRIT, "Error desconocido.\n");
    }
}

void HiloClienteLobby::evaluarOperacion(uint8_t operacion) {
    switch (operacion) {
        case (uint8_t) Operaciones::unirse:
            this->unirsePartida();
            break;
        case (uint8_t) Operaciones::crear:
            this->crearPartida();
            break;
    }
}

void HiloClienteLobby::unirsePartida() {
    PartidaDTO partida_a_unirse = protocolo.recibirSolicitudDeUnion(this->fue_cerrado);
    bool el_jugador_se_unio = lobby->unirAPartida(partida_a_unirse);
    protocolo.enviarStatusDeUnion(el_jugador_se_unio, this->fue_cerrado);
}

void HiloClienteLobby::crearPartida() {
    PartidaDTO partida_a_crear = protocolo.recibirSolicitudDeCreacion(this->fue_cerrado);
    bool la_partida_se_creo = lobby->crearPartida(partida_a_crear);
    protocolo.enviarStatusDeCreacion(la_partida_se_creo, this->fue_cerrado);
}

void HiloClienteLobby::cerrar_hilo() {
    hilo.join();
}

void HiloClienteLobby::comenzarPartida() {
    protocolo.notificarComenzarPartida(this->fue_cerrado);
}

