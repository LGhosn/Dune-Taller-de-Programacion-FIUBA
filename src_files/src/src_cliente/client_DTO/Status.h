#ifndef CLIENT_STATUS_H
#define CLIENT_STATUS_H

#include <cstdint>

class Status {
private:
    const uint8_t status_recibido;
public:
    explicit Status(uint8_t status);
    bool esperandoJugadores();
    bool conexionEstablecida();
};


#endif //CLIENT_STATUS_H
