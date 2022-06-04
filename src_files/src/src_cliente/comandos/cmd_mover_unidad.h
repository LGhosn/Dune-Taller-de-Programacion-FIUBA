#ifndef CMD_MOVER_UNIDAD_H
#define CMD_MOVER_UNIDAD_H

#include "comando_a_enviar.h"
#include "../client_protocolo.h"

class SolicitudMoverUnidad : public ComandoEnviar {
    uint16_t id_unidad;
    uint16_t x;
    uint16_t y;

public:
    MoverUnidad(int id_unidad, int x, int y);
    virtual void enviar_comando(Protocolo& protocolo);
    virtual ~MoverUnidad();
}

#endif // CMD_MOVER_UNIDAD_H
