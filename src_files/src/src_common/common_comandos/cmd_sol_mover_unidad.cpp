#include "cmd_sol_mover_unidad.h"

SolicitudMoverUnidad::SolicitudMoverUnidad(uint16_t& id_unidad, uint16_t& x, uint16_t& y) : id_unidad(id_unidad), x(x), y(y) {}

void SolicitudMoverUnidad::enviarSolicitud(ProtocoloCliente& protocolo) {
    protocolo.enviarSolicitudMoverUnidad(id_unidad, x, y);
}

void SolicitudMoverUnidad::enviarInstruccion(Protocolo_server& protocolo) {
    protocolo.enviarInstruccionMoverUnidad(id_unidad, x, y);
}