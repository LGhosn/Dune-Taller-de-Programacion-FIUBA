#ifndef SDL_EDIFICIO_H
#define SDL_EDIFICIO_H

#include <SDL2pp/SDL2pp.hh>
#include "../../../src_common/common_coords.h"

#define LARGO_TILE 32

#define ALTO_HP 6
#define ANCHO_HP 40
#define OFFSET_HP_Y -1
#define PADDING_HP_X 4
#define PADDING_HP_RECT 2 

#define RATIO_LINEAS_LARGO 0.2

class EdificioSDL {
protected:
    uint8_t id;
    uint8_t id_jugador;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    SDL2pp::Rect origen;
    SDL2pp::Rect destino;
    SDL2pp::Rect destino_ui;
    Coordenadas coords;
    uint16_t alto, ancho;
    int pos_en_tex_x, pos_en_tex_y;
    long frame_anterior = 0;
    bool seleccionado = false;
    float zoom;

    void setearPosicionUI(uint32_t origen_movil_x, uint32_t origen_movil_y);

private:
    void renderRectanguloSeleccion();
    void renderHP();

public:
    EdificioSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura, const Coordenadas& coords,
                uint16_t alto, uint16_t ancho, uint8_t casa);

    Coordenadas obtenerDimensiones() const;
    
    virtual void cambiarHP(uint16_t hp_edificio) = 0;
    
    void seleccionar();
    void deseleccionar();

    virtual void update(uint32_t offset_x, uint32_t offset_y, long frame_actual, float zoom) = 0;

    virtual void render() = 0;

    void renderUI();

    virtual ~EdificioSDL() = default;
};

#endif
