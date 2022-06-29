#include "cmd_empezar_entrenamiento.h"
#include "../server_protocolo/server_protocolo.h"

CmdEmpezarEntrenamientoServer::CmdEmpezarEntrenamientoServer(uint8_t tipo_unidad, uint16_t tiempo_construccion) :
                                                 tipo_unidad(tipo_unidad),
                                                 tiempo_construccion(tiempo_construccion) {}

void CmdEmpezarEntrenamientoServer::enviarComando(ProtocoloServidor& protocolo) const {
    // protocolo.enviarComandoEmpezarEntrenamientoUnidad(tipo_unidad, tipo_unidad);
}
