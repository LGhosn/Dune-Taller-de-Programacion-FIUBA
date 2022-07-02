#include "server_lobby.h"

Partida* Lobby::encontrarPartida(const std::string& nombre) {
    for (auto& partida: partidas_creadas) {
        if (partida.getNombre() == nombre) {
            return &partida;
        }
    }
    return nullptr;
}

void Lobby::crearPartida(const SolicitudCrearPartidaDTO& partida_a_crear, HandlerCliente& cliente) {
    std::lock_guard<std::mutex> lock(m);
    Partida* partida = encontrarPartida(partida_a_crear.nombre_partida);
    if (!partida) {
        this->partidas_creadas.emplace_back(partida_a_crear.nombre_partida,
                                            partida_a_crear.jugadores_requeridos,
                                            partida_a_crear.mapa);
        partidas_creadas.back().agregarJugador(cliente, partida_a_crear.casa_codigo);
        Status status(CONEXION_EXITOSA, PARTIDA_NO_EXISTENTE);
        cliente.enviarStatusDeCreacion(status);
    } else {
        Status status(CONEXION_FALLIDA, PARTIDA_EXISTENTE);
        cliente.enviarStatusDeCreacion(status);
    }
}

void Lobby::unirAPartida(const SolicitudUnirseAPartidaDTO& partida_a_unirse, HandlerCliente& cliente) {
    std::lock_guard<std::mutex> lock(m);
    Partida* partida = encontrarPartida(partida_a_unirse.nombre_partida);
    // Si el iterador llegó hasta el final del map,
    // entonces, la partida no fue creada.
    if (!partida) {
         Status status(CONEXION_FALLIDA, PARTIDA_NO_EXISTENTE);
         cliente.enviarStatusDeUnion(status);
    } else {
        // En cambio, si el iterador encontró dicha partida,
        // debemos chequear que no esté completa.
        if (partida->estaCompleta()) {
            Status status(CONEXION_FALLIDA, PARTIDA_EXISTENTE);
            cliente.enviarStatusDeUnion(status);
        } else {
            partida->agregarJugador(cliente, partida_a_unirse.casa_codigo);
            partida->jugadores_actuales++;
            Status status(CONEXION_EXITOSA, PARTIDA_EXISTENTE);
            cliente.enviarStatusDeUnion(status);
            if (partida->estaCompleta()) {
                informarPartidaComenzada(partida->nombre_partida);
                partida->empezar();
            }
        }
    }
}

void Lobby::informarPartidaComenzada(std::string &nombre_partida) {
    std::string notificacion = "Comenzando partida " + nombre_partida + "...\n";
    std::cout << notificacion;
}

void Lobby::limpiarPartidasFinalizadas() {
    std::list<Partida>::iterator it;
    for (it = partidas_creadas.begin(); it != partidas_creadas.end(); it++) {
        if (it->haFinalizado()) {
            it = partidas_creadas.erase(it);
            std::cerr << "Cerrando partida" << std::endl;
        }
    }
}

void Lobby::terminarPartidas() {
    partidas_creadas.clear();
}

// PartidasDTO Lobby::getListado() {
//     std::lock_guard<std::mutex> lock(m);
//     std::vector<PartidaDTO> partidas;
//     for (auto& partida : this->partidas_creadas) {
//         partidas.emplace_back(partida.second.getNombre(), partida.second.jugadores_requeridos,
//                               partida.second.jugadores_actuales);
//     }
//     return PartidasDTO(partidas);
// }
