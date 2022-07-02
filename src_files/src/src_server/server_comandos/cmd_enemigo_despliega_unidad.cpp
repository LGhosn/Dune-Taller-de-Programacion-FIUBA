#include "cmd_enemigo_despliega_unidad.h"

CmdEnemigoDespliegaUnidadServer::CmdEnemigoDespliegaUnidadServer(uint8_t id_jugador,
                                                                uint8_t id_unidad,
                                                                uint8_t tipo_unidad,
                                                                long tiempo_entrenamiento,
                                                                Coordenadas& coords_spawn) :
                                                                id_jugador(id_jugador),
                                                                id_unidad(id_unidad),
                                                                tipo_unidad(tipo_unidad),
                                                                tiempo_entrenamiento(tiempo_entrenamiento),
                                                                coords_spawn(coords_spawn) {}

void CmdEnemigoDespliegaUnidadServer::enviarComando(ProtocoloServidor& protocolo) const {
    protocolo.enviarComandoEnemigoDespliegaUnidad(id_unidad, id_jugador, tipo_unidad, tiempo_entrenamiento, coords_spawn);
}