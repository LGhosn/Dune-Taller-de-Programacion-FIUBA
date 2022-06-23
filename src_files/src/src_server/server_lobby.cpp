#include "server_lobby.h"

void Lobby::listarPartida(Partida& nueva_partida) {
    this->partidas_creadas.emplace(nueva_partida.getNombre(), std::move(nueva_partida));
}

void Lobby::crearPartida(const SolicitudCrearPartidaDTO& partida_a_crear, HandlerCliente* cliente) {
    std::lock_guard<std::mutex> lock(m);
    auto busqueda = this->partidas_creadas.find(partida_a_crear.nombre_partida);
    if (busqueda == this->partidas_creadas.end()) {
        Partida partida_nueva(partida_a_crear.nombre_partida,
                                partida_a_crear.jugadores_requeridos,
                                partida_a_crear.mapa);
        partida_nueva.agregarJugador(cliente, partida_a_crear.casa_codigo);
        this->listarPartida(partida_nueva);
        Status status(CONEXION_EXITOSA, PARTIDA_NO_EXISTENTE);
        cliente->enviarStatusDeCreacion(status);
    } else {
        Status status(CONEXION_FALLIDA, PARTIDA_EXISTENTE);
        cliente->enviarStatusDeCreacion(status);
    }
}

void Lobby::unirAPartida(const SolicitudUnirseAPartidaDTO& partida_a_unirse, HandlerCliente* cliente) {
    std::lock_guard<std::mutex> lock(m);
    auto partida = this->partidas_creadas.find(partida_a_unirse.nombre_partida);
    // Si el iterador llegó hasta el final del map,
    // entonces, la partida no fue creada.
    if (partida == this->partidas_creadas.end()) {
         Status status(CONEXION_FALLIDA, PARTIDA_NO_EXISTENTE);
         cliente->enviarStatusDeUnion(status);
    } else {
        // En cambio, si el iterador encontró dicha partida,
        // debemos chequear que no esté completa.
        if (partida->second.estaCompleta()) {
            Status status(CONEXION_FALLIDA, PARTIDA_EXISTENTE);
            cliente->enviarStatusDeUnion(status);
        } else {
            partida->second.agregarJugador(cliente, partida_a_unirse.casa_codigo);
            partida->second.jugadores_actuales++;
            Status status(CONEXION_EXITOSA, PARTIDA_EXISTENTE);
            cliente->enviarStatusDeUnion(status);
            if (partida->second.estaCompleta()) {
                informarPartidaComenzada(partida->second.nombre_partida);
                partida->second.empezar();
            }
        }
    }
}

void Lobby::informarPartidaComenzada(std::string &nombre_partida) {
    std::string notificacion = "Comenzando partida " + nombre_partida + "...\n";
    std::cout << notificacion;
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
