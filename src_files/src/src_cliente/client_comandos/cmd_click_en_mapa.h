#ifndef CMD_CLICK_EN_MAPA_H
#define CMD_CLICK_EN_MAPA_H

#include "client_comando.h"

class ClickEnMapa : public ComandoCliente {
    int pos_x;
    int pos_y;
public:
    ClickEnMapa(int pos_x, int pos_y);
    virtual bool ejecutar(WorldView& world_view) const override;
    virtual ~ClickEnMapa() = default;
};

#endif // CMD_CLICK_EN_MAPA_H
