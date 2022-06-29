#ifndef SERVER_CMD_EMPEZAR_ENTRENAMIENTO_H
#define SERVER_CMD_EMPEZAR_ENTRENAMIENTO_H

#include "server_comando.h"

class CmdEmpezarEntrenamientoServer : public ComandoServer {
    uint8_t tipo_unidad;
    uint16_t tiempo_construccion;

public:
    CmdEmpezarEntrenamientoServer(uint8_t tipo_unidad, uint16_t tiempo_construccion);

    virtual void enviarComando(ProtocoloServidor& protocolo) const override;

    virtual ~CmdEmpezarEntrenamientoServer() = default;
};

#endif
