#include "cmd_empezar_construccion_edificio.h"

CmdEmpezarConstruccionEdificioServer::CmdEmpezarConstruccionEdificioServer(uint8_t tipo_edificio,
                                                uint16_t tiempo_construccion):
                                                tipo_edificio(tipo_edificio),
                                                tiempo_construccion(tiempo_construccion) {}

void CmdEmpezarConstruccionEdificioServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoEmpezarConstruccionEdificio(tipo_edificio, tiempo_construccion);
}


