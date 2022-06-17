#include "sol_crear_edificio.h"

SolicitudCrearEdificio::SolicitudCrearEdificio(Coordenadas& coords, uint8_t tipo) :
                                                coords(coords),
                                                tipo(tipo) {}

void SolicitudCrearEdificio::enviarSolicitud(ProtocoloCliente& protocolo) {
    protocolo.enviarSolicitudCrearEdificio(coords, tipo);
}
