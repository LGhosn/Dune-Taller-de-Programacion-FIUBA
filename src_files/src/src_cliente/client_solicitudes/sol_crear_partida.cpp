#include "sol_crear_partida.h"
#include "../client_DTO/SolicitudDeCreacion.h"

SolicitudCrearPartida::SolicitudCrearPartida(std::string casa, std::string nombre_partida,
std::string mapa, uint8_t jugadores_requeridos): casa(casa),
                                                 nombre_partida(nombre_partida),
                                                 mapa(mapa),
                                                 jugadores_requeridos(jugadores_requeridos) {}

void SolicitudCrearPartida::enviarSolicitud(ProtocoloCliente& protocolo) {
    SolicitudDeCreacion solicitud(nombre_partida, mapa, casa, jugadores_requeridos);
    protocolo.enviarSolicitudDeCreacion(solicitud);
}
