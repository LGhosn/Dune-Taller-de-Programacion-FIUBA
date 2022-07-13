#ifndef SDL_CENTRO_H
#define SDL_CENTRO_H

#include "sdl_edificio.h"
#include <vector>

class CentroSDL : public EdificioSDL {
    uint8_t frame_actual_brazo = 0;
    SDL2pp::Rect destino_brazo;
    std::vector<SDL2pp::Texture>& frames_brazo;

    // Constantes
    const uint32_t padding_edificio_y;
    const int32_t offset_x_edificio;
    const uint32_t limite_hp_debilitar;

    const uint8_t cant_frames_brazo;
    const uint32_t rate_brazo;
    const int32_t offset_x_brazo;
    const int32_t offset_y_brazo;
    long frames_restantes;

    void actualizarFrameBrazo(long frame_actual);
    void setearPosicionBrazo();

public:
    CentroSDL(uint8_t id, uint8_t id_jugador, uint16_t vida, SDL2pp::Renderer& renderer,
                TexturasSDL& texturas, const Coordenadas& coords, uint16_t alto,
                uint16_t ancho, uint8_t casa, YAML::Node& constantes, ColorSDL& color);

    virtual bool cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t offset_x, uint32_t offset_y, long frame_transcurridos, float zoom) override;

    void render() override;

    virtual ~CentroSDL() = default;
};

#endif
