#ifndef SERVER_CMD_ACTUALIZAR_TIENDA_EDIFICIOS_H
#define SERVER_CMD_ACTUALIZAR_TIENDA_EDIFICIOS_H

#include "server_comando.h"

class CmdActualizarTiendaEdificiosServer : public ComandoServer {
    std::vector<bool> edificios_comprables;

public:
    CmdActualizarTiendaEdificiosServer(std::vector<bool> edificios_comprables);

    virtual void enviarComando(ProtocoloServidor& protocolo) const override;

    virtual ~CmdActualizarTiendaEdificiosServer() = default;
};

#endif
