#ifndef SERVER_CMD_EMPEZAR_PARTIDA_H
#define SERVER_CMD_EMPEZAR_PARTIDA_H

#include "../../src_common/common_DTO/dto_info_partida.h"
#include "server_comando.h"

class CmdEmpezarPartida : public ComandoServer {
    InfoPartidaDTO info_partida;
public:
    CmdEmpezarPartida(InfoPartidaDTO& info_partida);

    virtual void enviarComando(ProtocoloServidor& protocolo) const override;

    ~CmdEmpezarPartida() = default;
};

#endif // SERVER_CMD_EMPEZAR_PARTIDA_H