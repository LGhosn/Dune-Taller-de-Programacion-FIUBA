#ifndef CMD_SERVER_ACTUALIZAR_PUNTAJE_H
#define CMD_SERVER_ACTUALIZAR_PUNTAJE_H

#include "server_comando.h"

class CmdActualizarPuntajeServer : public ComandoServer {
    uint8_t id_jugador;
    uint16_t nuevo_puntaje;
public:
    CmdActualizarPuntajeServer(uint8_t id_jugador, uint16_t nuevo_puntaje);

    virtual void enviarComando(ProtocoloServidor& protocolo) const;

    ~CmdActualizarPuntajeServer() = default;
};

#endif // CMD_SERVER_ACTUALIZAR_PUNTAJE_H
