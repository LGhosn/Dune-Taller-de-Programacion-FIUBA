#ifndef SDL_FABRICA_LIGERA_H
#define SDL_FABRICA_LIGERA_H

#include "sdl_edificio.h"

#define ANCHO_TEX_EDIFICIO_FL 94
#define ALTO_TEX_EDIFICIO_FL 63

#define OFFSET_PAREDES_FL_X 6
#define OFFSET_PAREDES_FL_Y 16

#define PADDING_EDIFICIO_FL_Y 16

#define LIMITE_HP_DEBILITAR 1000

class FabricaLigeraSDL : public EdificioSDL {
    SDL2pp::Rect origen_paredes;
    SDL2pp::Rect destino_paredes;
public:
    FabricaLigeraSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura, const Coordenadas& coords, uint16_t alto,
                uint16_t ancho, uint8_t casa);

    void cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t origen_movil_x, uint32_t origen_movil_y, long frame_actual, float zoom) override;

    void render() override;
};

#endif
