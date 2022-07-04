#include "cmd_click_der_en_mapa.h"

ClickDerEnMapa::ClickDerEnMapa(int pos_x, int pos_y) : pos_x(pos_x), pos_y(pos_y) {}

bool ClickDerEnMapa::ejecutar(WorldView& world_view) const {
    world_view.clickDerecho(pos_x, pos_y);
    return true;
}
