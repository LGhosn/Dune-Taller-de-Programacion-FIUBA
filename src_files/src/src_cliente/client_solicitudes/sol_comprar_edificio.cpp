#include "sol_comprar_edificio.h"

SolComprarEdificioCliente::SolComprarEdificioCliente(uint8_t tipo) :
                                                    tipo(tipo) {}

void SolComprarEdificioCliente::enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador) {
    protocolo.enviarSolicitudComprarEdificio(id_jugador, tipo);
}
