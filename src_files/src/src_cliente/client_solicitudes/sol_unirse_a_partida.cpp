#include "sol_unirse_a_partida.h"
#include "../../src_common/common_DTO/dto_sol_unirse_a_partida.h"

SolicitudUnirseAPartida::SolicitudUnirseAPartida(std::string casa, std::string nombre_partida):
                                                casa(casa),
                                                nombre_partida(nombre_partida) {}

void SolicitudUnirseAPartida::enviarSolicitud(ProtocoloCliente& protocolo) {
    SolicitudUnirseAPartidaDTO solicitud(nombre_partida, casa);
    protocolo.enviarSolicitudUnirseAPartida(solicitud);
}
