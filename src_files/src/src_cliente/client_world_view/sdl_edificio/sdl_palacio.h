#ifndef SDL_PALACIO_H
#define SDL_PALACIO_H

#include "sdl_edificio.h"

class PalacioSDL : public EdificioSDL {
    const uint32_t limite_hp_debilitar;
    const int32_t offset_y;
public:
    PalacioSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color);
    
    void cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual, float zoom) override;

    void render() override;
};

#endif // SDL_PALACIO_H
