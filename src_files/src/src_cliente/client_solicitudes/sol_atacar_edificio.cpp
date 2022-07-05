#include "sol_atacar_edificio.h"

SolicitudAtacarEdificio::SolicitudAtacarEdificio(uint8_t id_unidad_atacante, uint8_t id_edificio_a_atacar) : 
                                                id_unidad_atacante(id_unidad_atacante),
                                                id_edificio_a_atacar(id_edificio_a_atacar) {}

void SolicitudAtacarEdificio::enviarSolicitud(ProtocoloCliente& protocolo, uint8_t id_jugador) {
    protocolo.enviarSolicitudAtacarEdificio(id_jugador, id_unidad_atacante, id_edificio_a_atacar);
}
