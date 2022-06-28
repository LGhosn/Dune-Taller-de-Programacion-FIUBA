#include "client_sol_crear_edificio.h"

SolicitudCrearEdificio::SolicitudCrearEdificio(Coordenadas& coords, uint8_t tipo) :
                                                coords(coords),
                                                tipo(tipo) {}

void SolicitudCrearEdificio::enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador) {
    protocolo.enviarSolicitudCrearEdificio(id_jugador, coords, tipo);
}
