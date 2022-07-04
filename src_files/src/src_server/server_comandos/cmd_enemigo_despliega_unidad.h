#ifndef CMD_ENENIGO_DESPLIEGA_UNIDAD_H
#define CMD_ENENIGO_DESPLIEGA_UNIDAD_H

#include "server_comando.h"

class CmdEnemigoDespliegaUnidadServer : public ComandoServer {
private:
    uint8_t id_unidad;
    uint8_t id_jugador;
    uint8_t tipo_unidad;
    uint16_t tiempo_entrenamiento;
    Coordenadas& coords_spawn;

public:
    CmdEnemigoDespliegaUnidadServer(uint8_t id_unidad, uint8_t id_jugador, uint8_t tipo_unidad, uint16_t tiempo_entrenamiento, Coordenadas& coords_spawn);
    virtual void enviarComando(ProtocoloServidor& protocolo) const override;
    virtual ~CmdEnemigoDespliegaUnidadServer() = default;
};

#endif // CMD_ENENIGO_DESPLIEGA_UNIDAD_H
