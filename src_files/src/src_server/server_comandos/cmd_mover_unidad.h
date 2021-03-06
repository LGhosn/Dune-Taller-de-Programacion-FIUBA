#ifndef CMD_MOVER_UNIDAD_H
#define CMD_MOVER_UNIDAD_H

#include "server_comando.h"
#include "../server_protocolo/server_protocolo.h"

class CmdMoverUnidadServer : public ComandoServer {
private:
    uint8_t id_unidad;
    uint8_t direccion;
    uint16_t tiempo;

public:
    CmdMoverUnidadServer(uint8_t id_unidad, uint8_t direccion, uint16_t tiempo);
    virtual void enviarComando(ProtocoloServidor& protocolo) const override;
    virtual ~CmdMoverUnidadServer() = default;
};

#endif // CMD_MOVER_UNIDAD_H
