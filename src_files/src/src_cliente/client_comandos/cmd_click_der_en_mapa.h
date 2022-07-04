#ifndef CMD_CLICK_DER_EN_MAPA_H
#define CMD_CLICK_DER_EN_MAPA_H

#include "client_comando.h"

class ClickDerEnMapa : public ComandoCliente {
    int pos_x;
    int pos_y;
public:
    ClickDerEnMapa(int pos_x, int pos_y);
    virtual bool ejecutar(WorldView& world_view) const override;
    virtual ~ClickDerEnMapa() = default;
};

#endif // CMD_CLICK_DER_EN_MAPA_H
