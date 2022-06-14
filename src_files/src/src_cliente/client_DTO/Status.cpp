#include "Status.h"

Status::Status(uint8_t status) : status_recibido(status) {}

bool Status::esperandoJugadores() {
    return (this->status_recibido == 1);
}
bool Status::conexionEstablecida() {
    return (this->status_recibido == 0);
}
