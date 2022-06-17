#ifndef COMMON_STATUS_H
#define COMMON_STATUS_H

#include <cstdint>

#define CONEXION_EXITOSA 0
#define CONEXION_FALLIDA 1
#define PARTIDA_EXISTENTE 2
#define PARTIDA_NO_EXISTENTE 3

class Status {
private:
    const uint8_t conexion_establecida;
    const uint8_t partida_comenzada;
public:
    Status(uint8_t conexion_establecida, uint8_t partida_comenzada);
    const uint8_t obtenerCodigoDeConexion();
    const uint8_t obtenerCodigoDePartida();
};


#endif // COMMON_STATUS_H
