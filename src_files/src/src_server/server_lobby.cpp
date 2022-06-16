#include "server_lobby.h"

void Lobby::listarPartida(Partida& nueva_partida) {
    this->partidas_creadas.emplace(nueva_partida.getNombre(), std::move(nueva_partida));
}

bool Lobby::crearPartida(const SolicitudCrearPartidaDTO& partida_a_crear, HandlerCliente* cliente) {
    std::lock_guard<std::mutex> lock(m);
    auto busqueda = this->partidas_creadas.find(partida_a_crear.nombre_partida);
    if (busqueda == this->partidas_creadas.end()) {
        Partida partida_nueva(partida_a_crear.nombre_partida,
                                partida_a_crear.jugadores_requeridos,
                                partida_a_crear.mapa);
        partida_nueva.agregarJugador(cliente);
        this->listarPartida(partida_nueva);
        return true;
    } else {
        return false;
    }
}

bool Lobby::unirAPartida(const SolicitudUnirseAPartidaDTO& partida_a_unirse, HandlerCliente* cliente) {
    std::lock_guard<std::mutex> lock(m);
    auto partida = this->partidas_creadas.find(partida_a_unirse.nombre_partida);
    // Si el iterador llegó hasta el final del map,
    // entonces, la partida no fue creada.
    if (partida == this->partidas_creadas.end()) {
        return false;
    } else {
        // En cambio, si el iterador encontró dicha partida,
        // debemos chequear que no esté completa.
        if (partida->second.estaCompleta()) {
            return false;
        } else {
            partida->second.agregarJugador(cliente);
            partida->second.jugadores_actuales++;
            if (partida->second.estaCompleta()) {
                std::string notificacion =
                        "Comenzando partida " + partida_a_unirse.nombre_partida + "...\n";
                std::cout << notificacion;
                partida->second.empezar();
            }
            return true;
        }
    }
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
