#ifndef SDL_EDIFICIO_H
#define SDL_EDIFICIO_H

#include <SDL2pp/SDL2pp.hh>
#include "../../../src_common/common_coords.h"

#define LARGO_TILE 32

#define ALTO_HP 6
#define ANCHO_HP 40
#define OFFSET_HP_Y -15
#define PADDING_HP_X 4

class EdificioSDL {
protected:
    uint8_t id;
    uint8_t id_jugador;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    Coordenadas coords;
    uint16_t alto, ancho;
    int pos_en_tex_x, pos_en_tex_y;
    int pos_actual_x = 0;
    int pos_actual_y = 0;
    int tam_actual_x = 0;
    int tam_actual_y = 0;
    long frame_anterior = 0;
    bool seleccionado = false;

public:
    EdificioSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura, const Coordenadas& coords,
                uint16_t alto, uint16_t ancho, uint8_t casa);

    Coordenadas obtenerDimensiones() const;
    
    virtual void cambiarHP(uint16_t hp_edificio) = 0;
    
    void seleccionar();
    void deseleccionar();

    virtual void update(uint32_t offset_x, uint32_t offset_y, long frame_actual) = 0;

    virtual void render() = 0;

    void renderUI();

    virtual ~EdificioSDL() = default;
};

#endif
