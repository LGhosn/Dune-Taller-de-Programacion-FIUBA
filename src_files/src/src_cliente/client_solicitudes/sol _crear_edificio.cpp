#include "sol_crear_edificio.h"

SolicitudCrearEdificio::SolicitudCrearEdificio(uint8_t id_jugador, Coordenadas& coords, uint8_t tipo) :
id_jugador(id_jugador), coords(coords), tipo(tipo) {}

void SolicitudCrearEdificio::enviarSolicitud(ProtocoloCliente& protocolo) {
    protocolo.enviarSolicitudCrearEdificio(id_jugador, coords, tipo);
}
