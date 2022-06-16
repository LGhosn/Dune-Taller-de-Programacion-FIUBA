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

#define OFFSET_HP_Y -15

#define OFFSET_EDIFICIO_X 3

#define OFFSET_BRAZO_X 2
#define OFFSET_BRAZO_Y 25

#define HARKONNEN 0 
#define ATREIDES 1
#define ORDOS 2

#define LIMITE_HP_DEBILITAR 1000

class CentroSDL : public EdificioSDL {
    uint8_t id;
    uint8_t id_jugador;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    Coordenadas coords;
    uint16_t alto, ancho;
    int pos_en_tex_x, pos_en_tex_y;
    int pos_en_tex_brazo_x, pos_en_tex_brazo_y;
    uint8_t frame_actual_brazo = 0;
    int pos_actual_x = 0;
    int pos_actual_y = 0;
    int pos_actual_brazo_x = 0;
    int pos_actual_brazo_y = 0;
    int tam_actual_x = 0;
    int tam_actual_y = 0;
    int tam_actual_brazo_x = 0;
    int tam_actual_brazo_y = 0;
    long frame_anterior = 0;
    bool seleccionado = false;

    void actualizarFrameBrazo(long frame_actual);
    void setearPosicionBrazo();

public:
    CentroSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer, SDL2pp::Texture& textura,
              const Coordenadas& coords, uint16_t alto, uint16_t ancho, uint8_t casa);

    Coordenadas obtenerDimensiones() const override;

    void cambiarHP(uint16_t hp_edificio) override;

    void seleccionar() override;
    void deseleccionar() override;

    void update(uint32_t offset_x, uint32_t offset_y, long frame_actual) override;

    void render() override;

    virtual ~CentroSDL() = default;
};

#endif