#ifndef CLIENT_CMD_ACTUALIZAR_PUNTAJE_H
#define CLIENT_CMD_ACTUALIZAR_PUNTAJE_H

#include "client_comando.h"

class CmdActualizarPuntajeCliente : public ComandoCliente {
    uint8_t id_jugador;
    uint16_t nuevo_puntaje;
public:
    CmdActualizarPuntajeCliente(uint8_t id_jugador, uint16_t nuevo_puntaje);

    virtual bool ejecutar(WorldView& worldView) const;

    ~CmdActualizarPuntajeCliente() = default;
};

#endif // CLIENT_CMD_ACTUALIZAR_PUNTAJE_H
