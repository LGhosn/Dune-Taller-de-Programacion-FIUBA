#ifndef SDL_FABRICA_PESADA_H
#define SDL_FABRICA_PESADA_H

#include "sdl_edificio.h"

#define ANCHO_TEX_EDIFICIO_FP 96
#define ALTO_TEX_EDIFICIO_FP 85

#define OFFSET_PAREDES_FP_X 6
#define OFFSET_PAREDES_FP_Y 16

#define PADDING_EDIFICIO_FP_Y 7

#define LIMITE_HP_DEBILITAR 1000

class FabricaPesadaSDL : public EdificioSDL {
    SDL2pp::Rect origen_paredes;
    SDL2pp::Rect destino_paredes;

    // Constantes
    const uint32_t ancho_edificio;
    const uint32_t alto_edificio;
    const uint32_t padding_edificio_y;
    const uint32_t limite_hp_debilitar;
    const int32_t offset_paredes_x;
    const int32_t offset_paredes_y;
public:
    FabricaPesadaSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                    SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                    uint16_t ancho, uint8_t casa, YAML::Node& constantes);
    
    void cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual, float zoom) override;

    void render() override;
};

#endif
