#include "sol_crear_partida.h"
#include "../server_DTO/partida_DTO.h"

#define JUGADORES_INICIALES 1

SolCrearPartidaServer::SolCrearPartidaServer(const std::string& nombre_partida, uint8_t jugadores_requeridos, const std::string& nombre_mapa) : 
    nombre_partida(nombre_partida), jugadores_requeridos(jugadores_requeridos), nombre_mapa(nombre_mapa){}

void SolCrearPartidaServer::manejarSolicitud(Lobby& lobby) const {
    PartidaDTO partida(nombre_partida, JUGADORES_INICIALES, jugadores_requeridos, nombre_mapa);
    lobby.crearPartida(partida);
}
