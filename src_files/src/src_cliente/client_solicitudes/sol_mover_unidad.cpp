#include "sol_mover_unidad.h"

SolicitudMoverUnidad::SolicitudMoverUnidad(uint16_t id_unidad, uint16_t x, uint16_t y) : id_unidad(id_unidad), x(x), y(y) {}

void SolicitudMoverUnidad::enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador) {
    protocolo.enviarSolicitudMoverUnidad(id_jugador, id_unidad, x, y);
}
