#ifndef SERVER_CMD_ACTUALIZAR_TIENDA_UNIDADES_H
#define SERVER_CMD_ACTUALIZAR_TIENDA_UNIDADES_H

#include "server_comando.h"

class CmdActualizarTiendaUnidadesServer : public ComandoServer {
    std::vector<bool> unidades_comprables;

public:
    explicit CmdActualizarTiendaUnidadesServer(std::vector<bool> unidades_comprables);

    virtual void enviarComando(ProtocoloServidor& protocolo) const override;

    virtual ~CmdActualizarTiendaUnidadesServer() = default;
};

#endif
