#ifndef CMD_COMPRAR_UNIDAD_H
#define CMD_COMPRAR_UNIDAD_H

#include "server_comando.h"

class CmdComprarUnidadServer : public ComandoServer {
    uint16_t id_jugador;
    uint8_t tipo_unidad;

public:
    CmdComprarUnidadServer(uint16_t id_jugador, uint8_t tipo_unidad);

    virtual void enviarComando(ProtocoloServidor& protocolo) const override;

    virtual ~CmdComprarUnidadServer() = default;
};

#endif
