#include "sol_unirse_a_partida.h"
#include "../client_DTO/SolicitudDeUnion.h"

SolicitudUnirseAPartida::SolicitudUnirseAPartida(std::string casa, std::string nombre_partida):
                                                casa(casa),
                                                nombre_partida(nombre_partida) {}

void SolicitudUnirseAPartida::enviarSolicitud(ProtocoloCliente& protocolo) {
    SolicitudDeUnion solicitud(nombre_partida, casa);
    protocolo.enviarSolicitudDeUnion(solicitud);
}
