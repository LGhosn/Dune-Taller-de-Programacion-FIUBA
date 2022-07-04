#ifndef SDL_TRAMPA_H
#define SDL_TRAMPA_H

#include "sdl_edificio.h"

class TrampaSDL : public EdificioSDL {
    std::vector<SDL2pp::Texture>& luces;
    SDL2pp::Rect destino_luces;
    uint8_t frame_actual_luces = 0;
    long frame_anterior = 0;

    // Constantes
    const uint32_t limite_hp_debilitar;
    const uint32_t frame_rate_luces;
    const int32_t offset_luces_x;
    const int32_t offset_luces_y;
    const uint8_t cantidad_frames;

    void actualizarFrameLuces(long frame_actual);

public: 
    TrampaSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
            TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
            uint16_t ancho, uint8_t casa,YAML::Node& constantes, ColorSDL& color);

    void cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frames_transcurridos, float zoom) override;

    void render() override;
};

#endif //SDL_TRAMPA_H
