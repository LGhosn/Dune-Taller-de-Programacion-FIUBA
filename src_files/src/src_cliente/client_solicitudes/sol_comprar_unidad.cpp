#include "sol_comprar_unidad.h"

SolComprarUnidadCliente::SolComprarUnidadCliente(uint8_t tipo):
                                                tipo(tipo) {}

void SolComprarUnidadCliente::enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador) {
    protocolo.enviarSolicitudComprarUnidad(id_jugador, tipo);
}
