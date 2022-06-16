#include "sol_crear_partida.h"
#include "../../src_common/common_DTO/dto_sol_crear_partida.h"

SolicitudCrearPartida::SolicitudCrearPartida(std::string& nombre_partida, std::string& mapa,
                                    std::string& casa, uint8_t jugadores_requeridos):
                                                 nombre_partida(nombre_partida),
                                                 mapa(mapa),
                                                 casa(casa),
                                                 jugadores_requeridos(jugadores_requeridos) {}

void SolicitudCrearPartida::enviarSolicitud(ProtocoloCliente& protocolo) {
    SolicitudCrearPartidaDTO solicitud(nombre_partida, mapa, casa, jugadores_requeridos);
    protocolo.enviarSolicitudCrearPartida(solicitud);
}
