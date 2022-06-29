#ifndef CMD_MOVER_UNIDAD_H
#define CMD_MOVER_UNIDAD_H

#include "server_comando.h"
#include "../server_protocolo/server_protocolo.h"

class CmdMoverUnidadServer : public ComandoServer {
private:
    uint16_t id_jugador;
    char direccion;
    long tiempo;

public:
    CmdMoverUnidadServer(uint16_t id_jugador, char direccion, long tiempo);
    virtual void enviarComando(ProtocoloServidor& protocolo) const override;
    virtual ~CmdMoverUnidadServer() = default;
};

#endif // CMD_MOVER_UNIDAD_H
