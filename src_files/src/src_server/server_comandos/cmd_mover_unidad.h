#ifndef CMD_MOVER_UNIDAD_H
#define CMD_MOVER_UNIDAD_H

#include "server_comando.h"

class CmdMoverUnidadServer : public ComandoServer {
private:
    uint16_t id_jugador;
    uint16_t x;
    uint16_t y;
public:
    CmdMoverUnidadServer(uint16_t id_jugador, uint16_t x, uint16_t y);
    virtual void enviarComando(ProtocoloServidor& protocolo) const override;
    virtual ~CmdMoverUnidadServer() = default;
};

#endif // CMD_MOVER_UNIDAD_H
