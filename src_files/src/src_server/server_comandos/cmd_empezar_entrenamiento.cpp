#include "cmd_empezar_entrenamiento.h"
#include "../server_protocolo/server_protocolo.h"

CmdEmpezarEntrenamientoServer::CmdEmpezarEntrenamientoServer(uint8_t id_unidad, uint8_t tipo_unidad, uint16_t tiempo_construccion, Coordenadas& coords_spawn) :
                                                id_unidad(id_unidad),
                                                 tipo_unidad(tipo_unidad),
                                                 tiempo_construccion(tiempo_construccion),
                                                 coords_spawn(coords_spawn) {}

void CmdEmpezarEntrenamientoServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoEmpezarEntrenamientoUnidad(id_unidad, tipo_unidad, tiempo_construccion, coords_spawn);
}
