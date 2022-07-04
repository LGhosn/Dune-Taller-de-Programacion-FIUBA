#ifndef SDL_CUARTEL_H
#define SDL_CUARTEL_H

#include "sdl_edificio.h"

class CuartelSDL : public EdificioSDL {
    const uint32_t padding_y;
    const uint32_t limite_hp_debilitar;

public:
    CuartelSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color);

    void cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t offset_x, uint32_t offset_y, long frame_transcurridos, float zoom) override;

    void render() override;

};

#endif // SDL_CUARTEL_H
