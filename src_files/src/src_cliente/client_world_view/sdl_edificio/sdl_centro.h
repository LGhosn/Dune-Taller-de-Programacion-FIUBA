#ifndef SDL_CENTRO_H
#define SDL_CENTRO_H

#include "sdl_edificio.h"

#define ANCHO_TEX_EDIFICIO 97
#define ALTO_TEX_EDIFICIO 86
#define PADDING_EDIFICIO_Y 8

#define ANCHO_TEX_BRAZO 52
#define ALTO_TEX_BRAZO 65
#define CANT_FRAMES_BRAZO 14
#define RATE_BRAZO 5

#define OFFSET_EDIFICIO_X 3

#define OFFSET_BRAZO_X 2
#define OFFSET_BRAZO_Y 30

#define HARKONNEN 0 
#define ATREIDES 1
#define ORDOS 2

#define LIMITE_HP_DEBILITAR 1000

class CentroSDL : public EdificioSDL {
    uint8_t frame_actual_brazo = 0;
    SDL2pp::Rect origen_brazo;
    SDL2pp::Rect destino_brazo;

    // Constantes
    const uint32_t ancho_edificio;
    const uint32_t alto_edificio;
    const uint32_t padding_edificio_y;
    const int32_t offset_x_edificio;
    const uint32_t limite_hp_debilitar;

    const uint32_t ancho_brazo;
    const uint32_t alto_brazo;
    const uint8_t cant_frames_brazo;
    const uint32_t rate_brazo;
    const int32_t offset_x_brazo;
    const int32_t offset_y_brazo;
    

    void actualizarFrameBrazo(long frame_actual);
    void setearPosicionBrazo();

public:
    CentroSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer, SDL2pp::Texture& textura,
              const Coordenadas& coords, uint16_t alto, uint16_t ancho, uint8_t casa,
              YAML::Node& constantes);

    void cambiarHP(uint16_t hp_edificio) override;

    void update(uint32_t offset_x, uint32_t offset_y, long frame_actual, float zoom) override;

    void render() override;

    virtual ~CentroSDL() = default;
};

#endif
