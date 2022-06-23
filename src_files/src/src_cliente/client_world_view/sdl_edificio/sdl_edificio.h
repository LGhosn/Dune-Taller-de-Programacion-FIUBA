#ifndef SDL_EDIFICIO_H
#define SDL_EDIFICIO_H

#include <SDL2pp/SDL2pp.hh>
#include "yaml-cpp/yaml.h"
#include "../../../src_common/common_coords.h"
#include "../sdl_color/sdl_color.h"

class EdificioSDL {
protected:
    uint8_t id;
    uint8_t id_jugador;
    SDL2pp::Renderer& renderer;
    SDL2pp::Texture& textura;
    ColorSDL& color;
    SDL2pp::Rect origen;
    SDL2pp::Rect destino;
    SDL2pp::Rect destino_ui;
    Coordenadas coords;
    uint16_t alto, ancho;
    int pos_en_tex_x, pos_en_tex_y;
    long frame_anterior = 0;
    bool seleccionado = false;
    float zoom;

    // Constantes
    const int alto_hp;
    const int ancho_hp;
    const int offset_x_hp;
    const int offset_y_hp;
    const int padding_x_hp;
    const int padding_rect_hp;
    const float relacion_lineas_largo;
    const int ancho_tile;
    const int largo_tile;
    const uint8_t codigo_atreides;
    const uint8_t codigo_harkonnen;
    const uint8_t codigo_ordos;

    void setearPosicionUI(uint32_t origen_movil_x, uint32_t origen_movil_y);

private:
    void renderRectanguloSeleccion();
    void renderHP();

public:
    EdificioSDL(uint8_t id, uint8_t id_jugador, SDL2pp::Renderer& renderer,
                SDL2pp::Texture& textura, const Coordenadas& coords,
                uint16_t alto, uint16_t ancho, uint8_t casa, YAML::Node& constantes,
                ColorSDL& color);

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
