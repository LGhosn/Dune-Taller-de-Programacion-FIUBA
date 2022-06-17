#include "cmd_click_en_mapa.h"

ClickEnMapa::ClickEnMapa(int pos_x, int pos_y) : pos_x(pos_x), pos_y(pos_y) {}

bool ClickEnMapa::ejecutar(WorldView& world_view) const {
    world_view.click_en_mapa(pos_x, pos_y);
    return true;
}
