#ifndef SDL_REFINERIA_H
#define SDL_REFINERIA_H

#include "sdl_edificio.h"

class RefineriaSDL : public EdificioSDL {
    SDL2pp::Texture& textura_paredes;
    SDL2pp::Rect destino_paredes;

    // Constantes
    const uint32_t padding_edificio_y;
    const uint32_t limite_hp_debilitar;
public:
    RefineriaSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color);

    void cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_transcurridos, float zoom) override;

    void render() override;
};


#endif
