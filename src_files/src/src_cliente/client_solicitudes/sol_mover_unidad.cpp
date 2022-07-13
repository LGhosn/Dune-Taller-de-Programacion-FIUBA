#include "sol_mover_unidad.h"

SolicitudMoverUnidad::SolicitudMoverUnidad(uint8_t id_unidad, const Coordenadas& coords_a_moverse) : id_unidad(id_unidad), coords_a_moverse(coords_a_moverse) {}

void SolicitudMoverUnidad::enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador) {
    protocolo.enviarSolicitudMoverUnidad(id_jugador, id_unidad, coords_a_moverse);
}
