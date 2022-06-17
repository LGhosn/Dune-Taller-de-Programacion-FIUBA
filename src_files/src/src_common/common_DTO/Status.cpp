#include "Status.h"

Status::Status(uint8_t conexion_establecida, uint8_t partida_comenzada) :
                conexion_establecida(conexion_establecida),
                partida_comenzada(partida_comenzada) {}

const uint8_t Status::obtenerCodigoDeConexion() {
    return conexion_establecida;
}
const uint8_t Status::obtenerCodigoDePartida() {
    return partida_comenzada;
}