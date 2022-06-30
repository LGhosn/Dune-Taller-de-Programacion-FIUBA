#include "cmd_construccion_invalida.h"

void CmdConstruccionInvalidaServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoConstruccionInvalida();
}
