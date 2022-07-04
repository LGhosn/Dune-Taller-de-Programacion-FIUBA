#include "sol_atacar_unidad.h"

SolicitudAtacarUnidad::SolicitudAtacarUnidad(uint8_t id_unidad_atacante, uint8_t id_unidad_a_atacar, Coordenadas& coords_a_atacar) : 
                                                id_unidad_atacante(id_unidad_atacante), id_unidad_a_atacar(id_unidad_a_atacar), coords_a_atacar(coords_a_atacar) {}

void SolicitudAtacarUnidad::enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador) {
    protocolo.enviarSolicitudAtacarUnidad(id_jugador, id_unidad_atacante, id_unidad_a_atacar, coords_a_atacar);
}
